#include <iostream>
using namespace std;
int Num, Edge, weight = 0;
struct edge
{
	int weight, first, last; edge() {};
	edge(int f, int l, int w) :first(f), last(l), weight(w) {};
}*E;
struct tree_point
{
	int weight, parent;
}*tree;
edge Min(int i = 0)
{
	edge min = E[1];
	if (!i)
		E[++i] = E[Edge--];
	edge Root = E[i];
	for (int child = i * 2; i * 2 <= Edge; i = child)
	{
		child = i * 2;
		if (child != Edge && E[child].weight > E[child + 1].weight)
			child++;
		if (E[child].weight < Root.weight)
			E[i] = E[child];
		else break;
	}
	E[i] = Root;
	return min;
}
bool ring(edge e)
{
	int i, j;
	for (i = e.first; tree[i].parent != -1; i = tree[i].parent);
	for (j = e.last; tree[j].parent != -1; j = tree[j].parent);
	if (i != j)
	{
		tree[j].parent = i;
		weight = weight > e.weight ? weight : e.weight;
		return false;
	}
	return true;
}
int Kruskal()
{
	for (int i = 1, f, l , w; i < Edge; i++)
	{
		cin >> f >> l >> w;
		E[i] = edge(f, l, w);
	}
	for (int i = --Edge / 2; i > 0; i--)
		Min(i);
	for (int i = 0; i < Num; i++)
		tree[i].parent = -1;
	for (int i = 1; i < Num - 1; i++)
		if (ring(Min()))
			i--;
	return weight;
}
int main()
{
	cin >> Num >> Edge;
	tree = new tree_point[++Num];
	E = new edge[++Edge];
	cout << Kruskal() << endl;
	return 0;
}