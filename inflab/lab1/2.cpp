//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
    int price = 10;

    cout << "Цена одной тарелки: " << price << " рублей" << endl;
    cout << endl;
    cout << "Количество         |          Стоимость" << endl;
    cout << "-------------------|-------------------" << endl;


    for (int i = 1; i <= 10; i++) {
        int cost = i * price;
        cout << i << " тарелок"<< "                    " << cost << " рублей" << endl;
    }

    return 0;
}
