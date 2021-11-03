#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, ll[MAXN];
char s[MAXN], ss[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++)
            ll[s[i]] = i;
        scanf("%s", ss + 1);
        len = strlen(ss + 1);
        int ans = 0;
        for (int i = 2; i <= len; i++)
            ans += abs(ll[ss[i - 1]] - ll[ss[i]]);
        printf("%d\n", ans);
    }
    return 0;
}