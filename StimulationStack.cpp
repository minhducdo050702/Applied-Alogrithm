#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    string temp;
    int temp2;
    cin >> temp;
    while (temp != "#")
    {
        if (temp == "PUSH")
        {
            cin >> temp2;
            s.push(temp2);
        }
        if (temp == "POP")
        {
            if (!s.empty())
            {
                cout << s.top() << endl;
                s.pop();
            }
            else
                cout << "NULL" << endl;
        }
        cin >> temp;
    }
    return 0;
}
