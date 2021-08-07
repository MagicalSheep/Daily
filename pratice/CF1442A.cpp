#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        bool isok = true;
        int dec = 0x3f3f3f3f, inc = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            if (!isok)
                continue;
            dec = min(dec, a - inc);
            inc = a - dec;
            if (inc < 0 || dec < 0)
                isok = false;
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}