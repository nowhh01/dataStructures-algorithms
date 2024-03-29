#include <iostream>

template<typename T>
struct Node
{
	T Data;
	Node<T>* Next;
};

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();

	int GetSize() const;
	bool IsEmpty() const;

	T Pop();
	T Peek();
	void Push(T data);
	void Clear();
	void Display();

private:
	Node<T>* mTop;
	int mSize;

};

template<typename T>
Stack<T>::Stack() : mTop{nullptr}, mSize{0}
{
}

template<typename T>
Stack<T>::~Stack()
{
	Clear();
}

template<typename T>
int Stack<T>::GetSize() const
{
	return mSize;
}

template<typename T>
bool Stack<T>::IsEmpty() const
{
	return mTop == nullptr;
}

template<typename T>
T Stack<T>::Pop()
{
	Node<T>* node = mTop;
	T data = node->Data;
	mTop = mTop->Next;
	mSize--;

	delete node;
	return data;
}

template<typename T>
T Stack<T>::Peek()
{
	return mTop->Data;
}

template<typename T>
void Stack<T>::Push(T data)
{
	Node<T>* node = new Node<T>{ data, nullptr };

	node->Next = mTop;
	mTop = node;
	mSize++;
}

template<typename T>
void Stack<T>::Clear()
{
	Node<T>* node = nullptr;

	while(mTop)
	{
		node = mTop;
		mTop = mTop->Next;
		delete node;
	}
	
	mSize = 0;
}

template<typename T>
void Stack<T>::Display()
{
	Node<T>* node = mTop;

	std::cout << "Stack: ";

	while(node)
	{
		std::cout << node->Data << ' ';
		node = node->Next;
	}

	std::cout << '\n';
}
/*
int main()
{
	Stack<std::string> s1{};

	for(int i = 0; i < 5; i++)
	{
		s1.Push("str" + std::to_string(i));
	}

	std::cout << "\n-------------Stack<string>------------\n";
	s1.Display();

	std::cout << "\nCall Peek(): " << s1.Peek() << '\n';
	s1.Display();

	std::cout << "\nCall Pop(): " << s1.Pop() << '\n';
	s1.Display();

	std::cout << "\nCall Push(\"orange\")\n";
	s1.Push("orange");
	s1.Display();

	std::cout << "\nCall push(\"banana\")\n";
	s1.Push("banana");
	s1.Display();

	std::cout << "\nCall Pop(): " << s1.Pop() << '\n';
	s1.Display();
}
*/
