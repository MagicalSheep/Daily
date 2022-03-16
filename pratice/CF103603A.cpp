#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, s[MAXN], t;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    scanf("%d", &t);
    sort(s + 1, s + 1 + n);
    int ans = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = s[i] / t + 1;
        if (last != tmp)
            ++ans;
        last = tmp;
    }
    printf("%d\n", ans);
    return 0;
}