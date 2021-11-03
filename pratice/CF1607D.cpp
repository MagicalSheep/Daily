#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, n, a[MAXN], b[MAXN], c[MAXN];
char s[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        scanf("%s", s + 1);
        ll len = 0, lenc = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'R')
                b[++len] = a[i];
            else
                c[++lenc] = a[i];
        }
        sort(c + 1, c + 1 + lenc);
        ll j = 0;
        for (int i = 1; i <= lenc; i++)
            j = min(j + 1, c[i]);
        if (j + len != n)
        {
            printf("NO\n");
            continue;
        }
        ++j;
        sort(b + 1, b + 1 + len);
        bool isok = true;
        for (int i = 1; i <= len; i++)
        {
            if (j < b[i])
            {
                isok = false;
                break;
            }
            ++j;
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}