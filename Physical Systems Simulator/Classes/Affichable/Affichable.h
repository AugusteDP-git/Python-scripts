#pragma once
#include <iostream>

//SuperClasse peremttant l'optimisation de l'opérateur <<
class Affichable {
	public :
	virtual std::ostream & affiche(std::ostream& sortie) const = 0;
};

std::ostream& operator <<(std::ostream& sortie, const Affichable& instance);
