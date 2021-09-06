#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int N;
char str[MAXN];

namespace AC
{
    int tr[MAXN][26], cnt, exist[MAXN], fail[MAXN];

    void init()
    {
        memset(tr, 0, sizeof(tr));
        memset(exist, 0, sizeof(exist));
        memset(fail, 0, sizeof(fail));
        cnt = 0;
    }

    void insert(char *s)
    {
        int p = 0;
        for (int i = 1; s[i]; i++)
        {
            int c = s[i] - 'a';
            if (!tr[p][c])
                tr[p][c] = ++cnt;
            p = tr[p][c];
        }
        exist[p]++;
    }

    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (tr[0][i])
                q.push(tr[0][i]);
        while (q.size())
        {
            int p = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                if (tr[p][i])
                    fail[tr[p][i]] = tr[fail[p]][i], q.push(tr[p][i]);
                else
                    tr[p][i] = tr[fail[p]][i];
            }
        }
    }

    int query(char *s)
    {
        int p = 0, ret = 0;
        for (int i = 1; s[i]; i++)
        {
            int c = s[i] - 'a';
            p = tr[p][c];
            for (int j = p; j && exist[j] != -1; j = fail[j])
                ret += exist[j], exist[j] = -1;
        }
        return ret;
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%s", str + 1), AC::insert(str);
    AC::build();
    scanf("%s", str + 1);
    printf("%d\n", AC::query(str));
    return 0;
}