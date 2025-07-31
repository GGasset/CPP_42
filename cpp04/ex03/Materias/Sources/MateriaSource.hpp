
#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "iostream"
#include "cstring"

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
private:
	static const size_t max_spell_count = 4;
	AMateria *learned_materias[MateriaSource::max_spell_count];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &src);
	~MateriaSource();

	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
};

#endif
