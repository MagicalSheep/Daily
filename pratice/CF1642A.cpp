#include <bits/stdc++.h>
using namespace std;

int t, x, y;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < 3; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            vec.emplace_back(pair<int, int>(x, y));
        }
        int line = 0, ans = 0;
        if (vec[0].second == vec[1].second)
            line = vec[2].second - vec[0].second, ans = abs(vec[0].first - vec[1].first);
        else if (vec[0].second == vec[2].second)
            line = vec[1].second - vec[0].second, ans = abs(vec[0].first - vec[2].first);
        else if (vec[1].second == vec[2].second)
            line = vec[0].second - vec[1].second, ans = abs(vec[1].first - vec[2].first);
        else
            line = 2;
        printf("%d\n", (line > 0) ? 0 : ans);
    }
    return 0;
}