#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->materials[i] = NULL;
    this->totalMaterials = 0;
}

MateriaSource::MateriaSource(const MateriaSource& toCopy) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = toCopy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
    std::cout << "MateriaSource equal operator called" << std::endl;
    if (this == &src)
        return *this;
    for (int i = 0; i < 4; i++) {
        if (this->materials[i] != NULL)
            delete this->materials[i];
        this->materials[i] = src.materials[i];
    }
    this->totalMaterials = 0;
    return (*this);
}


MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* ptr) {
    if (this->totalMaterials < 4) {
        this->materials[totalMaterials] = ptr;
        totalMaterials++;
        std::cout << "Material Learned" << std::endl;
    } else {
        std::cout << "Materials full, unable to learn" << std::endl;
    }
}


AMateria* MateriaSource:: createMateria(std::string const& type) {
    for (int i = 0; i < this->totalMaterials; i++) {
        if (this->materials[i]->getType() == type) 
            return this->materials[i]->clone();
    }
    std::cout << "Material not found, unable to create" << std::endl;
    return NULL;
}
