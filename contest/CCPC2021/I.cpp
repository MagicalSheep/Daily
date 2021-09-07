#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

int t, n;
char cmd[MAXN];
int x, y;
map<pair<int, int>, ll> m;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, cmd);
        ll ans = 0;
        x = 0, y = 0;
        map<pair<int, int>, ll>::iterator it;
        m.insert(pair<pair<int, int>, ll>(pair<int, int>(x, y), 1LL));
        for (int i = 0; i < n; i++)
        {
            if (cmd[i] == 'U')
                y += 1;
            else if (cmd[i] == 'D')
                y -= 1;
            else if (cmd[i] == 'L')
                x -= 1;
            else if (cmd[i] == 'R')
                x += 1;
            if ((it = m.find(pair<int, int>(x, y))) != m.end())
                ans += it->second, it->second += 1;
            else
                m.insert(pair<pair<int, int>, ll>(pair<int, int>(x, y), 1LL));
        }
        printf("%lld\n", ans);
        m.clear();
    }
    return 0;
}