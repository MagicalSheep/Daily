#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    cin >> in;
    if (in.size() == 1)
    {
        cout << in << endl;
        return 0;
    }
    bool isok = true;
    for (int i = 0; i < in.size() - 1; i++)
    {
        if (in[i] != '9')
        {
            isok = false;
            break;
        }
    }
    if (isok)
    {
        cout << in << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i < in.size(); i++)
            cout << '9';
        cout << endl;
    }
    return 0;
}