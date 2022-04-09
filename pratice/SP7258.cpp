#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

struct state
{
    int len, link;
    ll sum;
    map<char, int> next;
} st[MAXN << 1];

int last, sz, vis[MAXN << 1];

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
    int p = last;
    while (p != -1 && !st[p].next.count(c))
    {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1)
    {
        st[cur].link = 0;
    }
    else
    {
        int q = st[p].next[c];
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
            while (p != -1 && st[p].next[c] == q)
            {
                st[p].next[c] = clone;
                p = st[p].link;
            }
        }
    }
    last = cur;
}

void dfs1(int s)
{
    vis[s] = 1;
    for (auto x : st[s].next)
    {
        int v = x.second;
        if (!vis[v])
            dfs1(v);
        st[s].sum += st[v].sum;
    }
}

void solve(string &ans, int s, int k)
{
    if (s && k <= 1)
        return;
    if (s)
        k--;
    int v = 0;
    char vc;
    for (auto x : st[s].next)
    {
        vc = x.first;
        v = x.second;
        if (st[v].sum >= k)
            break;
        k -= st[v].sum;
    }
    ans.push_back(vc);
    solve(ans, v, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int t;
    cin >> s >> t;
    sam_init();
    for (auto c : s)
        sam_extend(c);
    for (int i = 1; i < sz; i++)
        st[i].sum = 1;
    dfs1(0);
    while (t--)
    {
        int k;
        cin >> k;
        string ans;
        solve(ans, 0, k);
        cout << ans << endl;
    }
    return 0;
}