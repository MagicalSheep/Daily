#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10;

int n, vis[MAXN << 1];

struct unit
{
    int id, colors[26], cnt;
} ma[MAXN << 1];

char src[MAXN][MAXN];

struct answer
{
    char rc, ch;
    int ind;
};

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ma[i].id = i, ma[i + n].id = i + n;
        scanf("%s", src[i] + 1);
        for (int j = 1; j <= n; j++)
        {
            if (src[i][j] == '?')
                continue;
            if (ma[i].colors[src[i][j] - 'a'] == 0)
                ma[i].cnt++;
            ma[i].colors[src[i][j] - 'a']++;
            if (ma[j + n].colors[src[i][j] - 'a'] == 0)
                ma[j + n].cnt++;
            ma[j + n].colors[src[i][j] - 'a']++;
        }
    }
    queue<struct unit> q;
    vector<answer> ans;
    for (int i = 1; i <= n; i++)
    {
        if (ma[i].cnt <= 1)
            q.push(ma[i]), vis[i] = 1;
        if (ma[i + n].cnt <= 1)
            q.push(ma[i + n]), vis[i + n] = 1;
    }
    while (!q.empty())
    {
        auto ttt = q.front();
        int v = ttt.id;
        bool iscol = false;
        if (ttt.id > n)
            iscol = true, v -= n;
        char color = 'a';
        if (ttt.cnt != 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if (ttt.colors[i] > 0)
                {
                    color = i + 'a';
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (iscol)
            {
                if (src[i][v] == color)
                {
                    ma[i].colors[color - 'a']--;
                    if (ma[i].colors[color - 'a'] == 0)
                        ma[i].cnt--;
                }
            }
            else
            {
                if (src[v][i] == color)
                {
                    ma[i + n].colors[color - 'a']--;
                    if (ma[i + n].colors[color - 'a'] == 0)
                        ma[i + n].cnt--;
                }
            }
        }
        answer tmp;
        tmp.ch = color;
        tmp.ind = v;
        tmp.rc = (iscol) ? 'v' : 'h';
        ans.emplace_back(tmp);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && ma[i].cnt <= 1)
                q.push(ma[i]), vis[i] = 1;
            if (!vis[i + n] && ma[i + n].cnt <= 1)
                q.push(ma[i + n]), vis[i + n] = 1;
        }
        q.pop();
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%c %d %c\n", ans[i].rc, ans[i].ind, ans[i].ch);
    return 0;
}