//============================================================================
// Name        : lab2oaip.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

vector<char*> splitIntoWords(char* str) {
    vector<char*> words;
    char* word = strtok(str, " ");

    while (word != nullptr) {
        words.push_back(word);
        word = strtok(nullptr, " ");
    }

    return words;
}

int countWordsStartingWithA(vector<char*>& words) {
    int count = 0;
    for (char* word : words) {
        if (word[0] == 'a' || word[0] == 'A') {
            count++;
        }
    }
    return count;
}

int findShortestWordLength(vector<char*>& words) {
    int minLength = INT_MAX;

    for (char* word : words) {
        int length = strlen(word);
        if (length < minLength) {
            minLength = length;
        }
    }

    return minLength;
}

int countAInLastWord(vector<char*>& words) {
    if (words.empty()) return 0;

    char* lastWord = words.back();
    int count = 0;

    for (int i = 0; lastWord[i] != '\0'; i++) {
        if (lastWord[i] == 'a' || lastWord[i] == 'A') {
            count++;
        }
    }

    return count;
}


void convertToLowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}


int countWordsWithMatchingEnds(vector<char*>& words) {
    int count = 0;

    for (char* word : words) {
        int length = strlen(word);
        if (length > 0 && tolower(word[0]) == tolower(word[length - 1])) {
            count++;
        }
    }

    return count;
}


string findShortestCommonSubstring(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    string shortestSubstring = "";
    int minLength = INT_MAX;

    for (int i = 0; i < len1; i++) {
        for (int j = i; j < len1; j++) {
            int subLen = j - i + 1;
            if (subLen > minLength) continue;

   
            string substring;
            for (int k = i; k <= j; k++) {
                substring += word1[k];
            }


            bool found = false;
            for (int m = 0; m <= len2 - subLen; m++) {
                bool match = true;
                for (int n = 0; n < subLen; n++) {
                    if (tolower(substring[n]) != tolower(word2[m + n])) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    break;
                }
            }

            if (found && subLen < minLength) {
                minLength = subLen;
                shortestSubstring = substring;
            }
        }
    }

    return shortestSubstring;
}

int main() {
    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];

    cout << "Лабораторная работа №2: Работа со строками" << endl;
    cout << "===========================================" << endl;
    cout << "Введите строку из 10 слов на латинице: ";


    cin.getline(input, MAX_LENGTH);


    char* workingString = new char[strlen(input) + 1];
    strcpy(workingString, input);


    vector<char*> words = splitIntoWords(workingString);

    cout << "\nРезультаты анализа строки:" << endl;
    cout << "============================" << endl;

    int wordsWithA = countWordsStartingWithA(words);
    cout << "1. Количество слов, начинающихся с буквы 'a': " << wordsWithA << endl;


    int shortestLength = findShortestWordLength(words);
    cout << "2. Длина самого короткого слова: " << shortestLength << endl;


    int aInLastWord = countAInLastWord(words);
    cout << "3. Количество букв 'a' в последнем слове: " << aInLastWord << endl;


    char* lowercaseString = new char[strlen(input) + 1];
    strcpy(lowercaseString, input);
    convertToLowercase(lowercaseString);
    cout << "4. Строка в нижнем регистре: " << lowercaseString << endl;


    int matchingEnds = countWordsWithMatchingEnds(words);
    cout << "5. Количество слов с совпадающими первым и последним символами: "
         << matchingEnds << endl;

    if (words.size() >= 2) {
        string commonSubstring = findShortestCommonSubstring(words[0], words[1]);
        if (!commonSubstring.empty()) {
            cout << "6. Самая короткая общая подстрока между первым и вторым словом: '"
                 << commonSubstring << "'" << endl;
        } else {
            cout << "6. Общая подстрока между первым и вторым словом не найдена" << endl;
        }


        cout << "\nСлова в строке:" << endl;
        for (int i = 0; i < words.size(); i++) {
            cout << "Слово " << (i + 1) << ": " << words[i] << endl;
        }
    } else {
        cout << "6. Недостаточно слов для поиска общей подстроки" << endl;
    }


    delete[] workingString;
    delete[] lowercaseString;

    return 0;
}
