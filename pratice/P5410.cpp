#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e7 + 5;

char a[MAXN], b[MAXN];
int la, lb, z1[MAXN], nex[MAXN], z2[MAXN];

void z_function(char *s, int n, int *z)
{
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r && z[i - l] < r - i + 1)
        {
            z[i] = z[i - l];
        }
        else
        {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

void p_function(char *s, int n, char *p, int m)
{
    z_function(p, m, nex);
    while (z2[0] < n && z2[0] < m && s[z2[0]] == p[z2[0]])
        ++z2[0];
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r && nex[i - l] < r - i + 1)
        {
            z2[i] = nex[i - l];
        }
        else
        {
            z2[i] = max(0, r - i + 1);
            while (i + z2[i] < n && z2[i] < m && s[i + z2[i]] == p[z2[i]])
                ++z2[i];
            if (i + z2[i] - 1 > r)
                l = i, r = i + z2[i] - 1;
        }
    }
}

ll func(int *z, int n)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= (1ll * (i + 1) * (z[i] + 1));
    return ans;
}

int main()
{
    scanf("%s%s", a, b);
    la = strlen(a);
    lb = strlen(b);
    z_function(b, lb, z1);
    p_function(a, la, b, lb);
    printf("%lld\n%lld\n", func(z1, lb), func(z2, la));
    return 0;
}