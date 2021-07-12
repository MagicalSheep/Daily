#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll n, p1[MAXN], p2[MAXN], m[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p1[i];
    for (int i = 0; i < n; i++)
        cin >> p2[i];
    for (int i = 0; i < n; i++)
        m[p1[i]] = i;
    vector<ll> tmp, ans;
    for (int i = 0; i < n; i++)
        tmp.emplace_back(m[p2[i]]);
    ans.emplace_back(tmp[0]);
    for (int i = 1; i < (int)tmp.size(); i++)
    {
        if (ans.back() < tmp[i])
            ans.emplace_back(tmp[i]);
        else
            *lower_bound(ans.begin(), ans.end(), tmp[i]) = tmp[i];
    }
    cout << ans.size() << endl;
    return 0;
}