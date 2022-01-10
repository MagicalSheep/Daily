#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int t, n;
string s;
string ss[] = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int ans = -1;
        for (int i = 0; i < 7; i++)
        {
            if (s.find(ss[i]) != string::npos)
            {
                ans = ss[i].size();
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}