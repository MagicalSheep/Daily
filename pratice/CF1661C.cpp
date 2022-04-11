#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t, n;

ll solve(vector<int> &vec, int target)
{
    ll ans = 0x7fffffffffffffff, left = 0, right = 0x7fffffffffffffff;
    while (left <= right)
    {
        ll mid = (left + right) >> 1;
        ll cnt1 = ceil(mid / 2.0), cnt2 = mid / 2, sum = 0;
        for (auto x : vec)
        {
            ll need = (target - x) / 2;
            x += min(cnt2, need) * 2;
            cnt2 -= min(cnt2, need);
            sum += (target - x);
        }
        if (cnt1 >= sum)
            ans = min(ans, mid), right = mid - 1;
        else
            left = mid + 1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vector<int> h(n);
        int mx = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]), mx = max(mx, h[i]);
        printf("%lld\n", min(solve(h, mx), solve(h, mx + 1)));
    }
    return 0;
}