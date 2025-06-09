#include <iostream>
#include <memory>

/**
 * @brief Target — цільовий інтерфейс, який очікує клієнтський код.
 */
class Target {
public:
    /**
     * @brief Віртуальний метод, який викликається клієнтським кодом.
     */
    virtual void request() const {
        std::cout << "Target: Стандартна поведінка Target.\n";
    }

    virtual ~Target() = default;
};

/**
 * @brief Adaptee — клас, який має інтерфейс, несумісний з клієнтом.
 */
class Adaptee {
public:
    /**
     * @brief Специфічна поведінка, яку потрібно адаптувати.
     * @return std::string Результат специфічної поведінки
     */
    std::string specificRequest() const {
        return ".eetpadA евротанис опакс ящоб з";
    }
};

/**
 * @brief Adapter — адаптер, який робить інтерфейс Adaptee сумісним з Target.
 */
class Adapter : public Target {
private:
    std::shared_ptr<Adaptee> adaptee; ///< Вказівник на адаптований об'єкт

public:
    /**
     * @brief Конструктор, що приймає адаптований об'єкт.
     * @param a Вказівник на об'єкт Adaptee
     */
    Adapter(std::shared_ptr<Adaptee> a) : adaptee(a) {}

    /**
     * @brief Перевизначення методу request, який використовує специфічну поведінку Adaptee.
     */
    void request() const override {
        std::string reversed = adaptee->specificRequest();
        std::reverse(reversed.begin(), reversed.end());
        std::cout << "Adapter: (Адаптовано) " << reversed << "\n";
    }
};

/**
 * @brief Демонстрація шаблону Adapter у дії.
 */
int main() {
    std::cout << "Клієнт: Я можу працювати з Target об'єктами:\n";
    std::shared_ptr<Target> target = std::make_shared<Target>();
    target->request();

    std::cout << "\nКлієнт: Клас Adaptee має дивну поведінку:\n";
    std::shared_ptr<Adaptee> adaptee = std::make_shared<Adaptee>();
    std::cout << "Adaptee: " << adaptee->specificRequest() << "\n";

    std::cout << "\nКлієнт: Я можу використовувати Adapter, щоб працювати з Adaptee:\n";
    std::shared_ptr<Target> adapter = std::make_shared<Adapter>(adaptee);
    adapter->request();

    return 0;
}
