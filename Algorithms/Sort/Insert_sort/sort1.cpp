#include <iostream>
using namespace std;

void Insert_Sort(int A[], int n) {
    int i, j, key;
    int Alength = n;
    for (j = 1; j < Alength; j++) {
        key = A[j];  
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];  
            i--;
        }
        A[i + 1] = key;  
    }
}
int main() {
    int i;
    int A[5];
    cout << "请输入5个数字: ";
    for (i = 0; i < 5; i++)
        cin >> A[i];
    Insert_Sort(A, 5);
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    system("pause");
    return 0;
}