//============================================================================
// Name        : указатели.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 1. Подсчёт длины строки вручную
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int myStrLen(const char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// 2.
void myStrCopy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// 3.
void myStrCat(char* dest, const char* src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// 4.
int countChar(const char* str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}

// 5.
void replaceSpaces(char* str) {
    while (*str != '\0') {
        if (*str == ' ') {
            *str = '_';
        }
        str++;
    }
}

// 6.
void reverse(char* str) {
    char* start = str;
    char* end = str;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// 7.
bool isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        if (*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// 8.
const char* findSubstring(const char* text, const char* word) {
    while (*text != '\0') {
        const char* t = text;
        const char* w = word;

        while (*t != '\0' && *w != '\0' && *t == *w) {
            t++;
            w++;
        }

        if (*w == '\0') {
            return text;
        }

        text++;
    }
    return nullptr;
}

// 9.
void removeSpaces(char* str) {
    char* dest = str;

    while (*str != '\0') {
        if (*str != ' ') {
            *dest = *str;
            dest++;
        }
        str++;
    }
    *dest = '\0';
}

// 10.
int myStrCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// 11.
int sumVector(const vector<int>& vec) {
    int sum = 0;
    const int* p = &vec[0];
    int size = vec.size();

    for (int i = 0; i < size; i++) {
        sum += *(p + i);
    }
    return sum;
}

// 12.
void increaseByTen(vector<int>& vec) {
    int* p = vec.data();
    int size = vec.size();

    for (int i = 0; i < size; i++) {
        *(p + i) += 10;
    }
}

// 13.
void parseTelemetry(const char* data) {
    const char* p = data;

    while (*p != '\0') {
        const char* name_start = p;
        const char* value_start = nullptr;

        while (*p != '\0' && *p != ':' && *p != ';') {
            if (*p == ':') {
                value_start = p + 1;
            }
            p++;
        }

        if (*p == ':') {
            value_start = p + 1;
            p++;
        }

        const char* value_end = p;

        if (value_start && value_start < value_end) {
            cout << "Parameter: ";
            const char* n = name_start;
            while (n < value_start - 1) {
                cout << *n;
                n++;
            }
            cout << ", Value: ";
            const char* v = value_start;
            while (v < value_end) {
                cout << *v;
                v++;
            }
            cout << endl;
        }

        if (*p == ';') {
            p++;
        }
    }
}

// 14.
double computeRMS(const vector<double>& signal) {
    const double* p = signal.data();
    int size = signal.size();
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        double val = *(p + i);
        sum += val * val;
    }

    return sqrt(sum / size);
}

// 15.
struct Command {
    string name;
    int value;
};

void parseCommand(const char* input, vector<Command>& buffer) {
    Command cmd;
    const char* p = input;

    string name_str;
    while (*p != '\0' && *p != ' ') {
        name_str += *p;
        p++;
    }
    cmd.name = name_str;

    if (*p == ' ') {
        p++;
        int value = 0;
        while (*p != '\0') {
            value = value * 10 + (*p - '0');
            p++;
        }
        cmd.value = value;
    } else {
        cmd.value = 0;
    }

    buffer.push_back(cmd);
}

// 16.
void analyzePressure(const vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    int size = data.size();

    if (size == 0) {
        minVal = maxVal = avgVal = 0.0;
        return;
    }

    minVal = *p;
    maxVal = *p;
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        double val = *(p + i);
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
        sum += val;
    }

    avgVal = sum / size;
}

int main() {
    //1
    cout << "Task 1: " << myStrLen("Hello") << endl;

    //2
    char src[] = "Hello";
    char dest[20];
    myStrCopy(dest, src);
    cout << "Task 2: " << dest << endl;

    //3
    char str1[20] = "Hello ";
    char str2[] = "World";
    myStrCat(str1, str2);
    cout << "Task 3: " << str1 << endl;

    //4
    cout << "Task 4: " << countChar("Hello world", 'o') << endl;

    // 5
    char str5[] = "Hello world test";
    replaceSpaces(str5);
    cout << "Task 5: " << str5 << endl;

    //6
    char str6[] = "Hello";
    reverse(str6);
    cout << "Task 6: " << str6 << endl;

    //7
    cout << "Task 7: " << boolalpha << isPalindrome("racecar") << endl;

    //8
    const char* result8 = findSubstring("Hello world", "world");
    cout << "Task 8: ";
    if (result8) cout << result8 << endl;
    else cout << "Not found" << endl;

    //9
    char str9[] = "H e l l o";
    removeSpaces(str9);
    cout << "Task 9: " << str9 << endl;

    //10
    cout << "Task 10: " << myStrCmp("Hello", "Hello") << endl;

    // Задача 11
    vector<int> vec11 = {1, 2, 3, 4, 5};
    cout << "Task 11: " << sumVector(vec11) << endl;

    //12
    vector<int> vec12 = {1, 2, 3};
    increaseByTen(vec12);
    cout << "Task 12: ";
    for (int num : vec12) cout << num << " ";
    cout << endl;

    // Задача 13
    cout << "Task 13:" << endl;
    parseTelemetry("TEMP:24.5;PRESS:101.3;HUM:55.2");

    //14
    vector<double> signal = {2.0, 3.0, 1.0, 4.0, 3.0};
    cout << "Task 14: " << computeRMS(signal) << endl;

    // Задача 15
    vector<Command> buffer;
    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);
    cout << "Task 15:" << endl;
    for (const auto& cmd : buffer) {
        cout << "Command: " << cmd.name << ", Value: " << cmd.value << endl;
    }

    //16
    vector<double> pressure = {101.3, 100.8, 101.9, 100.5, 102.0};
    double minVal, maxVal, avgVal;
    analyzePressure(pressure, minVal, maxVal, avgVal);
    cout << "Task 16:" << endl;
    cout << "Min pressure: " << minVal << endl;
    cout << "Max pressure: " << maxVal << endl;
    cout << "Average pressure: " << avgVal << endl;

    return 0;
}
