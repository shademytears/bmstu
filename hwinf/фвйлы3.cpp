//============================================================================
// Name        : фвйлы3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Задача 1: Моделирование ожидания в очереди
void addToQueue(queue<string>& queue, const string& person) {
    queue.push(person);
    cout << person << " добавлен в очередь." << endl;
}

void processQueue(queue<string>& queue) {
    if (queue.empty()) {
        cout << "Очередь пуста." << endl;
        return;
    }

    string person = queue.front();
    queue.pop();
    cout << person << " обработан и удален из очереди." << endl;
}

void task1() {
    cout << "=== Задача 1: Моделирование очереди в магазине ===" << endl;

    queue<string> shopQueue;

    // Добавляем людей в очередь
    addToQueue(shopQueue, "Иван");
    addToQueue(shopQueue, "Мария");
    addToQueue(shopQueue, "Алексей");

    cout << "\nОбработка очереди:" << endl;

    // Обрабатываем очередь
    processQueue(shopQueue);
    processQueue(shopQueue);
    processQueue(shopQueue);
    processQueue(shopQueue); // Попытка обработки пустой очереди

    cout << endl;
}

// Задача 2: Обработка событий в сетевом приложении
void addEventToQueue(queue<string>& eventQueue, const string& event) {
    eventQueue.push(event);
    cout << "Событие добавлено: " << event << endl;
}

void processEvents(queue<string>& eventQueue) {
    if (eventQueue.empty()) {
        cout << "Очередь событий пуста." << endl;
        return;
    }

    string event = eventQueue.front();
    eventQueue.pop();
    cout << "Обрабатывается событие: " << event << endl;
}

void task2() {
    cout << "=== Задача 2: Обработка событий в сетевом приложении ===" << endl;

    queue<string> eventQueue;

    // Добавляем события
    addEventToQueue(eventQueue, "GET /index.html HTTP/1.1");
    addEventToQueue(eventQueue, "POST /api/login HTTP/1.1");
    addEventToQueue(eventQueue, "GET /api/data HTTP/1.1");
    addEventToQueue(eventQueue, "PUT /api/update HTTP/1.1");

    cout << "\nОбработка событий:" << endl;

    // Обрабатываем события
    while (!eventQueue.empty()) {
        processEvents(eventQueue);
    }

    // Попытка обработки пустой очереди
    processEvents(eventQueue);

    cout << endl;
}

// Задача 3: Обработка заказов в интернет-магазине
struct Order {
    string customerName;
    vector<string> items;
};

void addOrder(queue<Order>& orderQueue, const Order& newOrder) {
    orderQueue.push(newOrder);
    cout << "Заказ добавлен для клиента: " << newOrder.customerName << endl;
}

void processOrder(queue<Order>& orderQueue) {
    if (orderQueue.empty()) {
        cout << "Очередь заказов пуста." << endl;
        return;
    }

    Order order = orderQueue.front();
    orderQueue.pop();

    cout << "\nОбработка заказа:" << endl;
    cout << "Клиент: " << order.customerName << endl;
    cout << "Товары:" << endl;

    for (size_t i = 0; i < order.items.size(); i++) {
        cout << "  - " << order.items[i] << endl;
    }

    cout << "Заказ обработан и удален из очереди." << endl;
}

void task3() {
    cout << "=== Задача 3: Обработка заказов в интернет-магазине ===" << endl;

    queue<Order> orderQueue;

    // Создаем заказы
    Order order1;
    order1.customerName = "Иван Петров";
    order1.items.push_back("Ноутбук Dell");
    order1.items.push_back("Мышь беспроводная");
    order1.items.push_back("Сумка для ноутбука");

    Order order2;
    order2.customerName = "Мария Сидорова";
    order2.items.push_back("Смартфон Samsung");
    order2.items.push_back("Чехол для телефона");

    Order order3;
    order3.customerName = "Алексей Иванов";
    order3.items.push_back("Наушники Sony");
    order3.items.push_back("Флешка 64GB");
    order3.items.push_back("Кабель USB-C");

    // Добавляем заказы в очередь
    addOrder(orderQueue, order1);
    addOrder(orderQueue, order2);
    addOrder(orderQueue, order3);

    cout << "\nОбработка заказов:" << endl;

    // Обрабатываем все заказы
    while (!orderQueue.empty()) {
        processOrder(orderQueue);
        cout << "------------------------" << endl;
    }

    // Попытка обработки пустой очереди
    processOrder(orderQueue);

    cout << endl;
}

int main() {
    task1();
    task2();
    task3();

    return 0;
}
