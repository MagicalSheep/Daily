#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0 && y == 0)
        {
            printf("0\n");
            continue;
        }
        int tmp = sqrt(x * x + y * y);
        if (tmp * tmp == x * x + y * y)
        {
            printf("1\n");
            continue;
        }
        printf("2\n");
    }
    return 0;
}