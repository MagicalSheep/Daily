#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll x;

ll func(int lea, int nex, int num)
{
    int del = nex - lea;
    string val;
    val.push_back('0' + lea);
    val.push_back('0' + nex);
    int last = nex;
    for (int i = 3; i <= num; i++)
    {
        if (last + del > 9 || last + del < 0)
            return -1;
        last += del;
        val.push_back('0' + last);
    }
    return stoll(val);
}

int main()
{
    scanf("%lld", &x);
    string str = to_string(x);
    int num = str.length();
    if (num == 1 || num == 2)
    {
        printf("%lld\n", x);
        return 0;
    }
    int lea = str[0] - '0';
    ll ans = 0;
    for (int i = lea; i <= lea + 1; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ll tmp = func(i, j, num);
            if (tmp >= x)
            {
                if (ans == 0)
                    ans = tmp;
                else
                    ans = min(ans, tmp);
                goto end;
            }
        }
    }
end:
    printf("%lld\n", ans);
    return 0;
}