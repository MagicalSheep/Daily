#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll X, Y, V[5];

bool check(ll x, ll y, ll a, ll b)
{
    bool res1 = true, res2 = true;
    ll yy = (a - 1) / x + 1;
    if (yy >= y || (y - yy) * x < b)
        res1 = false;
    ll xx = (a - 1) / y + 1;
    if (xx >= x || (x - xx) * y < b)
        res2 = false;
    return res1 || res2;
}

int main()
{
    scanf("%lld%lld%lld%lld%lld", &X, &Y, &V[1], &V[2], &V[3]);
    bool isok = false;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (check(X, Y, V[i], V[j]))
                {
                    ll yy = (V[i] - 1) / X + 1;
                    if (yy < Y && check(X, Y - yy, V[j], V[k]))
                        isok = true;
                    ll xx = (V[i] - 1) / Y + 1;
                    if (xx < X && check(X - xx, Y, V[j], V[k]))
                        isok = true;
                }
            }
        }
    }
    printf((isok) ? "Yes\n" : "No\n");
    return 0;
}