#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 10;

struct state
{
    int len, link, next[26], flag;
} st[MAXN << 1];

int sz, last;
char s[MAXN];
ll ans, siz[MAXN << 1];
vector<int> tr[MAXN << 1];

void sam_init()
{
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sam_extend(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].flag = 1;
    int p = last;
    while (p != -1 && !st[p].next[c - 'a'])
    {
        st[p].next[c - 'a'] = cur;
        p = st[p].link;
    }
    if (p == -1)
    {
        st[cur].link = 0;
    }
    else
    {
        int q = st[p].next[c - 'a'];
        if (st[p].len + 1 == st[q].len)
        {
            st[cur].link = q;
        }
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            for (int i = 0; i < 26; i++)
                st[clone].next[i] = st[q].next[i];
            st[clone].link = st[q].link;
            st[q].link = st[cur].link = clone;
            while (p != -1 && st[p].next[c - 'a'] == q)
            {
                st[p].next[c - 'a'] = clone;
                p = st[p].link;
            }
        }
    }
    last = cur;
}

void dfs(int s)
{
    for (auto x : tr[s])
    {
        dfs(x);
        siz[s] += siz[x];
    }
    if (siz[s] > 1)
        ans = max(ans, 1ll * st[s].len * siz[s]);
}

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    sam_init();
    for (int i = 0; i < len; i++)
        sam_extend(s[i]);
    for (int i = 1; i < sz; i++)
    {
        if (st[i].flag)
            siz[i] = 1;
        tr[st[i].link].emplace_back(i);
    }
    dfs(0);
    printf("%lld\n", ans);
    return 0;
}