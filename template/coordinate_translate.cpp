#include <bits/stdc++.h>
using namespace std;

struct coordinate
{
    pair<double, double> origin, ex, ey;
};

struct coordinate_trans
{
    coordinate base, another;
    double k1, k2, k3, k4;

    void init()
    {
        double axl = sqrt(another.ex.first * another.ex.first + another.ex.second * another.ex.second);
        double ayl = sqrt(another.ey.first * another.ey.first + another.ey.second * another.ey.second);
        k1 = another.ex.first / axl;
        k2 = another.ey.first / ayl;
        k3 = another.ex.second / axl;
        k4 = another.ey.second / ayl;
    }

    pair<double, double> base_to_another(pair<double, double> &pos)
    {
        pair<double, double> ret;
        if (k2 == 0)
        {
            ret.first = (pos.first - base.origin.first) / k1;
            ret.second = (pos.second - base.origin.second) / k4;
        }
        else
        {
            double t1 = pos.second - base.origin.second - (k4 * (pos.first - base.origin.first)) / k2;
            double t2 = k3 - (k1 * k4) / k2;
            ret.first = t1 / t2;
            ret.second = (pos.first - base.origin.first - k1 * ret.first) / k2;
        }
        return ret;
    }

    pair<double, double> another_to_base(pair<double, double> &pos)
    {
        pair<double, double> ret;
        ret.first = base.origin.first + k1 * pos.first + k2 * pos.second;
        ret.second = base.origin.second + k3 * pos.first + k4 * pos.second;
        return ret;
    }
};

int main()
{
}