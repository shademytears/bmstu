//============================================================================
// Name        : умные.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// Задача 1
void task1() {
    cout << "Задача 1:" << endl;
    unique_ptr<int> ptr = make_unique<int>(10);
    cout << *ptr << endl;
    *ptr = 25;
    cout << *ptr << endl << endl;
}

// Задача 2
void task2() {
    cout << "Задача 2:" << endl;
    int N = 5;
    unique_ptr<int[]> arr = make_unique<int[]>(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

// Задача 3
void fillArray(unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
}

void task3() {
    cout << "Задача 3:" << endl;
    int n = 5;
    unique_ptr<int[]> arr = make_unique<int[]>(n);
    fillArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

// Задача 4
void task4() {
    cout << "Задача 4:" << endl;
    unique_ptr<int> ptr1 = make_unique<int>(42);
    cout << "ptr1: " << (ptr1 ? *ptr1 : 0) << endl;

    unique_ptr<int> ptr2 = move(ptr1);
    cout << "После move:" << endl;
    cout << "ptr1: " << (ptr1 == nullptr ? "nullptr" : "не nullptr") << endl;
    cout << "ptr2: " << *ptr2 << endl << endl;
}

// Задача 5
void task5() {
    cout << "Задача 5:" << endl;
    int N = 3, M = 4;
    unique_ptr<int[]> table = make_unique<int[]>(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            table[i * M + j] = i * j;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << table[i * M + j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Задача 6
void task6() {
    cout << "Задача 6:" << endl;
    shared_ptr<int> ptr1 = make_shared<int>(100);
    cout << "use_count после ptr1: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr2 = ptr1;
    cout << "use_count после ptr2: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr3 = ptr1;
    cout << "use_count после ptr3: " << ptr1.use_count() << endl;

    ptr2.reset();
    cout << "use_count после reset ptr2: " << ptr1.use_count() << endl << endl;
}

// Задача 7
void task7() {
    cout << "Задача 7:" << endl;
    string text = "Hello World";
    unique_ptr<char[]> chars = make_unique<char[]>(text.length() + 1);

    for (size_t i = 0; i < text.length(); i++) {
        chars[i] = text[i];
    }
    chars[text.length()] = '\0';

    int vowels = 0, consonants = 0;
    for (size_t i = 0; i < text.length(); i++) {
        char c = tolower(chars[i]);
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    unique_ptr<char[]> vowelsOnly = make_unique<char[]>(vowels + 1);
    int index = 0;
    for (size_t i = 0; i < text.length(); i++) {
        char c = tolower(chars[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelsOnly[index++] = chars[i];
        }
    }
    vowelsOnly[index] = '\0';

    cout << "Гласные: " << vowels << ", Согласные: " << consonants << endl;
    cout << "Только гласные: " << vowelsOnly.get() << endl << endl;
}

// Задача 8
void task8() {
    cout << "Задача 8:" << endl;
    int size = 5;

    unique_ptr<double[]> temp = make_unique<double[]>(size);
    double tempVals[] = {20.5, 21.0, 22.3, 20.8, 19.9};
    for (int i = 0; i < size; i++) temp[i] = tempVals[i];

    unique_ptr<double[]> press = make_unique<double[]>(size);
    double pressVals[] = {101.3, 101.5, 101.1, 101.8, 100.9};
    for (int i = 0; i < size; i++) press[i] = pressVals[i];

    unique_ptr<double[]> hum = make_unique<double[]>(size);
    double humVals[] = {45.5, 46.2, 47.8, 44.9, 43.5};
    for (int i = 0; i < size; i++) hum[i] = humVals[i];

    double tempSum = 0, pressSum = 0, humSum = 0;
    for (int i = 0; i < size; i++) {
        tempSum += temp[i];
        pressSum += press[i];
        humSum += hum[i];
    }

    cout << "Параметр\tСреднее значение" << endl;
    cout << "Температура\t" << tempSum / size << endl;
    cout << "Давление\t" << pressSum / size << endl;
    cout << "Влажность\t" << humSum / size << endl << endl;
}

// Задача 9
void processA(shared_ptr<vector<int>> buf) {
    for (size_t i = 0; i < buf->size(); i++) {
        (*buf)[i] += 1;
    }
}

void processB(shared_ptr<vector<int>> buf) {
    for (size_t i = 0; i < buf->size(); i++) {
        (*buf)[i] *= 2;
    }
}

void task9() {
    cout << "Задача 9:" << endl;
    shared_ptr<vector<int>> buffer = make_shared<vector<int>>();
    for (int i = 1; i <= 10; i++) {
        buffer->push_back(i);
    }

    processA(buffer);
    processB(buffer);

    for (size_t i = 0; i < buffer->size(); i++) {
        cout << (*buffer)[i] << " ";
    }
    cout << endl << endl;
}

// Задача 10
unique_ptr<int[]> createArray(int n) {
    unique_ptr<int[]> arr = make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

void task10() {
    cout << "Задача 10:" << endl;
    int n = 5;
    unique_ptr<int[]> arr = createArray(n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

// Задача 11
void task11() {
    cout << "Задача 11:" << endl;
    vector<double> signals = {25.4, 27.1, 30.0, 29.5, 28.3};
    cout << "Исходные данные: ";
    for (size_t i = 0; i < signals.size(); i++) cout << signals[i] << " ";
    cout << endl;

    unique_ptr<double[]> data = make_unique<double[]>(signals.size());
    for (size_t i = 0; i < signals.size(); i++) {
        data[i] = signals[i];
    }

    auto mean = [](unique_ptr<double[]>& arr, int size) -> double {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
    };

    auto normalize = [](unique_ptr<double[]>& arr, int size, double maxVal) {
        for (int i = 0; i < size; i++) {
            arr[i] /= maxVal;
        }
    };

    auto copyBack = [](vector<double>& signals, unique_ptr<double[]>& arr, int size) {
        for (int i = 0; i < size; i++) {
            signals[i] = arr[i];
        }
    };

    double avg = mean(data, signals.size());
    cout << "Среднее значение: " << avg << endl;

    double maxVal = *max_element(signals.begin(), signals.end());
    normalize(data, signals.size(), maxVal);
    copyBack(signals, data, signals.size());

    cout << "Нормализованные сигналы: ";
    for (size_t i = 0; i < signals.size(); i++) cout << signals[i] << " ";
    cout << endl << endl;
}

// Задача 12
void task12() {
    cout << "Задача 12:" << endl;
    vector<string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop"
    };

    shared_ptr<vector<string>> plogs = make_shared<vector<string>>(logs);
    vector<string> errors;

    auto filterErrors = [](shared_ptr<vector<string>> logs, vector<string>& errors) {
        for (size_t i = 0; i < logs->size(); i++) {
            if ((*logs)[i].find("ERROR") != string::npos) {
                errors.push_back((*logs)[i]);
            }
        }
    };

    filterErrors(plogs, errors);
    sort(errors.begin(), errors.end());
    errors.erase(unique(errors.begin(), errors.end()), errors.end());

    cout << "Исходный журнал:" << endl;
    for (size_t i = 0; i < logs.size(); i++) {
        cout << logs[i] << endl;
    }

    cout << "\nОшибки:" << endl;
    for (size_t i = 0; i < errors.size(); i++) {
        cout << errors[i] << endl;
    }
    cout << endl;
}

// Задача 13
void task13() {
    cout << "Задача 13:" << endl;
    unique_ptr<string> part1 = make_unique<string>("Sensor data:");
    unique_ptr<string> part2 = make_unique<string>("Voltage stable.");
    unique_ptr<string> part3 = make_unique<string>("System nominal.");

    vector<unique_ptr<string>> reportParts;
    reportParts.push_back(move(part1));
    reportParts.push_back(move(part2));
    reportParts.push_back(move(part3));

    auto concatParts = [&reportParts]() -> string {
        string result;
        for (size_t i = 0; i < reportParts.size(); i++) {
            result += *reportParts[i] + "\n";
        }
        return result;
    };

    auto countWord = [](const string& text, const string& word) -> int {
        int count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
        return count;
    };

    string report = concatParts();
    cout << "Отчёт:\n" << report;
    int wordCount = countWord(report, "data");
    cout << "Слово \"data\" встречается " << wordCount << " раз" << endl << endl;
}

// Задача 14
void task14() {
    cout << "Задача 14:" << endl;
    int N = 3, M = 3;
    unique_ptr<double[]> matrix = make_unique<double[]>(N * M);

    double values[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < N * M; i++) {
        matrix[i] = values[i];
    }

    auto sumColumns = [&matrix, N, M]() -> vector<double> {
        vector<double> sums(M, 0);
        for (int j = 0; j < M; j++) {
            for (int i = 0; i < N; i++) {
                sums[j] += matrix[i * M + j];
            }
        }
        return sums;
    };

    auto maxIndex = [](const vector<double>& sums) -> int {
        double maxVal = sums[0];
        int maxIdx = 0;
        for (size_t i = 1; i < sums.size(); i++) {
            if (sums[i] > maxVal) {
                maxVal = sums[i];
                maxIdx = i;
            }
        }
        return maxIdx;
    };

    vector<double> sums = sumColumns();
    int maxIdx = maxIndex(sums);

    cout << "Суммы столбцов: [";
    for (size_t i = 0; i < sums.size(); i++) {
        cout << sums[i];
        if (i < sums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Столбец с максимальной суммой: " << maxIdx + 1
         << " (" << sums[maxIdx] << ")" << endl << endl;
}

// Задача 15
void task15() {
    cout << "Задача 15:" << endl;
    vector<string> routes = {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };

    shared_ptr<vector<string>> proutes = make_shared<vector<string>>(routes);

    auto countCity = [](shared_ptr<vector<string>> routes, const string& city) -> int {
        int count = 0;
        for (size_t i = 0; i < routes->size(); i++) {
            if ((*routes)[i].find(city) != string::npos) {
                count++;
            }
        }
        return count;
    };

    auto sortByLength = [](shared_ptr<vector<string>> routes) {
        for (size_t i = 0; i < routes->size() - 1; i++) {
            for (size_t j = 0; j < routes->size() - i - 1; j++) {
                if ((*routes)[j].length() < (*routes)[j + 1].length()) {
                    string temp = (*routes)[j];
                    (*routes)[j] = (*routes)[j + 1];
                    (*routes)[j + 1] = temp;
                }
            }
        }
    };

    auto concat = [](shared_ptr<vector<string>> routes) -> string {
        string result;
        for (size_t i = 0; i < routes->size(); i++) {
            result += (*routes)[i];
            if (i < routes->size() - 1) result += " -> ";
        }
        return result;
    };

    cout << "Количество маршрутов с \"Paris\": "
         << countCity(proutes, "Paris") << endl;

    sortByLength(proutes);
    cout << "Отсортированные маршруты:" << endl;
    for (size_t i = 0; i < proutes->size(); i++) {
        cout << (*proutes)[i] << endl;
    }

    cout << "Общий маршрут:" << endl;
    cout << concat(proutes) << endl;
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
    task13();
    task14();
    task15();

    return 0;
}
