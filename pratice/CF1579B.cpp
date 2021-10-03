#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, n;

struct obj
{
    int idx, val, id;
} a[MAXN];

bool cmp1(obj x, obj y) { return x.val < y.val; }
bool cmp2(obj x, obj y) { return x.idx < y.idx; }

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        vector<pair<pair<int, int>, int>> ans;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].val), a[i].idx = i;
        sort(a + 1, a + 1 + n, cmp1);
        for (int i = 1; i <= n; i++)
            a[i].id = i;
        sort(a + 1, a + 1 + n, cmp2);
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[j].id == i)
                {
                    if (a[j].idx != i)
                    {
                        ans.emplace_back(pair<pair<int, int>, int>(pair<int, int>(i, a[j].idx), a[j].idx - i));
                        obj temp = a[j];
                        temp.idx = a[i].idx;
                        for (int k = a[j].idx; k > i; k--)
                            a[k] = a[k - 1], a[k].idx++;
                        a[i] = temp;
                    }
                    break;
                }
            }
        }
        printf("%d\n", ans.size());
        for (auto x : ans)
            printf("%d %d %d\n", x.first.first, x.first.second, x.second);
    }
    return 0;
}