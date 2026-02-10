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

    long long ops = 0;
    long long prev = 0;

    for (int i = 0; i < n; i++) {
        long long cur = a[i];

        if (cur + ops < m) {
            // no wrap
            if (cur + ops < prev) {
                ops += prev - (cur + ops);
            } else {
                prev = cur + ops;
            }
        } else {
            // wrap possible
            long long wrapped = (cur + ops) % m;
            if (wrapped < prev) {
                // must increase ops to avoid wrap
                ops += prev - wrapped;
            } else {
                prev = wrapped;
            }
        }
    }

    cout << ops << "\n";
    return 0;
}
