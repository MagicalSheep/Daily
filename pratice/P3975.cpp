#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10;

string s;
int t, k, last, sz, vis[MAXN << 1];

struct state
{
    int len, link, next[26];
    ll cnt, sum;
} st[MAXN << 1];

vector<int> tr[MAXN << 1];

void sam_init()
{
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sam_extend(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
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

void dfs1(int s)
{
    for (auto v : tr[s])
    {
        dfs1(v);
        st[s].cnt += st[v].cnt;
    }
}

void dfs2(int s)
{
    vis[s] = 1;
    st[s].sum = st[s].cnt;
    for (int i = 0; i < 26; i++)
    {
        if (!st[s].next[i])
            continue;
        int v = st[s].next[i];
        if (!vis[v])
            dfs2(v);
        st[s].sum += st[v].sum;
    }
}

void solve(string &ans, int s, int k)
{
    if (k <= st[s].cnt)
        return;
    k -= st[s].cnt;
    int i = 0, v;
    for (; i < 26; i++)
    {
        if (!st[s].next[i])
            continue;
        v = st[s].next[i];
        if (st[v].sum >= k)
            break;
        k -= st[v].sum;
    }
    ans.push_back(i + 'a');
    solve(ans, v, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t >> k;
    sam_init();
    for (auto c : s)
        sam_extend(c);
    for (int i = 1; i < sz; i++)
        tr[st[i].link].emplace_back(i);
    if (t)
        dfs1(0);
    else
        for (int i = 1; i < sz; i++)
            st[i].cnt = 1;
    st[0].cnt = 0;
    dfs2(0);
    st[0].sum -= 1;
    if (st[0].sum < k)
    {
        cout << -1 << endl;
    }
    else
    {
        string ans;
        solve(ans, 0, k);
        cout << ans << endl;
    }
    return 0;
}