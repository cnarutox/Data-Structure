#include <iostream>
#include <string>
using namespace std;
int n[26];
bool j(int a)
{
    if (a >= 'A' && a <= 'Z')
        return true;
    return false;
}
int main()
{
    string s;
    int max = 0;
    while (cin >> s)
        for (int i = 0; i < s.size(); i++)
            if (j(s[i]))
                max = ++n[s[i] - 'A'] > max ? n[s[i] - 'A'] : max;
    int **p = new int *[max];
    for (int i = 0; i < max; i++)
        p[i] = new int[26];
    for (int k = 0; k < max; k++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (n[i])
            {
                n[i]--;
                p[k][i] = 1;
            }
        }
    }
    for (int i = max - 1; i >= 0; i--)
    {
        for (int j = 0; j < 25; j++)
        {
            if (p[i][j] == 1)
                cout << "* ";
            else
                cout << "  ";
        }
        if (p[i][25] == 1)
            cout << '*' << endl;
        else
            cout << ' ' << endl;
    }
    for (char i = 'A'; i < 'Z'; i++)
        cout << i << ' ';
    cout << 'Z';
    for (int i = 0; i < max; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}