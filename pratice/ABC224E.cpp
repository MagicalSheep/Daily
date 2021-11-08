#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int H, W, N;
ll f[MAXN];
map<ll, vector<ll>> ma;
vector<ll> vv;
ll rmx[MAXN], cmx[MAXN];
pair<int, int> a[MAXN];

int main()
{
    scanf("%d%d%d", &H, &W, &N);
    for (int i = 1; i <= N; i++)
    {
        pair<int, int> pos;
        ll val;
        scanf("%d%d%lld", &a[i].first, &a[i].second, &val);
        ma[val].emplace_back(i);
        vv.emplace_back(val);
    }
    sort(vv.begin(), vv.end(), greater<ll>());
    auto end = unique(vv.begin(), vv.end());
    for (auto it = vv.begin(); it != end; ++it)
    {
        vector<ll> tmp = ma[*it];
        for (auto i : tmp)
            f[i] = max(rmx[a[i].first], cmx[a[i].second]);
        for (auto i : tmp)
        {
            rmx[a[i].first] = max(rmx[a[i].first], f[i] + 1);
            cmx[a[i].second] = max(cmx[a[i].second], f[i] + 1);
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%lld\n", f[i]);
    return 0;
}