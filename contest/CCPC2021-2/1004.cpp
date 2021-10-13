#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T, x;

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &x);
        if (x == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}