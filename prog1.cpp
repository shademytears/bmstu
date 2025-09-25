//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int size = 10;
	int numbers [size];
	cout << "Введите 10 чисел" << endl;
	for ( int i = 0; i < size; i++) {
		cout << "Число " << (i + 1) << ": ";
		cin >> numbers[i];
	}
	cout << endl << "Элементы маcсива:";
	for (int i = 0; i < size; i++){
		cout << numbers[i] << " ";
	}

	cout << endl << "Сумма чисел массива: ";
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += numbers[i];
	}
	cout << sum << endl;

	int min = numbers[0];
	for (int i = 0; i < size; i++){
		if (numbers[i] < min){
			min = numbers[i];
		}
	}
	cout << "Минимальный элемент массива: " << min << endl;

	for (int k = size - 1; k > 0; k--){
			for(int i = 0; i < k; i++){
				if (numbers[i] > numbers[i+1]){
				int temp = numbers[i];
				numbers[i] = numbers[i+1];
				numbers[i+1] = temp;
				}
		}
	}
	cout << "Отсортированный массив в порядке возрастания: ";
	for (int i = 0; i < size; i++){
		cout << numbers[i] << " ";
	}
	cout << endl;






    return 0;
}
