#include <bits/stdc++.h>
using namespace std;

int t;
string s;
char c;

bool solve()
{
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if ((s[i] == c) && ((i + 1) & 1))
            return true;
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> c;
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}