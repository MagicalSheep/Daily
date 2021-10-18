#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t, a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d ", max(0, max(b, c) + 1 - a));
        printf("%d ", max(0, max(a, c) + 1 - b));
        printf("%d\n", max(0, max(a, b) + 1 - c));
    }
    return 0;
}