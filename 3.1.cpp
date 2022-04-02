#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int arrcreate(char **arr, char *str, char *s) {
    int i = 0;
    while (arr[i] != NULL) // ������ �� ������
    {
//        puts(arr[i]); // ����� �����
        arr[++i] = strtok(NULL, s); // ������ ����� � ��������� ������
    }
    return i; // ����������� ���������� ���������� � �������
}


void checkingallarray(char **arr, int k) {
    for (int i = 0; i < k; i++) { // ������ �� ��������� �������
        for (int j = 0; j < k; j++) {

            char temp1[strlen(arr[i])];
            strcpy(temp1, arr[i]);
            char temp2[strlen(arr[j])];
            strcpy(temp2, arr[j]);


            sort(temp1, temp1 + strlen(temp1) * sizeof(char));
            sort(temp2, temp2 + strlen(temp2) * sizeof(char));


            if (strcmp(temp1, temp2) == 0 && i != j) {
                printf("% s ", arr[i]);
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "rus");;
    char str[100] = "";
    char *arr[100];
    char s[] = " ";
    int k = 0;

    cin.clear();
    gets(str);

    arr[0] = strtok(str, s); // ������������� ������� ���� � ������������ - ��������
    k = arrcreate(arr, str, s);

    checkingallarray(arr, k);

    return 0;
}

