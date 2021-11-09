#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int N, ceng, cnt[MAXN], vis[MAXN];
vector<int> G[MAXN];

void dfs(int u, int c)
{
    if (vis[u])
        return;
    vis[u] = 1;
    cnt[c]++;
    ceng = max(ceng, c);
    for (auto v : G[u])
        dfs(v, c + 1);
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(1, 1);
    if (ceng > 3 || (ceng == 3 && cnt[2] > 1))
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}