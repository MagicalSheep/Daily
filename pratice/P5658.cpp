#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 10;

int n, fa[MAXN];
ll f[MAXN], sum[MAXN];
char s[MAXN];
stack<int> sta;
vector<int> edge[MAXN];

void dfs(int u)
{
    int tmp = 0;

    if (s[u] == '(')
        sta.emplace(u);
    else if (!sta.empty())
        f[u] = f[fa[tmp = sta.top()]] + 1, sta.pop();

    sum[u] = sum[fa[u]] + f[u];
    for (auto x : edge[u])
        dfs(x);

    if (tmp)
        sta.emplace(tmp);
    else if (sta.size())
        sta.pop();
}

int main()
{
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i < n; i++)
    {
        int in = 0;
        scanf("%d", &in);
        edge[in].emplace_back(i + 1);
        fa[i + 1] = in;
    }
    dfs(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans ^= (i * sum[i]);
    printf("%lld\n", ans);
    return 0;
}