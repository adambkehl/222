template <class T>
class queue
{
private:
	Node <T> *first;
	Node<T> *last;
public:
	queue();
	queue(T v);
	void enqueue(T v);
	T dequeue();
	int length() const;
	void display() const;
};
