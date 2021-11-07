#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int N;
set<vector<int>> ma;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int len;
        scanf("%d", &len);
        vector<int> tmp;
        for (int j = 0; j < len; j++)
        {
            int in;
            scanf("%d", &in);
            tmp.emplace_back(in);
        }
        ma.insert(tmp);
    }
    printf("%d\n", ma.size());
    return 0;
}