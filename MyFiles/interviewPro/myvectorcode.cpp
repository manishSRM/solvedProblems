#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class myVector {
	T *p;
	int lastElementIndex;
	int currentCapacity;

	void _clone(const myVector &obj) {
		this->p = new T[obj.currentCapacity];
		int totalBytes = obj.size() * sizeof(T);
		memcpy(this->p, obj.p, totalBytes);
	}

public:
	myVector(int size = 3) {
		p = new T[size];
		currentCapacity = size;
		lastElementIndex = -1;
	}

	myVector(const myVector &copy) {
		_clone(copy);
	    lastElementIndex = copy.lastElementIndex;	
	}

	int size() const {
		return this->lastElementIndex + 1;
	}

	T& operator[] (const T& index) {
		return *(p + index);
	}

	bool isVectorFull() {
		return ((lastElementIndex + 1) > currentCapacity);
	}

	bool isVectorEmpty() {
		return (lastElementIndex == -1);
	}

	void resize(const int &newsize) {
		int totalBytes = size() * sizeof(T);
		T *newptr = new T[newsize];
		memcpy(newptr, p, totalBytes);
		delete[] p;
		p = newptr;
	}

	void push_back(const T &val) {
		if (isVectorFull()) {
			currentCapacity *= 2;
			resize(currentCapacity);
		}
		++lastElementIndex;
		*(p + lastElementIndex) = val;
	}

	bool shouldShrinkToFit() {
		return ((lastElementIndex + 1) * 5 <= currentCapacity);  
	}

	void pop_back() {
		if (isVectorEmpty()) {
			return;
		}
		if (shouldShrinkToFit()) {
			currentCapacity = lastElementIndex;
			resize(currentCapacity);
		}
		--lastElementIndex;
	}

	myVector& operator= (myVector &assignThis) {
		delete[] this->p;
		_clone(assignThis);
		return *this;
	}

	~myVector() {
	    cout << "~myVector() start " << p[0].first << " " << endl;
		delete[] p;
		cout << "~myVector() end" << endl;
	}

};

int main() {
    {
    	myVector<pair<int, int> > p;
    	for (int i = 0; i < 10; i++) {
    		p.push_back(make_pair(23, 34));
    	}
    }
	return 0;
}
