#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int t, n;
char c[5], str[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, c);
        scanf("%s", str + 1);
        bool is_same = true;
        for (int i = 1; i <= n; i++)
        {
            if (str[i] != c[0])
            {
                is_same = false;
                break;
            }
        }
        if (is_same)
        {
            printf("0\n");
            continue;
        }
        int ans = 0;
        bool is_valid = false;
        for (int i = 1; i <= n; i++)
        {
            bool isok = true;
            for (int j = 1; i * j <= n; j++)
            {
                if (str[i * j] != c[0])
                {
                    isok = false;
                    break;
                }
            }
            if (isok)
            {
                is_valid = true;
                ans = i;
                break;
            }
        }
        if (is_valid)
        {
            printf("1\n%d\n", ans);
            continue;
        }
        printf("2\n%d %d\n", n, n - 1);
    }
    return 0;
}