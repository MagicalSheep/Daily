#include <bits/stdc++.h>
using namespace std;

int t, k;
int ans[1000 + 10];

bool check(int i)
{
    if (i % 3 == 0)
        return false;
    if (i % 10 == 3)
        return false;
    return true;
}

int main()
{
    int ind = 0;
    for (int i = 1; i <= 2000; i++)
    {
        if (check(i))
            ans[++ind] = i;
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
    return 0;
}