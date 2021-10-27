#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXM = 1 << 13;

int n, f[MAXM];
vector<int> t[MAXM];
set<int> a, ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int in;
        scanf("%d", &in);
        a.insert(in);
        t[in].emplace_back(i);
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (auto j : a)
    {
        for (int i = 1; i < MAXM; i++)
        {
            auto pos = upper_bound(t[j].begin(), t[j].end(), f[i ^ j]);
            if (pos != t[j].end())
                f[i] = min(f[i], (*pos));
        }
    }
    for (int i = 0; i < MAXM; i++)
        if (f[i] != INF)
            ans.insert(i);
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}