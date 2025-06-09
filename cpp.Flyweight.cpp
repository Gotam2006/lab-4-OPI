#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

// Flyweight — спільний інтерфейс
class Shape {
public:
    virtual void draw(int x, int y) const = 0;
    virtual ~Shape() {}
};

// ConcreteFlyweight — зберігає внутрішній стан (shared)
class Circle : public Shape {
private:
    std::string color; // Внутрішній стан (shared)

public:
    Circle(const std::string& color) : color(color) {}

    void draw(int x, int y) const override {
        std::cout << "Draw " << color << " circle at (" << x << ", " << y << ")\n";
    }
};

// FlyweightFactory — створює/повертає існуючі об'єкти
class ShapeFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<Shape>> shapes;

public:
    std::shared_ptr<Shape> getCircle(const std::string& color) {
        if (shapes.find(color) == shapes.end()) {
            shapes[color] = std::make_shared<Circle>(color);
        }
        return shapes[color];
    }

    void printTotal() const {
        std::cout << "Total unique Circle objects: " << shapes.size() << "\n";
    }
};

int main() {
    ShapeFactory factory;

    // Створюємо кола різного кольору
    auto red = factory.getCircle("Red");
    auto blue = factory.getCircle("Blue");
    auto green = factory.getCircle("Green");

    // Повторно використовуємо червоне коло
    auto red2 = factory.getCircle("Red");

    // Виклик методу draw із різними координатами (зовнішній стан)
    red->draw(10, 20);
    blue->draw(30, 40);
    green->draw(50, 60);
    red2->draw(70, 80);

    factory.printTotal(); // Має бути 3, бо червоне коло не створюється повторно

    return 0;
}
