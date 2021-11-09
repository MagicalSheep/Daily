#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int N, M, ind[MAXN], vis[MAXN];
vector<int> G[MAXN];

priority_queue<int, vector<int>, greater<int>> q;
vector<int> ans;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].emplace_back(b);
        ind[b]++;
    }
    for (int i = 1; i <= N; i++)
        if (ind[i] == 0)
            q.push(i);
    while (q.size())
    {
        int u = q.top();
        q.pop();
        ans.emplace_back(u);
        vis[u] = 1;
        for (auto v : G[u])
        {
            ind[v]--;
            if (ind[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] == 0)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}