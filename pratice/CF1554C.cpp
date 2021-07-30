#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int nn[30 + 5] = {0}, mm[30 + 5] = {0}, ans[30 + 5] = {0}, tmp = max(++m, n), nums = 0;
        do
        {
            tmp >>= 1;
            ++nums;
        } while (tmp);
        for (int i = nums; i >= 1; i--, m >>= 1, n >>= 1)
            mm[i] = m & 1, nn[i] = n & 1;
        for (int i = 1; i <= nums; i++)
        {
            if (mm[i] == 0 && nn[i] == 1)
                break;
            ans[i] = mm[i] ^ nn[i];
        }
        int ansnum = 0;
        for (int i = nums; i >= 1; i--)
            ansnum += pow(2, nums - i) * ans[i];
        printf("%d\n", ansnum);
    }
    return 0;
}