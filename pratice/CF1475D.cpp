#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, m;
ll a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        vector<ll> id1, id2;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &b[i]);
        for (int i = 1; i <= n; i++)
            if (b[i] == 1)
                id1.emplace_back(a[i]);
            else
                id2.emplace_back(a[i]);
        sort(id1.begin(), id1.end(), greater<ll>());
        sort(id2.begin(), id2.end(), greater<ll>());
        id1.insert(id1.begin(), 0);
        id2.insert(id2.begin(), 0);
        int len1 = id1.size(), len2 = id2.size();
        ll sum1 = 0, sum2[MAXN] = {0}, ans = 0x3f3f3f3f;
        for (int i = 1; i < len2; i++)
            sum2[i] = sum2[i - 1] + id2[i];
        int j = len2 - 1;
        for (int i = 0; i < len1; i++)
        {
            sum1 += id1[i];
            while (j >= 0 && sum1 + sum2[j] >= m)
                j--;
            if (sum1 + sum2[j + 1] >= m)
                ans = min(ans, 1ll * 2 * (j + 1) + i);
        }
        printf("%lld\n", (ans == 0x3f3f3f3f) ? -1 : ans);
    }
    return 0;
}