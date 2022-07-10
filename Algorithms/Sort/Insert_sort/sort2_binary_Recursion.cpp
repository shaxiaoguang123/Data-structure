#include <iostream>
using namespace std;

int Binary_Search(int A[], int index, int p, int r);  
void Insert_Sort(int A[], int p, int r);              
int main() {
    int A[5];
    cout << "请输入5个数字: ";
    int i;
    for (i = 0; i < 5; i++)
        cin >> A[i];
    Insert_Sort(A, 0, 4);
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    system("pause");
    return 0;
}

int Binary_Search(int A[], int index, int p, int r) {
    int q = (p + r) / 2;
    if (p > r)
        return p;
    if (A[q] >= index)                             
        return Binary_Search(A, index, p, q - 1);  
    else
        return Binary_Search(A, index, q + 1, r);  
}

void Insert_Sort(int A[], int p, int r) {
    int Alength = r - p + 1;
    int i, j, k, key;
    for (j = 1; j < Alength; j++) {
        i = j - 1;
        key = A[j];
        k = Binary_Search(A, key, 0, i);  
        for (i = j - 1; i >= k; i--)
            A[i + 1] = A[i];
        A[k] = key;
    }
}