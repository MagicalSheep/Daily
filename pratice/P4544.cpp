#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 500 + 10;
const int MAXM = 1e5 + 10;

ll K, E, N;
ll f[MAXM], g[MAXM], q[MAXM], head, tail;

struct shop
{
    ll X, F, C;
} shops[MAXN];

bool cmp(shop a, shop b) { return a.X < b.X; }

inline ll calc(int i, ll k) { return g[k] + k * k * (shops[i].X - shops[i - 1].X) - k * shops[i].C; }

int main()
{
    scanf("%lld%lld%lld", &K, &E, &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld%lld%lld", &shops[i].X, &shops[i].F, &shops[i].C);
    shops[0].X = 0, shops[0].F = 0, shops[0].C = 0;
    shops[N + 1].X = E, shops[N + 1].F = 0, shops[N + 1].C = 0;
    sort(shops + 1, shops + 2 + N, cmp);
    memset(f, 0x3f, sizeof(f));
    memset(g, 0x3f, sizeof(g));
    f[0] = g[0] = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        head = 0, tail = -1;
        for (int j = 0; j <= K; j++)
        {
            while (head <= tail && j - q[head] > shops[i].F)
                ++head;
            while (head <= tail && calc(i, q[tail]) > calc(i, j))
                --tail;
            q[++tail] = j; // when j = 0, queue is empty, so we need to push back before updating
            f[j] = calc(i, q[head]) + j * shops[i].C;
        }
        for (int j = 0; j <= K; j++)
            g[j] = f[j];
    }
    printf("%lld\n", f[K]);
    return 0;
}