#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e4 + 10;

ll N, q[MAXN], head, tail, f[MAXN];

struct obj
{
    ll w, l;
} a[MAXN], b[MAXN];

bool cmp(obj x, obj y) { return x.l < y.l; }

inline double calc(ll k_1, ll k_2)
{
    return (1.0 * (f[k_1] - f[k_2])) / (1.0 * (b[k_2 + 1].w - b[k_1 + 1].w));
}

int main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld%lld", &a[i].w, &a[i].l);
    sort(a + 1, a + 1 + N, cmp);
    head = 0, tail = -1;
    for (int i = 1; i <= N; i++)
    {
        while (head <= tail && a[q[tail]].w <= a[i].w)
            --tail;
        q[++tail] = i;
    }
    int len = tail + 1;
    for (int i = 0; i < len; i++)
        b[i + 1].w = a[q[i]].w, b[i + 1].l = a[q[i]].l;
    for (int i = 0; i < len; i++)
        q[i] = 0;
    head = tail = 0;
    for (int i = 1; i <= len; i++)
    {
        while (head < tail && calc(q[head], q[head + 1]) < b[i].l)
            ++head;
        f[i] = f[q[head]] + b[q[head] + 1].w * b[i].l;
        while (head < tail && calc(q[tail], i) <= calc(q[tail - 1], q[tail]))
            --tail;
        q[++tail] = i;
    }
    printf("%lld\n", f[len]);
    return 0;
}