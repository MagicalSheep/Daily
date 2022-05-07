#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        if (s[1] == '0' || s[n] == '1')
        {
            printf("1\n");
            continue;
        }
        int last_one = 0, first_zero = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '1')
                last_one = i;
            if (s[i] == '0' && first_zero == 0)
                first_zero = i;
        }
        if (last_one == 0 && first_zero == 0)
        {
            printf("%d\n", n);
            continue;
        }
        if (last_one == 0)
        {
            printf("%d\n", first_zero);
            continue;
        }
        if (first_zero == 0)
        {
            printf("%d\n", n - last_one + 1);
            continue;
        }
        printf("%d\n", abs(first_zero - last_one) + 1);
    }
    return 0;
}