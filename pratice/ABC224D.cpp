#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;

int M;
vector<int> G[15];
string state;
queue<string> Q;
map<string, int> ma;

int main()
{
    scanf("%d", &M);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    state = "999999999";
    for (int i = 1; i <= 8; i++)
    {
        int p;
        scanf("%d", &p);
        state[p - 1] = i + '0';
    }
    Q.push(state);
    ma[state] = 0;
    while (Q.size())
    {
        string s = Q.front();
        Q.pop();
        int v;
        for (int i = 0; i < 9; i++)
            if (s[i] == '9')
                v = i + 1;
        for (auto u : G[v])
        {
            string tmp = s;
            swap(tmp[u - 1], tmp[v - 1]);
            if (ma.count(tmp))
                continue;
            Q.push(tmp);
            ma[tmp] = ma[s] + 1;
        }
    }
    if (ma.count("123456789") == 0)
        printf("-1\n");
    else
        printf("%d\n", ma["123456789"]);
    return 0;
}