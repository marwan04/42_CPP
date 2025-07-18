#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE / 2; i++)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; i++)
        animals[i] = new Cat();
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    for (int i = 0; i < SIZE; i++)
        delete animals[i];
    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog basic;
    basic.makeSound();
    Dog copy = basic;
    copy.makeSound();

    return 0;
}
