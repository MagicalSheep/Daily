#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        a.clear();
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            int in;
            scanf("%d", &in);
            a.emplace_back(pair<int, int>(in, i));
        }
        sort(a.begin(), a.end());
        int cnt = 1;
        for (int i = 1; i < a.size(); i++)
            if (a[i].second - a[i - 1].second != 1)
                ++cnt;
        if (k >= cnt)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}