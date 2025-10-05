//============================================================================
// Name        : дзгеом.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {

/* 1 задача
	double n[3][2];

    cout << "координаты вершин:" << endl;


    for (int i = 0; i < 3; i++) {
        cout << "вершина " << i + 1;
        cin >> n[i][0] >> n[i][1];
    }
    cout << "вершины:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ": (" << n[i][0] << ", " << n[i][1] << ")" << endl;
    }
    double x1 = n[0][0], y1 = n[0][1];
    double x2 = n[1][0], y2 = n[1][1];
    double x3 = n[2][0], y3 = n[2][1];


    double area = 0.5 * abs(x1 * (y2 - y3) +x2 * (y3 - y1) + x3 * (y1 - y2));

    cout << "S= " << area << endl; */

	/* 2 задача
	double n[4][2];

	    for (int i = 0; i < 4; i++) {
	    	 cout << "вершина " << i + 1;
	    	 cin >> n[i][0] >> n[i][1];
	    }

	    double p = 0;
	    for (int i = 0; i < 4; i++) {
	        int next = (i + 1) % 4;
	        double dx = n[next][0] - n[i][0];
	        double dy = n[next][1] - n[i][1];
	        double side = sqrt(dx*dx + dy*dy);
	        p += side;
	    }

	    cout << "Периметр: " << p << endl; */

		/* 3 задача
		 double n[3][2];

	    for (int i = 0; i < 3; i++) {
	        cout << "вершина " << i + 1;
	        cin >> n[i][0] >> n[i][1];
	    }


	    double cx = (n[0][0] + n[1][0] + n[2][0]) / 3;
	    double cy = (n[0][1] + n[1][1] + n[2][1]) / 3;

	    cout << "Центр масс треугольника: ("
	         << cx << ", " << cy << ")" << endl;*/


	/* 4 задача
		double n[4][2];

	    for (int i = 0; i < 4; i++) {
	        cout << "вершина " << i + 1;
	        cin >> n[i][0] >> n[i][1];
	    }

	    double dx = n[2][0] - n[0][0];
	    double dy = n[2][1] - n[0][1];
	    double d = sqrt(dx * dx + dy * dy);

	    cout << "диагональ " << d << endl;*/

		/* 5 задача
		double n[3][2];
	    for (int i = 0; i < 3; i++) {
	        cout << "точка " << i + 1;
	        cin >> n[i][0] >> n[i][1];
	    }

	    double a = (n[1][0] - n[0][0]) * (n[2][1] - n[0][1]) - (n[1][1] - n[0][1]) * (n[2][0] - n[0][0]);

	    if (a == 0) {
	        cout << "лежат" << endl;
	    } else {
	        cout << "не лежат" << endl;
	    }
	    */


		/* 6 задача
		double n[4][2];

	    for (int i = 0; i < 4; i++) {
	        cout << "точка " << i + 1;
	        cin >> n[i][0] >> n[i][1];
	    }

	    // a = points[0], b = points[1] c = points[2], d = points[3]

	    double v1 = (n[2][0] - n[0][0]) * (n[1][1] - n[0][1]) -
	                (n[2][1] - n[0][1]) * (n[1][0] - n[0][0]);

	    double v2 = (n[3][0] - n[0][0]) * (n[1][1] - n[0][1]) -
	                (n[3][1] - n[0][1]) * (n[1][0] - n[0][0]);

	    double v3 = (n[0][0] - n[2][0]) * (n[3][1] - n[2][1]) -
	                (n[0][1] - n[2][1]) * (n[3][0] - n[2][0]);

	    double v4 = (n[1][0] - n[2][0]) * (n[3][1] - n[2][1]) -
	                (n[1][1] - n[2][1]) * (n[3][0] - n[2][0]);

	    if (v1 * v2 < 0 && v3 * v4 < 0) {
	        cout << "пересекаются" << endl;
	    } else {
	        cout << "не пересекаются" << endl;
	    }*/


	/* 7 задача
		int k;
	    cout << "количество вершин ";
	    cin >> k;

	    double n[k][2];

	    for (int i = 0; i < k; i++) {
	        cout << "вершина " << i + 1;
	        cin >> n[i][0] >> n[i][1];
	    }

	    double p[2];
	    cout << "координаты точки: ";
	    cin >> p[0] >> p[1];

	    int c = 0;
	    for (int i = 0; i < k; i++) {
	        int j = (i + 1) % k;

	        if ((n[i][1] > p[1]) != (n[j][1] > p[1])) {

	            double x = (n[j][0] - n[i][0]) * (p[1] - n[i][1]) / (n[j][1] - n[i][1]) + n[i][0];

	            if (p[0] < x) {
	                c++;
	            }
	        }
	    }

	    if (c % 2 == 1) {
	        cout << "внутри" << endl;
	    } else {
	        cout << "снаружи" << endl;
	    }*/

		double n[2][2];

		for (int i =0; i < 2; i++){
			cout << "точка" << i + 1;
			cin >> n[i][0] >> n[i][1];
		}

		double dx = n[1][0] - n[0][0];
		double dy = n[1][1] - n[0][1];
		int l = sqrt(dx*dx + dy*dy);
		cout << "длина" << l;

    return 0;
}
