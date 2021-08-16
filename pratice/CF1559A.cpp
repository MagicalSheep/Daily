#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n, in;
        scanf("%d", &n);
        int ans = 1073741823;
        for (int i = 1; i <= n;i++)
            scanf("%d", &in), ans &= in;
        printf("%d\n", ans);
    }
    return 0;
}