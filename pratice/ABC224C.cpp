#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 300 + 5;

ll N, ans;
pair<ll, ll> pos[MAXN];

int main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld%lld", &pos[i].first, &pos[i].second);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = j + 1; k <= N; k++)
            {
                pair<ll, ll> d, d2;
                d.first = pos[i].first - pos[j].first;
                d.second = pos[i].second - pos[j].second;
                ll tmp = __gcd(d.first, d.second);
                d.first /= tmp;
                d.second /= tmp;
                d2.first = pos[i].first - pos[k].first;
                d2.second = pos[i].second - pos[k].second;
                tmp = __gcd(d2.first, d2.second);
                d2.first /= tmp;
                d2.second /= tmp;
                if (!((d.first == d2.first && d.second == d2.second) || (d.first == -d2.first && d.second == -d2.second)))
                    ++ans;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}