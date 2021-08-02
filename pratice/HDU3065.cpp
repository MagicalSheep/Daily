#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;

int N;
string str[1000 + 5], ss;
int tr[50000 + 10][27], cnt, exist[MAXN], fail[MAXN];
int ans[1000 + 5];

void init()
{
    memset(tr, 0, sizeof(tr));
    memset(exist, 0, sizeof(exist));
    memset(fail, 0, sizeof(fail));
    memset(ans, 0, sizeof(ans));
    cnt = 0;
}

void insert(int id, string s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int c;
        if (s[i] >= 'A' && s[i] <= 'Z')
            c = s[i] - 'A';
        else
            c = 26;
        if (!tr[p][c])
            tr[p][c] = ++cnt;
        p = tr[p][c];
    }
    exist[p] = id;
}

void build()
{
    queue<int> q;
    for (int i = 0; i <= 26; i++)
        if (tr[0][i])
            q.push(tr[0][i]);
    while (q.size())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i <= 26; i++)
        {
            if (tr[p][i])
                fail[tr[p][i]] = tr[fail[p]][i], q.push(tr[p][i]);
            else
                tr[p][i] = tr[fail[p]][i];
        }
    }
}

void query(string s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int c;
        if (s[i] >= 'A' && s[i] <= 'Z')
            c = s[i] - 'A';
        else
            c = 26;
        p = tr[p][c];
        for (int j = p; j; j = fail[j])
            ans[exist[j]]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N)
    {
        init();
        for (int i = 1; i <= N; i++)
        {
            cin >> str[i];
            insert(i, str[i]);
        }
        build();
        cin >> ss;
        query(ss);
        for (int i = 1; i <= N; i++)
        {
            if (ans[i] == 0)
                continue;
            cout << str[i] << ": " << ans[i] << endl;
        }
    }
    return 0;
}