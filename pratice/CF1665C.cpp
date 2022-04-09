#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n;

ll solve(vector<ll> &vec)
{
    if (vec.empty())
        return 0;
    ll ret = 0, last = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == vec[0])
            last = i;
        else
            break;
    }
    --vec[last];
    for (int i = 0; i < vec.size(); i++)
        --vec[i];
    ++ret;
    while (!vec.empty() && vec.back() <= 0)
        vec.pop_back();
    ret += solve(vec);
    return ret;
    // ll ret = 0, sum = 0, di = 0, geshu = 0, need = 0;
    // for (auto x : vec)
    //     sum += x;
    // for (ll i = 0; i < vec.size(); i++)
    // {
    //     ll seconds = vec[i];
    //     ll remain = sum - vec.size() * vec[i];
    //     if (remain == seconds)
    //         return seconds;
    //     if (remain > seconds)
    //     {
    //         need += vec[i];
    //         continue;
    //     }
    //     ret = seconds;
    //     di = (i == 0) ? 0ll : vec[i - 1];
    //     geshu = vec.size() - i;
    //     break;
    // }
    // while ((ret > di) && ((sum - geshu * ret - need) < ret))
    //     --ret;
    // return ret + 1;
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        map<ll, ll> ma;
        for (ll i = 1; i < n; i++)
        {
            ll p;
            scanf("%lld", &p);
            if (ma.find(p) == ma.end())
                ma[p] = 0;
            ++ma[p];
        }
        ma[0] = 1;
        vector<ll> vec;
        for (auto x : ma)
            vec.emplace_back(x.second);
        sort(vec.begin(), vec.end(), greater<ll>());
        ll len = vec.size(), zeros = 0;
        ll ans = len;
        for (ll i = 0; i < vec.size(); i++)
        {
            vec[i] = max(0ll, vec[i] - (len - i));
            if (vec[i] == 0)
                ++zeros;
        }
        if (zeros == len)
        {
            printf("%lld\n", ans);
            continue;
        }
        vector<ll> ve;
        for (auto x : vec)
            if (x != 0)
                ve.emplace_back(x);
        sort(ve.begin(), ve.end(), greater<ll>());
        ans += solve(ve);
        printf("%lld\n", ans);
    }
    return 0;
}