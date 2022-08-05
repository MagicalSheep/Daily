#include <bits/stdc++.h>
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);
using PII = std::pair<int, int>;
using ll = long long;

ll solve()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1, u, v; i < n; ++i)
    {
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> siz(n + 1);
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        siz[u] = 1;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
    };
    dfs(1, 0);
    std::vector<ll> res(n + 1);
    std::function<void(int, int)> getAns = [&](int u, int fa)
    {
        ll mx = 0;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            getAns(v, u);
            if (res[v] > mx)
                mx = res[v];
        }
        res[u] = siz[u] + mx;
    };
    getAns(1, 0);
    return res[1];
}

int main()
{
    IOS;
    int t;
    std::cin >> t;
    while (t--)
        std::cout << solve() << '\n';
    return 0;
}