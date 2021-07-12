#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, cnt = 0, head[1500 + 10], f[1500 + 10][2], fa[1500 + 10];
struct edge
{
    ll to, next;
} Edge[3000];

void addEdge(ll from, ll to)
{
    Edge[++cnt].to = to;
    Edge[cnt].next = head[from];
    head[from] = cnt;
    fa[to] = from;
}

ll solve(ll p, ll is_place)
{
    if (f[p][is_place])
        return f[p][is_place];
    ll ret;
    if (is_place)
    {
        ret = 1;
        for (int i = head[p]; i; i = Edge[i].next)
            ret += min(solve(Edge[i].to, 0), solve(Edge[i].to, 1));
    }
    else
    {
        ret = 0;
        for (int i = head[p]; i; i = Edge[i].next)
            ret += solve(Edge[i].to, 1);
    }
    return f[p][is_place] = ret;
}

int main()
{
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        ll i = 0, k = 0;
        cin >> i >> k;
        while (k--)
        {
            ll r = 0;
            cin >> r;
            addEdge(i, r);
        }
    }
    ll root = 0;
    for (int i = 0; i < n; i++)
    {
        if (!fa[i])
        {
            root = i;
            break;
        }
    }
    cout << min(solve(root, 1), solve(root, 0)) << endl;
    return 0;
}