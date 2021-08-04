#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int a[10 + 5];
        set<int> s;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < (1 << n); i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    sum += a[j];
            s.insert(sum);
        }
        printf((s.size() != (1 << n)) ? "YES\n" : "NO\n");
    }
    return 0;
}