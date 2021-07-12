#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll L, R, f[11 + 5][10][10][2][2][2][2], num[11 + 5];

ll dfs(ll p, ll last, ll llast, ll _4, ll _8, ll is_3, ll ok)
{
    if (~f[p][last][llast][_4][_8][is_3][ok])
        return f[p][last][llast][_4][_8][is_3][ok];
    if (_4 && _8)
        return 0;
    if (!p)
        return is_3;
    ll ret = 0, end = ok ? 9 : num[p];
    for (int i = 0; i <= end; i++)
        ret += dfs(p - 1, i, last, _4 || (i == 4), _8 || (i == 8), is_3 || (i == last && i == llast), ok || (i < end));
    return f[p][last][llast][_4][_8][is_3][ok] = ret;
}

ll solve(ll x)
{
    if (x < 1e10)
        return 0;
    memset(f, -1, sizeof(f));
    ll len = 0;
    for (; x; x /= 10)
        num[++len] = x % 10;
    ll ret = 0;
    for (int i = 1; i <= num[len]; i++)
        ret += dfs(10, i, -1, i == 4, i == 8, 0, i < num[len]);
    return ret;
}

int main()
{
    cin >> L >> R;
    cout << solve(R) - solve(L - 1) << endl;
    return 0;
}