#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, f[26], vis[26], tot = 1;
vector<int> ans;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    fill(f, f + 26, 1);
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        vis[c] = 1;
        for (int j = c + 1; j < 26; j++)
            if (vis[j])
                f[c] = max(f[c], f[j] + 1);
        ans.emplace_back(f[c]);
        tot = max(tot, f[c]);
    }
    cout << tot << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}