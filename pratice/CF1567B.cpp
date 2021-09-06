#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int xo[MAXN], t, a, b;

int main()
{
    for (int i = 1; i <= 300000; i++)
        xo[i] = xo[i - 1] ^ i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        if (xo[a - 1] == b)
            printf("%d\n", a);
        else if ((xo[a - 1] ^ b) != a)
            printf("%d\n", a + 1);
        else
            printf("%d\n", a + 2);
    }
    return 0;
}