#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Materia source default constructor called" << std::endl;
	std::memset(learned_materias, 0, sizeof(AMateria *) * max_spell_count);
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "Materia source copy constructor called" << std::endl;
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << "Materia source copy assignment operator called" << std::endl;
	for (size_t i = 0; i < max_spell_count; i++)
	{
		if (learned_materias[i])
		{
			delete learned_materias[i];
			learned_materias[i] = 0;
		}
		if (src.learned_materias[i]) learned_materias[i] = src.learned_materias[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia source destructor called" << std::endl;
	for (size_t i = 0; i < max_spell_count; i++)
	{
		delete learned_materias[i];
		learned_materias[i] = 0;
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia) return;
	for (size_t i = 0; i < max_spell_count; i++)
		if (!learned_materias[i]) {learned_materias[i] = materia; break; }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < max_spell_count; i++)
		if (learned_materias[i] && learned_materias[i]->getType() == type)
			return learned_materias[i]->clone();
	return 0;
}
