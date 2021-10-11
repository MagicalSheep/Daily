#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, x, ans;
string s;

int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
        s.append(to_string(i));
    for (auto c : s)
        if (c - '0' == x)
            ++ans;
    printf("%d\n", ans);
    return 0;
}