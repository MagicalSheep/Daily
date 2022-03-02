#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int r = 0, g = 0, b = 0;
        bool isok = true;
        for (auto c : s)
        {
            if (c == 'r')
                ++r;
            else if (c == 'g')
                ++g;
            else if (c == 'b')
                ++b;

            if ((c == 'R' && r == 0) || (c == 'G' && g == 0) || (c == 'B' && b == 0))
            {
                isok = false;
                break;
            }
        }
        cout << ((isok) ? "YES" : "NO") << endl;
    }
    return 0;
}