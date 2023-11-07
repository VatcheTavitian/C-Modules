#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
{
	
	const Animal* i = new Cat();
	const Animal* j = new Cat();
	
	delete i;
	delete j;
}
{

	Animal* i = new Dog();
	Animal* j = new Dog();
	
	delete j;
	delete i;
}
	return 0;
}