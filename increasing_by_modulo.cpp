#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ops = 0;        // number of operations used
    long long prev = a[0];   // previous value after ops

    for (int i = 1; i < n; i++) {
        long long cur = (a[i] + ops) % m;

        if (cur < prev) {
            // need to increase ops so that cur >= prev
            long long need = prev - cur;
            ops += need;
            cur = (cur + need) % m;
        }

        prev = cur;
    }

    cout << ops << "\n";
    return 0;
}
