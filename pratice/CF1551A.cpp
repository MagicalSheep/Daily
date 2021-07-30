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
        int tmp = n / 3;
        if (n % 3 == 0)
        {
            printf("%d %d\n", tmp, tmp);
        }
        else
        {
            if ((tmp + 1) + 2 * tmp == n)
                printf("%d %d\n", tmp + 1, tmp);
            else
                printf("%d %d\n", tmp, tmp + 1);
        }
    }
    return 0;
}