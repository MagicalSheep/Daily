#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int N;
int f[MAXN][MAXN], g[MAXN][MAXN], ans;
int q[MAXN], head, tail;
pair<int, int> obj[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &obj[i].first, &obj[i].second);
    if (N == 1)
    {
        printf("%d\n", obj[1].second);
        return 0;
    }
    sort(obj + 1, obj + 1 + N);
    for (int j = 1; j <= N; j++)
    {
        for (int i = j + 1; i <= N; i++)
        {
            f[i][j] = f[j][0] + obj[j].second;
            for (int k = j - 1; k >= 1; k--)
            {
                if (obj[i].first - obj[j].first < obj[j].first - obj[k].first)
                    break;
                f[i][j] = max(f[i][j], f[j][k] + obj[j].second);
            }
            ans = max(ans, f[i][j] + obj[i].second);
        }
    }
    for (int j = N; j >= 1; j--)
    {
        for (int i = j - 1; i >= 1; i--)
        {
            g[i][j] = g[j][N + 1] + obj[j].second;
            for (int k = j + 1; k <= N; k++)
            {
                if (obj[j].first - obj[i].first < obj[k].first - obj[j].first)
                    break;
                g[i][j] = max(g[i][j], g[j][k] + obj[j].second);
            }
            ans = max(ans, g[i][j] + obj[i].second);
        }
    }
    printf("%d\n", ans);
    return 0;
}