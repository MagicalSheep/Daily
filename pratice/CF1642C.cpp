#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll n, x;
        scanf("%lld%lld", &n, &x);
        map<ll, int> ma;
        vector<ll> vec;
        for (int i = 1; i <= n; i++)
        {
            ll in;
            scanf("%lld", &in);
            ma[in]++;
            vec.emplace_back(in);
        }
        sort(vec.begin(), vec.end());
        int ans = 0;
        for (auto xx : vec)
        {
            if (ma[xx] == 0)
                continue;
            --ma[xx];
            if (ma[xx * x] == 0)
                ++ans;
            else
                --ma[xx * x];
        }
        printf("%d\n", ans);
    }
    return 0;
}