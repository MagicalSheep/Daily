#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int ma[3][MAXN], t, m;
int sum1[MAXN], sum2[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        scanf("%d", &m);
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &ma[1][i]);
            sum1[i] = sum1[i - 1] + ma[1][i];
            sum += ma[1][i];
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &ma[2][i]);
            sum2[i] = sum2[i - 1] + ma[2][i];
            sum += ma[2][i];
        }
        int ans[MAXN];
        for (int i = 1; i <= m; i++)
        {
            int tt = sum1[i] + sum2[m] - sum2[i - 1];
            ans[i] = max(sum1[m] - sum1[i], sum2[i - 1]);
        }
        sort(ans + 1, ans + 1 + m);
        printf("%d\n", ans[1]);
    }
    return 0;
}