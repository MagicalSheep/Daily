#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, len;
char x[MAXN];

void solve()
{
    int st = 0;
    for (int i = len - 2; i >= 0; i--)
    {
        int a = x[i] - '0';
        int b = x[i + 1] - '0';
        int sum = a + b;
        if (sum < 10)
            continue;
        st = i;
        break;
    }
    int a = x[st] - '0';
    int b = x[st + 1] - '0';
    int sum = a + b;
    string ans;
    b = sum % 10;
    a = sum / 10;
    for (int i = 0; i < len; i++)
    {
        if (i == st)
        {
            if (sum < 10)
                ans.push_back(b + '0');
            else
                ans.push_back(a + '0');
            continue;
        }
        if (i == st + 1)
        {
            if (sum < 10)
                continue;
            else
                ans.push_back(b + '0');
            continue;
        }
        ans.push_back(x[i]);
    }
    bool flag = true;
    for (int i = 0; i < ans.size(); i++)
    {
        if (flag && ans[i] == '0')
            continue;
        putchar(ans[i]);
        flag = false;
    }
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", x);
        len = strlen(x);
        solve();
    }
}