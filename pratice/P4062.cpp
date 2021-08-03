#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 10;

int n, a[MAXN];
int cnt[MAXN], vis[MAXN], sum[MAXN << 1];
ll ans;

void solve(int l, int r)
{
    if (l == r)
    {
        ++ans;
        return;
    }
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    vector<int> all_x;
    for (int i = mid; i >= l; i--)
    {
        ++cnt[a[i]];
        if ((cnt[a[i]] > (mid - i + 1) / 2) && !vis[a[i]])
            all_x.emplace_back(a[i]), vis[a[i]] = 1;
    }
    for (int j = l; j <= mid; j++)
        cnt[a[j]] = 0;
    for (int i = mid; i <= r; i++)
    {
        ++cnt[a[i]];
        if ((cnt[a[i]] > (i - mid) / 2) && !vis[a[i]])
            all_x.emplace_back(a[i]), vis[a[i]] = 1;
    }
    for (int j = l; j <= r; j++)
        cnt[a[j]] = vis[a[j]] = 0;
    int len = all_x.size();
    for (int i = 0; i < len; i++)
    {
        int s = 0, num = all_x[i];
        sum[n]++;
        for (int j = l; j < mid; j++)
        {
            s += (a[j] == num) ? 1 : -1;
            sum[s + n]++;
        }
        for (int j = -(r - l + 1) + 1; j <= (r - l + 1); j++)
            sum[j + n] += sum[j + n - 1];
        s += (a[mid] == num) ? 1 : -1;
        for (int j = mid + 1; j <= r; j++)
        {
            s += (a[j] == num) ? 1 : -1;
            ans += sum[s + n - 1];
        }
        for (int j = -(r - l + 1); j <= (r - l + 1); j++)
            sum[j + n] = 0;
    }
}

int main()
{
    ans = 0;
    int type = 0;
    scanf("%d%d", &n, &type);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    solve(1, n);
    printf("%lld\n", ans);
    return 0;
}