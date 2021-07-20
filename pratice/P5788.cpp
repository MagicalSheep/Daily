#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 10;

int a[MAXN], f[MAXN];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    stack<int> s;
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        f[i] = (s.empty()) ? 0 : s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    return 0;
}