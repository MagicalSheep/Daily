#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int t, n;
vector<pair<int, int>> vec, p;

bool check(int x, int y)
{
    for (auto v : p)
    {
        if ((v.first == x) || (v.second == y) ||
            (abs(v.first - x) == abs(v.second - y)))
            continue;
        return false;
    }
    return true;
}

bool solve(vector<pair<int, int>> &p)
{
    pair<int, int> point = p.front();
    bool flag = true;
    for (auto u : p)
    {
        if (u.first == point.first)
            continue;
        flag = false;
        if (check(point.first, u.second) ||
            check(point.first, u.second - (point.first - u.first)) ||
            check(point.first, u.second + (point.first - u.first)))
            return true;
        break;
    }
    return flag;
}

bool func()
{
    for (auto v : vec)
        p.emplace_back(pair<int, int>(v.first, v.second));
    if (solve(p))
        return true;
    p.clear();
    for (auto v : vec)
        p.emplace_back(pair<int, int>(v.second, v.first));
    if (solve(p))
        return true;
    p.clear();
    for (auto v : vec)
        p.emplace_back(pair<int, int>(v.first + v.second, v.first - v.second));
    if (solve(p))
        return true;
    p.clear();
    for (auto v : vec)
        p.emplace_back(pair<int, int>(v.first - v.second, v.first + v.second));
    if (solve(p))
        return true;
    return false;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        vec.clear(), p.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            vec.emplace_back(pair<int, int>(x, y));
        }
        if (func())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}