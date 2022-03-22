#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

int t, n, a[MAXN];

bool solve()
{
    ll ori = 0;
    unordered_map<int, int> cnt;
    priority_queue<ll> q, mq;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ori += 1ll * a[i];
        ++cnt[a[i]];
        mq.push(a[i]);
    }
    q.push(ori);
    while (!q.empty())
    {
        ll val = q.top();
        q.pop();
        if (val < mq.top())
            return false;
        if (!cnt[val])
        {
            ll r1 = val / 2;
            ll r2 = val - r1;
            q.push(r1);
            q.push(r2);
            continue;
        }
        ans.emplace_back(val);
        --cnt[val];
        if (val == mq.top())
            mq.pop();
    }
    if (ans.size() != n)
        return false;
    sort(a + 1, a + 1 + n);
    sort(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++)
        if (a[i] != ans[i - 1])
            return false;
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        printf(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}