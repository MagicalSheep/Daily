#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

char s[MAXN];
int len;
int z[MAXN];

void z_function()
{
    z[0] = len;
    for (int i = 1, l = 0, r = 0; i < len; i++)
    {
        if (i <= r && z[i - l] < r - i + 1)
        {
            z[i] = z[i - l];
        }
        else
        {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < len && s[z[i]] == s[i + z[i]])
                ++z[i];
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main()
{
    scanf("%s", s);
    len = strlen(s);
    z_function();
    vector<int> tmp;
    vector<pair<int, int>> ans;
    for (int i = 0; i < len; i++)
        if (z[i] == len - i)
            tmp.emplace_back(i);
    sort(z, z + len);
    for (auto x : tmp)
    {
        int le = len - x;
        int ind = lower_bound(z, z + len, le) - z;
        ans.emplace_back(pair<int, int>(le, len - ind));
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d %d\n", x.first, x.second);
    return 0;
}