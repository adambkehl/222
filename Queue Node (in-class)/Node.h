template <class T>
class Node
{
private:
	T data;
	Node <T> *next;
public:
	Node();
	Node(T v);
	~Node();
	T getdata();
	void setdata(T v);
	void setnext(Node<T> *n);
	Node <T> *getnext();
};
