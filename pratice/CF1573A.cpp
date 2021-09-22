#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
char nums[105];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        scanf("%s", nums + 1);
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] == '0')
                continue;
            if (i != n)
                ans += nums[i] - '0' + 1;
            else
                ans += nums[i] - '0';
        }
        printf("%d\n", ans);
    }
    return 0;
}