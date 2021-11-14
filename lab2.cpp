#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int i = 0, j = 0, N, num_A = 0, num_LJ = 0, num_LI = 0;

    cout << "Введите размерность матрицы:"; //ввод количества строк
    cin >> N;
    int** a = new int* [N];                  // создаем 
    for (int i = 0; i < N; i++) {          // двумерный
        a[i] = new int[N];              // массив 
    }
 

        cout << "Введите данные матрицы \n" << endl;
        //цикл в которой перебираем строки матрицы
        for (i = 0; i < N; i++) {
            //цикл в котором перебираем элементы внутри строки
            for (j = 0; j < N; j++) {
                cin >> a[i][j];
            }
        }
        cout << "Матрица сгенерирована \n";
        for (i = 0; i < N; i++)
        {
            // в котором перебираем строки матрицы
            for (j = 0; j < N; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        }
        int* arr_A = new int[num_A];
        cout << "Массив значений A" << endl;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                if (a[i][j] != 0) {
                    arr_A[num_A] = a[i][j];
                    cout << arr_A[num_A] << "\t";
                    num_A += 1;
                }
        }

        cout << endl;
        int* arr_LJ = new int[num_LJ];
        cout << "Массив значений LJ" << endl;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                if (a[i][j] != 0) {
                    arr_LJ[num_LJ] = j;
                    cout << arr_LJ[num_LJ] << "\t";
                    num_LJ += 1;
                }
        }

        cout << endl;
        int* arr_LI = new int[num_LI];
        cout << "Массив значений LI" << endl;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++) 
                if (a[i][j] != 0) {
                    for (int* ptr = arr_A; ptr <= &arr_A[num_A-1]; ptr++) {
                        if (a[i][j] == *ptr) {
                            arr_LI[num_LI] = ptr - arr_A + 1;
                            cout << arr_LI[num_LI] << "\t";
                            arr_A[ptr - arr_A] = 0;
                            num_LI += 1;
                            i += 1;
                            break;
                        }
                    }
            }
        }
            delete[] a;// удаляем массив
            //delete[] arrA;
    }
