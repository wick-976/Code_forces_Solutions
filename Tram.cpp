#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;   // number of stops

    int total = 0, leave = 0, enter = 0, ans = 0;

    for (int i = 0; i < t; i++) {
        cin >> leave >> enter;
        total -= leave;
        total += enter;
        ans = max(ans, total);
    }

    cout << ans;
    return 0;
}

// Explanation:
// T(O)-> O(N)
// S(O)-> O(1)  
//approach: Maintain current passenger, update max passengers at each stop.
//pattern: Running sum + maximum prefix. 