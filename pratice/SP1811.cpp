#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

string s, t;
int sz, last;

struct state
{
    int len, link, next[26];
} st[MAXN << 1];

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

int lcs()
{
    int v = 0, len = 0, ans = 0;
    for (auto c : t)
    {
        while (v && !st[v].next[c - 'a'])
        {
            v = st[v].link;
            len = st[v].len;
        }
        if (st[v].next[c - 'a'])
        {
            v = st[v].next[c - 'a'];
            len++;
        }
        if (len > ans)
            ans = len;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    sam_init();
    for (auto c : s)
        sam_extend(c);
    cout << lcs() << endl;
    return 0;
}