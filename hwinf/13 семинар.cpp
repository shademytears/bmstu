//============================================================================
// Name        : 13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*#include <iostream>
#include <string>

using namespace std;


class Book {
private:
    string title;
    string author;
    int year;

public:

    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }


    void displayInfo() {
        cout << "Название: " << title
             << ", Автор: " << author
             << ", Год выпуска: " << year << endl;
    }
};

class Rectangle {
private:
    double length;
    double width;

public:

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    void displayInfo() {
        double area = calculateArea();
        double perimeter = calculatePerimeter();
        cout << "Длина: " << length
             << ", Ширина: " << width
             << ", Площадь: " << area
             << ", Периметр: " << perimeter << endl;
    }
};

int main() {
    cout << "=== Задача 1: Создание класса «Книга» ===" << endl;
    cout << "Пример работы класса Book:" << endl;


    Book book1("Преступление и наказание", "Фёдор Достоевский", 1866);
    Book book2("Мастер и Маргарита", "Михаил Булгаков", 1967);
    Book book3("Война и мир", "Лев Толстой", 1869);


    book1.displayInfo();
    book2.displayInfo();
    book3.displayInfo();

    cout << "\n=== Задача 2: Создание класса «Прямоугольник» ===" << endl;
    cout << "Пример работы класса Rectangle:" << endl;


    Rectangle rect1(5, 3);
    Rectangle rect2(7.5, 4.2);
    Rectangle rect3(10, 6.5);


    rect1.displayInfo();
    rect2.displayInfo();
    rect3.displayInfo();

    cout << "\n=== Дополнительные вычисления ===" << endl;

    // Демонстрация отдельных методов
    cout << "Для прямоугольника rect1:" << endl;
    cout << "Площадь: " << rect1.calculateArea() << endl;
    cout << "Периметр: " << rect1.calculatePerimeter() << endl;

    return 0;
}


#include <iostream>
#include <string>

using namespace std;


class Book {
private:
    string title;
    string author;
    int year;

public:

    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }


    void displayInfo() {
        cout << "Название: " << title
             << ", Автор: " << author
             << ", Год выпуска: " << year << endl;
    }
};


class Rectangle {
private:
    double length;
    double width;

public:

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }


    double calculateArea() {
        return length * width;
    }


    double calculatePerimeter() {
        return 2 * (length + width);
    }


    void displayInfo() {
        cout << "Длина: " << length
             << ", Ширина: " << width
             << ", Площадь: " << calculateArea()
             << ", Периметр: " << calculatePerimeter() << endl;
    }
};

int main() {
    cout << "=== Задача 1: Создание класса «Книга» ===" << endl;


    Book myBook("Преступление и наказание", "Фёдор Достоевский", 1866);


    cout << "Информация о книге:" << endl;
    myBook.displayInfo();

    cout << "\n=== Задача 2: Создание класса «Прямоугольник» ===" << endl;


    Rectangle myRectangle(8.5, 5.3);


    cout << "Информация о прямоугольнике:" << endl;
    myRectangle.displayInfo();

    return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;


class Publication {
protected:
    string title;

public:

    Publication(string t) {
        title = t;
    }


    virtual void displayInfo() {
        cout << "Название: " << title;
    }
};


class Book : public Publication {
private:
    string author;
    int year;

public:
    // Конструктор с параметрами
    Book(string t, string a, int y) : Publication(t) {
        author = a;
        year = y;
    }


    void displayInfo() override {
        cout << "Название: " << title
             << ", Автор: " << author
             << ", Год выпуска: " << year << endl;
    }
};


class Shape {
protected:
    double length;

public:

    Shape(double l) {
        length = l;
    }


    virtual void displayInfo() {
        cout << "Длина: " << length;
    }
};


class Rectangle : public Shape {
private:
    double width;

public:

    Rectangle(double l, double w) : Shape(l) {
        width = w;
    }


    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }


    void displayInfo() override {
        double area = calculateArea();
        double perimeter = calculatePerimeter();
        cout << "Длина: " << length
             << ", Ширина: " << width
             << ", Площадь: " << area
             << ", Периметр: " << perimeter << endl;
    }
};


int main() {
    cout << "=== Задача 1: Создание класса «Книга» с наследованием ===" << endl;


    Book myBook("Преступление и наказание", "Фёдор Достоевский", 1866);


    cout << "Информация о книге:" << endl;
    myBook.displayInfo();

    cout << "\n=== Задача 2: Создание класса «Прямоугольник» с наследованием ===" << endl;


    Rectangle myRectangle(10.5, 6.3);


    cout << "Информация о прямоугольнике:" << endl;
    myRectangle.displayInfo();

    cout << "\n=== Дополнительная демонстрация полиморфизма ===" << endl;


    cout << "1. Использование указателя на Publication:" << endl;
    Publication* pubPtr = &myBook;
    pubPtr->displayInfo();

    cout << "\n2. Использование указателя на Shape:" << endl;
    Shape* shapePtr = &myRectangle;
    shapePtr->displayInfo();

    return 0;
}
