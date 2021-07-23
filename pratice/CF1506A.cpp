#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ll n, m, x;
        scanf("%lld%lld%lld", &n, &m, &x);
        int row = ((x % n) == 0) ? n : x % n;
        int col = (x - 1) / n + 1;
        printf("%lld\n", (row - 1) * m + col);
    }
    return 0;
}