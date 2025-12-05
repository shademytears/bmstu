//============================================================================
// Name        : структуры.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// ===== ЗАДАЧИ НА СТРУКТУРЫ =====

// Задача 1: Учет сотрудников
struct Employee {
    string name;
    int age;
    string position;
    double salary;
};

void task1() {
    cout << "=== Задача 1: Учет сотрудников ===" << endl;

    int n;
    cout << "Введите количество сотрудников: ";
    cin >> n;
    cin.ignore(); // очистка буфера

    vector<Employee> employees(n);

    // Ввод данных о сотрудниках
    for (int i = 0; i < n; i++) {
        cout << "\nСотрудник " << i + 1 << ":" << endl;
        cout << "Введите имя сотрудника: ";
        getline(cin, employees[i].name);

        cout << "Введите возраст сотрудника: ";
        cin >> employees[i].age;
        cin.ignore();

        cout << "Введите должность сотрудника: ";
        getline(cin, employees[i].position);

        cout << "Введите зарплату сотрудника: ";
        cin >> employees[i].salary;
        cin.ignore();
    }

    // Поиск самого молодого и старшего сотрудников
    int youngestIndex = 0;
    int oldestIndex = 0;
    double totalSalary = 0;

    for (int i = 0; i < n; i++) {
        if (employees[i].age < employees[youngestIndex].age) {
            youngestIndex = i;
        }
        if (employees[i].age > employees[oldestIndex].age) {
            oldestIndex = i;
        }
        totalSalary += employees[i].salary;
    }

    // Вывод результатов
    cout << "\n=== Результаты ===" << endl;
    cout << "Самый молодой сотрудник: " << employees[youngestIndex].name
         << ", возраст: " << employees[youngestIndex].age
         << ", должность: " << employees[youngestIndex].position
         << ", зарплата: " << employees[youngestIndex].salary << endl;

    cout << "Самый старший сотрудник: " << employees[oldestIndex].name
         << ", возраст: " << employees[oldestIndex].age
         << ", должность: " << employees[oldestIndex].position
         << ", зарплата: " << employees[oldestIndex].salary << endl;

    cout << "Средняя зарплата всех сотрудников: " << totalSalary / n << endl;
    cout << endl;
}

// Задача 2: Банковский счет
struct BankAccount {
    int accountNumber;
    string ownerName;
    double balance;
};

void task2() {
    cout << "=== Задача 2: Банковский счет ===" << endl;

    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n=== Меню ===" << endl;
        cout << "1. Создать новый банковский счет" << endl;
        cout << "2. Положить деньги на счет" << endl;
        cout << "3. Снять деньги со счета" << endl;
        cout << "4. Проверить информацию о счете" << endl;
        cout << "5. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: { // Создать новый счет
                BankAccount newAccount;
                cout << "Введите номер счета: ";
                cin >> newAccount.accountNumber;
                cin.ignore();
                cout << "Введите имя владельца счета: ";
                getline(cin, newAccount.ownerName);
                newAccount.balance = 0.0;
                accounts.push_back(newAccount);
                cout << "Банковский счет создан." << endl;
                break;
            }
            case 2: { // Положить деньги
                int accNumber;
                double amount;
                cout << "Введите номер счета: ";
                cin >> accNumber;
                cout << "Введите сумму для внесения: ";
                cin >> amount;

                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        accounts[i].balance += amount;
                        cout << "Средства зачислены. Новый баланс: "
                             << accounts[i].balance << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Счет не найден." << endl;
                break;
            }
            case 3: { // Снять деньги
                int accNumber;
                double amount;
                cout << "Введите номер счета: ";
                cin >> accNumber;
                cout << "Введите сумму для снятия: ";
                cin >> amount;

                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        if (accounts[i].balance >= amount) {
                            accounts[i].balance -= amount;
                            cout << "Средства сняты. Новый баланс: "
                                 << accounts[i].balance << endl;
                        } else {
                            cout << "Недостаточно средств." << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Счет не найден." << endl;
                break;
            }
            case 4: { // Проверить информацию
                int accNumber;
                cout << "Введите номер счета: ";
                cin >> accNumber;

                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        cout << "\nИнформация о счете:" << endl;
                        cout << "Номер счета: " << accounts[i].accountNumber << endl;
                        cout << "Владелец: " << accounts[i].ownerName << endl;
                        cout << "Баланс: " << accounts[i].balance << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Счет не найден." << endl;
                break;
            }
            case 5:
                cout << "Программа завершена." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);

    cout << endl;
}

// Задача 3: Библиотека
struct Book {
    string title;
    string author;
    int year;
    string genre;
};

struct Library {
    Book books[100];
    int count;
};

void task3() {
    cout << "=== Задача 3: Библиотека ===" << endl;

    Library library;
    library.count = 0;
    int choice;

    do {
        cout << "\n=== Меню библиотеки ===" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Удалить книгу по названию" << endl;
        cout << "3. Найти книги по автору" << endl;
        cout << "4. Вывести все книги" << endl;
        cout << "5. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: { // Добавить книгу
                if (library.count >= 100) {
                    cout << "Библиотека полна!" << endl;
                    break;
                }

                cout << "Введите название книги: ";
                getline(cin, library.books[library.count].title);
                cout << "Введите автора книги: ";
                getline(cin, library.books[library.count].author);
                cout << "Введите год издания: ";
                cin >> library.books[library.count].year;
                cin.ignore();
                cout << "Введите жанр: ";
                getline(cin, library.books[library.count].genre);

                library.count++;
                cout << "Книга добавлена." << endl;
                break;
            }
            case 2: { // Удалить книгу
                string titleToDelete;
                cout << "Введите название книги для удаления: ";
                getline(cin, titleToDelete);

                bool found = false;
                for (int i = 0; i < library.count; i++) {
                    if (library.books[i].title == titleToDelete) {
                        // Сдвигаем все книги после удаленной
                        for (int j = i; j < library.count - 1; j++) {
                            library.books[j] = library.books[j + 1];
                        }
                        library.count--;
                        cout << "Книга удалена." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Книга не найдена." << endl;
                break;
            }
            case 3: { // Найти по автору
                string authorToFind;
                cout << "Введите автора для поиска: ";
                getline(cin, authorToFind);

                bool found = false;
                cout << "\nНайденные книги:" << endl;
                for (int i = 0; i < library.count; i++) {
                    if (library.books[i].author == authorToFind) {
                        cout << "Название: " << library.books[i].title << endl;
                        cout << "Автор: " << library.books[i].author << endl;
                        cout << "Год: " << library.books[i].year << endl;
                        cout << "Жанр: " << library.books[i].genre << endl;
                        cout << "---" << endl;
                        found = true;
                    }
                }
                if (!found) cout << "Книги не найдены." << endl;
                break;
            }
            case 4: { // Вывести все книги
                if (library.count == 0) {
                    cout << "Библиотека пуста." << endl;
                    break;
                }

                cout << "\nВсе книги в библиотеке (" << library.count << "):" << endl;
                for (int i = 0; i < library.count; i++) {
                    cout << i + 1 << ". " << library.books[i].title
                         << " (" << library.books[i].author
                         << ", " << library.books[i].year
                         << ") - " << library.books[i].genre << endl;
                }
                break;
            }
            case 5:
                cout << "Выход из библиотеки." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);

    cout << endl;
}

// ===== ЗАДАЧИ НА ОБЪЕДИНЕНИЯ =====

// Задача 1: Хранение различных типов данных
union Variant {
    int intValue;
    double doubleValue;
    char charValue;
};

void task4() {
    cout << "=== Задача 1: Объединение Variant ===" << endl;

    Variant data;
    char typeChoice;

    cout << "Выберите тип данных (i - целое число, d - число с плавающей запятой, c - символ): ";
    cin >> typeChoice;

    switch (typeChoice) {
        case 'i':
            cout << "Введите целое число: ";
            cin >> data.intValue;
            cout << "Вы ввели: " << data.intValue << endl;
            break;
        case 'd':
            cout << "Введите число с плавающей запятой: ";
            cin >> data.doubleValue;
            cout << "Вы ввели: " << fixed << setprecision(2) << data.doubleValue << endl;
            break;
        case 'c':
            cout << "Введите символ: ";
            cin >> data.charValue;
            cout << "Вы ввели: " << data.charValue << endl;
            break;
        default:
            cout << "Неверный выбор типа." << endl;
    }
    cout << endl;
}

// Задача 2: Управление геометрическими фигурами
union ShapeData {
    struct {
        double radius;
    } circle;

    struct {
        double length;
        double width;
    } rectangle;
};

enum ShapeType { CIRCLE = 1, RECTANGLE };

void task5() {
    cout << "=== Задача 2: Управление геометрическими фигурами ===" << endl;

    ShapeData shape;
    ShapeType type;
    int choice;

    cout << "Выберите фигуру (1 - круг, 2 - прямоугольник): ";
    cin >> choice;

    switch (choice) {
        case CIRCLE:
            cout << "Введите радиус круга: ";
            cin >> shape.circle.radius;
            cout << "Площадь круга: "
                 << fixed << setprecision(2)
                 << 3.14159 * shape.circle.radius * shape.circle.radius << endl;
            break;

        case RECTANGLE:
            cout << "Введите длину прямоугольника: ";
            cin >> shape.rectangle.length;
            cout << "Введите ширину прямоугольника: ";
            cin >> shape.rectangle.width;
            cout << "Площадь прямоугольника: "
                 << shape.rectangle.length * shape.rectangle.width << endl;
            break;

        default:
            cout << "Неверный выбор фигуры." << endl;
    }
    cout << endl;
}

// Задача 3: Хранение даты и времени
union DateTime {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    } components;

    long long timestamp;
};

void task6() {
    cout << "=== Задача 3: Хранение даты и времени ===" << endl;

    DateTime dt;

    cout << "Введите год: ";
    cin >> dt.components.year;
    cout << "Введите месяц: ";
    cin >> dt.components.month;
    cout << "Введите день: ";
    cin >> dt.components.day;
    cout << "Введите час: ";
    cin >> dt.components.hour;
    cout << "Введите минуту: ";
    cin >> dt.components.minute;
    cout << "Введите секунду: ";
    cin >> dt.components.second;

    cout << "Дата и время: "
         << dt.components.year << "-"
         << dt.components.month << "-"
         << dt.components.day << " "
         << dt.components.hour << ":"
         << setw(2) << setfill('0') << dt.components.minute << ":"
         << setw(2) << setfill('0') << dt.components.second << endl;
    cout << endl;
}

int main() {
    task1(); // Учет сотрудников
    task2(); // Банковский счет
    task3(); // Библиотека
    task4(); // Объединение Variant
    task5(); // Геометрические фигуры
    task6(); // Дата и время

    return 0;
}
