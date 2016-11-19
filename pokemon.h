#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

<<<<<<< HEAD
=======
#include <cmath>
#include <list>

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};

struct PokeEntry{
	int number;
	char name[30];
	char type[15];
	char description[100];
	PokeEntry() {};
	PokeEntry(int n) {};
};

class Pokemon {
private:
	std::string name;
	int index;
	int level = 1;
	PokeEntry pokeEntry;
	
protected:
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
	std::list<element> weaknesses;

public:
	Pokemon() {};
	Pokemon(int i) { index = i; pokeEntry.name = i; }
	~Pokemon() {};
	std::string get_name() {
		return name;
	}
	int get_level() {
		return level;
	}
	int get_maxHP() {
		return maxHP;
	}
	int get_currentHP() {
		return currentHP;
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);
	
	friend Pokemon* make_pokemon(element type, std::string name);
	
	//Function set name
	void set_name(string name) {
		this->name = name;
	}

	//Function get species name from pokeEntry
	string get_species() { 
		return pokeEntry.name; 
	}
	int take_damage(int damageAmount, list<element> damageTypes);

	//Abstraction function attack1 and attack2
	virtual int attack1(Pokemon* pokePointer);
	virtual int attack2(Pokemon* pokePointer);
	
	int get_index() { return index; }
	int get_Attk() { return attack; }
	int get_Def() { return defense; }
	friend ostream& operator<<(ostream &, Pokemon);
	void write();
};

class Fire : public Pokemon {
public:
	Fire(int index);
};

class Water : public Pokemon {
public:
	Water(int index);
};

class Grass : public Pokemon {
public:
	Grass(int index);
};

//Class Squirtle is a child of Water class
class Squirtle : public Water {
public:
	//Constructor
	Squirtle(string speciesName);

	//Virtual function attack2
	virtual int attack2(Pokemon * pokePointer);
};

//Class Wartortle is a child of Water class
class Wartortle : public Water {
public:
	//Constructor
	Wartortle(string speciesName);

	//Virtual function attack2
	virtual int attack2(Pokemon * pokePointer);
};

//Class Blastoise is a child of Water class
class Blastoise : public Water {
public:
	//Constructor
	Blastoise(string speciesName);

	//Virtual function attack1 and attack2
	virtual int attack2(Pokemon * pokePointer);
	virtual int attack1(Pokemon * pokePointer);
};


#endif // POKEMON_H
