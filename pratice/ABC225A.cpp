#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> ss;
    for (auto c : s)
        ss.insert(c);
    if (ss.size() == 1)
        cout << "1" << endl;
    else if (ss.size() == 2)
        cout << "3" << endl;
    else
        cout << "6" << endl;
    return 0;
}