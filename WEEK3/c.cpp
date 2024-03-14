#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

bool sSmall(string a, string b)
{
    int len = min(a.length(), b.length());
    for (int i = 0; i < len; i++)
    {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }

    if (a.length() <= b.length())
        return true;
    else
        return false;
}

int main()
{
    // cout << sSmall("Alice","Sue") << endl;
    int n;
    while (1)
    {

        cin >> n;
        if (n == 0)
            break;

        map<string, vector<string> *> dict;

        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            string list;
            stringstream listStream;
            getline(cin, list);
            listStream << list;
            while (1)
            {
                string food;
                listStream >> food;
                if (listStream.fail())
                    break;
                if (dict.count(food))
                {
                    dict[food]->push_back(name);
                }
                else
                {
                    dict[food] = new vector<string>;
                    dict[food]->push_back(name);
                }
            }
        }
        for (auto i : dict)
        {
            vector<string>* p = i.second;
            sort(p->begin(),p->end());
            cout << i.first << " ";
            for (auto i : *p)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    cout << endl;
    }


    return 0;
}