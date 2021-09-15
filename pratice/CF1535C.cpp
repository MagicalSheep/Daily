#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, f[MAXN][2];
char s[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        ll len = strlen(s + 1), ans = 0;
        for (int i = 1; i <= len; i++)
        {
            if (s[i] == '1')
                f[i][1] = f[i - 1][0] + 1, f[i][0] = 0;
            else if (s[i] == '0')
                f[i][0] = f[i - 1][1] + 1, f[i][1] = 0;
            else
                f[i][1] = f[i - 1][0] + 1, f[i][0] = f[i - 1][1] + 1;
            ans += max(f[i][1], f[i][0]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}