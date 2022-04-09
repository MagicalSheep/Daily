#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> aans(32769);
map<int, int> ma;

int main()
{
    for (int i = 0; i < 32768; i++)
    {
        bool flag = false;
        for (int j = 0; j < 15; j++)
        {
            if ((i * (1 << j)) % 32768 == 0)
            {
                ma[i] = j;
                flag = true;
                break;
            }
        }
        if (!flag)
            ma[i] = 0x3f3f3f3f;
    }
    ma[32768] = 0;
    ma[1] = 15;
    aans[32768] = 0;
    for (int i = 32767; i >= 0; i--)
        aans[i] = min(ma[i], aans[i + 1] + 1);
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        printf("%d ", aans[a[i]]);
    printf("\n");
    return 0;
}