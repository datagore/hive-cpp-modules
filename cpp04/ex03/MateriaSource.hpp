#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource&);
	MateriaSource& operator=(const MateriaSource&);
	void learnMateria(AMateria* materia);
	AMateria* createMateria(const std::string& name);

private:
	enum {MAX_MATERIAS = 4};
	AMateria* materias[MAX_MATERIAS];
};

#endif // #ifndef MATERIASOURCE_HPP
