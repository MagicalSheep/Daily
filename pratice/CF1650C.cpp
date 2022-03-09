#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, m;
vector<pair<int, pair<int, int>>> ma; // <val, <pos, id>>
vector<pair<int, int>> vec;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ma.clear();
        vec.clear();
        scanf("%d%d", &n, &m);
        int x, w;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &w);
            ma.emplace_back(pair<int, pair<int, int>>(w, pair<int, int>(x, i)));
        }
        sort(ma.begin(), ma.end());
        int cnt = 0, sum = 0;
        for (auto v : ma)
        {
            vec.emplace_back(v.second);
            sum += v.first;
            ++cnt;
            if (cnt == (2 * n))
                break;
        }
        printf("%d\n", sum);
        sort(vec.begin(), vec.end());
        int len = vec.size() / 2;
        for (int i = 0; i < len; i++)
        {
            int r = vec.size() - i - 1;
            printf("%d %d\n", vec[i].second, vec[r].second);
        }
    }
    return 0;
}