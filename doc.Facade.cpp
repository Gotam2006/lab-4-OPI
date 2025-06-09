#include <iostream>

/**
 * @brief Підсистема 1 — відповідає за початкову перевірку.
 */
class Subsystem1 {
public:
    /**
     * @brief Перевірка автентифікації користувача.
     */
    void authenticate() {
        std::cout << "Subsystem1: Користувач автентифікований.\n";
    }
};

/**
 * @brief Підсистема 2 — відповідає за зчитування даних.
 */
class Subsystem2 {
public:
    /**
     * @brief Зчитування даних користувача.
     */
    void readUserData() {
        std::cout << "Subsystem2: Дані користувача зчитано.\n";
    }
};

/**
 * @brief Підсистема 3 — відповідає за збереження змін.
 */
class Subsystem3 {
public:
    /**
     * @brief Збереження змінених даних.
     */
    void saveChanges() {
        std::cout << "Subsystem3: Зміни збережено.\n";
    }
};

/**
 * @brief Клас Facade, що інкапсулює складну логіку підсистем.
 */
class Facade {
private:
    Subsystem1* s1;
    Subsystem2* s2;
    Subsystem3* s3;

public:
    /**
     * @brief Конструктор, створює екземпляри підсистем.
     */
    Facade() {
        s1 = new Subsystem1();
        s2 = new Subsystem2();
        s3 = new Subsystem3();
    }

    /**
     * @brief Деструктор, очищує пам'ять.
     */
    ~Facade() {
        delete s1;
        delete s2;
        delete s3;
    }

    /**
     * @brief Високоуровневий метод, який викликає потрібні методи підсистем у правильному порядку.
     */
    void performUserSession() {
        std::cout << "Facade: Початок сесії користувача...\n";
        s1->authenticate();
        s2->readUserData();
        s3->saveChanges();
        std::cout << "Facade: Сесію завершено.\n";
    }
};

/**
 * @brief Демонстрація використання шаблону Facade.
 */
int main() {
    Facade facade;
    facade.performUserSession();

    return 0;
}





