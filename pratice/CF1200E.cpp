#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n - 1];
}

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string ans;
    cin >> ans;
    for (int i = 2; i <= n; i++)
    {
        string str, tmp;
        cin >> str;
        int s_size = str.size();
        int a_size = ans.size();
        int l = min(s_size, a_size);
        if (s_size >= a_size)
            tmp = str.substr(0, l) + "#" + ans;
        else
            tmp = str + "#" + ans.substr(a_size - l, l);
        int len = prefix_function(tmp);
        for (int j = len; j < s_size; j++)
            ans.push_back(str[j]);
    }
    cout << ans << endl;
    return 0;
}