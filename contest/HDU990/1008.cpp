#include <bits/stdc++.h>
using namespace std;

int T;
int x, y, d;
string ans;

inline void print(int num, char c)
{
    for (int i = 1; i <= num; i++)
        ans.push_back(c);
}

void go(int fx, int fy)
{
    int forwardy = abs(y - fy), forwardx = abs(x - fx);
    if (fx < x && fy > y)
    {
        if (d == 2)
            ans.push_back('c'), d = 3;
        else if (d == 1)
            ans.push_back('u'), d = 0;
        if (d == 3)
            print(forwardx, 'f'), x -= forwardx;
        else if (d == 0)
            print(forwardy, 'f'), y += forwardy;
    }
    else if (fx > x && fy > y)
    {
        if (d == 3)
            ans.push_back('c'), d = 0;
        else if (d == 2)
            ans.push_back('u'), d = 1;
        if (d == 0)
            print(forwardy, 'f'), y += forwardy;
        else if (d == 1)
            print(forwardx, 'f'), x += forwardx;
    }
    else if (fx < x && fy < y)
    {
        if (d == 1)
            ans.push_back('c'), d = 2;
        else if (d == 0)
            ans.push_back('u'), d = 3;
        if (d == 2)
            print(forwardy, 'f'), y -= forwardy;
        else if (d == 3)
            print(forwardx, 'f'), x -= forwardx;
    }
    else if (fx > x && fy < y)
    {
        if (d == 0)
            ans.push_back('c'), d = 1;
        else if (d == 3)
            ans.push_back('u'), d = 2;
        if (d == 1)
            print(forwardx, 'f'), x += forwardx;
        else if (d == 2)
            print(forwardy, 'f'), y -= forwardy;
    }
    else if (fx == x && fy > y)
    {
        if (d == 3)
            ans.push_back('c'), d = 0;
        else if (d == 1)
            ans.push_back('u'), d = 0;
        print(forwardy, 'f');
        y += forwardy;
    }
    else if (fx == x && fy < y)
    {
        if (d == 3)
            ans.push_back('u'), d = 2;
        else if (d == 1)
            ans.push_back('c'), d = 2;
        print(forwardy, 'f');
        y -= forwardy;
    }
    else if (fy == y && fx > x)
    {
        if (d == 0)
            ans.push_back('c'), d = 1;
        else if (d == 2)
            ans.push_back('u'), d = 1;
        print(forwardx, 'f');
        x += forwardx;
    }
    else if (fy == y && fx < x)
    {
        if (d == 0)
            ans.push_back('u'), d = 3;
        else if (d == 2)
            ans.push_back('c'), d = 3;
        print(forwardx, 'f');
        x -= forwardx;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        ans.clear();
        cin >> x >> y >> d;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int fx, fy;
            cin >> fx >> fy;
            go(fx, fy);
            go(fx, fy);
        }
        cout << ans << endl;
    }
    return 0;
}