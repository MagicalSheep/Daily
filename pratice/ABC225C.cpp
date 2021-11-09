#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e4 + 10;

ll N, M, B[MAXN][10];

ll calc_val(pair<ll, ll> pos)
{
    return (pos.first - 1) * 7 + pos.second;
}

pair<ll, ll> calc_pos(ll val)
{
    pair<ll, ll> ret;
    ret.first = (val - 1) / 7 + 1;
    ret.second = val % 7;
    if (ret.second == 0)
        ret.second = 7;
    return ret;
}

int main()
{
    scanf("%lld%lld", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%lld", &B[i][j]);
    pair<ll, ll> st = calc_pos(B[1][1]);
    pair<ll, ll> ed;
    ed.first = st.first + N - 1;
    ed.second = st.second + M - 1;
    if (st.first < 1 || st.second < 1 || st.second > 7 || ed.first < 1 || ed.second < 1 || ed.second > 7)
    {
        printf("No\n");
        return 0;
    }
    bool isok = true;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            pair<ll, ll> pos;
            pos.first = st.first + i - 1;
            pos.second = st.second + j - 1;
            if (calc_val(pos) != B[i][j])
            {
                isok = false;
                goto end;
            }
        }
    }
end:
    printf((isok) ? "Yes\n" : "No\n");
    return 0;
}