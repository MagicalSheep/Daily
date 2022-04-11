#include <bits/stdc++.h>
using namespace std;

int n, ans;

struct Product
{
    int id, a, b;
};

int main()
{
    cin >> n;
    vector<struct Product> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].a, vec[i].id = i + 1;
    for (int i = 0; i < n; i++)
        cin >> vec[i].b;
    auto cmp = [](const struct Product &x, const struct Product &y) -> bool
    {
        if (min(x.a, y.b) == min(y.a, x.b))
            return x.a < y.a;
        return min(x.a, y.b) < min(y.a, x.b);
    };
    sort(vec.begin(), vec.end(), cmp);
    int sum = 0;
    for (auto x : vec)
    {
        sum += x.a;
        if (ans < sum)
            ans += (sum - ans);
        ans += x.b;
    }
    cout << ans << endl;
    for (auto x : vec)
        cout << x.id << " ";
    cout << endl;
    return 0;
}