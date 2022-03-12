// #include <bits/stdc++.h>
// using namespace std;

// int t;

// int main()
// {
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int remain = n % 3;
//         int cnt = n / 3;
//         string ans;
//         if (n == 1)
//         {
//             cout << "1" << endl;
//             continue;
//         }
//         if (n == 2)
//         {
//             cout << "2" << endl;
//             continue;
//         }
//         if (n == 3)
//         {
//             cout << "21" << endl;
//             continue;
//         }
//         if (n & 1)
//         {
//             for (int i = 1; i <= cnt; i++)
//                 ans.append("12");
//             if (remain == 1)
//                 ans.append("1");
//             else if (remain == 2)
//                 cout << "2";
//             cout << ans << endl;
//         }
//         else
//         {
//             for (int i = 1; i <= cnt; i++)
//                 ans.append("21");
//             if (remain == 1)
//                 cout << "1";
//             else if (remain == 2)
//                 ans.append("2");
//             cout << ans << endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int t;

void solve()
{
    int n, now = 2;
    cin >> n;
    string res;
    if (n % 3 == 1)
        now = 1;
    while (n)
    {
        if (now & 1)
            res.push_back('1');
        else
            res.push_back('2');
        n -= now;
        now = ((now == 1) ? 2 : 1);
    }
    cout << res << endl;
}

int main()
{
    cin >> t;
    while (t--)
        solve();
    return 0;
}
