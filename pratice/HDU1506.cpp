#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll a[MAXN], l[MAXN], r[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    while (1)
    {
        memset(a, 0, sizeof(a));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        ll n;
        cin >> n;
        if (n == 0)
            break;
        a[0] = -1, a[n + 1] = -1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        stack<ll> s;
        s.push(0);
        for (int i = 1; i <= n; i++)
        {
            while (a[s.top()] >= a[i])
                s.pop();
            l[i] = s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        s.push(n + 1);
        for (int i = n; i >= 1; i--)
        {
            while (a[s.top()] >= a[i])
                s.pop();
            r[i] = s.top();
            s.push(i);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, a[i] * (r[i] - l[i] - 1));
        cout << ans << endl;
    }
    return 0;
}