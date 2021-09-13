#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 10;

ll n, a, b, c;
ll f[MAXN], sum[MAXN], g[MAXN];
ll q[MAXN], head, tail;

inline double calc(ll k_1, ll k_2) { return (1.0 * (f[k_1] + g[k_1] - f[k_2] - g[k_2])) / (2.0 * a * (sum[k_1] - sum[k_2])); }

int main()
{
    scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &sum[i]), sum[i] += sum[i - 1], g[i] = a * sum[i] * sum[i] - b * sum[i];
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && calc(q[head], q[head + 1]) < 1.0 * sum[i])
            ++head;
        ll X = sum[i] - sum[q[head]];
        f[i] = f[q[head]] + a * X * X + b * X + c;
        while (head < tail && calc(q[tail], i) <= calc(q[tail - 1], q[tail]))
            --tail;
        q[++tail] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}