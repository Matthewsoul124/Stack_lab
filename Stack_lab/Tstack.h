#pragma once

template <class T>
class TStack
{
protected:
	T* pMem;
	int size;
	int top;
public:
	TStack() { 
		size = 0; 
		top = -1;
		pMem = nullptr;
	}
	TStack(int _size = 0) {
		if (_size < 0) throw "error";
		top = -1;
		size = _size;
		pMem = new T[size];
		for (int i = 0; i < size; i++) pMem[i] = 0;
	}
	//TStack(int _size = 10, int _top = 0, T* pMem);
	
	//TStack(int _size, int _top);
	TStack(TStack<T>& stack) {
		top = stack.top;
		size = stack.size;
		pMem = new T[size];
		for (int i = 0; i < size; i++) pMem[i] = stack.pMem[i];
	}
	~TStack() { delete pMem; }

	int GetSize()
	{
		return top + 1;
	}

	T GetTop()
	{
		if (top < 0) throw "error";
		return pMem[top];
	}

	T Pop() {
		if (IsEmpty()) {
			throw "Stack is empty";
		}
		return pMem[top--];
		//return mas[top--];
	}
	void Push(double elem) {
		if (IsFull()) {
			throw - 1;
		}
		//pMem[top] = elem;
		//top++;
		pMem[++top] = elem;
	}
	bool IsEmpty() { return top + 1 == 0; }


	bool IsFull() { return top + 1 == size; }

	void Clear() { for (int i = 0; i < size; i++) pMem[i] = 0; }

	T Get() {
		if (IsEmpty()) {
			throw - 1;
		}
		top--;
		return pMem[top];
	}

	void copyInnards(const TStack& s) {
		if (size != s.size) throw "error";
		for (int i = 0; i < size; i++) pMem[i] = s.pMem[i];
	}

	TStack& operator=(const TStack<T>& stack) {
		if (&stack == this) return *this;
		size = stack.size;
		top = stack.top;
		delete[] pMem;
		pMem = new T[size];
		for (size_t i = 0; i < size; i++) pMem[i] = stack.pMem[i];
		return *this;
	}

	bool operator==(const TStack<T>& stack) {
		if (size != stack.size) return false;
		for (int i = 0; i < size; i++) {
			if (pMem[i] != stack.pMem[i]) return false;
		}
		return true;
	}
	bool operator!=(const TStack<T>& stack) {
		if (size != stack.size) return true;
		for (int i = 0; i < size; i++) {
			if (pMem[i] != stack.pMem[i]) return true;
		}
		return false;
	}
};

