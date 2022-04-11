#include <bits/stdc++.h>
using namespace std;

struct Person
{
    int id;
    int department_id;
    string name;
    int age; // small is older
};

struct cmp
{
    bool operator()(struct Person x, struct Person y) const
    {
        if (x.age == y.age)
        {
            if (x.department_id == y.department_id)
                return x.id < y.id;
            return x.department_id < y.department_id;
        }
        return x.age < y.age;
    }
};

int n;
unordered_map<int, int> department_ids;
map<pair<int, int>, struct Person> persons;
map<int, set<struct Person, cmp>> department_persons;
set<struct Person, cmp> office_persons;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        int t, d;
        cin >> t >> d;
        if (t == 1)
        {
            struct Person person;
            string bir;
            cin >> person.name >> bir;
            int day = (bir[0] - '0') * 10 + (bir[1] - '0');
            int month = (bir[3] - '0') * 10 + (bir[4] - '0');
            int year = (bir[6] - '0') * 1000 + (bir[7] - '0') * 100 + (bir[8] - '0') * 10 + (bir[9] - '0');
            person.age = year * 99 * 99 + month * 99 + day;
            if (department_ids.find(d) == department_ids.end())
                department_ids[d] = 0;
            person.id = ++department_ids[d];
            person.department_id = d;
            persons[pair<int, int>(person.department_id, person.id)] = person;
            office_persons.insert(person);
            department_persons[d].insert(person);
        }
        else
        {
            int k;
            cin >> k;
            struct Person person = persons[pair<int, int>(d, k)];
            office_persons.erase(person);
            department_persons[d].erase(person);
            persons.erase(pair<int, int>(d, k));
        }

        if (office_persons.empty())
        {
            cout << "Vacant ";
        }
        else
        {
            auto it = office_persons.begin();
            cout << (*it).name << " ";
        }
        if (department_persons[d].empty())
        {
            cout << "Vacant" << endl;
        }
        else
        {
            auto it = department_persons[d].begin();
            cout << (*it).name << endl;
        }
    }
    return 0;
}