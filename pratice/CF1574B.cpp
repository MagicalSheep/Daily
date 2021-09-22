#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, m;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &m);
        int mx = a + b + c - 3;
        int mmx = max(a, max(b, c));
        int mmn = min(a, min(b, c));
        int mid = a + b + c - mmx - mmn;
        int mn = 0;
    be:
        if (mmn + mid < mmx - 1)
        {
            mn = mmx - 1 - mmn - mid;
        }
        else if (mmn + mid >= mmx - 1 && mmn + mid <= mmx + 1)
        {
            mn = 0;
        }
        else
        {
            int tmp = mmn + mid - mmx - 1;
            if (tmp & 1)
                ++tmp;
            tmp /= 2;
            mmn -= tmp;
            mid -= tmp;
            goto be;
        }
        if (mx >= m && mn <= m)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}