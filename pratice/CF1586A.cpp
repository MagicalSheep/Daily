#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int t, n;

bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void func1()
{
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", i);
    printf("\n");
}

void func2(int sum, int *a)
{
    printf("%d\n", n - 1);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!flag && (a[i] & 1))
        {
            flag = true;
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int a[MAXN] = {0}, sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum += a[i];
        if (!is_prime(sum))
            func1();
        else
            func2(sum, a);
    }
    return 0;
}