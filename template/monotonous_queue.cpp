#include <bits/stdc++.h>
using namespace std;

/** Monotonous Queue Begin**/
template <typename T>
class MQ
{
private:
    deque<pair<int, T>> q;
    int index, siz, type;

public:
    const static int DEC = 0;
    const static int INC = 1;

    MQ() { index = 0, siz = -1, type = INC; }
    MQ(int type) { index = 0, siz = -1, this->type = type; }
    MQ(int size, int type) { index = 0, this->siz = size, this->type = type; }

    void push(T val)
    {
        while (!q.empty() && (((type == INC) && q.back().second >= val) || ((type == DEC) && q.back().second <= val)))
            q.pop_back();
        q.push_back(pair<int, T>(++index, val));
        if (siz > 0 && index >= siz && q.front().first < index - siz + 1)
            q.pop_front();
    }

    int size() { return q.size(); }

    bool empty() { return q.empty(); }

    T getans() { return q.front().second; }
};
/** Monotonous Queue End**/

int main()
{
    // sliding window
    // MQ<int> q(len, MQ<int>::INC);
    // MQ<int> q(len, MQ<int>::DEC);

    MQ<int> q(MQ<int>::INC);

    q.push(3), q.push(5), q.push(-2), q.push(9);

    cout << q.getans() << endl;

    return 0;
}