#include <bits/stdc++.h>
using namespace std;

int T, n;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int len = 0;
        scanf("%d", &n);
        int tmp = n % 4;
        if (tmp == 1)
            len += 1;
        else if (tmp == 2)
            len += 4;
        else if (tmp == 3)
            len += 2;
        len += 4 * (n / 4);
        printf("%d\n", len);
        if (tmp == 1)
            printf("1");
        else if (tmp == 2)
            printf("0001");
        else if (tmp == 3)
            printf("01");
        tmp = n / 4;
        for (int i = 1; i <= tmp; i++)
            printf("1001");
        printf("\n");
    }
    return 0;
}