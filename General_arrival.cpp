#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // Find maximum and minimum values
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    int maxPos, minPos;

    // Find leftmost maximum
    for(int i = 0; i < n; i++)
    {
        if(a[i] == mx)
        {
            maxPos = i;
            break;
        }
    }

    // Find rightmost minimum
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == mn)
        {
            minPos = i;
            break;
        }
    }

    // Calculate minimum time
    int ans = maxPos + (n - 1 - minPos);

    // Fix overlap
    if(maxPos > minPos)
        ans--;

    cout << ans;

    return 0;
}
