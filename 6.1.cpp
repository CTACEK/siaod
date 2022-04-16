//
// Created by CTACEK on 4/16/2022.
//

#include <cmath>
#include <iostream>

using namespace std;

double f(int n, int a) {

    if (n == 1) return sqrt(a);

    return sqrt(a + f(n - 1, a));

}

int main() {
    cout << "n = 5\na = 2\n";
    cout << "f(5, 2) = " << f(5, 2) << endl;
    return 0;
}

