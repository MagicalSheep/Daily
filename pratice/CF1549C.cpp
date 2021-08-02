#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int friends[MAXN], weaker[MAXN];
int n, m, ans;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ++friends[u], ++friends[v];
        ++weaker[max(u, v)];
    }
    for (int i = 1; i <= n; i++)
        if (weaker[i] == friends[i])
            ++ans;
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int o;
        scanf("%d", &o);
        if (o == 1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (friends[min(u, v)] == weaker[min(u, v)])
                --ans;
            ++friends[u], ++friends[v];
            ++weaker[max(u, v)];
        }
        else if (o == 2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            --friends[u], --friends[v];
            --weaker[max(u, v)];
            if (friends[min(u, v)] == weaker[min(u, v)])
                ++ans;
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}