#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int n, a[MAXN], b[MAXN], vis[MAXN], bound;
int dis[MAXN], fa[MAXN], de[MAXN];
vector<int> ans;
queue<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    reverse(a, a + n);
    reverse(b, b + n);
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    q.push(0);
    vis[0] = 1;
    bound = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = a[u]; i >= 0; i--)
        {
            int v = u + i;
            if (v <= bound)
                break;
            v -= b[u + i];
            if (vis[v])
                continue;
            dis[v] = dis[u] + 1, fa[v] = u, de[v] = b[u + i];
            vis[v] = 1;
            q.push(v);
        }
        bound = max(bound, u + a[u]);
    }
    if (dis[n] == 0x3f3f3f3f)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", dis[n]);
    ans.emplace_back(0);
    for (int e = fa[n]; e; e = fa[e])
        ans.emplace_back(n - e - de[e]);
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}