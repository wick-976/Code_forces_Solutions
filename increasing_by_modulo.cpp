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

    auto can = [&](long long k) {
        long long prev = 0;

        for (int i = 0; i < n; i++) {
            long long x = a[i];

            // Case 1: no wrap
            if (x + k < m) {
                if (prev > x + k) return false;
                prev = max(prev, x);
            }
            // Case 2: wrap possible
            else {
                long long wrapped = (x + k) % m;
                if (prev <= wrapped) {
                    // choose wrapped part
                } else if (prev <= x + k) {
                    prev = max(prev, x);
                } else {
                    return false;
                }
            }
        }
        return true;
    };

    long long lo = 0, hi = m, ans = m;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
