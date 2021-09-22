#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
                putchar('(');
            for (int j = 1; j <= i; j++)
                putchar(')');
            putchar('(');
            for (int j = 1; j <= n - i; j++)
                putchar(')');
            puts("");
        }
    }
    return 0;
}