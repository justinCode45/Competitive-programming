#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool value[n];
    for (int i = 0; i < n; i++)
    {
        char buffer;
        cin >> buffer;
        value[i] = (buffer == 'T') ? 1 : 0;
    }

    stack<bool> st;
    cin.ignore(100, '\n');
    string ins;
    getline(cin, ins);

    for (int i = 0; i < ins.length(); i += 2)
    {
        char input;
        input = ins[i];
        // cout << input << endl;
        if (input >= 'A' && input <= 'Z')
        {
            // cout << input << endl;
            st.push(value[input - 'A']);
            continue;
        }
        else
        {
            if (input == '*')
            {
                bool a = st.top();
                st.pop();
                bool b = st.top();
                st.pop();

                st.push((bool)(a && b));
                continue;
            }
            if (input == '+')
            {
                bool a = st.top();
                st.pop();
                bool b = st.top();
                st.pop();
                st.push((bool)(a || b));
                continue;
            }
            if (input == '-')
            {
                bool a = st.top();
                st.pop();
                st.push((bool)(!a));
                continue;
            }
        }
    }

    if (st.top())
        cout << "T" << endl;
    else
        cout << "F" << endl;

    return 0;
}