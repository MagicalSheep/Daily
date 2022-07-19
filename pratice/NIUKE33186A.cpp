#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;

ll n, ans;
pair<ll, ll> b[MAXN], seg[MAXN];
vector<pair<ll, ll>> vec;

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &b[i].first, &b[i].second);
        seg[i].first = b[i].first - b[i].second;
        seg[i].second = b[i].first + b[i].second;
    }
    sort(seg + 1, seg + 1 + n);
    pair<ll, ll> tmp = seg[1];
    for (int i = 2; i <= n; i++)
    {
        if (tmp.first == seg[i].first || seg[i].first <= tmp.second)
            tmp.second = max(tmp.second, seg[i].second);
        else
            vec.emplace_back(tmp), tmp = seg[i];
    }
    vec.emplace_back(tmp);
    for (int i = 0; i < vec.size() - 1; i++)
        ans += vec[i + 1].first - vec[i].second;
    printf("%lld\n", ans);
    return 0;
}