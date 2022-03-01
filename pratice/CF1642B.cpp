#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> vec;
        for (int i = 1; i <= n; i++)
        {
            int in;
            scanf("%d", &in);
            vec.emplace_back(in);
        }
        sort(vec.begin(), vec.end());
        int last = 0, cnt = 0;
        for (auto x : vec)
        {
            if (x == last)
                continue;
            last = x, ++cnt;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", (i <= cnt) ? cnt : i);
        printf("\n");
    }
    return 0;
}