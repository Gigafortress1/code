#include <iostream>
using namespace std;

//T19
template<class T>
class extendedChain // : linearList<T>
{
private:
	int listSize;
	// chainNode<T>* lastNode;
	// chainNode<T>* firstNode;  	//先写一个chainNode的类，作为链表的节点
public:
	extendedChain(/* args */){}
	~extendedChain(){}
	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theIndex) const;
	void erase(int theIndex);
	void insert (int theIndex, const T& theElement);
	void output (ostream& out) const;
	void clear();
	void push_back(const T& theElement);
};

template<class T>
extendedChain<T> merge(extendedChain<T> a, extendedChain<T> b);


//T20
template<class T>
class chain // : linearList<T>
{
private:
	int listSize;
	// chainNode<T>* firstNode;  	//先写一个chainNode的类，作为链表的节点
public:
	chain(/* args */){}
	~chain(){}
	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theIndex) const;
	void erase(int theIndex);
	void insert (int theIndex, const T& theElement);
	void output (ostream& out) const;

	chain<T> merge(chain<T> b);		// 最后要把a,b都清空: 分别遍历两个链表再调用erase函数即可
};


int main()
{
	//T19
	extendedChain<int> a,b,c;
	c = merge(a,b);


	//T20
	chain<int> a1,b1,c1;
	c1 = a1.merge(b1);

	return 0;
}

//T19
template<class T>
extendedChain<T> merge(extendedChain<T> a, extendedChain<T> b){}

template<class T>
T& extendedChain<T> :: get(int theIndex) const{}

template<class T>
void extendedChain<T> :: erase(int theIndex){}

template<class T>
void extendedChain<T> :: insert (int theIndex, const T& theElement){}

template<class T>
void extendedChain<T> :: output (ostream& out) const{}

template<class T>
void extendedChain<T> :: clear(){}

template<class T>
void extendedChain<T> :: push_back(const T& theElement){}


//T20
template<class T>
chain<T> chain<T> ::  merge(chain<T> b){}

template<class T>
chain<T> merge(chain<T> a, chain<T> b){}

template<class T>
T& chain<T> :: get(int theIndex) const{}

template<class T>
void chain<T> :: erase(int theIndex){}

template<class T>
void chain<T> :: insert (int theIndex, const T& theElement){}

template<class T>
void chain<T> :: output (ostream& out) const{}

//This is a new change.
//This is another new change.