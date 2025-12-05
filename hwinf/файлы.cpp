//============================================================================
// Name        : файлы.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>
using namespace std;

// Задача 1
void task1() {
    cout << "Задача 1:" << endl;
    ifstream inFile("input.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "Содержимое файла:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    cout << endl;
}

// Задача 2
void task2() {
    cout << "Задача 2:" << endl;
    ifstream inFile("data.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    int count = 0;
    string line;
    while (getline(inFile, line)) {
        count++;
    }

    cout << "Количество строк в файле: " << count << endl;
    inFile.close();
    cout << endl;
}

// Задача 3
void task3() {
    cout << "Задача 3:" << endl;
    ifstream inFile("text.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    int wordCount = 0;
    string word;
    while (inFile >> word) {
        wordCount++;
    }

    cout << "Количество слов в файле: " << wordCount << endl;
    inFile.close();
    cout << endl;
}

// Задача 4
void task4() {
    cout << "Задача 4:" << endl;
    ifstream source("source.txt");
    ofstream dest("copy.txt");

    if (!source || !dest) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    int lineCount = 0;
    string line;
    while (getline(source, line)) {
        dest << line << endl;
        lineCount++;
    }

    cout << "Файл успешно скопирован." << endl;
    cout << "Количество скопированных строк: " << lineCount << endl;

    source.close();
    dest.close();
    cout << endl;
}

// Задача 5
void task5() {
    cout << "Задача 5:" << endl;
    ifstream inFile("input.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    char ch;
    int charCount = 0;
    while (inFile.get(ch)) {
        charCount++;
    }

    cout << "Количество символов в файле: " << charCount << endl;
    inFile.close();
    cout << endl;
}

// Задача 6
void task6() {
    cout << "Задача 6:" << endl;
    ofstream outFile("output.txt");

    if (!outFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "Введите строки (пустая строка завершает ввод):" << endl;
    string line;

    while (true) {
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        outFile << line << endl;
    }

    cout << "Данные записаны в файл output.txt." << endl;
    outFile.close();
    cout << endl;
}

// Задача 7
void task7() {
    cout << "Задача 7:" << endl;
    ifstream inFile("numbers.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    int num, count = 0, sum = 0;
    while (inFile >> num) {
        count++;
        sum += num;
    }

    double average = count > 0 ? (double)sum / count : 0;

    cout << "Количество чисел: " << count << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Среднее: " << fixed << setprecision(1) << average << endl;

    inFile.close();
    cout << endl;
}

// Задача 8
void task8() {
    cout << "Задача 8:" << endl;
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1 || !file2) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    bool identical = true;
    string line1, line2;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            identical = false;
            break;
        }
    }

    if (getline(file1, line1) || getline(file2, line2)) {
        identical = false;
    }

    if (identical) {
        cout << "Файлы идентичны." << endl;
    } else {
        cout << "Файлы различаются." << endl;
    }

    file1.close();
    file2.close();
    cout << endl;
}

// Задача 9 - упрощенная версия без map
void task9() {
    cout << "Задача 9:" << endl;
    ifstream inFile("temperature_data.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    // Простой анализ без map
    vector<string> sensors;
    vector<double> temps;
    string sensorName;
    double temperature;

    while (inFile >> sensorName >> temperature) {
        sensors.push_back(sensorName);
        temps.push_back(temperature);
    }

    inFile.close();

    ofstream outFile("report.txt");

    // Группируем вручную
    for (size_t i = 0; i < sensors.size(); i++) {
        string currentSensor = sensors[i];
        if (currentSensor == "") continue;

        double minTemp = temps[i];
        double maxTemp = temps[i];
        double sum = temps[i];
        int count = 1;

        for (size_t j = i + 1; j < sensors.size(); j++) {
            if (sensors[j] == currentSensor) {
                if (temps[j] < minTemp) minTemp = temps[j];
                if (temps[j] > maxTemp) maxTemp = temps[j];
                sum += temps[j];
                count++;
                sensors[j] = ""; // пометим как обработанный
            }
        }

        double avgTemp = sum / count;
        outFile << currentSensor << ": min = " << fixed << setprecision(1)
                << minTemp << ", max = " << maxTemp << ", avg = " << avgTemp << endl;
    }

    cout << "Отчёт о температурных данных сохранён в report.txt" << endl;
    outFile.close();
    cout << endl;
}

// Задача 10 - упрощенная версия без map
void task10() {
    cout << "Задача 10:" << endl;
    ifstream inFile("power_log.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    vector<string> devices;
    vector<double> powers;
    string timestamp, deviceName;
    double power;

    while (inFile >> timestamp >> deviceName >> power) {
        devices.push_back(deviceName);
        powers.push_back(power);
    }

    inFile.close();

    ofstream outFile("energy_report.txt");

    for (size_t i = 0; i < devices.size(); i++) {
        string currentDevice = devices[i];
        if (currentDevice == "") continue;

        double total = powers[i];
        int count = 1;

        for (size_t j = i + 1; j < devices.size(); j++) {
            if (devices[j] == currentDevice) {
                total += powers[j];
                count++;
                devices[j] = ""; // пометим как обработанный
            }
        }

        double average = total / count;
        outFile << currentDevice << ": measurements = " << count
                << ", total = " << fixed << setprecision(2) << total
                << " kWh, average = " << average << " kW" << endl;
    }

    cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << endl;
    outFile.close();
    cout << endl;
}

// Задача 11
void task11() {
    cout << "Задача 11:" << endl;
    ifstream inFile("vibration_log.txt");

    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    vector<double> amplitudes;
    double value;

    while (inFile >> value) {
        amplitudes.push_back(value);
    }

    inFile.close();

    // Фильтруем значения > 0.05
    vector<double> filtered;
    for (size_t i = 0; i < amplitudes.size(); i++) {
        if (amplitudes[i] > 0.05) {
            filtered.push_back(amplitudes[i]);
        }
    }

    // Вычисляем статистики
    double sum = 0;
    double minVal = filtered[0];
    double maxVal = filtered[0];

    for (size_t i = 0; i < filtered.size(); i++) {
        sum += filtered[i];
        if (filtered[i] < minVal) minVal = filtered[i];
        if (filtered[i] > maxVal) maxVal = filtered[i];
    }

    double meanVal = filtered.size() > 0 ? sum / filtered.size() : 0;

    ofstream outFile("vibration_report.txt");

    outFile << "Количество измерений: " << amplitudes.size() << endl;
    outFile << "Фильтрованные значения (>0.05): ";
    for (size_t i = 0; i < filtered.size(); i++) {
        outFile << fixed << setprecision(2) << filtered[i];
        if (i < filtered.size() - 1) outFile << " ";
    }
    outFile << endl;
    outFile << "Среднее значение: " << fixed << setprecision(4) << meanVal << endl;
    outFile << "Минимум: " << fixed << setprecision(2) << minVal << endl;
    outFile << "Максимум: " << fixed << setprecision(2) << maxVal << endl;

    outFile.close();

    cout << "Анализ вибрационных данных завершён. Отчёт сохранён в vibration_report.txt" << endl;
    cout << endl;
}

int main() {
    // Создаем тестовые файлы
    ofstream testFile("input.txt");
    testFile << "Это первая строка.\nА это вторая.\nТретья строка завершает файл.";
    testFile.close();

    ofstream dataFile("data.txt");
    dataFile << "Строка 1\nСтрока 2\nСтрока 3\nСтрока 4";
    dataFile.close();

    ofstream textFile("text.txt");
    textFile << "Это тестовый текст с несколькими словами для проверки";
    textFile.close();

    ofstream sourceFile("source.txt");
    sourceFile << "Первая строка\nВторая строка\nТретья строка";
    sourceFile.close();

    ofstream numbersFile("numbers.txt");
    numbersFile << "10 20 30 40 50 60";
    numbersFile.close();

    ofstream file1("file1.txt");
    file1 << "Текст для сравнения\nВторая строка";
    file1.close();

    ofstream file2("file2.txt");
    file2 << "Текст для сравнения\nВторая строка";
    file2.close();

    // Тестовые данные для задач 9-11
    ofstream tempFile("temperature_data.txt");
    tempFile << "Sensor1 22.5\nSensor2 21.8\nSensor3 23.1\n";
    tempFile << "Sensor1 22.7\nSensor2 22.0\nSensor3 23.3";
    tempFile.close();

    ofstream powerFile("power_log.txt");
    powerFile << "2025-11-09T08:00:00 MotorA 1.25\n";
    powerFile << "2025-11-09T08:00:00 PumpB 0.95\n";
    powerFile << "2025-11-09T08:30:00 MotorA 1.40\n";
    powerFile << "2025-11-09T08:30:00 PumpB 0.90\n";
    powerFile << "2025-11-09T09:00:00 MotorA 1.35";
    powerFile.close();

    ofstream vibFile("vibration_log.txt");
    vibFile << "0.02\n0.05\n0.03\n0.10\n0.09\n0.07\n0.15\n0.04";
    vibFile.close();

    task1();
    task2();
    task3();
    task4();
    task5();

    cout << "Задача 6 требует интерактивного ввода. Пропускаем в автономном режиме." << endl << endl;

    task7();
    task8();
    task9();
    task10();
    task11();

    return 0;
}
