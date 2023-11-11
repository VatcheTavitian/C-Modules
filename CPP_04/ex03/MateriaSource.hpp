#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include "MateriaSource.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        int totalMaterials;
        AMateria* materials[4];
        
        MateriaSource();
        MateriaSource(const MateriaSource& toCopy);
        MateriaSource& operator=(const MateriaSource& src);
        ~MateriaSource();

        virtual void learnMateria(AMateria* ptr);
        virtual AMateria* createMateria(std::string const& type);
};
#endif