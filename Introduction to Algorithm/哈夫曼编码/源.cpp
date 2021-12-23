#include <iostream>
#include <string>
#include <queue>
using namespace std;
int sum = 0;
struct Char {
	string c;
	int f;
	Char *left = nullptr, *right = nullptr;
	Char(char f) :f(f) {};
	Char(priority_queue<Char> *que)
	{
		left = new Char(que->top());
		que->pop();
		right = new Char(que->top());
		que->pop();
		f = left->f + right->f;
	}
};
bool operator<(const Char &a, const Char &b)
{
	return a.f > b.f;
}
void DFS(Char *root, priority_queue<Char> &que, string i)
{
	root->c = i;
	if (root->left == NULL || root->right == NULL)
	{
		sum += root->c.size() * root->f;
		return;
	}
	DFS(root->left, que, i + "0");
	DFS(root->right, que, i + "1");
}
int main()
{
	priority_queue<Char> *que = new priority_queue<Char>;
	int n, f;
	char c;
	cin >> n;
	while (cin >> c >> f)
		que->push(Char(f));
	while (que->size() > 1)
		que->push(Char(que));
	Char *root;
	if (que->empty())
	{
		cout << 0;
		return 0;
	}
	else root = new Char(que->top());
	que->pop();
	DFS(root, *que, "");
	cout << sum << endl;
	return 0;
}