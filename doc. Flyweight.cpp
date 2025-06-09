#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

/**
 * @brief Абстрактний клас Flyweight, що визначає інтерфейс для об'єктів, які можуть бути спільно використані.
 */
class Shape {
public:
    /**
     * @brief Віртуальний метод для малювання об'єкта на координатах (x, y).
     * @param x Координата X
     * @param y Координата Y
     */
    virtual void draw(int x, int y) const = 0;

    /// Віртуальний деструктор.
    virtual ~Shape() {}
};

/**
 * @brief Конкретний клас Flyweight, що реалізує об'єкт "Коло" зі спільним кольором.
 */
class Circle : public Shape {
private:
    std::string color; ///< Внутрішній стан — колір кола

public:
    /**
     * @brief Конструктор, що ініціалізує колір кола.
     * @param color Колір, який буде збережено як спільний стан
     */
    Circle(const std::string& color) : color(color) {}

    /**
     * @brief Метод для малювання кола у вказаній позиції.
     * @param x Координата X
     * @param y Координата Y
     */
    void draw(int x, int y) const override {
        std::cout << "Draw " << color << " circle at (" << x << ", " << y << ")\n";
    }
};

/**
 * @brief Фабрика для створення та повторного використання об'єктів Flyweight (Circle).
 */
class ShapeFactory {
private:
    /// Колекція унікальних об'єктів типу Circle (за кольором)
    std::unordered_map<std::string, std::shared_p
