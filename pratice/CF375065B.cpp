#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int len = 1 << n;
    int cnt;
    if (n == 1)
        cnt = 1;
    else if (n <= 3)
        cnt = 2;
    else if (n <= 6)
        cnt = 4;
    else if (n <= 11)
        cnt = 8;
    else
        cnt = 16;
    string ans;
    for (int i = 0, curlen = 0; curlen < len; i++, curlen += cnt)
        for (int j = cnt - 1; j >= 0; j--)
            ans.push_back(((i >> j) & 1) + '0');
    cout << ans << endl;
    return 0;
}