#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;

int n, m;
ll a[MAXN], ans;

void update(int pos, ll d)
{
    if (a[pos] != a[pos + 1])
        ans += d * (n - pos) * pos;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    ans = 1ll * (n + 1) * n / 2;
    for (int i = 1; i < n; i++)
        update(i, 1);
    while (m--)
    {
        int pos, x;
        scanf("%d%d", &pos, &x);
        update(pos - 1, -1);
        update(pos, -1);
        a[pos] = x;
        update(pos - 1, 1);
        update(pos, 1);
        printf("%lld\n", ans);
    }
    return 0;
}