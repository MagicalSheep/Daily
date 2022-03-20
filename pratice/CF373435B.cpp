#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 40 + 5;

int h, w;
char ma[MAXN][MAXN];

int cnt;
map<pair<int, int>, int> nodes;
map<int, char> val;
vector<int> edges[MAXN * MAXN];
vector<char> expr;
stack<ll> sta;

void build(int x, int y)
{
    nodes[pair<int, int>(x, y)] = ++cnt;
    val[cnt] = ma[x][y];
    if (val[cnt] >= '0' && val[cnt] <= '9')
        return;
    int pa = cnt, lson = 0, rson = 0;
    for (int i = y - 1; i > 0; i--)
    {
        if (ma[x + 1][i] != '.')
        {
            build(x + 1, i);
            lson = nodes[pair<int, int>(x + 1, i)];
            break;
        }
    }
    for (int i = y + 1; i <= w; i++)
    {
        if (ma[x + 1][i] != '.')
        {
            build(x + 1, i);
            rson = nodes[pair<int, int>(x + 1, i)];
            break;
        }
    }
    edges[pa].emplace_back(lson);
    edges[pa].emplace_back(rson);
}

void dfs(int s)
{
    for (auto v : edges[s])
        dfs(v);
    expr.emplace_back(val[s]);
}

int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
        scanf("%s", ma[i] + 1);
    for (int i = 1; i <= w; i++)
    {
        if (ma[1][i] != '.')
        {
            build(1, i);
            break;
        }
    }
    dfs(1);
    for (auto c : expr)
    {
        if (c >= '0' && c <= '9')
        {
            sta.push(c - '0');
        }
        else
        {
            ll r2 = sta.top();
            sta.pop();
            ll r1 = sta.top();
            sta.pop();
            ll ans = 0;
            if (c == '+')
                ans = r1 + r2;
            else if (c == '-')
                ans = r1 - r2;
            else if (c == '*')
                ans = r1 * r2;
            sta.push(ans);
        }
    }
    printf("%lld\n", sta.top());
    return 0;
}