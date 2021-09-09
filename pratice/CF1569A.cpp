#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, n;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i < n; i++)
        {
            if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a'))
            {
                printf("%d %d\n", i, i + 1);
                goto end;
            }
        }
        printf("-1 -1\n");
    end:;
    }
    return 0;
}