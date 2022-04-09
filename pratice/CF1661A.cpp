#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t, n;

void solve(vector<ll> &a, vector<ll> &b)
{
    ll last_a = a[0], last_b = b[0], ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll s1 = abs(last_a - a[i]) + abs(last_b - b[i]);
        ll s2 = abs(last_a - b[i]) + abs(last_b - a[i]);
        if (s2 < s1)
            last_a = b[i], last_b = a[i], ans += s2;
        else
            last_a = a[i], last_b = b[i], ans += s1;
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%lld", &b[i]);
        solve(a, b);
    }
    return 0;
}