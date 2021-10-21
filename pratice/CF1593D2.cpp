#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40 + 5;

int t, n, a[MAXN], k;

set<int> divs(int x)
{
    set<int> ret;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
            ret.insert(x / i), ret.insert(i);
    return ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        k = -1;
        for (int i = 1; i <= n; i++)
        {
            int same = 0;
            vector<int> tt;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] < a[i])
                    continue;
                if (a[j] == a[i])
                {
                    ++same;
                    continue;
                }
                tt.emplace_back(a[j] - a[i]);
            }
            if (same >= n / 2)
            {
                k = INT_MAX;
                continue;
            }
            map<int, int> count;
            for (auto x : tt)
                for (auto y : divs(x))
                    count[y]++;
            for (auto x : count)
                if (x.second >= n / 2 - same)
                    k = max(k, x.first);
        }
        printf("%d\n", (k == INT_MAX) ? -1 : k);
    }
    return 0;
}