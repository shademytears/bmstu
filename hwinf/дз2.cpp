//============================================================================
// Name        : дз2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	/*1 задача
	 * int n = 0;
	    int c = 0;
	    cout << "количество чисел ";
	    cin >> n;
	    cout << "введите числa ";


	    for(int k = 1; k <= n; k++){
	    	int a;
	    	cin >> a;
	    	if (a > pow(2,k)){
	    		c = c + 1;
	    	}
	    }
	    cout << c;*/

		/*2 задача
		 * int mx = 0;
		int n;
		cin >> n;
		int c = 0;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			if (a[i] % 2 == 0){
				c++;
			}
			else{
				if (a[i] > mx){
					mx = a[i];
				}
			}
		}
		cout << mx << endl;
		cout << c;*/

		/*3 задача
		 * float a[15];
		for (int i = 0; i < 15; i++){
			cin >> a[i];
		}
		int min = 0;
		int max = 0;
		for (int i = 0; i < 15; i++){
			if (a[i] < a[min]) {
				min = i;
			}
			if (a[i] > a[max]) {
				max = i;
		}
		}
		swap(a[0],a[min]);
		swap(a[14],a[max]);

		for (int i =0; i < 15; i++){
			cout << a[i] << " ";
		}*/

		/* 4 задача
		double n[15];

	    cout << "числа:" << endl;
	    for (int i = 0; i < 15; i++) {
	        cin >> n[i];
	    }

	    double maxi = n[0], mini = n[0];
	    int maxp = 0, minp = 0;

	    for (int i = 1; i < 15; i++) {
	        if (n[i] > maxi) {
	            maxi = n[i];
	            maxp = i;
	        }
	        if (n[i] < mini) {
	            mini = n[i];
	            minp = i;
	        }
	    }

	    if (maxp < minp) {
	        cout << "Произведение: " << maxi * mini << endl;
	    } else {
	        cout << "максимальный элемент не предшествует минимальному" << endl;
	    }*/

		/* 5задача
		int n[10];

	    cout << "чисел:" << endl;
	    for (int i = 0; i < 10; i++) {
	        cin >> n[i];
	    }

	    int max = n[0], min = n[0];
	    int maxp = 0, minp = 0;

	    for (int i = 1; i < 10; i++) {
	        if (n[i] > max) {
	            max = n[i];
	            maxp = i;
	        }
	        if (n[i] < min) {
	            min = n[i];
	            minp = i;
	        }
	    }

	    if (minp == 4 && maxp == 9) {
	        double avg = (max + min) / 2.0;
	        cout << "среднее арифметическое: " << avg << endl;
	    } else {
	        cout << "условие не выполняется" << endl;
	    } */

		/* 6 задача
		double n[15];

	    cout << "Введите 15 чисел:" << endl;
	    for (int i = 0; i < 15; i++) {
	        cin >> n[i];
	    }

	    double max = n[0], min = n[0];
	    int maxp = 0, minp = 0;

	    for (int i = 1; i < 15; i++) {
	        if (n[i] > max) {
	            max = n[i];
	            maxp = i;
	        }
	        if (n[i] < min) {
	            min = n[i];
	            minp = i;
	        }
	    }

	    if (maxp == 0 && minp == 1) {
	        cout << "/2:" << endl;
	        for (int i = 0; i < 15; i++) {
	            n[i] /= 2;
	            cout << n[i] << " ";
	        }
	    } else {
	        cout << "не выполняется" << endl;
	    }*/

		/* 7 задача

		int n[15];

	    cout << "Введите 15 чисел:" << endl;
	    for (int i = 0; i < 15; i++) {
	        cin >> n[i];
	    }

	    cout << "Исходный массив: ";
	    for (int i = 0; i < 15; i++) {
	        cout << n[i] << " ";
	    }
	    cout << endl;

	    int max = n[0], min = n[0];
	    int minp = 0, maxp = 0;

	    for (int i = 1; i < 15; i++) {
	        if (n[i] > max) {
	            max = n[i];
	            maxp = i;
	        }
	        if (n[i] < min) {
	            min = n[i];
	            minp = i;
	        }
	    }

	    if (min == 0 || max == 0) {
	        cout << "Обнуляем элементы перед минимальным:" << endl;
	        for (int i = 0; i < minp; i++) {
	            n[i] = 0;
	        }

	        cout << "Результат: ";
	        for (int i = 0; i < 15; i++) {
	            cout << n[i] << " ";
	        }
	    } else {
	        cout << "Условие не выполняется" << endl;
	    }*/

		int n[10];

	    for (int i = 0; i < 10; i++) {
	        cin >> n[i];
	    }

	    int max = n[0], min = n[0];
	    int maxp = 0, minp = 0;

	    for (int i = 1; i < 10; i++) {
	        if (n[i] > max) {
	            max = n[i];
	            maxp = i;
	        }
	        if (n[i] < min) {
	            min = n[i];
	            minp = i;
	        }
	    }

	    if (maxp == 1 && minp == 4) {
	        for (int i = minp; i < 10; i++) {
	            n[i] = max;
	        }

	        for (int i = 0; i < 10; i++) {
	            cout << n[i] << " ";
	        }
	    }

return 0;

}
