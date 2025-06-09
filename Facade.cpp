#include <iostream>

class SubsystemA {
public:
    void operationA() {
        std::cout << "SubsystemA: виконання операції A\n";
    }
};

class SubsystemB {
public:
    void operationB() {
        std::cout << "SubsystemB: виконання операції B\n";
    }
};

class SubsystemC {
public:
    void operationC() {
        std::cout << "SubsystemC: виконання операції C\n";
    }
};

class Facade {
private:
    SubsystemA a;
    SubsystemB b;
    SubsystemC c;

public:
    void operation() {
        std::cout << "Facade: спрощений виклик підсистем:\n";
        a.operationA();
        b.operationB();
        c.operationC();
    }
};

int main() {
    Facade facade;
    facade.operation();
    return 0;
}





