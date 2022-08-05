#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;
pair<double, double> A, B, C, D, a, b, c, d;
pair<double, double> aM, bM, cM, dM;
double cd, da, CD, DA, k, k1, k2, k3, k4;
double kk1, kk2, kk3, kk4;

inline double distance(pair<double, double> &pos1, pair<double, double> &pos2)
{
    return sqrt((pos1.first - pos2.first) * (pos1.first - pos2.first) + (pos1.second - pos2.second) * (pos1.second - pos2.second));
}

pair<double, double> trans(pair<double, double> &Mpos)
{
    pair<double, double> ret;
    ret.first = D.first + kk1 * Mpos.first + kk2 * Mpos.second;
    ret.second = D.second + kk3 * Mpos.first + kk4 * Mpos.second;
    return ret;
}

pair<double, double> transM(pair<double, double> &pos)
{
    pair<double, double> ret;
    if (kk2 == 0)
    {
        ret.first = (pos.first - D.first) / kk1;
        ret.second = (pos.second - D.second) / kk4;
    }
    else
    {
        double t1 = pos.second - D.second - (kk4 * (pos.first - D.first)) / kk2;
        double t2 = kk3 - (kk1 * kk4) / kk2;
        ret.first = t1 / t2;
        ret.second = (pos.first - D.first - kk1 * ret.first) / kk2;
    }
    return ret;
}

void prework()
{
    cd = distance(c, d);
    da = distance(d, a);
    CD = distance(C, D);
    DA = distance(D, A);
    kk1 = (C.first - D.first) / CD;
    kk2 = (A.first - D.first) / DA;
    kk3 = (C.second - D.second) / CD;
    kk4 = (A.second - D.second) / DA;
    aM = transM(a);
    bM = transM(b);
    cM = transM(c);
    dM = transM(d);
    k = cd / CD;
    k1 = (cM.first - dM.first) / cd;
    k2 = (aM.first - dM.first) / da;
    k3 = (cM.second - dM.second) / cd;
    k4 = (aM.second - dM.second) / da;
}

void solve()
{
    double t1 = dM.second * (1 - k1 * k) + k3 * k * dM.first;
    double t2 = (1 - k4 * k) * (1 - k1 * k) - k3 * k2 * k * k;
    pair<double, double> ans;
    ans.second = t1 / t2;
    ans.first = (dM.first + k2 * k * ans.second) / (1 - k1 * k);
    ans = trans(ans);
    printf("%.6f %.6f\n", ans.first, ans.second);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf", &A.first, &A.second);
        scanf("%lf%lf", &B.first, &B.second);
        scanf("%lf%lf", &C.first, &C.second);
        scanf("%lf%lf", &D.first, &D.second);
        scanf("%lf%lf", &a.first, &a.second);
        scanf("%lf%lf", &b.first, &b.second);
        scanf("%lf%lf", &c.first, &c.second);
        scanf("%lf%lf", &d.first, &d.second);
        prework();
        solve();
    }
    return 0;
}