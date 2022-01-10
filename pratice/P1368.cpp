#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int n, a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n)
    {
        if (a[(i + k) % n] == a[(j + k) % n])
        {
            ++k;
            continue;
        }
        (a[(i + k) % n] > a[(j + k) % n]) ? i += k + 1 : j += k + 1;
        if (i == j)
            ++i;
        k = 0;
    }
    i = min(i, j);
    for (int it = 0; it < n; it++)
        printf("%d ", a[(i + it) % n]);
    printf("\n");
    return 0;
}