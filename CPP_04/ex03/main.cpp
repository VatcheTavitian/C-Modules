#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"

int main() {
// {
//     Ice* newIce = new Ice();
//     std::cout << newIce->getType() << std::endl;

//     Cure* newCure = new Cure();
//     std::cout << newCure->getType() << "\n" << std::endl;

//     // Set type of newIce and newCure to to test cloning worked.
//     newIce->setType("New ice");
//     newCure->setType("New cure");
//     // Create clone
//     AMateria* cloneIce = newIce->clone();
//     AMateria* cloneCure = newCure->clone();
//     // Check values of newIce and cloneIce
//     std::cout << cloneIce->getType() << std::endl;
//     std::cout << cloneCure->getType() << std::endl;

//     delete newIce;
//     delete newCure;
//     delete cloneIce;
// }
// {
//     Ice* newIce = new Ice();
//     Cure* newCure = new Cure();
//     Character* jim = new Character("Jim");
//     newIce->use(*jim);
//     newCure->use(*jim);
//     jim->equip(newIce);
//     jim->equip(newIce);
//     jim->equip(newIce);
//     jim->equip(newIce);
//     jim->equip(newIce); // inventory full
//     jim->unequip(0); // unequip from index 0
//     std::cout << jim->checkUnequiped()[0]->getType() << std::endl; // check has been put in unequipped array
//     jim->equip(newCure);
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0);  
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
//     jim->equip(newIce);
//     jim->unequip(0); 
   

//     // Materials will be deleted when character deleted
//     // delete newIce; 
//     // delete newCure;
//     delete jim;

// }

{
    Ice* newIce = new Ice();
    Cure* newCure = new Cure();
    Character* jim = new Character("Jim");
  
   
    jim->equip(newIce);
    jim->equip(newCure);

    jim->equip(newCure);
    jim->equip(newIce);
    std::cout << jim->checkEquiped()[0]->getType() << std::endl; // check what is equiped
    std::cout << jim->checkEquiped()[1]->getType() << std::endl; // check what is equiped
    Character* tim = new Character(*jim);
    std::cout << tim->getName() << " has been copied as tim" << std::endl;
    std::cout << tim->checkEquiped()[0]->getType() << std::endl; // check what is equiped
    std::cout << tim->checkEquiped()[1]->getType() << std::endl; // check what is equiped
    
    delete jim;
    delete tim;

}
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
  
}