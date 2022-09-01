#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (n == 1 && m == 1)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", m + n - 2 + min(m, n));
    }
    return 0;
}