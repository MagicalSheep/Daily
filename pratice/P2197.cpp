#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int n, ans = 0, in;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &in), ans ^= in;
        printf((ans) ? "Yes\n" : "No\n");
    }
    return 0;
}