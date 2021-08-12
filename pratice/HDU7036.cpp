#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ll n, mn, mx, ave;
        scanf("%lld%lld%lld%lld", &n, &mx, &mn, &ave);
        if (mn > mx)
        {
            printf("no\n");
            continue;
        }
        ll mn2 = (n - 1) * mn + mx;
        ll mx2 = (n - 1) * mx + mn;
        if (ave * n >= mn2 && ave * n <= mx2)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}