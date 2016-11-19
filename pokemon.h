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
>>>>>>> d5ce0ac15b86ee03f43283aebe028af000ee4dc2
};

struct PokeEntry{
	std::string name;
	int number;
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
>>>>>>> d5ce0ac15b86ee03f43283aebe028af000ee4dc2

public:
	Pokemon() {};
	Pokemon(int i) { index = i; }
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
	void set_name(string name) {
		this->name = name;
	}

	string get_species() { 
		return pokeEntry.name; 
	}
	int take_damage(int damageAmount, list<element> damageTypes);
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

class Squirtle : public Water {
public:
	Squirtle(string speciesName);
	virtual int attack2(Pokemon * pokePointer);
};

class Wartortle : public Water {
public:
	Wartortle(string speciesName);
	virtual int attack2(Pokemon * pokePointer);

};

class Blastoise : public Water {
public:
	Blastoise(string speciesName);
	virtual int attack2(Pokemon * pokePointer);
	virtual int attack1(Pokemon * pokePointer);
};


#endif // POKEMON_H
