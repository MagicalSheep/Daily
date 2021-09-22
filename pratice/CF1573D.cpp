#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, a[MAXN], sum[MAXN];

void solve(int l, int r, vector<int> &ans)
{
    for (int i = l; i <= r - 2; i += 2)
        ans.emplace_back(i);
    for (int i = r - 4; i >= l; i -= 2)
        ans.emplace_back(i);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum[i] = sum[i - 1] ^ a[i];
        if (n & 1)
        {
            if (!(sum[n] & 1))
            {
                printf("YES\n");
                vector<int> ans;
                solve(1, n, ans);
                printf("%d\n", ans.size());
                for (auto x : ans)
                    printf("%d ", x);
                printf("\n");
            }
            else
            {
                printf("NO\n");
            }
            continue;
        }
        for (int i = 1; i < n; i += 2)
        {
            if (!(sum[i] & 1) && !((sum[n] ^ sum[i]) & 1))
            {
                printf("YES\n");
                vector<int> ans;
                solve(1, i, ans), solve(i + 1, n, ans);
                printf("%d\n", ans.size());
                for (auto x : ans)
                    printf("%d ", x);
                printf("\n");
                goto end;
            }
        }
        printf("NO\n");
    end:;
    }
    return 0;
}