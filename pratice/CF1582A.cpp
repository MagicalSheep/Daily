#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a = a % 2;
        b = b % 2;
        c = c % 2;
        if ((a == 0 && b == 0 && c == 0) || (a == 0 && b == 1 && c == 0) || (a == 1 && b == 0 && c == 1) || (a == 1 && b == 1 && c == 1))
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}