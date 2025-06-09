#include <iostream>
#include <string>
#include <algorithm>

// Цільовий інтерфейс
class Target {
public:
    virtual void request() const {
        std::cout << "Target: Стандартний запит\n";
    }
    virtual ~Target() = default;
};

// Клас, який потрібно адаптувати
class Adaptee {
public:
    std::string specificRequest() const {
        return ".eetpadA єцирпс ящоб з";
    }
};

// Адаптер, що робить Adaptee сумісним із Target
class Adapter : public Target {
private:
    Adaptee adaptee;

public:
    void request() const override {
        std::string result = adaptee.specificRequest();
        std::reverse(result.begin(), result.end());
        std::cout << "Adapter: (адаптовано) " << result << "\n";
    }
};

// Демонстрація роботи
int main() {
    Target* target = new Target();
    std::cout << "Клієнт: Працює з Target:\n";
    target->request();

    Adapter* adapter = new Adapter();
    std::cout << "\nКлієнт: Працює з Adapter:\n";
    adapter->request();

    delete target;
    delete adapter;

    return 0;
}
