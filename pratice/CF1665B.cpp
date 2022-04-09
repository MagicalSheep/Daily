#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        map<int, int> cnt;
        for (int i = 1; i <= n; i++)
        {
            int in;
            scanf("%d", &in);
            if (cnt.find(in) == cnt.end())
                cnt[in] = 0;
            ++cnt[in];
        }
        int big = 0, bignum = 0;
        for (auto x : cnt)
        {
            if (x.second > bignum)
                big = x.first, bignum = x.second;
        }
        ll ans = 0, cur = bignum;
        while (cur < n)
        {
            ++ans;
            ans += cur;
            cur *= 2;
        }
        if (cur > n)
            ans -= (cur - n);
        printf("%lld\n", ans);
    }
    return 0;
}