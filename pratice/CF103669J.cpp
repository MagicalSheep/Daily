#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, p, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> p >> k;
        if (k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        ll highest = 0, tmp = p - 1;
        ll ones = 0;
        while (tmp)
        {
            ++highest;
            if (tmp & 1)
                ++ones;
            tmp >>= 1;
        }
        if (highest + ones - 1 <= k)
        {
            cout << p - 1 << endl;
            continue;
        }
        if (k <= highest)
        {
            cout << (1LL << (k - 1)) << endl;
            continue;
        }
        ll cnt = (ones - 1) - (k - highest), oft = 0;
        tmp = p - 1;
        while (tmp)
        {
            if (tmp & 1)
            {
                --cnt;
                if (cnt == 0)
                {
                    tmp >>= 1;
                    tmp <<= (1 + oft);
                    break;
                }
            }
            tmp >>= 1;
            ++oft;
        }
        cout << tmp << endl;
    }
    return 0;
}