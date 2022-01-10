#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll K;

ll fpow(ll a, ll n)
{
    if (n == 0)
        return 1;
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main()
{
    cin >> K;
    ll num = 63;
    for (ll i = 1; i < 63; i++)
    {
        if (fpow(2, i) - 1 >= K)
        {
            num = i;
            break;
        }
    }
    ll d = K - fpow(2, num - 1);
    string ans;
    for (int i = 1; i < num; i++)
    {
        if (d & 1)
            ans.push_back('2');
        else
            ans.push_back('0');
        d >>= 1ll;
    }
    reverse(ans.begin(), ans.end());
    cout << "2" << ans << endl;
    return 0;
}