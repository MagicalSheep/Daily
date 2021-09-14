#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e4 + 10;

ll n, w[MAXN], d[MAXN];
ll f[MAXN], g[MAXN], h[MAXN], tot;
ll q[MAXN], head, tail;

inline double calc(ll j_1, ll j_2)
{
    return (1.0 * (g[j_2] * h[j_2] - g[j_1] * h[j_1])) / (1.0 * (h[j_2] - h[j_1]));
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &w[i], &d[i]), h[i] = h[i - 1] + w[i];
    for (int i = n; i >= 1; i--)
        g[i] = g[i + 1] + d[i];
    for (int i = 1; i <= n; i++)
        tot += w[i] * g[i];
    q[++tail] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (head < tail && calc(q[head], q[head + 1]) > g[i])
            ++head;
        f[i] = tot - g[q[head]] * h[q[head]] - g[i] * (h[i] - h[q[head]]);
        while (head < tail && calc(q[tail], i) >= calc(q[tail - 1], q[tail]))
            --tail;
        q[++tail] = i;
    }
    ll ans = 0x3f3f3f3f;
    for (int i = 2; i <= n; i++)
        ans = min(ans, f[i]);
    printf("%lld\n", ans);
    return 0;
}