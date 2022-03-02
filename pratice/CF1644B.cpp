#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            int num = n;
            for (int k = 1; k <= n; k++)
            {
                if (k == j)
                {
                    cout << "1 ";
                }
                else
                {
                    cout << num << " ";
                    --num;
                }
            }
            cout << endl;
        }
    }
    return 0;
}