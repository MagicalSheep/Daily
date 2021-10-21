#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld %lld\n", 1 - n, n);
    }
    return 0;
}