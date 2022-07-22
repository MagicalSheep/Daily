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
        for (auto c : s)
        {
            if (c == 's' || c == 't' || c == 'd' || c == ':' || c == 'm' || c == 'a' || c == 'k' || c == 'e' || c == '_' || c == 'u' || c == 'p' || c == 'l' || c == 'e')
                continue;
            cout << c;
        }
        cout << endl;
    }
    return 0;
}