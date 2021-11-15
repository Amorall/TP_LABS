#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int count = 0, count2 = 0, num_A = 0, num_LJ = 0, num_LI = 0, N;

    cout << "Введите размерность матрицы:"; //ввод количества строк
    cin >> N;
    int** a = new int* [N];                  // создаем 
    for (int i = 0; i < N; i++) {          // двумерный
        a[i] = new int[N];              // массив 
    };
 

        cout << "Введите данные матрицы \n" << endl;
        //цикл в которой перебираем строки матрицы
        for (int i = 0; i < N; i++) {
            //цикл в котором перебираем элементы внутри строки
            for (int j = 0; j < N; j++) {
                cin >> a[i][j];
            };
        };
        cout << "Матрица сгенерирована \n";
        for (int i = 0; i < N; i++)
        {
            // в котором перебираем строки матрицы
            for (int j = 0; j < N; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        };
        int* arr_A = new int[num_A];
        cout << "Массив значений A" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                if (a[i][j] != 0) {
                    arr_A[num_A] = a[i][j];
                    cout << arr_A[num_A] << "\t";
                    num_A += 1; 
                };
        };

        cout << endl;
        int* arr_LJ = new int[num_LJ];
        cout << "Массив значений LJ" << endl;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                if (a[i][j] != 0) {
                    arr_LJ[num_LJ] = j + 1;
                    cout << arr_LJ[num_LJ] << "\t";
                    num_LJ += 1; 
                };
        };

        cout << endl;


        int* arr_LI = new int[num_LI];
        cout << "Массив значений LI" << endl;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a[i][j] == 0) {
                    count += 1;
                    if (count == N) {
                        count = 0;
                        count2 += 1;
                    }
                } else {
                    for (int k = 0; k < num_A - 1; k++) {
                        if (a[i][j] == arr_A[k]) {
                            if (count2 == 0) {
                                arr_LI[num_LI] = k + 1;
                                cout << arr_LI[num_LI] << "\t";
                                num_LI += 1;
                                count = 0;
                            } else {
                                for (int f = 0; f <= count2; f++) {
                                    arr_LI[num_LI] = k + 1;
                                    cout << arr_LI[num_LI] << "\t";
                                    num_LI += 1;
                                }
                                count = 0;
                                count2 = 0;
                                num_LI += 1; 
                            };
                        };
                    };
                    break;
                };
            };
        };
        arr_LI[num_LI] = num_A + 1;
        cout << arr_LI[num_LI] << endl;
        for (int i = 0; i < N; i++) {
            delete[] a[i];
        }
            delete[] a;
            //delete[] arr_LI;
            //delete[] arr_A;
            //delete[] arr_LJ;   
            system("pause");
            return 0;
    };
