#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

int t;
int n, m, k;

struct block
{
    ll l, r;
};

vector<block> blocks[MAXN], ansblocks[MAXN];
vector<int> mine[MAXN];

void prework()
{
    for (int i = 1; i <= n; i++)
    {
        blocks[i].clear();
        if (mine[i].size() == 0)
        {
            block b;
            b.l = 1, b.r = m;
            blocks[i].emplace_back(b);
            continue;
        }
        bool first = false;
        int j = 0;
        for (; j < mine[i].size(); j++)
        {
            block b;
            if (!first)
                b.l = 1;
            else
                b.l = mine[i].at(j - 1) + 1;
            b.r = mine[i].at(j) - 1;
            if (b.l <= b.r)
                blocks[i].emplace_back(b);
            first = true;
        }
        block b;
        b.l = mine[i].at(j - 1) + 1;
        b.r = m;
        if (b.l <= b.r)
            blocks[i].emplace_back(b);
    }
}

ll solve()
{
    ansblocks[1].clear();
    ansblocks[1].emplace_back(blocks[1].at(0));
    for (int i = 2; i <= n; i++)
    {
        ansblocks[i].clear();
        int ansblocks_siz = ansblocks[i - 1].size();
        int blocks_siz = blocks[i].size();
        for (int k = 0; k < blocks_siz; k++)
        {
            int l = blocks[i].at(k).l;
            int r = blocks[i].at(k).r;
            for (int j = 0; j < ansblocks_siz; j++)
            {
                int last_l = ansblocks[i - 1].at(j).l;
                int last_r = ansblocks[i - 1].at(j).r;
                if (r < last_l || l > last_r)
                    continue;
                block b;
                b.l = max(last_l, l);
                b.r = r;
                ansblocks[i].emplace_back(b);
                break;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int len = ansblocks[i].size();
        for (int j = 0; j < len; j++)
            ans += (ansblocks[i].at(j).r - ansblocks[i].at(j).l + 1);
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            mine[i].clear();
        for (int i = 1; i <= k; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            mine[x].emplace_back(y);
        }
        for (int i = 1; i <= n; i++)
            sort(mine[i].begin(), mine[i].end());
        prework();
        printf("%lld\n", solve());
    }
    return 0;
}