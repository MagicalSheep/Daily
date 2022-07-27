#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vector<vector<int>> vec(n + 1);
        int s = ceil(sqrt(n));
        int ss = ceil(1.0 * n / s);
        int base = 1;
        for (int i = 1; i <= ss; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (base + j > n)
                    continue;
                vec[i].emplace_back(base + j);
            }
            base += s;
        }
        for (int i = vec.size() - 1; i >= 0; i--)
            for (auto v : vec[i])
                printf("%d ", v);
        printf("\n");
    }
    return 0;
}