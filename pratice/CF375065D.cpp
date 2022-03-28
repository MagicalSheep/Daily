#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
set<map<int, int>> gr;

void dfs(int x, int sum, map<int, int> &g)
{
    sum += x;
    ++g[x];
    if (sum == n)
    {
        gr.insert(g);
        sum -= x;
        --g[x];
        if (g[x] == 0)
            g.erase(x);
        return;
    }
    for (int i = x; i <= 15; i++)
    {
        if (sum + x > n)
            break;
        dfs(i, sum, g);
    }
    sum -= x;
    --g[x];
    if (g[x] == 0)
        g.erase(x);
}

ll cc(int x, int y)
{
    ll b = 1, a = 1;
    for (ll i = y - x + 1; i <= y; i++)
        b *= i;
    for (ll i = x; i >= 1; i--)
        a *= i;
    return b / a;
}

void solve()
{
    ll ans = 0;
    for (auto g : gr)
    {
        ll tmp = 1;
        for (auto x : g)
            tmp *= cc(k - 1, k + x.second - 1);
        ans += tmp;
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%d%d", &n, &k);
    int sum = 0;
    map<int, int> g;
    for (int i = 1; i <= n; i++)
        dfs(i, sum, g);
    solve();
    return 0;
}