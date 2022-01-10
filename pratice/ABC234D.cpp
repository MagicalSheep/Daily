#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int N, K;
pair<int, int> s[MAXN], d[MAXN];

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        int in;
        scanf("%d", &in);
        s[i].first = d[i].first = in;
        s[i].second = d[i].second = i;
    }
    sort(d + 1, d + 1 + K);
    int p = d[1].first;
    printf("%d\n", p);
    sort(d + 1, d + 1 + N);
    for (int i = K + 1; i <= N; i++)
    {
        if (s[i].first > p)
        {
            for (int j = p + 1; j <= N; j++)
            {
                if (d[j].second > i)
                    continue;
                p = j;
                break;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}