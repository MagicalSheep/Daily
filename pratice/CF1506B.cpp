#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int a[MAXN];
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int k, n;
        scanf("%d%d", &n, &k);
        char str[100];
        scanf("%s", str);
        int ii = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '*')
                a[++ii] = i + 1;
        if (ii == 0)
        {
            printf("0\n");
            continue;
        }
        int last = 1, ans = 1;
        for (int i = 2; i <= ii; i++)
        {
            if (a[i] - a[last] > k)
                ans++, last = i - 1;
            if (i == ii)
            {
                ans++;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}