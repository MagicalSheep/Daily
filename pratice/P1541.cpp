#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 350 + 10;

ll N, M, a[MAXN], b[MAXN], f[45][45][45][45];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= M; i++)
    {
        ll t = 0;
        cin >> t;
        b[t]++;
    }
    f[0][0][0][0] = a[1];
    for (int i = 0; i <= b[1]; i++)
    {
        for (int j = 0; j <= b[2]; j++)
        {
            for (int k = 0; k <= b[3]; k++)
            {
                for (int l = 0; l <= b[4]; l++)
                {
                    ll x = 1 + i + 2 * j + 3 * k + 4 * l;
                    ll tmp = 0;
                    if (i)
                        tmp = max(tmp, f[i - 1][j][k][l]);
                    if (j)
                        tmp = max(tmp, f[i][j - 1][k][l]);
                    if (k)
                        tmp = max(tmp, f[i][j][k - 1][l]);
                    if (l)
                        tmp = max(tmp, f[i][j][k][l - 1]);
                    f[i][j][k][l] = tmp + a[x];
                }
            }
        }
    }
    cout << f[b[1]][b[2]][b[3]][b[4]] << endl;
    return 0;
}