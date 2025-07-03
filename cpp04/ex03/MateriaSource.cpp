#include <cstring>
#include <iostream>

#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor\n";
	std::memset(materias, 0, sizeof(materias));
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor\n";
	for (AMateria* materia: materias)
		delete materia;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor\n";
	std::memset(materias, 0, sizeof(materias));
	for (int i = 0; i < MAX_MATERIAS; i++)
		if (other.materias[i] != nullptr)
			materias[i] = other.materias[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource copy assignment\n";
	for (AMateria* materia: materias)
		delete materia;
	std::memset(materias, 0, sizeof(materias));
	for (int i = 0; i < MAX_MATERIAS; i++)
		if (other.materias[i] != nullptr)
			materias[i] = other.materias[i]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == nullptr)
		return;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (materias[i] == nullptr) {
			std::cout << "MateriaSource learned " << materia->getType() << "\n";
			materias[i] = materia;
			return;
		}
	}
	std::cout << "MateriaSource couldn't learn " << materia->getType() << "\n";
	delete materia; // No empty slots; don't leak the materia at least.
}

AMateria* MateriaSource::createMateria(const std::string& name)
{
	for (AMateria* materia: materias) {
		if (materia != nullptr && materia->getType() == name) {
			std::cout << "MateriaSource created " << name << " materia\n";
			return materia->clone();
		}
	}
	std::cout << "MateriaSource couldn't create " << name << " materia\n";
	return nullptr;
}
