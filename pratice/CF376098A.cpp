#include <bits/stdc++.h>
using namespace std;

map<pair<string, int>, vector<vector<string>>> db;

void solve(string &query)
{
    int len = query.size();
    string buf;
    vector<string> params;
    pair<string, int> key;
    for (int i = 0; i < len; i++)
    {
        if (query[i] == ' ')
            continue;
        if (query[i] == '(')
        {
            key.first = buf;
            key.second = 0;
            buf.clear();
            continue;
        }
        if (query[i] == ',' || query[i] == ')')
        {
            params.emplace_back(buf);
            key.second += 1;
            buf.clear();
            continue;
        }
        buf.push_back(query[i]);
    }
    int ans = 0;
    if (db.find(key) == db.end())
    {
        cout << ans << endl;
        return;
    }
    auto li = db[key];
    for (auto x : li)
    {
        map<string, set<string>> variables;
        for (int i = 0; i < key.second; i++)
        {
            if (params[i][0] == '_')
            {
                if (params[i].size() > 1)
                    variables[params[i]].insert(x[i]);
                continue;
            }
            if (x[i] != params[i])
                goto end;
        }
        for (auto it : variables)
            if (it.second.size() > 1)
                goto end;
        ++ans;
    end:;
    }
    cout << ans << endl;
}

int main()
{
    // freopen("D:\\1.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string line;
    while (true)
    {
        getline(cin, line);
        if (line.empty())
            break;
        int len = line.size();
        string buf;
        vector<string> params;
        pair<string, int> key;
        for (int i = 0; i < len; i++)
        {
            if (line[i] == ' ')
                continue;
            if (line[i] == '(')
            {
                key.first = buf;
                key.second = 0;
                buf.clear();
                continue;
            }
            if (line[i] == ',')
            {
                params.emplace_back(buf);
                key.second += 1;
                buf.clear();
                continue;
            }
            if (line[i] == ')')
            {
                params.emplace_back(buf);
                key.second += 1;
                buf.clear();
                db[key].emplace_back(params);
                params.clear();
                continue;
            }
            buf.push_back(line[i]);
        }
    }
    string query;
    while (true)
    {
        getline(cin, query);
        if (query.empty())
            break;
        solve(query);
    }
    return 0;
}