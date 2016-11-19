#include "pokemon.h"
#include <iostream>
#include <fstream>
#include <string>

<<<<<<< HEAD
using namespace std; 

=======
Fire::Fire(int index) : Pokemon(index){
	maxHP+=1; speed+=2;
	attack+=2; defense-=2;
	specialAttack+=4; specialDefense+=1;
	weaknesses.push_back(element::water);
}

Water::Water(int index) : Pokemon(index){
	maxHP+=2; speed-=1;
	attack-=2; defense+=2;
	specialAttack-=4; specialDefense-=1;
	weaknesses.push_back(element::grass);
}

Grass::Grass(int index) : Pokemon(index){
	maxHP-=3; speed-=2;
	attack-=2; defense+=0;
	specialAttack-=3; specialDefense+=0;
	weaknesses.push_back(element::fire);
>>>>>>> d5ce0ac15b86ee03f43283aebe028af000ee4dc2
}

int Pokemon::take_damage(int damageAmount, std::list<element> damageTypes) {
	int weaknessCount = 0;
	for(auto wIt = weaknesses.begin(); wIt != weaknesses.end(); wIt++)
		for(auto dIt = damageTypes.begin(); dIt != damageTypes.end(); dIt++)
			if(*dIt == *wIt) weaknessCount++;

	damageAmount = damageAmount * (log(5 * weaknessCount + 5) / log(5));
	currentHP -= damageAmount;
	return damageAmount;
};

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
	os << "\t<number> " << () << " </number>" << endl;
	os << "\t<name> " << << " </name>" << endl;
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