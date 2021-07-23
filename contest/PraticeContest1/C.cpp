#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int N;

int main()
{
    scanf("%d", &N);
    char str[MAXN];
    scanf("%s", str);
    str[N] = str[N - 1];
    int ptr = 1;
    bool isok = false;
    if (str[0] != str[N - 1])
    {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i < N; i++)
    {
        if (str[i] == str[0])
            continue;
        if (str[i + 1] != str[N - 1])
        {
            isok = true;
            break;
        }
    }
    if (isok)
        printf("2\n");
    else
        printf("-1\n");
    return 0;
}