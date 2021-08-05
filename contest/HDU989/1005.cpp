#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int T, n, m, b[MAXN], block[MAXN];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        sort(b + 1, b + 1 + m);
        b[m + 1] = n + 1;
        for (int i = 1; i <= m + 1; i++)
            block[i] = b[i] - b[i - 1] - 1;
        int s = 0, mx = 0, mxi = 0;
        for (int i = 1; i <= m + 1; i++)
        {
            if (mx < block[i])
                mx = block[i], mxi = i;
            s += block[i];
        }
        s -= mx;
        if (mx <= s)
            printf("YES\n");
        else if (mxi - 1 >= mx - s)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}