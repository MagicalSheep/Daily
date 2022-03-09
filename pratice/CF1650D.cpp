#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;

int t, n, in, id[MAXN];

void solve()
{
    vector<int> real_ans;
    for (int i = n; i >= 1; i--)
    {
        int ans = 0;
        if (id[i] >= i)
            ans = id[i] - i;
        else
            ans = i + id[i] - i;
        for (int j = 1; j <= i; j++)
        {
            id[j] -= ans;
            if (id[j] <= 0)
                id[j] += i;
        }
        real_ans.emplace_back(ans);
    }
    for (int i = real_ans.size() - 1; i >= 0; i--)
        printf("%d ", real_ans[i]);
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &in), id[in] = i;
        solve();
    }
    return 0;
}