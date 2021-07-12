#include <bits/stdc++.h>
using namespace std;

int n, m, a[100 + 10], f[100 + 10];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= min(a[i], j); k++)
                f[j] = (f[j] + f[j - k]) % 1000007;
    cout << f[m] << endl;
    return 0;
}