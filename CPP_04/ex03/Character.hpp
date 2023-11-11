#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include "ICharacter.hpp"
# include "AMateria.hpp"



class Character : public ICharacter {
private:
    std::string _name;
    AMateria* _inventory[4];
    int       _items;
    Character();

public:
    Character(const std::string& name);
    Character(const Character& toCopy);
    Character& operator=(const Character& src);
    ~Character();
    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

    AMateria** checkEquiped();
    AMateria** checkUnequiped();
    void    nullifyUnequiped(AMateria** unequiped);
};

#endif