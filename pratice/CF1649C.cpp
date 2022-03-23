#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

int n, m;
vector<pair<int, int>> group[MAXN];
set<int> cs;

ll solve(vector<pair<int, int>> &gr)
{
    ll ret = 0;
    int k = gr.size();
    sort(gr.begin(), gr.end());
    vector<ll> sum(k + 5);
    for (int i = k - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + gr[i].first;
    for (int i = 0; i < k - 1; i++)
        ret += sum[i + 1] - 1ll * (k - i - 1) * gr[i].first;
    auto cmp = [](pair<int, int> x, pair<int, int> y) -> bool
    {
        return x.second < y.second;
    };
    sort(gr.begin(), gr.end(), cmp);
    for (int i = k - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + gr[i].second;
    for (int i = 0; i < k - 1; i++)
        ret += sum[i + 1] - 1ll * (k - i - 1) * gr[i].second;
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int c;
            scanf("%d", &c);
            cs.insert(c);
            group[c].emplace_back(pair<int, int>(i, j));
        }
    }
    ll ans = 0;
    for (auto c : cs)
        ans += solve(group[c]);
    printf("%lld\n", ans);
    return 0;
}