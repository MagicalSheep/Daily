#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int fa[MAXN], N, Q, nex[MAXN];

int Find(int x)
{
    while (x != fa[x])
        x = fa[x];
    return x;
}

void setroot(int x)
{
    if (x != fa[x])
        setroot(fa[x]);
    fa[x] = fa[fa[x]] = x;
}

// a -> b
void link(int a, int b)
{
    setroot(a), fa[a] = b;
}

// a -> b ==> root(a), root(b)
void cut(int a, int b)
{
    setroot(a), fa[b] = b;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    while (Q--)
    {
        int o, x, y;
        scanf("%d", &o);
        if (o == 1)
        {
            scanf("%d%d", &x, &y);
            nex[x] = y;
            link(y, x);
        }
        else if (o == 2)
        {
            scanf("%d%d", &x, &y);
            nex[x] = 0;
            int head = Find(x);
            cut(x, y);
            setroot(head);
        }
        else
        {
            scanf("%d", &x);
            int head = Find(x);
            vector<int> ans;
            ans.emplace_back(head);
            for (int node = nex[head]; node; node = nex[node])
                ans.emplace_back(node);
            printf("%d ", ans.size());
            for (auto v : ans)
                printf("%d ", v);
            printf("\n");
        }
    }
    return 0;
}