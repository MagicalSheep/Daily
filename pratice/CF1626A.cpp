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
        sort(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}