#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, k;
char str[MAXN];

void solve()
{
    vector<int> f(n + 1), ones(n + 1);
    int zeros = k;
    for (int i = 1; i <= n; i++)
    {
        ones[i] = (str[i] == '0') ? 0 : 1;
        if (((k + ones[i]) & 1) || zeros <= 0)
        {
            ones[i] += k;
            continue;
        }
        ones[i] += (k - 1);
        ++f[i];
        --zeros;
    }
    ones[n] -= zeros;
    f[n] += zeros;
    for (int i = 1; i <= n; i++)
    {
        if (ones[i] & 1)
            putchar('1');
        else
            putchar('0');
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", f[i]);
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", str + 1);
        solve();
    }
}