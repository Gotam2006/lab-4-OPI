#include <iostream>
#include <memory>

// Реалізація: інтерфейс, який не залежить від абстракції
class Implementor {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementor() = default;
};

// Конкретна реалізація A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA: Реалізація операції\n";
    }
};

// Конкретна реалізація B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB: Інша реалізація операції\n";
    }
};

// Абстракція
class Abstraction {
protected:
    std::shared_ptr<Implementor> implementor;

public:
    Abstraction(std::shared_ptr<Implementor> impl) : implementor(impl) {}
    virtual void operation() const {
        std::cout << "Abstraction: Делегує реалізацію...\n";
        implementor->operationImpl();
    }
    virtual ~Abstraction() = default;
};

// Розширена абстракція
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(std::shared_ptr<Implementor> impl) : Abstraction(impl) {}

    void operation() const override {
        std::cout << "RefinedAbstraction: Додаткове розширення\n";
        implementor->operationImpl();
    }
};

// Демонстрація
int main() {
    std::shared_ptr<Implementor> implA = std::make_shared<ConcreteImplementorA>();
    std::shared_ptr<Implementor> implB = std::make_shared<ConcreteImplementorB>();

    Abstraction* abs1 = new Abstraction(implA);
    Abstraction* abs2 = new RefinedAbstraction(implB);

    std::cout << "\n=== Виклик через Abstraction:\n";
    abs1->operation();

    std::cout << "\n=== Виклик через RefinedAbstraction:\n";
    abs2->operation();

    delete abs1;
    delete abs2;

    return 0;
}

