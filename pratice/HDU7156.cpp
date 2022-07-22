#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<int, int>> vec;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        vec.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            vec.emplace_back(pair<int, int>(x, y));
        }
        int ans = 0;
        bool flag = true;
        sort(vec.begin(), vec.end());
        pair<int, int> last = vec.front();
        for (int i = 1; i < vec.size(); i++)
        {
            auto v = vec[i];
            if (v.first > last.second)
            {
                last = v;
                ++ans;
                continue;
            }
            flag = false;
            break;
        }
        if (flag)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}