#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll f(ll t)
{
    return t * t + 2 * t + 3;
}

int x;

int main()
{
    scanf("%lld", &x);
    printf("%lld\n", f(f(f(x) + x) + f(f(x))));
    return 0;
}