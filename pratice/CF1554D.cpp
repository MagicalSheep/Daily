#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            printf("a\n");
            continue;
        }
        int k = n / 2;
        for (int i = 1; i <= k; i++)
            printf("x");
        printf((n % 2 == 0) ? "y" : "yz");
        for (int i = 1; i <= k - 1; i++)
            printf("x");
        printf("\n");
    }
    return 0;
}