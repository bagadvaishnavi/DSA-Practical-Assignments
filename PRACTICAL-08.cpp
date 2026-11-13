
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    deque<char> dq;
    string str;
    int flag = 1;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        dq.push_back(str[i]);
    }

    while (dq.size() > 1)
    {
        char first = dq.front();
        char last = dq.back();

        if (first != last)
        {
            flag = 0;
            break;
        }

        dq.pop_front();
        dq.pop_back();
    }

    if (flag == 1)
        cout << "The string is a palindrome.";
    else
        cout << "The string is not a palindrome.";

    return 0;
}
