#include <iostream>
#include <string>
#include <stack>
using namespace std;
class bracket {
public:
	bracket(int loc) :loc(loc) {};
	bool LR;
	int loc;
};
int main()
{
	string str;
	stack<bracket> bra;
	while (getline(cin, str)) 
	{
		cout << str << endl;
		for (int i = 0; i < str.length(); i++)
		{
			char c = str[i];
			str[i] = ' ';
			if (c == '(') bra.push(bracket(i));
			else if (c == ')') {
				if (bra.empty()) str[i] = '?';
				else bra.pop();
			}
		}
		while (!bra.empty())
		{
			str[bra.top().loc] = '$';
			bra.pop();
		}
		cout << str << endl;
	}
	return 0;
}