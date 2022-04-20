#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    printf("%d\n", (n / 3) + (n + 2) / 3);
    if (n == 1)
    {
        printf("1 1\n");
        return 0;
    }
    while (n % 3 != 2)
    {
        printf("%d %d\n", n, n);
        --n;
    }
    int cnt = (n + 1) / 3;
    for (int i = 1; i <= cnt; i++)
        printf("%d %d\n", i, cnt - i + 1);
    for (int i = 1; i < cnt; i++)
        printf("%d %d\n", n - cnt + i + 1, n - i + 1);
    return 0;
}