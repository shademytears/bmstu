//============================================================================
// Name        : дзматрицы.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	/* 1 задача
	int n;
    cin >> n;
    int A[100][100];
    int B1[100][100], B2[100][100], B3[100][100], B4[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B1[i][j] = A[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B2[i][j] = A[n - 1 - j][n - 1 - i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B3[i][j] = A[i][n - 1 - j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B4[i][j] = A[n - 1 - i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B3[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B4[i][j] << " ";
        }
        cout << endl;
    }

    bool found = false;

    bool same;

    same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B1[i][j] != B2[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "1 2" << endl;
        found = true;
    }

    same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B1[i][j] != B3[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "1 3" << endl;
        found = true;
    }

    same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B1[i][j] != B4[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "1 4" << endl;
        found = true;
    }

    same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B2[i][j] != B3[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "2 3" << endl;
        found = true;
    }

    // B2 и B4
    same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B2[i][j] != B4[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "2 4" << endl;
        found = true;
    }

    same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B3[i][j] != B4[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "3 4" << endl;
        found = true;
    }

    if (!found) {
        cout << "none" << endl;
    }*/

    /* 2 задача
	int n;
    cin >> n;

    int m[50][50];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int t = 0;
    for (int j = 0; j < n; j++) {
        t += m[0][j];
    }

    for (int i = 1; i < n; i++) {
        int rw = 0;
        for (int j = 0; j < n; j++) {
            rw += m[i][j];
        }
        if (rw != t) {
            cout << "no" << endl;
            return 0;
        }
    }

    for (int j = 0; j < n; j++) {
        int cl = 0;
        for (int i = 0; i < n; i++) {
            cl += m[i][j];
        }
        if (cl != t) {
            cout << "no" << endl;
            return 0;
        }
    }

    int md = 0;
    for (int i = 0; i < n; i++) {
        md += m[i][i];
    }
    if (md != t) {
        cout << "no" << endl;
        return 0;
    }

    int pd = 0;
    for (int i = 0; i < n; i++) {
        pd += m[i][n - 1 - i];
    }
    if (pd != t) {
        cout << "no" << endl;
        return 0;
    }

    cout << "yes " << t << endl; */

	/* 3 задача

	int n, m;
	    cin >> n >> m;
	    int matrix[100][100];
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            cin >> matrix[i][j];
	        }
	    }
	    int rmin[100];
	    int rmax[100];
	    int cmin[100];
	    int cmax[100];
	    for (int i = 0; i < n; i++) {
	        rmin[i] = INT_MAX;
	        rmax[i] = INT_MIN;
	    }

	    for (int j = 0; j < m; j++) {
	        cmin[j] = INT_MAX;
	        cmax[j] = INT_MIN;
	    }
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            int value = matrix[i][j];
	            if (value < rmin[i]) {
	                rmin[i] = value;
	            }
	            if (value > rmax[i]) {
	                rmax[i] = value;
	            }
	            if (value < cmin[j]) {
	                cmin[j] = value;
	            }
	            if (value > cmax[j]) {
	                cmax[j] = value;
	            }
	        }
	    }

	    bool f = false;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            int value = matrix[i][j];


	            if (value == rmin[i] && value == cmax[j]) {
	                cout << "A " << value << " " << i + 1 << " " << j + 1 << endl;
	                f = true;
	            }


	            if (value == rmax[i] && value == cmin[j]) {
	                cout << "B " << value << " " << i + 1 << " " << j + 1 << endl;
	                f = true;
	            }
	        }
	    }


	    if (!f) {
	        cout << "none" << endl;
	    } */

		/* 4 задача
		int n;
	    cin >> n;

	    int matrix[100][100] = {0};

	    int top = 0, bottom = n - 1;
	    int left = 0, right = n - 1;

	    int number = 1;

	    while (number <= n * n) {
	        for (int j = left; j <= right && number <= n * n; j++) {
	            matrix[top][j] = number++;
	        }
	        top++;

	        for (int i = top; i <= bottom && number <= n * n; i++) {
	            matrix[i][right] = number++;
	        }
	        right--;

	        for (int j = right; j >= left && number <= n * n; j--) {
	            matrix[bottom][j] = number++;
	        }
	        bottom--;

	        for (int i = bottom; i >= top && number <= n * n; i--) {
	            matrix[i][left] = number++;
	        }
	        left++;
	    }

	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cout << matrix[i][j] << " ";
	        }
	        cout << endl;
	    }*/

		/* 6 задача
		int n, m;
	    cin >> n >> m;

	    int matrix[100][100];
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            cin >> matrix[i][j];
	        }
	    }
	    int top = 0, bottom = n - 1;
	    int left = 0, right = m - 1;
	    while (top <= bottom && left <= right) {
	        for (int j = left; j <= right; j++) {
	            cout << matrix[top][j] << " ";
	        }
	        top++;
	        for (int i = top; i <= bottom; i++) {
	            cout << matrix[i][right] << " ";
	        }
	        right--;
	        if (top <= bottom) {
	            for (int j = right; j >= left; j--) {
	                cout << matrix[bottom][j] << " ";
	            }
	            bottom--;
	        }
	        if (left <= right) {
	            for (int i = bottom; i >= top; i--) {
	                cout << matrix[i][left] << " ";
	            }
	            left++;
	        }
	    }*/
    return 0;
}
