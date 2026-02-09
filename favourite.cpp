#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;

    while (l <= r) {
        if (l == r) {
            cout << arr[l] << " ";
        } else {
            cout << arr[l] << " " << arr[r] << " ";
        }
        l++;
        r--;
    }

    return 0;
}
