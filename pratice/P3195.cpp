#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e4 + 10;

ll n, L;
ll f[MAXN], sum[MAXN], g[MAXN], h[MAXN];
ll q[MAXN], head, tail;

inline double calc(ll j_1, ll j_2)
{
    return (double)(f[j_2] + h[j_2] - f[j_1] - h[j_1]) / (g[j_2] - g[j_1]);
}

int main()
{
    scanf("%lld%lld", &n, &L);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
        g[i] = sum[i] + i;
        h[i] = (g[i] + 1 + L) * (g[i] + 1 + L);
    }
    h[0] = (1 + L) * (1 + L);
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && calc(q[head], q[head + 1]) <= 2 * g[i])
            ++head;
        f[i] = f[q[head]] + (g[i] - g[q[head]] - 1 - L) * (g[i] - g[q[head]] - 1 - L);
        while (head < tail && calc(q[tail], i) < calc(q[tail - 1], q[tail]))
            --tail;
        q[++tail] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}