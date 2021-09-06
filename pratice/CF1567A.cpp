#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int t, n;
char str[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, str);
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'U')
                printf("D");
            else if (str[i] == 'D')
                printf("U");
            else
                printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}