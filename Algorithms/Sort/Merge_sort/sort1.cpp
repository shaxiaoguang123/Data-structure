#include <iostream>
using namespace std;


void Merge(int A[], int p, int q, int r) {  
    int n1 = q - p + 1;                     
    int n2 = r - q;
    int* L = new int[n1];  
    int* R = new int[n2];
    int i, j, k;              
    for (i = 0; i < n1; i++)  
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[p + k] = L[i];
            i++;
        } else {
            A[p + k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        A[p + k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[p + k] = R[j];
        j++;
        k++;
    }
}


void Merge_Sort(int A[], int p, int r) {
    int q = (p + r) / 2;
    if (p >= r)
        return;  
    Merge_Sort(A, p, q);
    Merge_Sort(A, q + 1, r);
    Merge(A, p, q, r);
}

int main() {
    int A[5];
    int i;
    cout << "请输入5个数字: ";
    for (i = 0; i < 5; i++)
        cin >> A[i];
    Merge_Sort(A, 0, 4);
    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    system("pause");
}