//============================================================================
// Name        : указатели2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 1. Обмен указателей на переменные
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

void swapPointers(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Динамическое создание двумерного массива
int **create2DArray(int n, int m) {
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    return arr;
}

void fill2DArray(int **arr, int n, int m) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = value % 100;
            value++;
        }
    }
}

void print2DArray(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// 3. Освобождение памяти двумерного массива
void free2DArray(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// 4. Транспонирование матрицы
int **transposeMatrix(int **matrix, int n, int m) {
    int **result = create2DArray(m, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// 5. Сортировка строк по сумме
int rowSum(int *row, int m) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
        sum += *(row + j);
    }
    return sum;
}

void sortRowsBySum(int **arr, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rowSum(arr[j], m) > rowSum(arr[j + 1], m)) {
                int *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 6. Сумма всех элементов матрицы через указатели
int sumElements(int **arr, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += *(*(arr + i) + j);
        }
    }
    return sum;
}

// 7. Массив строк и сортировка указателей
void sortWords(char **words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// 8. Динамическое управление сеточной структурой данных
double **allocatePlate(int n, int m) {
    double **plate = new double*[n];
    for (int i = 0; i < n; i++) {
        plate[i] = new double[m];
        for (int j = 0; j < m; j++) {
            plate[i][j] = 20.0;
        }
    }
    plate[n/2][m/2] = 100.0;
    return plate;
}

void freePlate(double **plate, int n) {
    for (int i = 0; i < n; i++) {
        delete[] plate[i];
    }
    delete[] plate;
}

void updateTemperature(double **plate, int n, int m) {
    double **newPlate = new double*[n];
    for (int i = 0; i < n; i++) {
        newPlate[i] = new double[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n/2 && j == m/2) {
                newPlate[i][j] = 100.0;
                continue;
            }

            double sum = 0.0;
            int count = 0;

            if (i > 0) { sum += plate[i-1][j]; count++; }
            if (i < n-1) { sum += plate[i+1][j]; count++; }
            if (j > 0) { sum += plate[i][j-1]; count++; }
            if (j < m-1) { sum += plate[i][j+1]; count++; }

            newPlate[i][j] = (count > 0) ? sum / count : plate[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            plate[i][j] = newPlate[i][j];
        }
    }

    freePlate(newPlate, n);
}

// 9. Создание и управление нагрузкой узлов
int **createLoadMatrix(int n, int t) {
    int **load = new int*[n];
    for (int i = 0; i < n; i++) {
        load[i] = new int[t];
    }
    return load;
}

// Этап 1. Анализ баланса нагрузки
double *averageLoadPerNode(int **load, int n, int t) {
    double *avg = new double[n];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < t; j++) {
            sum += *(*(load + i) + j);
        }
        avg[i] = (double)sum / t;
    }
    return avg;
}

// Этап 2. Нормализация нагрузки
void normalizeLoad(int **load, int n, int t) {
    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n; i++) {
            if (load[i][j] > 80) {
                int overload = load[i][j] - 80;
                int perNode = overload / (n - 1);

                load[i][j] = 80;

                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        load[k][j] += perNode;
                        if (load[k][j] > 100) load[k][j] = 100;
                    }
                }
            }
        }
    }
}

// Этап 3. Определение критических интервалов
int findCriticalInterval(int **load, int n, int t) {
    int maxSum = 0;
    int criticalIdx = 0;

    for (int j = 0; j < t; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += *(*(load + i) + j);
        }
        if (sum > maxSum) {
            maxSum = sum;
            criticalIdx = j;
        }
    }
    return criticalIdx;
}

// Этап 4. Вывод матрицы
void printLoadMatrix(int **load, int n, int t) {
    cout << "Матрица нагрузок:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Узел " << i << ": ";
        for (int j = 0; j < t; j++) {
            cout << load[i][j] << " ";
        }
        cout << endl;
    }
}

// Этап 5. Освобождение памяти
void freeLoadMatrix(int **load, int n) {
    for (int i = 0; i < n; i++) {
        delete[] load[i];
    }
    delete[] load;
}

int main() {
    // Задача 1
    cout << "Задача 1: Обмен указателей" << endl;
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    cout << "До: p1=" << *p1 << " p2=" << *p2 << endl;
    swapPointers(&p1, &p2);
    cout << "После: p1=" << *p1 << " p2=" << *p2 << endl << endl;

    // Задача 2
    cout << "Задача 2: Двумерный массив 3x4" << endl;
    int **arr = create2DArray(3, 4);
    fill2DArray(arr, 3, 4);
    print2DArray(arr, 3, 4);
    cout << endl;

    // Задача 3 (освобождение в конце)

    // Задача 4
    cout << "Задача 4: Транспонирование" << endl;
    int **transposed = transposeMatrix(arr, 3, 4);
    print2DArray(transposed, 4, 3);
    cout << endl;

    // Задача 5
    cout << "Задача 5: Сортировка строк по сумме" << endl;
    sortRowsBySum(arr, 3, 4);
    print2DArray(arr, 3, 4);
    cout << endl;

    // Задача 6
    cout << "Задача 6: Сумма элементов = " << sumElements(arr, 3, 4) << endl << endl;

    // Задача 7
    cout << "Задача 7: Сортировка строк" << endl;
    char *words[] = {"orange", "apple", "banana", "grape", "pear"};
    sortWords(words, 5);
    for (int i = 0; i < 5; i++) {
        cout << words[i] << " ";
    }
    cout << endl << endl;

    // Задача 8
    cout << "Задача 8: Моделирование теплопередачи" << endl;
    double **plate = allocatePlate(5, 5);
    cout << "Итерация 0 (начальное состояние):" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << plate[i][j] << " ";
        }
        cout << endl;
    }

    for (int k = 0; k < 3; k++) {
        updateTemperature(plate, 5, 5);
    }

    cout << "После 3 итераций:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << plate[i][j] << " ";
        }
        cout << endl;
    }
    freePlate(plate, 5);
    cout << endl;

    // Задачи 9-16 (Распределение нагрузки)
    cout << "Задачи 9-16: Распределение нагрузки" << endl;

    int N = 3, T = 5;
    int **load = createLoadMatrix(N, T);

    int loadData[3][5] = {
        {40, 50, 70, 90, 100},
        {30, 40, 50, 60, 80},
        {20, 30, 30, 40, 50}
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            load[i][j] = loadData[i][j];
        }
    }

    printLoadMatrix(load, N, T);
    cout << endl;

    double *avgLoad = averageLoadPerNode(load, N, T);
    cout << "Средняя нагрузка по узлам:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Узел " << i << ": " << avgLoad[i] << "%" << endl;
    }
    cout << endl;

    normalizeLoad(load, N, T);
    cout << "После нормализации:" << endl;
    printLoadMatrix(load, N, T);
    cout << endl;

    int critical = findCriticalInterval(load, N, T);
    cout << "Критический интервал: " << critical << endl;

    delete[] avgLoad;
    freeLoadMatrix(load, N);

    // Освобождение памяти
    free2DArray(arr, 3);
    free2DArray(transposed, 4);

    return 0;
}
