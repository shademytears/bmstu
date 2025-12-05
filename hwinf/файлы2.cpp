//============================================================================
// Name        : файлы2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <chrono>
using namespace std;

// Задача 1
struct SearchResult {
    int line_number;
    int position;
    string word;
};

void task1() {
    cout << "Task 1: Text file analyzer" << endl;

    // Create test file
    ofstream testFile("book.txt");
    testFile << "The main character approached the window.\n";
    testFile << "There was no hero in the room.\n";
    testFile << "The hero silently looked into the distance.\n";
    testFile << "This is not about the hero, but about something else.\n";
    testFile.close();

    ifstream inFile("book.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string search_word = "hero";
    vector<SearchResult> results;
    string line;
    int line_num = 1;
    int total_count = 0;

    while (getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(search_word, pos)) != string::npos) {
            SearchResult result;
            result.line_number = line_num;
            result.position = pos + 1;
            result.word = search_word;
            results.push_back(result);
            total_count++;
            pos += search_word.length();
        }
        line_num++;
    }

    inFile.close();

    ofstream outFile("search_results.txt");
    outFile << "Found occurrences: " << total_count << endl;
    outFile << "Search results for word '" << search_word << "':" << endl;
    outFile << "Line\tPosition\tWord" << endl;

    for (size_t i = 0; i < results.size(); i++) {
        outFile << results[i].line_number << "\t"
                << results[i].position << "\t"
                << results[i].word << endl;
    }

    cout << "Found occurrences: " << total_count << endl;
    cout << "Results saved to search_results.txt" << endl << endl;
}

// Задача 2
void task2() {
    cout << "Task 2: Configuration file editor" << endl;

    // Create test file
    ofstream testFile("config.txt");
    testFile << "server_ip=192.168.1.1\n";
    testFile << "port=8080\n";
    testFile << "timeout=30\n";
    testFile << "max_connections=100\n";
    testFile.close();

    ifstream inFile("config.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    string search_key = "timeout=";
    string new_value = "60";

    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].find(search_key) == 0) {
            lines[i] = search_key + new_value;
            break;
        }
    }

    ofstream outFile("config.txt");
    for (size_t i = 0; i < lines.size(); i++) {
        outFile << lines[i] << endl;
    }
    outFile.close();

    cout << "File config.txt updated." << endl;
    cout << "Parameter timeout changed from 30 to 60" << endl << endl;
}

// Задача 3
void task3() {
    cout << "Task 3: Log file splitter" << endl;

    // Create test log file
    ofstream testFile("application.log");
    for (int i = 1; i <= 50; i++) {
        testFile << "2025-01-" << setw(2) << setfill('0') << (i % 30 + 1)
                 << " 10:" << setw(2) << setfill('0') << (i % 60)
                 << ":00 INFO: Log entry " << i << endl;
    }
    testFile.close();

    ifstream inFile("application.log");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int part_size = 1000;
    int part_count = 1;
    int current_size = 0;

    string line;
    ofstream outFile;
    vector<string> part_files;

    while (getline(inFile, line)) {
        if (current_size == 0) {
            string filename = "log_part" + to_string(part_count) + ".txt";
            part_files.push_back(filename);
            outFile.open(filename);
            part_count++;
        }

        outFile << line << endl;
        current_size += line.length() + 1;

        if (current_size >= part_size) {
            outFile.close();
            current_size = 0;
        }
    }

    if (outFile.is_open()) {
        outFile.close();
    }

    inFile.close();

    // Create index file
    ofstream indexFile("log_index.txt");
    indexFile << "Number of parts: " << part_count - 1 << endl;
    indexFile << "File list:" << endl;
    for (size_t i = 0; i < part_files.size(); i++) {
        indexFile << part_files[i] << endl;
    }
    indexFile.close();

    cout << "Log file split into " << part_count - 1 << " parts" << endl;
    cout << "Information saved to log_index.txt" << endl << endl;
}

// Задача 4
void task4() {
    cout << "Task 4: Binary files (numbers)" << endl;

    int numbers[] = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
    int count = 10;

    // Write to binary file
    ofstream outFile("numbers.bin", ios::binary);
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return;
    }

    outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    outFile.close();

    // Read from binary file
    ifstream inFile("numbers.bin", ios::binary);
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Determine file size
    inFile.seekg(0, ios::end);
    streampos file_size = inFile.tellg();
    inFile.seekg(0, ios::beg);

    // Read numbers
    int* buffer = new int[count];
    inFile.read(reinterpret_cast<char*>(buffer), file_size);

    // Display results
    cout << "File contents:" << endl;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "File size: " << file_size << " bytes" << endl;
    cout << "Sum of numbers: " << sum << endl;
    cout << "Average value: " << (double)sum / count << endl;

    delete[] buffer;
    inFile.close();
    cout << endl;
}

// Задача 5
struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

void task5() {
    cout << "Task 5: Structures in binary files" << endl;

    // Create array of students
    Student students[] = {
        {1, "Ivan Petrov", 20, 4.5},
        {2, "Maria Sidorova", 19, 4.8},
        {3, "Alexey Ivanov", 21, 4.2}
    };
    int student_count = 3;

    // Write to binary file
    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return;
    }

    for (int i = 0; i < student_count; i++) {
        outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    outFile.close();

    // Read from binary file
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Determine number of students
    inFile.seekg(0, ios::end);
    streampos file_size = inFile.tellg();
    int total_students = file_size / sizeof(Student);
    inFile.seekg(0, ios::beg);

    cout << "Total students in file: " << total_students << endl;
    cout << "Student list:" << endl;

    Student student;
    int best_student_idx = -1;
    double best_grade = -1;

    for (int i = 0; i < total_students; i++) {
        inFile.read(reinterpret_cast<char*>(&student), sizeof(Student));

        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Average grade: " << student.average_grade << endl;
        cout << "---" << endl;

        if (student.average_grade > best_grade) {
            best_grade = student.average_grade;
            best_student_idx = i;
        }
    }

    // Find best student
    if (best_student_idx != -1) {
        inFile.seekg(best_student_idx * sizeof(Student), ios::beg);
        inFile.read(reinterpret_cast<char*>(&student), sizeof(Student));
        cout << "Student with highest grade:" << endl;
        cout << student.name << " - " << student.average_grade << endl;
    }

    inFile.close();
    cout << endl;
}

// Задача 6
struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

void task6() {
    cout << "Task 6: Creating CSV file with products" << endl;

    srand(time(0));

    // Create array of categories
    string categories[] = {
        "Electronics", "Accessories", "Clothing",
        "Books", "Food", "Appliances"
    };
    int category_count = 6;

    // Create array of product names
    string product_names[] = {
        "Laptop", "Mouse", "Keyboard", "Monitor",
        "Headphones", "Flash Drive", "Case", "Charger",
        "T-Shirt", "Jeans", "Book", "Coffee",
        "Tea", "Microwave", "Refrigerator", "TV",
        "Smartphone", "Tablet", "Watch", "Backpack"
    };
    int name_count = 20;

    ofstream outFile("products.csv");
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return;
    }

    // CSV header
    outFile << "id,name,category,price,quantity" << endl;

    // Generate 20 products
    for (int i = 1; i <= 20; i++) {
        Product p;
        p.id = i;
        p.name = product_names[i - 1];
        p.category = categories[rand() % category_count];
        p.price = (rand() % 9900 + 100) / 100.0 * 100;
        p.quantity = rand() % 100 + 1;

        outFile << p.id << ","
                << p.name << ","
                << p.category << ","
                << fixed << setprecision(2) << p.price << ","
                << p.quantity << endl;
    }

    outFile.close();

    cout << "File products.csv created." << endl;
    cout << "Contains 20 product records." << endl << endl;
}

// Задача 7
void task7() {
    cout << "Task 7: Analyzing CSV file with products" << endl;

    // First create the file if it doesn't exist
    task6();

    ifstream inFile("products.csv");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<Product> products;
    string line;

    // Skip header
    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        Product p;

        // Read ID
        getline(ss, token, ',');
        p.id = stoi(token);

        // Read name
        getline(ss, p.name, ',');

        // Read category
        getline(ss, p.category, ',');

        // Read price
        getline(ss, token, ',');
        p.price = stod(token);

        // Read quantity
        getline(ss, token, ',');
        p.quantity = stoi(token);

        products.push_back(p);
    }

    inFile.close();

    // Analyze data
    double total_value = 0;
    int total_quantity = 0;
    double max_price = 0;
    double min_price = 1e9;
    string expensive_product, cheap_product;

    cout << "Product list:" << endl;
    cout << "ID\tName\t\tCategory\tPrice\tQuantity" << endl;

    for (size_t i = 0; i < products.size(); i++) {
        Product& p = products[i];

        cout << p.id << "\t"
             << p.name << "\t\t"
             << p.category << "\t"
             << fixed << setprecision(2) << p.price << "\t"
             << p.quantity << endl;

        total_value += p.price * p.quantity;
        total_quantity += p.quantity;

        if (p.price > max_price) {
            max_price = p.price;
            expensive_product = p.name;
        }

        if (p.price < min_price) {
            min_price = p.price;
            cheap_product = p.name;
        }
    }

    cout << "\nStatistics:" << endl;
    cout << "Total quantity: " << total_quantity << endl;
    cout << "Total value: " << fixed << setprecision(2) << total_value << " RUB" << endl;
    cout << "Most expensive product: " << expensive_product << " (" << max_price << " RUB)" << endl;
    cout << "Cheapest product: " << cheap_product << " (" << min_price << " RUB)" << endl;
    cout << "Average price: " << total_value / total_quantity << " RUB" << endl << endl;
}

// Задача 8 - Helper functions instead of lambda
bool isExpensive(const Product& p) {
    return p.price > 5000;
}

bool isElectronics(const Product& p) {
    return p.category == "Electronics";
}

bool hasHighQuantity(const Product& p) {
    return p.quantity > 10;
}

void task8() {
    cout << "Task 8: Product filtering" << endl;

    // First create the file if it doesn't exist
    task6();

    ifstream inFile("products.csv");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<Product> products;
    string line;

    // Skip header
    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        Product p;

        getline(ss, token, ',');
        p.id = stoi(token);

        getline(ss, p.name, ',');

        getline(ss, p.category, ',');

        getline(ss, token, ',');
        p.price = stod(token);

        getline(ss, token, ',');
        p.quantity = stoi(token);

        products.push_back(p);
    }

    inFile.close();

    // Filter products
    vector<Product> expensive_products;
    vector<Product> electronics_products;
    vector<Product> high_quantity_products;

    for (size_t i = 0; i < products.size(); i++) {
        if (isExpensive(products[i])) {
            expensive_products.push_back(products[i]);
        }
        if (isElectronics(products[i])) {
            electronics_products.push_back(products[i]);
        }
        if (hasHighQuantity(products[i])) {
            high_quantity_products.push_back(products[i]);
        }
    }

    // Save expensive products
    ofstream outFile("filtered_products.csv");
    outFile << "id,name,category,price,quantity" << endl;

    for (size_t i = 0; i < expensive_products.size(); i++) {
        Product& p = expensive_products[i];
        outFile << p.id << ","
                << p.name << ","
                << p.category << ","
                << fixed << setprecision(2) << p.price << ","
                << p.quantity << endl;
    }

    outFile.close();

    cout << "Filtering results:" << endl;
    cout << "Expensive products (>5000 RUB): " << expensive_products.size() << endl;
    cout << "Electronics products: " << electronics_products.size() << endl;
    cout << "High quantity products (>10): " << high_quantity_products.size() << endl;
    cout << "Expensive products saved to filtered_products.csv" << endl << endl;
}

// Задача 9 - Helper functions for sorting
bool compareByPriceAsc(const Product& a, const Product& b) {
    return a.price < b.price;
}

bool compareByPriceDesc(const Product& a, const Product& b) {
    return a.price > b.price;
}

bool compareByName(const Product& a, const Product& b) {
    return a.name < b.name;
}

bool compareByQuantityDesc(const Product& a, const Product& b) {
    return a.quantity > b.quantity;
}

void task9() {
    cout << "Task 9: Product sorting" << endl;

    // First create the file if it doesn't exist
    task6();

    ifstream inFile("products.csv");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<Product> products;
    string line;

    // Skip header
    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        Product p;

        getline(ss, token, ',');
        p.id = stoi(token);

        getline(ss, p.name, ',');

        getline(ss, p.category, ',');

        getline(ss, token, ',');
        p.price = stod(token);

        getline(ss, token, ',');
        p.quantity = stoi(token);

        products.push_back(p);
    }

    inFile.close();

    // Sort by price (ascending)
    sort(products.begin(), products.end(), compareByPriceAsc);

    // Save sorted data
    ofstream outFile("sorted_products.csv");
    outFile << "id,name,category,price,quantity" << endl;

    for (size_t i = 0; i < products.size(); i++) {
        Product& p = products[i];
        outFile << p.id << ","
                << p.name << ","
                << p.category << ","
                << fixed << setprecision(2) << p.price << ","
                << p.quantity << endl;
    }

    outFile.close();

    cout << "Products sorted by price (low to high)" << endl;
    cout << "Results saved to sorted_products.csv" << endl << endl;
}

// Задача 10
void task10() {
    cout << "Task 10: Configuration management" << endl;

    // Create configuration file
    ofstream outFile("config.json");
    outFile << "{" << endl;
    outFile << "    \"app_name\": \"My Application\"," << endl;
    outFile << "    \"version\": \"1.0.0\"," << endl;
    outFile << "    \"settings\": {" << endl;
    outFile << "        \"max_connections\": 100," << endl;
    outFile << "        \"timeout\": 30," << endl;
    outFile << "        \"debug_mode\": true" << endl;
    outFile << "    }," << endl;
    outFile << "    \"database\": {" << endl;
    outFile << "        \"host\": \"localhost\"," << endl;
    outFile << "        \"port\": 5432," << endl;
    outFile << "        \"username\": \"admin\"" << endl;
    outFile << "    }" << endl;
    outFile << "}" << endl;
    outFile.close();

    cout << "Configuration file created." << endl;

    // Read and display configuration
    ifstream inFile("config.json");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "\nContents of config.json:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    cout << "\nConfiguration read successfully." << endl << endl;
}

// Задача 11
bool isValidTemperature(double temp) {
    return temp >= -50 && temp <= 50;
}

void task11() {
    cout << "Task 11: Sensor data processing" << endl;

    // Create test data
    ofstream testFile("sensor_data.txt");
    testFile << "25.3\n";
    testFile << "-12.7\n";
    testFile << "38.9\n";
    testFile << "999.9\n"; // sensor error
    testFile << "22.1\n";
    testFile << "-60.5\n"; // invalid value
    testFile << "18.7\n";
    testFile << "42.3\n";
    testFile << "-5.2\n";
    testFile.close();

    ifstream inFile("sensor_data.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<double> temperatures;
    double value;

    while (inFile >> value) {
        temperatures.push_back(value);
    }
    inFile.close();

    // Filter data
    vector<double> filtered;
    for (size_t i = 0; i < temperatures.size(); i++) {
        if (isValidTemperature(temperatures[i])) {
            filtered.push_back(temperatures[i]);
        }
    }

    // Calculate average temperature
    double sum = 0;
    for (size_t i = 0; i < filtered.size(); i++) {
        sum += filtered[i];
    }
    double average = filtered.size() > 0 ? sum / filtered.size() : 0;

    // Save filtered data
    ofstream outFile("filtered_sensor_data.txt");
    outFile << "Filtered sensor data:" << endl;
    outFile << "Valid measurements: " << filtered.size() << endl;
    outFile << "Invalid measurements: " << temperatures.size() - filtered.size() << endl;
    outFile << "Average temperature: " << fixed << setprecision(2) << average << "°C" << endl;
    outFile << "Data:" << endl;

    for (size_t i = 0; i < filtered.size(); i++) {
        outFile << filtered[i] << endl;
    }

    outFile.close();

    cout << "Data processing complete." << endl;
    cout << "Valid measurements: " << filtered.size() << endl;
    cout << "Invalid measurements: " << temperatures.size() - filtered.size() << endl;
    cout << "Average temperature: " << average << "°C" << endl;
    cout << "Results saved to filtered_sensor_data.txt" << endl << endl;
}

// Задача 12
void task12() {
    cout << "Task 12: Write speed comparison" << endl;

    // Create vector with 100000 numbers
    vector<int> numbers;
    for (int i = 0; i < 100000; i++) {
        numbers.push_back(i);
    }

    // Method 1: Write each number individually
    ofstream file1("method1.bin", ios::binary);
    chrono::steady_clock::time_point start1 = chrono::steady_clock::now();

    for (int i = 0; i < 100000; i++) {
        file1.write(reinterpret_cast<char*>(&i), sizeof(int));
    }

    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    file1.close();
    long long time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

    // Method 2: Write all numbers at once
    ofstream file2("method2.bin", ios::binary);
    chrono::steady_clock::time_point start2 = chrono::steady_clock::now();

    file2.write(reinterpret_cast<char*>(&numbers[0]), numbers.size() * sizeof(int));

    chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
    file2.close();
    long long time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

    // Display results
    cout << "Comparison results:" << endl;
    cout << "Method 1 (one by one): " << time1 << " ms" << endl;
    cout << "Method 2 (all at once): " << time2 << " ms" << endl;
    cout << "Difference: " << (time1 - time2) << " ms" << endl;

    double speedup = (double)time1 / time2;
    cout << "Speedup: " << fixed << setprecision(2) << speedup << "x" << endl;

    // Clean up temporary files
    remove("method1.bin");
    remove("method2.bin");

    cout << endl;
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();

    return 0;
}
