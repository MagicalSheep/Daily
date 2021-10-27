#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 512 + 10;

int n, a[MAXN], f[MAXM];
set<int> ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = min(f[a[i]], a[i]);
        for (int j = 0; j <= 512; j++)
            if (f[j] < a[i])
                f[j ^ a[i]] = min(f[j ^ a[i]], a[i]);
    }
    ans.insert(0);
    for (int i = 0; i <= 512; i++)
        if (f[i] != INF)
            ans.insert(i);
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}