#include <iostream>
#include <vector>
using namespace std;

template <class Type>
class Node
{
public:
	Node();
	Node(Type);
	~Node();
private:
	Type data;
	vector <float> weights;
	vector <*Node<Type>> edge;
	Type getdata();
	void setdata(Type);
	vector <float> getweight();
	void setweight(vector<float>);
};
