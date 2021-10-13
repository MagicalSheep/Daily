#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;

int t, n;
bitset<MAXN> days[6];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 1; i <= 5; i++)
            days[i].reset();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int in;
                scanf("%d", &in);
                days[j].set(i, in);
            }
        }
        int cnt = n >> 1;
        bool isok = false;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (i == j)
                    continue;
                if (days[i].count() < cnt || days[j].count() < cnt)
                    continue;
                bitset<MAXN> tmp = days[i] & days[j];
                int ccnt = tmp.count();
                int aa = (days[i] ^ tmp).count();
                int bb = (days[j] ^ tmp).count();
                if (aa > cnt || bb > cnt)
                    continue;
                if (ccnt + aa + bb == n)
                {
                    isok = true;
                    break;
                }
            }
            if (isok)
                break;
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}