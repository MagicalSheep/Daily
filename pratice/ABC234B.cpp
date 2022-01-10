#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<pair<int, int>> d;
int N;

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        d.emplace_back(pair<int, int>(x, y));
    }
    ll ans = 0;
    for (auto a : d)
        for (auto b : d)
            ans = max(ans, 1ll * (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    printf("%.10f\n", sqrt((double)ans));
    return 0;
}