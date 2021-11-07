#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;

int N;
pair<int, int> pos[MAXN];
set<pair<int, int>> ans;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &pos[i].first, &pos[i].second);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            pair<int, int> tt;
            tt.first = pos[i].first - pos[j].first;
            tt.second = pos[i].second - pos[j].second;
            int tmp = __gcd(tt.first, tt.second);
            tt.first /= tmp;
            tt.second /= tmp;
            ans.insert(tt);
            tt.first = -tt.first;
            tt.second = -tt.second;
            ans.insert(tt);
        }
    }
    printf("%d\n", ans.size());
    return 0;
}