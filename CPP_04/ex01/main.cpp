#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
{
	
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	
	delete i;
	delete j;
}
{

}
	std::cout << "\nCheck copy constructor works\n" << std::endl;
	Dog* i = new Dog();
	Dog* j = new Dog();
	j->setType("Orange");
	std::cout << "\nMemory addresses before copy" << std::endl;
	std::cout << "Animal i = " << &i << " Type = " << i->getType() << std::endl;
	std::cout << "Animal j = " << &j << " Type = " << j->getType() << std::endl;
	*i = *j;
	std::cout << std::endl;
	std::cout << "\nMemory addresses after copy" << std::endl;
	std::cout << "Animal i = " << &i << " Type = " << i->getType() << std::endl;
	std::cout << "Animal j = " << &j << " Type = " << j->getType() << std::endl;

	delete j;
	delete i;
	return 0;
}