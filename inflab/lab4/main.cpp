#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include <ctime>
#include <fstream>

using namespace std;
using namespace pqxx;


connection* connectDB() {
    try {
        return new connection("dbname=library");
    } catch (...) {
        return nullptr;
    }
}


void logToFile(const string& msg) {
    ofstream log("log.txt", ios::app);
    if (log) {
        time_t t = time(0);
        log << ctime(&t) << " - " << msg << endl;
    }
}


void addAuthor(connection* conn) {
    string name;
    int year;
    cout << "Имя автора: ";
    getline(cin, name);
    cout << "Год рождения: ";
    cin >> year;
    cin.ignore();

    try {
        work txn(*conn);
        string sql = "INSERT INTO authors (name, birth_year) VALUES ($1, $2)";
        txn.exec_params(sql, name, year);
        txn.commit();
        cout << "Автор добавлен" << endl;
        logToFile("Добавлен автор: " + name);
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void addBook(connection* conn) {
    string title, genre;
    int author_id, year;
    cout << "Название книги: ";
    getline(cin, title);
    cout << "ID автора: ";
    cin >> author_id;
    cout << "Год издания: ";
    cin >> year;
    cin.ignore();
    cout << "Жанр: ";
    getline(cin, genre);

    try {
        work txn(*conn);
        string sql = "INSERT INTO books (title, author_id, publication_year, genre) VALUES ($1, $2, $3, $4)";
        txn.exec_params(sql, title, author_id, year, genre);
        txn.commit();
        cout << "Книга добавлена" << endl;
        logToFile("Добавлена книга: " + title);
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void addUser(connection* conn) {
    string name;
    cout << "Имя пользователя: ";
    getline(cin, name);

    try {
        work txn(*conn);
        string sql = "INSERT INTO users (name) VALUES ($1)";
        txn.exec_params(sql, name);
        txn.commit();
        cout << "Пользователь добавлен" << endl;
        logToFile("Добавлен пользователь: " + name);
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void borrowBook(connection* conn) {
    int user_id, book_id;
    cout << "ID пользователя: ";
    cin >> user_id;
    cout << "ID книги: ";
    cin >> book_id;
    cin.ignore();

    try {
        work txn(*conn);


        result check = txn.exec_params("SELECT id FROM borrowed_books WHERE book_id = $1 AND return_date IS NULL", book_id);
        if (check.size() > 0) {
            cout << "Книга уже выдана" << endl;
            return;
        }

        txn.exec_params("INSERT INTO borrowed_books (user_id, book_id) VALUES ($1, $2)", user_id, book_id);
        txn.commit();
        cout << "Книга выдана" << endl;
        logToFile("Книга " + to_string(book_id) + " выдана пользователю " + to_string(user_id));
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void returnBook(connection* conn) {
    int book_id;
    cout << "ID книги для возврата: ";
    cin >> book_id;
    cin.ignore();

    try {
        work txn(*conn);
        txn.exec_params("UPDATE borrowed_books SET return_date = CURRENT_DATE WHERE book_id = $1 AND return_date IS NULL", book_id);
        txn.commit();
        cout << "Книга возвращена" << endl;
        logToFile("Книга " + to_string(book_id) + " возвращена");
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void booksByAuthor(connection* conn) {
    string author_name;
    cout << "Имя автора: ";
    getline(cin, author_name);

    try {
        nontransaction ntx(*conn);
        result res = ntx.exec_params("SELECT b.title, b.genre FROM books b JOIN authors a ON b.author_id = a.id WHERE a.name = $1", author_name);

        if (res.empty()) {
            cout << "Книги не найдены" << endl;
            return;
        }

        cout << "Книги автора " << author_name << ":" << endl;
        for (auto row : res) {
            cout << "- " << row["title"].as<string>() << " (" << row["genre"].as<string>() << ")" << endl;
        }
        logToFile("Запрос: книги автора " + author_name);
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void usersLastYear(connection* conn) {
    try {
        nontransaction ntx(*conn);
        result res = ntx.exec("SELECT COUNT(*) FROM users WHERE registration_date >= CURRENT_DATE - INTERVAL '1 year'");
        int count = res[0][0].as<int>();
        cout << "Пользователей за последний год: " << count << endl;
        logToFile("Запрос: пользователи за год");
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void booksLast30Days(connection* conn) {
    try {
        nontransaction ntx(*conn);
        result res = ntx.exec("SELECT b.title, u.name FROM borrowed_books bb JOIN books b ON bb.book_id = b.id JOIN users u ON bb.user_id = u.id WHERE bb.borrow_date >= CURRENT_DATE - INTERVAL '30 days' AND bb.return_date IS NULL");

        if (res.empty()) {
            cout << "Нет книг за последние 30 дней" << endl;
            return;
        }

        cout << "Книги за последние 30 дней:" << endl;
        for (auto row : res) {
            cout << "- " << row["title"].as<string>() << " (взял: " << row["name"].as<string>() << ")" << endl;
        }
        logToFile("Запрос: книги за 30 дней");
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void top3Books(connection* conn) {
    try {
        nontransaction ntx(*conn);
        result res = ntx.exec("SELECT b.title, COUNT(*) as count FROM borrowed_books bb JOIN books b ON bb.book_id = b.id GROUP BY b.title ORDER BY count DESC LIMIT 3");

        if (res.empty()) {
            cout << "Нет данных" << endl;
            return;
        }

        cout << "Топ-3 популярных книги:" << endl;
        int i = 1;
        for (auto row : res) {
            cout << i++ << ". " << row["title"].as<string>() << " (" << row["count"].as<int>() << " раз)" << endl;
        }
        logToFile("Запрос: топ-3 книги");
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}


void showMenu() {
    cout << "\nБиблиотека" << endl;
    cout << "1. Добавить автора" << endl;
    cout << "2. Добавить книгу" << endl;
    cout << "3. Добавить пользователя" << endl;
    cout << "4. Выдать книгу" << endl;
    cout << "5. Вернуть книгу" << endl;
    cout << "6. Книги автора" << endl;
    cout << "7. Пользователи за год" << endl;
    cout << "8. Книги за 30 дней" << endl;
    cout << "9. Топ-3 книги" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите: ";
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    connection* conn = connectDB();
    if (!conn) {
        cerr << "Не удалось подключиться к базе" << endl;
        return 1;
    }

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addAuthor(conn); break;
            case 2: addBook(conn); break;
            case 3: addUser(conn); break;
            case 4: borrowBook(conn); break;
            case 5: returnBook(conn); break;
            case 6: booksByAuthor(conn); break;
            case 7: usersLastYear(conn); break;
            case 8: booksLast30Days(conn); break;
            case 9: top3Books(conn); break;
            case 0: cout << "Выход" << endl; break;
            default: cout << "Неверный выбор" << endl;
        }
    } while (choice != 0);

    conn->close();
    delete conn;

    return 0;
}
