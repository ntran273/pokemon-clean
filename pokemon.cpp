#include "pokemon.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

Fire::Fire(int index) : Pokemon(index) {
	maxHP += 1; speed += 2;
	attack += 2; defense -= 2;
	specialAttack += 4; specialDefense += 1;
}

Water::Water(int index) : Pokemon(index) {
	maxHP += 2; speed -= 1;
	attack -= 2; defense += 2;
	specialAttack -= 4; specialDefense -= 1;
}

Grass::Grass(int index) : Pokemon(index) {
	maxHP -= 3; speed -= 2;
	attack -= 2; defense += 0;
	specialAttack -= 3; specialDefense += 0;
}

Pokemon *make_pokemon(element e, std::string n) {

	Pokemon *newPokemon;
	if (e == element::fire) {
		newPokemon = new Fire(4);
		newPokemon->name = n;
	}
	else if (e == element::grass) {
		newPokemon = new Grass(1);
		newPokemon->name = n;
	}
	else if (e == element::water) {
		newPokemon = new Water(1);
		newPokemon->name = n;
	}
	return newPokemon;

}

ostream & operator<<(ostream &os, Pokemon poke)
{
	os << "<id> " << poke.get_index() << "</id>" << endl;
	os << "<name> " << poke.get_name() << " </name>" << endl;
	os << "<attack> " << poke.get_Attk() << " </attack>" << endl;
	os << "<defense> " << poke.get_Def() << " </defense>" << endl;
	os << "<entry>" << endl;
	
	Pokemon *a;
	element type = element::fire;
	a = make_pokemon(type, "Charmander");
	os << "\t<number> " << a->get_index() << " </number>" << endl;
	os << "\t<name> " << a->get_name() << " </name>" << endl;
	os << "</entry>" << endl;

	return os;
}

void Pokemon::write() {
	Pokemon pokeData;
	ofstream FileOut;
	int id = this->index;
	string str = to_string(id);
	string path = str.append(".dat");
	FileOut.open(path, ios_base::out);
	FileOut << pokeData;
	FileOut.close();

}

int main() {
	Pokemon a;
	a.write();

	return 0;
}