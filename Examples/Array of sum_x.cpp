#include <Algorithm>
#include <iostream>
using namespace std;

int main(void) {
    int n;
    cout << "请输入数列的长度: ";
    cin >> n;
    int* s = new int[n];
    int i, j;
    cout << "\n请输入数列中的元素: ";
    for (i = 0; i < n; i++)
        cin >> s[i];
    int x;
    cout << "\n请输入要查找的和: ";
    cin >> x;
    sort(s, s + n);
    // for (i = 0; i < n; i++)
    //     cout << s[i] << " ";
    for (i = 0; i < n - 1; i++) {
        int low, high, mid;
        low = i + 1;
        high = n - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (s[mid] + s[i] == x)
                break;
            else if (s[mid] + s[i] > x)
                high = mid - 1;
            else if (s[mid] + s[i] < x)
                low = mid + 1;
        }
        if (low <= high) {
            cout << "\n存在两个数" << s[i] << "," << s[mid] << "其和为" << x
                 << endl;
            break;
        }
    }
    if (i == n - 1)
        cout << "\n不存在两个数其和为" << x << endl;
    system("pause");
}