#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    char s[4] = "abb";
    sort(s, s + 3);
    do {
        cout << s << endl;
    } while(next_permutation(s, s + 3));
}