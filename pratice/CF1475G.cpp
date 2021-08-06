#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, cnt[MAXN], f[MAXN];
vector<int> a, b[MAXN];

int main()
{
    for (int i = 1; i < MAXN; i++)
        for (int k = 2; k * i < MAXN; k++)
            b[k * i].emplace_back(i);
    scanf("%d", &t);
    while (t--)
    {
        a.clear();
        memset(f, 0, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int in;
            scanf("%d", &in);
            a.emplace_back(in);
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());
        int len = unique(a.begin(), a.end()) - a.begin();
        for (int i = 0; i < len; i++)
        {
            int mx = 0;
            for (auto x : b[a[i]])
            {
                if (!cnt[x])
                    continue;
                mx = max(mx, f[x]);
            }
            f[a[i]] = cnt[a[i]] + mx;
        }
        int ans = 0;
        for (int i = 0; i < len; i++)
            ans = max(ans, f[a[i]]);
        printf("%d\n", n - ans);
    }
    return 0;
}