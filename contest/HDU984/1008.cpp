#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e3 + 10;

int T;
ll n, m, len[MAXN][MAXN], a[MAXN][MAXN];

ll solve(int n)
{
    ll ans = 0, l[MAXN], r[MAXN];
    stack<int> s;
    a[n][0] = -1, a[n][m + 1] = -1;
    s.push(0);
    for (int i = 1; i <= m; i++)
    {
        while (len[n][s.top()] >= len[n][i])
            s.pop();
        l[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    s.push(m + 1);
    for (int i = m; i >= 1; i--)
    {
        while (len[n][s.top()] >= len[n][i])
            s.pop();
        r[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= m; i++)
        ans = max(ans, len[n][i] * (r[i] - l[i] - 1));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        memset(len, 0, sizeof(len));
        memset(a, 0, sizeof(a));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= m; i++)
            len[n][i] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n - 1; j >= 1; j--)
                len[j][i] = (a[j][i] > a[j + 1][i]) ? 1 : len[j + 1][i] + 1;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, solve(i));
        cout << ans << endl;
    }
    return 0;
}