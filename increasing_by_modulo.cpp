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

    long long ops = 0;          // minimum operations needed
    long long prev = 0;         // minimum possible previous value

    for (int i = 0; i < n; i++) {
        long long cur = a[i];

        if (cur + ops < m) {
            // no wrap possible
            if (cur + ops < prev) {
                ops += prev - (cur + ops);
            } else {
                prev = cur + ops;
            }
        } else {
            // wrap is possible
            long long wrapped = (cur + ops) % m;
            if (wrapped < prev) {
                // must increase ops to avoid bad wrap
                ops += prev - wrapped;
            } else {
                prev = wrapped;
            }
        }
    }

    cout << ops << "\n";
    return 0;
}
