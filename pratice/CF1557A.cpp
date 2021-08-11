#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        ll sum = 0, mx = -0x3f3f3f3f;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            ll in = 0;
            cin >> in;
            mx = max(mx, in);
            sum += in;
        }
        sum -= mx;
        printf("%.9f\n", mx + (1.0 * sum) / (n - 1));
    }
}