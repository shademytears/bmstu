//============================================================================
// Name        : дз1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/* 1 задача
	float a = 0;
	cout << "Введите число ";
	cin >> a;
	float b = a / 100;
	cout << "В метрах: " << b;*/

	/* 2 задача
	float a = 0;
	float b = 0;
	cout << "Введите длину: ";
	cin >> a;
	cout << "Введите ширину: ";
	cin >> b;
	cout << "Площадь прямоугольника равна: " << a * b;*/

	/* 3 задача
	float a = 0;
	cout << "Введите температуру: ";
	cin >> a;
	float b = (a * 9)/5 + 32;
	cout << "Температура в фарингейтах: " << b;*/

	/* 4 задача
	int a = 0;
	cout << "Введите число ";
	cin >> a;
	if(a % 2 == 0){
		cout << "Число четное";
	}
	else {
		cout << "Число нечетное";
	}*/

	/* 5 задача
	int a = 0;
		cout << "Введите число ";
		cin >> a;
		if(a % 15 == 0) {
			cout << "Число делалится на 5 и на 3 без остатка";
		}
		else if(a % 5 == 0){
			cout << "Число делится на 5 без остатка";
		}
		else if(a % 3 == 0) {
			cout << "Число делится на 3 без остатка";
		}
		else{
			cout << "Число не делится ни на 3 ни на 5";
		}*/

		/* 6 задача
		int a = 0;
		cout << "Введите свой возраст ";
		cin >> a;
		if(a == 0) {
			cout << "Возраст не может равняться 0";
		}
		else if(a < 0){
			cout << "Возраст не может быть меньше 0";
		}
		else if(a < 18){
			cout << "Меньше 18";
		}
		else if(a < 60) {
			cout << "От 18 до 60";
		}
		else{
			cout << "Старше 60";
			}*/

	/* 7 задача
	int n;
	    cout << "Введите число: ";
	    cin >> n;

	    cout << "Квадраты чисел от 1 до " << n << ":" << endl;
	    for(int i = 1; i <= n; i++) {
	        cout << i << "^2 = " << i * i << ";" << endl;
	    }*/

	/* 8 задача

	 char i;
	int numbers = 0;

	cout << "ваша строка" << endl;
	while (cin.get(i) && i != '\n') {
	        switch(i) {
	            case 'a': case 'e': case 'i': case 'o': case 'u':
	            case 'A': case 'E': case 'I': case 'O': case 'U':
	                numbers++;
	                break;
	        }
	    }

	    cout << "Количество гласных букв: " << numbers << endl; */

	/* 9 задача
	int n;
	cout << "число " << endl;
	cin >> n;
	int sum = 0;

	for(int i = 1; i <= n; i++){
		if (i % 2==0 || i % 5==0){
		sum +=i;
		}
	}
	cout << sum;

	*/

	/* 10 задача
	int n;

	    cout << "число: ";
	    cin >> n;

	    if (n > 0) {
	        cout << "положительное" << endl;
	    } else if (n < 0) {
	        cout << "отрицательное" << endl;
	    } else {
	        cout << "равно нулю" << endl;
	    }
	*/

	//11 задача
	cout << "ASCII символы: " << endl;
	    cout << "Код Символ" << endl;
	    for (int i = 32; i <= 126; i++) {
	        cout << i << " " << char(i) << endl;
	    }

	return 0;
}
