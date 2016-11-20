#include "pokemon.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

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

/*
Pokemon makePokemon(int index) {

	Pokemon *newPokemon;
	switch(index){
		case 7: newPokemon = new Squirtle(7);
		case 8: newPokemon = new Wartortle(8);
		case 9: newPokemon = new Blastoise(9);
	}

	return *newPokemon;
}
*/

/*
ostream & operator<<(ostream &os, pokemon poke)
{
	os << "<id> " << poke.get_index() << "</id>" << endl;
	os << "<name> " << poke.get_name() << " </name>" << endl;
	os << "<attack> " << poke.get_attk() << " </attack>" << endl;
	os << "<defense> " << poke.get_def() << " </defense>" << endl;
	os << "<entry>" << endl;
	os << "\t<number> " << poke.entry->number << " </number>" << endl;
	os << "\t<name> " << poke.entry->name << " </name>" << endl;
	os << "</entry>" << endl;

	return os;
}
*/

/*
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
*/

//Pokemon virtual function attack1 definition
int Pokemon::attack1(Pokemon * pokePointer)
{
	return 0;
}

//Pokemon virtual function attack2 definition
int Pokemon::attack2(Pokemon * pokePointer)
{
	return 0;
}

//Water virtual function attack1 definition
int Water::attack1(Pokemon * pokePointer)
{
	cout << get_name() << " used Tackle. " << pokePointer->get_species()
		<< " took " << pokePointer->take_damage(2, list<element>({element::water})) << " Damage." << endl;
	return 0;
}

//Squirtle virtual function attack2 definition
int Squirtle::attack2(Pokemon * pokePointer)
{
	cout << get_name() << " used Tackle. " << pokePointer->get_species()
		<< " took " << pokePointer->take_damage(2, list<element>({element::water})) << " Damage." << endl;
	return 0;
}

//Wartortle virtual function attack2 definition
int Wartortle::attack2(Pokemon * pokePointer)
{
	cout << get_name() << " used Surf. " << pokePointer->get_species() << " took " << pokePointer->take_damage(4, list<element>({element::water})) << " Damage." << endl;
	return 0;
}

//Blastoise virtual function attack2 definition
int Blastoise::attack1(Pokemon * pokePointer)
{	
	cout << get_name() << " used Water Pledge. " << pokePointer->get_species() << " took " << pokePointer->take_damage(6, list<element> ({ element::water, element::dragon })) << " Damage." << endl;
	return 0;
}

//Blastoise virtual function attack1 definition
int Blastoise::attack2(Pokemon * pokePointer)
{
	cout << get_name() << " used Hydro Cannon. " << pokePointer->get_species() << " took " << pokePointer->take_damage(8, list<element>({ element::water })) << " Damage." << endl;
	return 0;
}

int main(){
	Wartortle b("GaoRanger");
	Pokemon *a = new Blastoise();
	b.attack2(a);

	Squirtle c("Superman");
	Pokemon *d = new Wartortle();
	c.attack2(d);

	Blastoise e("BigGuy");
	Pokemon *f = new Squirtle();
	e.attack1(f);
	e.attack2(f);

	Water g("BigWater");
	Pokemon *h = new Blastoise();
	g.attack1(h);

	return 0;
}