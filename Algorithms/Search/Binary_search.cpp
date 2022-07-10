#include <iostream>
using namespace std;

int Binary_Search(int A[], int index, int p, int r) {  
    int q = (p + r) / 2;
    if (p > r)  
        return -1;
    if (A[q] == index)
        return q;
    else if (A[q] > index)  
        return Binary_Search(A, index, p, q - 1);
    else
        return Binary_Search(A, index, q + 1, r);
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    cout << Binary_Search(A, 1, 0, 4) << endl;
    system("pause");
}