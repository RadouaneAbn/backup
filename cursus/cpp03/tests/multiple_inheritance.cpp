#include <iostream>

class CommonBaseClass {
    public:
        int common_value;

        CommonBaseClass( void ) : common_value(-99) {
            std::cout << "CommonBaseClass default contructor called" << std::endl;
        }
        CommonBaseClass( int common_value ) : common_value(common_value) {
            std::cout << "CommonBaseClass contructor called" << std::endl;
        }
};

class BaseClass1: virtual public CommonBaseClass {
    public:

        int value;

        BaseClass1() : CommonBaseClass(100) {
            std::cout << "BassClass1 default contructor called" << std::endl;
        }

        void function1() {
            std::cout << "Function1 BaseClass1" << std::endl;
        }
};

class BaseClass2: virtual public CommonBaseClass {
    public:

        int value;

        BaseClass2() : CommonBaseClass(200) {
            std::cout << "BaseClass2 default contructor called" << std::endl;
        }

        void function1() {
            std::cout << "Function1 BaseClass2" << std::endl;
        }
};

class DerivedClass: public BaseClass1, public BaseClass2 {
    public:

        DerivedClass( void ) : CommonBaseClass(999) {
            std::cout << "Derived default contructor called" << std::endl;
        }

        void function1() {
            BaseClass1::function1();
        }
};


int main() {

    DerivedClass derived;

/*
    // ######################
    // # Ambiguous solution #
    // ######################
    // class.BaseClass::function1() -> calls the function1 within BaseClass
    derived.BaseClass1::function1();
    derived.BaseClass2::function1();

    derived.BaseClass1::value = 10;
    derived.BaseClass2::value = 20;
    // ######################
*/

    derived.function1();

    std::cout << "Common value: " << derived.common_value << std::endl;

    return (0);
}

/*
            >>> Diamond Problem <<<

                CommonBaseClass
                /             \
               /               \
              /                 \
         BaseClass1         BaseClass2
             \                  /
              \                /
               \              /
                 DerivedClass
*/


/*
class CommonClass {
    public:
        int value;
};

class BaseClass1 : virtual public CommonClass {
    public:
        // int value;
    
    BaseClass1( void ) : value(-99) {
        value  = -99;
    };
    BaseClass1( int n ) : value(n) {};

    void show( void ) {
        std::cout << "Value: " << value << std::endl;
    }
};

class BaseClass2 : virtual public CommonClass {
    public:
        // int value;

    BaseClass2( void ) : value(-99) {};
    BaseClass2( int n ) : value(n) {};

    void show( void ) {
        std::cout << "Value: " << value << std::endl;
    }
};

class DerivedClass : public BaseClass1, public BaseClass2 {
    public:
        // Constructor must explicitly call the virtual base class constructor
        DerivedClass( void ) : CommonClass(), BaseClass1(), BaseClass2() {
            std::cout << "DerivedClass default constructor called" << std::endl;
        }
        
        DerivedClass( int n ) : CommonClass(), BaseClass1(n), BaseClass2(n) {
            // Since CommonClass is virtual, only one instance exists
            // The value will be set by the most derived class (DerivedClass)
            value = n;
            std::cout << "DerivedClass parameterized constructor called with value: " << n << std::endl;
        }

        void show( void ) {
            std::cout << "DerivedClass - Value: " << value << std::endl;
        }
        
        // Demonstrate accessing base class methods explicitly
        void showFromBase1( void ) {
            BaseClass1::show();
        }
        
        void showFromBase2( void ) {
            BaseClass2::show();
        }
};

// Example WITHOUT virtual inheritance to show the diamond problem
class NonVirtualCommon {
    public:
        int value;
        NonVirtualCommon() : value(0) {
            std::cout << "NonVirtualCommon constructor called" << std::endl;
        }
        NonVirtualCommon(int n) : value(n) {
            std::cout << "NonVirtualCommon constructor called with value: " << n << std::endl;
        }
};

class NonVirtualBase1 : public NonVirtualCommon {
    public:
        NonVirtualBase1() : NonVirtualCommon(1) {
            std::cout << "NonVirtualBase1 constructor" << std::endl;
        }
};

class NonVirtualBase2 : public NonVirtualCommon {
    public:
        NonVirtualBase2() : NonVirtualCommon(2) {
            std::cout << "NonVirtualBase2 constructor" << std::endl;
        }
};

// This class will have TWO copies of NonVirtualCommon (diamond problem)
class NonVirtualDerived : public NonVirtualBase1, public NonVirtualBase2 {
    public:
        NonVirtualDerived() {
            std::cout << "NonVirtualDerived constructor" << std::endl;
        }
        
        void showAmbiguity() {
            // These would be ambiguous without explicit scope resolution:
            // std::cout << value << std::endl;  // ERROR: ambiguous
            std::cout << "Value from NonVirtualBase1: " << NonVirtualBase1::value << std::endl;
            std::cout << "Value from NonVirtualBase2: " << NonVirtualBase2::value << std::endl;
        }
};

int main() {
    std::cout << "=== DIAMOND PROBLEM DEMONSTRATION ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "1. WITHOUT virtual inheritance (Diamond Problem):" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    NonVirtualDerived nvd;
    std::cout << "Size of NonVirtualDerived: " << sizeof(nvd) << " bytes" << std::endl;
    nvd.showAmbiguity();
    std::cout << "Note: NonVirtualCommon constructor called TWICE - we have 2 copies!" << std::endl;
    std::cout << std::endl;
    
    std::cout << "2. WITH virtual inheritance (Solution):" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Creating DerivedClass with default constructor:" << std::endl;
    DerivedClass d1;
    std::cout << "Size of DerivedClass: " << sizeof(d1) << " bytes" << std::endl;
    d1.show();
    std::cout << "Note: Only ONE CommonClass instance exists!" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Creating DerivedClass with parameterized constructor:" << std::endl;
    DerivedClass d2(42);
    d2.show();
    d2.showFromBase1();
    d2.showFromBase2();
    std::cout << "All methods access the SAME value because there's only one CommonClass instance!" << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== EXPLANATION ===" << std::endl;
    std::cout << "The Diamond Problem occurs when a class inherits from two classes" << std::endl;
    std::cout << "that both inherit from a common base class, creating ambiguity." << std::endl;
    std::cout << std::endl;
    std::cout << "Without virtual inheritance:" << std::endl;
    std::cout << "- Multiple copies of the base class exist" << std::endl;
    std::cout << "- Ambiguous member access" << std::endl;
    std::cout << "- Larger memory footprint" << std::endl;
    std::cout << std::endl;
    std::cout << "With virtual inheritance:" << std::endl;
    std::cout << "- Only one copy of the base class exists" << std::endl;
    std::cout << "- No ambiguity in member access" << std::endl;
    std::cout << "- More efficient memory usage" << std::endl;
    std::cout << "- The most derived class is responsible for initializing the virtual base" << std::endl;
    
    return 0;
}
*/