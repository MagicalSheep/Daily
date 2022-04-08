#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

int n, idcnt, sz, last;
unordered_map<int, int> ids;
ll ans;

struct state
{
    int len, link;
    unordered_map<int, int> next;
} st[MAXN << 1];

void sam_init()
{
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sam_extend(int x)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(x))
    {
        st[p].next[x] = cur;
        p = st[p].link;
    }
    if (p == -1)
    {
        st[cur].link = 0;
    }
    else
    {
        int q = st[p].next[x];
        if (st[p].len + 1 == st[q].len)
        {
            st[cur].link = q;
        }
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[q].link = st[cur].link = clone;
            while (p != -1 && st[p].next[x] == q)
            {
                st[p].next[x] = clone;
                p = st[p].link;
            }
        }
    }
    last = cur;
    ans += 1ll * st[cur].len - st[st[cur].link].len;
}

int main()
{
    scanf("%d", &n);
    sam_init();
    while (n--)
    {
        int x;
        scanf("%d", &x);
        if (ids.find(x) == ids.end())
            ids[x] = idcnt++;
        sam_extend(ids[x]);
        printf("%lld\n", ans);
    }
    return 0;
}