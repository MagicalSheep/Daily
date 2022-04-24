#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, vercnt, edgcnt, ans = 1;
string s;
map<pair<ll, ll>, ll> verid, edgid;
unordered_map<ll, bool> ver, edg;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    pair<ll, ll> cur = pair<ll, ll>(0, 0);
    verid[cur] = ++vercnt;
    ver[vercnt] = true;
    for (auto c : s)
    {
        pair<ll, ll> nexv;
        if (c == 'U')
        {
            nexv.first = cur.first;
            nexv.second = cur.second + 1;
        }
        else if (c == 'D')
        {
            nexv.first = cur.first;
            nexv.second = cur.second - 1;
        }
        else if (c == 'R')
        {
            nexv.first = cur.first + 1;
            nexv.second = cur.second;
        }
        else
        {
            nexv.first = cur.first - 1;
            nexv.second = cur.second;
        }
        if (!verid.count(nexv))
            verid[nexv] = ++vercnt, ver[vercnt] = false;
        pair<ll, ll> ne = pair<ll, ll>(verid[cur], verid[nexv]);
        pair<ll, ll> ne2 = pair<ll, ll>(ne.second, ne.first);
        if (!edgid.count(ne))
            edgid[ne] = ++edgcnt, edg[edgcnt] = false;
        edgid[ne2] = edgid[ne];
        if (ver[verid[nexv]] && !edg[edgid[ne]])
            ++ans;
        ver[verid[nexv]] = true;
        edg[edgid[ne]] = true;
        cur = nexv;
    }
    cout << ans << endl;
    return 0;
}