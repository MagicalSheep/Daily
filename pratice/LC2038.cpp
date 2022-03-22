#include <bits/stdc++.h>
using namespace std;

auto speedup = []
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int a = 0, b = 0, cnt = 1;
        char last = colors[0];
        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] == last)
            {
                ++cnt;
                continue;
            }
            if (last == 'A')
                a += max(0, cnt - 2);
            else
                b += max(0, cnt - 2);
            cnt = 1;
            last = colors[i];
        }
        if (last == 'A')
            a += max(0, cnt - 2);
        else
            b += max(0, cnt - 2);
        return a > b;
    }
};