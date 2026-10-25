
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string str;
    queue<char> q;
    int freq[256] = {0};

    cout << "Enter a string: ";
    cin >> str;

    cout << "First non-repeating characters: ";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        freq[(unsigned char)ch]++;
        q.push(ch);

        while (!q.empty() &&
               freq[(unsigned char)q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}

