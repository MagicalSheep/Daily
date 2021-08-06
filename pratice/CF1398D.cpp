#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 200 + 5;

int R[MAXN], G[MAXN], B[MAXN], r, g, b;
ll f[MAXN][MAXN][MAXN];

int main()
{
    scanf("%d%d%d", &r, &g, &b);
    for (int i = 1; i <= r; i++)
        scanf("%d", &R[i]);
    for (int i = 1; i <= g; i++)
        scanf("%d", &G[i]);
    for (int i = 1; i <= b; i++)
        scanf("%d", &B[i]);
    sort(R + 1, R + 1 + r, greater<int>());
    sort(G + 1, G + 1 + g, greater<int>());
    sort(B + 1, B + 1 + b, greater<int>());
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            for (int k = 0; k <= b; k++)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + R[i] * G[j]);
                if (i - 1 >= 0 && k - 1 >= 0)
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + R[i] * B[k]);
                if (j - 1 >= 0 && k - 1 >= 0)
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1] + G[j] * B[k]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= g; j++)
            for (int k = 0; k <= b; k++)
                ans = max(ans, f[i][j][k]);
    printf("%lld\n", ans);
}