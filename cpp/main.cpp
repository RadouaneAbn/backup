#include <iostream>

class Employee {
    protected:
        int __Age;

    public:
        int getAge( void ) {
            return (__Age);
        }
        void setAge( int age ) {
            __Age = age;
        }
        Employee( int age ) {
            __Age = age;
        }
    
        virtual void sayHi(void) {
            std::cout << "Em hi" << std::endl;
        }
};

class Dev: public Employee {
    private:
        std::string __name;
    
    public:
        Dev( std::string name, int age ): Employee( age ), __name(name) {};
    
    void promote( void ) {
        if (__Age > 10)
            std::cout << "direct valid" <<std::endl;
        if (getAge() > 10)
            std::cout << "getter valid" <<std::endl;

    }

    void sayHi (void ) {
        std::cout << "Dev hi" << std::endl;
    }
};

int main() {
    Dev d("red", 28);
    d.promote();
    d.sayHi();
    d.Employee::sayHi();
}   