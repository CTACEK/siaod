#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> inputmass(int n, int M, int N) {
    int y, x;
    vector<vector<int>> v(N, vector<int>(M, 0));
    for (int i = 0; i < n; i++) // заполнение поля точек
    {
        cout << "Введите координаты " << i + 1 << " точки\n ";
        cout << "Координата по х:";
        cin >> x;
        cout << "Координата по y:";
        cin >> y;
        vector<int> temp;
        v[x][y] = 1; // призваивание еденицы значению переменной на координате
    }
    return v;
}

void outputmass(vector<vector<int>> x, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (x[i][j] == 0) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
}

vector<int> mcord(vector<vector<int>> x, int M, int N) {
    vector<int> y;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (x[i][j] == 1) { // если текущий элемент это точка на координате
                y.push_back(i); // добавляем координату m в новый одномерный вектор
            }
    return y; // возврат нового одномерного вектора
}

vector<int> ncord(vector<vector<int>> x, int M, int N) {
    vector<int> y;
    for (int i = 0; i < M; i++) // цикл, идущий по строкам
        for (int j = 0; j < N; j++)
            if (x[i][j] == 1) { // если текущий элемент это точка на координате
                y.push_back(j); // добавляем координату n в новый одномерный вектор
            }
    return y; // возврат нового одномерного вектора
}

bool cheking(vector<int> x, vector<int> y) {
    bool flag = 0;
    for (int i = 0; i < (x.size() - 1); i++) // проверка, лежат ли 2 точки на одной прямой
        for (int j = i + 1; j < x.size(); j++) {
            if (x[i] == x[j]) {
                flag = 1;
                break;
            }
            if (flag == 1)
                break;
        }
    for (int i = 0; i < (y.size() - 1); i++) { // проверка, лежат ли 2 точки на одной прямой
        for (int j = i + 1; j < y.size(); j++) {
            if (y[i] == y[j]) {
                flag = 1;
                break;
            }
            if (flag == 1)
                break;
        }
        return flag;
    }
}

float equation(vector<int> x) {
    float l = x.size() / 2.0;
    return (x[l - 1] + 1 + x[l] + 1) / 2.0; // вычисление медианы по заданной формуле
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int p_n, p_m;
    long n = 0;
    vector<vector<int>> vec;
    vector<int> vecm;
    vector<int> vecn;
    cout << "Введите количество точек в плоскости (кратное 2): ";
    cin >> n;
    if ((n <= 0 || n > 100) || (n%2==1)) // проверка ввода n
    {
        cout << "\nНеверный ввод n";
        return 1;
    }

    cout << "Введите размер поля(mxn), в пределах которого расположены точки\n";
    cout << "M = ";
    cin >> p_m;

    cout << "N = ";
    cin >> p_n;

    if (p_m <= 0 || p_m > 100 || p_n <= 0 || p_n > 100) // проверка ввода
    {
        cout << "\nНеверный ввод";
        return 1;
    }

    vec = inputmass(n, p_m, p_n);

    cout << "Вывод поля плоскости" << endl;
    outputmass(vec, p_m, p_n);

    vecm = mcord(vec, p_m, p_n);
    vecn = ncord(vec, p_m, p_n);

    if (cheking(vecn, vecm) == 0) {
        cout << "Вертикальная медиана имеет уравнение x = " << equation(vecm) << endl;
    } else {
        cout << "Какие-либо 2 точки лежат на одной горизонтальной или вертикальной прямой" << endl;
        cout << "Вертикальная медиана имеет уравнение x = " << equation(vecm) << endl;
    }

    return 0;
}