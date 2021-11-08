#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 50 + 10;

ll H, W, A[MAXN][MAXN];

int main()
{
    scanf("%lld%lld", &H, &W);
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            scanf("%lld", &A[i][j]);
    bool isok = true;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            for (int k = i + 1; k <= H; k++)
            {
                for (int g = j + 1; g <= W; g++)
                {
                    if (A[i][j] + A[k][g] > A[k][j] + A[i][g])
                    {
                        isok = false;
                        goto end;
                    }
                }
            }
        }
    }
end:
    printf((isok) ? "Yes\n" : "No\n");
    return 0;
}