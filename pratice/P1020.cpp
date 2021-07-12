#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> a;

int main()
{
    ll tmp = 0;
    while (cin >> tmp)
        a.emplace_back(tmp);
    int len = a.size();
    vector<ll> aa1;
    aa1.emplace_back(a[0]);
    for (int i = 1; i < len; i++)
    {
        if (aa1.back() >= a[i])
            aa1.emplace_back(a[i]);
        else
            *upper_bound(aa1.begin(), aa1.end(), a[i], greater<ll>()) = a[i];
    }
    cout << aa1.size() << endl;
    vector<ll> aa2;
    aa2.emplace_back(a[0]);
    for (int i = 1; i < len; i++)
    {
        if(aa2.back() < a[i])
            aa2.emplace_back(a[i]);
        else
            *lower_bound(aa2.begin(), aa2.end(), a[i]) = a[i];
    }
    cout << aa2.size() << endl;
    return 0;
}