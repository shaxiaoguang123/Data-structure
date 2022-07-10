#include <iostream>
using namespace std;

void insert_sort(int arr[], int n) {
    int low, high, place, temp;
    for (int i = 1; i < n; ++i) {
        low = 0, high = i - 1;
        temp = arr[i];
        while (low <= high)  
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        place = low;
       
        for (int j = i - 1; j >= place; --j) {
            arr[j + 1] = arr[j];
        }
        arr[place] = temp;
    }
}

int main() {
    int arr[9] = {3, 5, 1, 2, 7, 9, 45, 14, 8};
    insert_sort(arr, 9);
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}