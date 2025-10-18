//============================================================================
// Name        : дз6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
/*к 10 задаче
		void reverseWord(char* start, char* end) {
	    while (start < end) {
	        char temp = *start;
	        *start = *end;
	        *end = temp;
	        start++;
	        end--;
	    }
	}*/
bool allUnique(char* substr, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (substr[i] == substr[j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
	/* 1 задача
	char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    int left = 0;
    int right = strlen(str) - 1;
    bool isPalindrome = true;

    while (left < right) {
        while (left < right && isspace(str[left])) left++;
        while (left < right && isspace(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right])) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        cout << "Палиндром" << endl;
    } else {
        cout << "Не палиндром" << endl;
    }*/
	/* 2 задача
	char str[100];
	    cout << "Введите строку: ";
	    cin.getline(str, 100);

	    int count = 0;
	    int len = strlen(str);

	    for (int i = 0; i < len; i++) {
	        bool found = false;
	        for (int j = 0; j < i; j++) {
	            if (str[j] == str[i]) {
	                found = true;
	                break;
	            }
	        }
	        if (!found) {
	            count++;
	        }
	    }

	    cout << count << " (символы: ";
	    for (int i = 0; i < len; i++) {
	        bool printed = false;
	        for (int j = 0; j < i; j++) {
	            if (str[j] == str[i]) {
	                printed = true;
	                break;
	            }
	        }
	        if (!printed) {
	            cout << str[i] << " ";
	        }
	    }
	    cout << ")" << endl;*/
	/* 3 задача
	char str[100];
	    cout << "Введите строку: ";
	    cin.getline(str, 100);

	    int writeIndex = 0;
	    int len = strlen(str);

	    for (int readIndex = 0; readIndex < len; readIndex++) {
	        if (!isdigit(str[readIndex])) {
	            str[writeIndex] = str[readIndex];
	            writeIndex++;
	        }
	    }
	    str[writeIndex] = '\0';

	    cout << str << endl;*/
	/* 4 задача
	char A[100], B[100];
	    cout << "Введите строку A: ";
	    cin.getline(A, 100);
	    cout << "Введите строку B: ";
	    cin.getline(B, 100);

	    bool allFound = true;
	    int lenB = strlen(B);

	    for (int i = 0; i < lenB; i++) {
	        bool found = false;
	        int lenA = strlen(A);

	        for (int j = 0; j < lenA; j++) {
	            if (B[i] == A[j]) {
	                found = true;
	                break;
	            }
	        }

	        if (!found) {
	            allFound = false;
	            break;
	        }
	    }

	    if (allFound) {
	        cout << "Да" << endl;
	    } else {
	        cout << "Нет" << endl;
	    }*/
	/* 5 задача
	char str[100];
	    cout << "Введите строку: ";
	    cin.getline(str, 100);

	    int vowels = 0, consonants = 0;
	    int len = strlen(str);

	    for (int i = 0; i < len; i++) {
	        char ch = tolower(str[i]);

	        if (ch >= 'a' && ch <= 'z') {
	            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
	                vowels++;
	            } else {
	                consonants++;
	            }
	        }
	    }

	    cout << "Гласных: " << vowels << endl;
	    cout << "Согласных: " << consonants << endl;*/
	/* 6 задача
	char text[100];
	    int shift;

	    cout << "Текст: ";
	    cin.getline(text, 100);
	    cout << "Сдвиг: ";
	    cin >> shift;

	    int len = strlen(text);

	    for (int i = 0; i < len; i++) {
	        if (isupper(text[i])) {
	            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
	            if (text[i] < 'A') text[i] += 26;
	        } else if (islower(text[i])) {
	            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
	            if (text[i] < 'a') text[i] += 26;
	        }
	    }

	    cout << text << endl;*/
	/* 7 задача
	char str[100];
	    cout << "Введите строку: ";
	    cin.getline(str, 100);

	    int len = strlen(str);
	    int count = 1;

	    for (int i = 0; i < len; i++) {
	        if (i < len - 1 && str[i] == str[i + 1]) {
	            count++;
	        } else {
	            cout << str[i] << count;
	            count = 1;
	        }
	    }*/
	/* 8 задача
	char text[100];
	    cout << "Введите текст: ";
	    cin.getline(text, 100);

	    int len = strlen(text);
	    bool newSentence = true;

	    for (int i = 0; i < len; i++) {
	        if (newSentence && isalpha(text[i])) {
	            text[i] = toupper(text[i]);
	            newSentence = false;
	        } else if (isalpha(text[i])) {
	            text[i] = tolower(text[i]);
	        }

	        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
	            newSentence = true;
	        }
	    }

	    cout << text << endl;*/

	/* 9 задачи
	char str1[100], str2[100];
	    cout << "Введите первую строку: ";
	    cin.getline(str1, 100);
	    cout << "Введите вторую строку: ";
	    cin.getline(str2, 100);

	    int len1 = strlen(str1);
	    int len2 = strlen(str2);

	    int maxLen = 0;
	    int endPos = 0;

	    for (int i = 0; i < len1; i++) {
	        for (int j = 0; j < len2; j++) {
	            int k = 0;
	            while (i + k < len1 && j + k < len2 && str1[i + k] == str2[j + k]) {
	                k++;
	            }
	            if (k > maxLen) {
	                maxLen = k;
	                endPos = i + k;
	            }
	        }
	    }

	    cout << "Наибольшая общая подстрока: \"";
	    for (int i = endPos - maxLen; i < endPos; i++) {
	        cout << str1[i];
	    }
	    cout << "\"" << endl;*/

	    /* 10 задача
		char text[100];
	    cout << "Введите предложение: ";
	    cin.getline(text, 100);

	    int len = strlen(text);
	    char* start = text;

	    for (int i = 0; i <= len; i++) {
	        if (text[i] == ' ' || text[i] == '\0') {
	            reverseWord(start, text + i - 1);
	            start = text + i + 1;
	        }
	    }

	    cout << text << endl;*/
	char str[100];
	    int k;

	    cout << "Строка: ";
	    cin.getline(str, 100);
	    cout << "k = ";
	    cin >> k;

	    int len = strlen(str);

	    for (int i = 0; i <= len - k; i++) {
	        if (allUnique(str + i, k)) {
	            for (int j = i; j < i + k; j++) {
	                cout << str[j];
	            }
	            cout << endl;
	        }
	    }

	return 0;
}
