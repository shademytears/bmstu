#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

vector<Book> readBooksFromFile() {
    vector<Book> books;
    ifstream inFile("books.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                Book book;
                book.title = line.substr(0, pos1);
                book.author = line.substr(pos1 + 1, pos2 - pos1 - 1);
                book.year = stoi(line.substr(pos2 + 1));
                books.push_back(book);
            }
        }
        inFile.close();
    } else {
        cout << "файл books.txt не найден или пуст. будет создан новый." << endl;
    }

    return books;
}

void writeBooksToFile(const vector<Book>& books) {
    ofstream outFile("books.txt");

    if (outFile.is_open()) {
        for (const auto& book : books) {
            outFile << book.title << "|" << book.author << "|" << book.year << endl;
        }
        outFile.close();
        cout << "данные успешно сохранены в файл books.txt" << endl;
    } else {
        cout << "ошибка: не удалось открыть файл для записи." << endl;
    }
}


void writeToOutput(const string& result) {
    ofstream outFile("output.txt", ios::app);

    if (outFile.is_open()) {
        outFile << result << endl;
        outFile.close();
    } else {
        cout << "ошибка: не удалось открыть output.txt для записи." << endl;
    }
}

void createAndFillFile() {
    vector<Book> books;
    cout << "=== СОЗДАНИЕ И ЗАПОЛНЕНИЕ ФАЙЛА ===" << endl;

    while (true) {
        Book book;
        cout << "введите название книги (пустая строка для завершения): ";
        getline(cin, book.title);

        if (book.title.empty()) {
            break;
        }

        cout << "введите автора книги: ";
        getline(cin, book.author);

        cout << "Введите год выпуска: ";
        cin >> book.year;
        cin.ignore();

        books.push_back(book);
        cout << "книга добавлена!" << endl;
    }

    writeBooksToFile(books);
    writeToOutput("=== СОЗДАН И ЗАПОЛНЕН ФАЙЛ BOOKS.TXT ===");
}

void searchBook() {
    vector<Book> books = readBooksFromFile();
    if (books.empty()) {
        cout << "файл пуст или не существует." << endl;
        return;
    }

    string searchTitle;
    cout << "введите название книги для поиска: ";
    getline(cin, searchTitle);

    bool found = false;
    string result = "=== РЕЗУЛЬТАТЫ ПОИСКА ===\n";

    for (const auto& book : books) {
        if (book.title.find(searchTitle) != string::npos) {
            cout << "найдена книга: " << book.title << " | "
                 << book.author << " | " << book.year << endl;
            result += "найдена книга: " + book.title + " | " +
                     book.author + " | " + to_string(book.year) + "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "книга с названием '" << searchTitle << "' не найдена." << endl;
        result += "книга с названием '" + searchTitle + "' не найдена.\n";
    }

    writeToOutput(result);
}

void sortBooks() {
    vector<Book> books = readBooksFromFile();
    if (books.empty()) {
        cout << "файл пуст или не существует." << endl;
        return;
    }

    int choice;
    cout << "выберите критерий сортировки:" << endl;
    cout << "1 - по автору" << endl;
    cout << "2 - по году выпуска" << endl;
    cout << "ваш выбор: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {

        for (size_t i = 0; i < books.size() - 1; i++) {
            for (size_t j = 0; j < books.size() - i - 1; j++) {
                if (books[j].author > books[j + 1].author) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        cout << "книги отсортированы по автору." << endl;
    } else if (choice == 2) {

        for (size_t i = 0; i < books.size() - 1; i++) {
            for (size_t j = 0; j < books.size() - i - 1; j++) {
                if (books[j].year > books[j + 1].year) {
                    // Обмен книгами
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        cout << "Книги отсортированы по году выпуска." << endl;
    } else {
        cout << "Неверный выбор." << endl;
        return;
    }

    writeBooksToFile(books);

    string result = "=== ОТСОРТИРОВАННЫЙ СПИСОК КНИГ ===\n";
    cout << "отсортированный список книг:" << endl;
    for (const auto& book : books) {
        cout << book.title << " | " << book.author << " | " << book.year << endl;
        result += book.title + " | " + book.author + " | " + to_string(book.year) + "\n";
    }

    writeToOutput(result);
}

void addBookToFile() {
    vector<Book> books = readBooksFromFile();

    Book newBook;
    cout << "=== ДОБАВЛЕНИЕ НОВОЙ КНИГИ ===" << endl;
    cout << "введите название книги: ";
    getline(cin, newBook.title);

    cout << "введите автора книги: ";
    getline(cin, newBook.author);

    cout << "введите год выпуска: ";
    cin >> newBook.year;
    cin.ignore();

    books.push_back(newBook);
    writeBooksToFile(books);

    string result = "=== ДОБАВЛЕНА НОВАЯ КНИГА ===\n";
    result += newBook.title + " | " + newBook.author + " | " + to_string(newBook.year);
    writeToOutput(result);

    cout << "книга успешно добавлена!" << endl;
}

void showBooksByYear() {
    vector<Book> books = readBooksFromFile();
    if (books.empty()) {
        cout << "файл пуст или не существует." << endl;
        return;
    }

    int maxYear;
    cout << "введите максимальный год выпуска: ";
    cin >> maxYear;
    cin.ignore();

    string result = "=== КНИГИ ДО " + to_string(maxYear) + " ГОДА ===\n";
    bool found = false;

    cout << "Книги выпущенные до " << maxYear << " года:" << endl;
    for (const auto& book : books) {
        if (book.year <= maxYear) {
            cout << book.title << " | " << book.author << " | " << book.year << endl;
            result += book.title + " | " + book.author + " | " + to_string(book.year) + "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "книги выпущенные до " << maxYear << " года не найдены." << endl;
        result += "книги не найдены.\n";
    }

    writeToOutput(result);
}

void showMenu() {
    int choice;

    do {
        cout << "\n=== меню ===" << endl;
        cout << "1 - создание и заполнение файла книгами" << endl;
        cout << "2 - поиск книги по названию" << endl;
        cout << "3 - сортировка книг" << endl;
        cout << "4 - добавление новой книги" << endl;
        cout << "5 - вывод книг по году выпуска" << endl;
        cout << "0 - выход из программы" << endl;
        cout << "выберите действие: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                createAndFillFile();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                sortBooks();
                break;
            case 4:
                addBookToFile();
                break;
            case 5:
                showBooksByYear();
                break;
            case 0:
                cout << "конец программы." << endl;
                writeToOutput("=== ПРОГРАММА ЗАВЕРШЕНА ===");
                break;
            default:
                cout << "неверный выбор. Попробуйте снова." << endl;
        }

    } while (choice != 0);
}

int main() {

    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "=== НАЧАЛО РАБОТЫ ПРОГРАММЫ ===" << endl;
        outFile.close();
    }

    showMenu();
    return 0;
}
