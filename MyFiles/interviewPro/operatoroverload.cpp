#include <iostream>

using namespace std;

class ABC {
	int A, B;
public:
	ABC(int x, int y) {
		A = x;
		B = y;
	}
	
	ABC operator+ (const ABC &temp) {
		ABC result(0, 0);
		result.A = this->A + temp.A;
		result.B = this->B + temp.B;
		return result;
	}
	
	ABC& operator= (const ABC &copy) {
	    cout << "JUST CHECK\n";
	    this->A = copy.A;
	    this->B = copy.B;
	    return *this;
	}
 	
	ABC& operator+= (const ABC &add) {
		this->A = this->A + add.A;
		this->B = this->B + add.B;
	    return *this;
	}	
    
    ABC& operator+= (const int& val) {
        this->A = this->A + val;
        this->B = this->B + val;
        return *this;
    }
     
	void display() {
		cout << A << " + i" << B << endl;
	}
};

int main() {
	ABC o1(2, 3), o2(3, 4);

	ABC o3 = o1 + o2;
	ABC o4 = o1.operator+(o2);
	o3.display();
	//o4.display();
	// o4 = o1;
	// o4.display();
	// o2 = (o3 = o4);
    //o2.operator=(o3.operator=(o4));
    //o2.display();
    o3 += o2;
    o3.display();
    o3.operator+=(o2);
    o3.display();

    o2 += 7;
    o2.display();

	return 0;
}
