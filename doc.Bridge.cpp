#include <iostream>
#include <memory>

/**
 * @brief Інтерфейс реалізації, який відокремлений від абстракції.
 */
class Implementor {
public:
    /**
     * @brief Чиста віртуальна функція для реалізації операції.
     */
    virtual void operationImpl() const = 0;

    virtual ~Implementor() = default;
};

/**
 * @brief Конкретна реалізація A інтерфейсу Implementor.
 */
class ConcreteImplementorA : public Implementor {
public:
    /**
     * @brief Реалізація операції специфічна для ConcreteImplementorA.
     */
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA: Реалізація операції\n";
    }
};

/**
 * @brief Конкретна реалізація B інтерфейсу Implementor.
 */
class ConcreteImplementorB : public Implementor {
public:
    /**
     * @brief Інша реалізація операції.
     */
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB: Інша реалізація операції\n";
    }
};

/**
 * @brief Абстракція, яка визначає інтерфейс і зберігає посилання на реалізацію.
 */
class Abstraction {
protected:
    std::shared_ptr<Implementor> implementor; ///< Вказівник на реалізацію

public:
    /**
     * @brief Конструктор, який приймає об'єкт реалізації.
     * @param impl Об'єкт реалізації, що реалізує інтерфейс Implementor.
     */
    Abstraction(std::shared_ptr<Implementor> impl) : implementor(impl) {}

    /**
     * @brief Метод, який делегує виклик об'єкту реалізації.
     */
    virtual void operation() const {
        std::cout << "Abstraction: Делегує реалізацію...\n";
        implementor->operationImpl();
    }

    virtual ~Abstraction() = default;
};

/**
 * @brief Розширена абстракція, яка додає додаткову поведінку.
 */
class RefinedAbstraction : public Abstraction {
public:
    /**
     * @brief Конструктор, що приймає реалізацію.
     * @param impl Об'єкт реалізації.
     */
    RefinedAbstraction(std::shared_ptr<Implementor> impl) : Abstraction(impl) {}

    /**
     * @brief Перевизначена операція з додатковою поведінкою.
     */
    void operation() const override {
        std::cout << "RefinedAbstraction: Додаткове розширення\n";
        implementor->operationImpl();
    }
};

/**
 * @brief Точка входу в програму. Демонстрація шаблону Bridge.
 */
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


