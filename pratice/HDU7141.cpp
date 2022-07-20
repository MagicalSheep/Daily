#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXM = 2e5 + 5;
const int MAXN = 2e3 + 5;

int t, n, m, mark[MAXM], x[MAXN], y[MAXN];
bitset<MAXN> bs[MAXN];

struct point
{
    int s, a, b;
};

bool cmp(point &a, point &b)
{
    return a.s < b.s;
}

int main()
{
    mark[1] = 1;
    for (int i = 2; i < MAXM; i++)
    {
        if (mark[i])
            continue;
        for (int j = i + i; j < MAXM; j += i)
            mark[j] = 1;
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &x[i], &y[i]);
        vector<point> vec;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                vec.emplace_back(point{abs(x[i] - x[j]) + abs(y[i] - y[j]), i, j});
        sort(vec.begin(), vec.end(), cmp);
        ll ans = 0;
        for (auto v : vec)
        {
            if (!mark[v.s])
                ans += (bs[v.a] ^ bs[v.b]).count();
            bs[v.a][v.b] = 1;
            bs[v.b][v.a] = 1;
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++)
            bs[i].reset();
    }
    return 0;
}