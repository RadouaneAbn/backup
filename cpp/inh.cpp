#include <iostream>

using namespace std;


class Animal {
	public:
		int age;
		void call( void ) {
			cout << "animal is calling\n";
		}
};

class Tiger : virtual public Animal {
	public:
		void call( void ) {
			cout << "Tiger is calling\n";
		}
};

class Lion : virtual public Animal {
	public:
		void call( void ) {
			cout << "Lion is calling\n";
		}
};

class Liger : public Lion, public Tiger {
	public:
	// int age;
		void call( void ) {
			cout << "Liger is calling\n";
		}
};

int main() {
	Liger l;

	l.call();
	l.age = 100;
	l.Tiger::age = 200;
	l.Lion::age = 300;
	l.Lion::Animal::age = 500;

	cout << "age:               " << l.age << endl;
	cout << "Tiger::age:        " << l.Tiger::age << endl;
	cout << "Lion::age:         " << l.Lion::age << endl;
	cout << "Lion::Animal::age: " << l.Lion::Animal::age << endl;
}