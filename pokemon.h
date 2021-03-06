#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <fstream>

using namespace std;

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};


struct PokeEntry {
	int number;
	char name[20];
	char type[10];
	char description[200];
	PokeEntry(int n) {
		std::ifstream entryFile(std::to_string(n) + ".txt");
		entryFile >> number;
		entryFile >> name;
		entryFile >> type;
		entryFile.seekg(1, std::ios::cur);
		entryFile.getline(description, 199);
		entryFile.close();
	};
};

class Pokemon {
private:
	int index;
	std::string name;
	int level = 1;
public: PokeEntry *entry;
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
	Pokemon(int i) {
		entry = new PokeEntry(i);
	}
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
	
	friend Pokemon make_pokemon(int index);
	
	//Function set name
	void set_name(string name) {
		this->name = name;
	}

	//Function get species name from pokeEntry
	string get_species() { 
		return entry->name; 
	}

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
private: string name;
public:
	Water(int index);

	Water(string nickname = "Water") : Pokemon(4){
		name = nickname;
	}

	string get_name() {return name;}
	virtual int attack1(Pokemon * pokePointer);
};

class Grass : public Pokemon {
public:
	Grass(int index);
};

//Class Squirtle is a child of Water class
class Squirtle : public Water {
private: string name;
public:
	//Constructor
	Squirtle(string nickname = "Squirtle") : Water(7){
		name = nickname;
	}

	string get_name() {return name;}

	//Virtual function attack2
	virtual int attack2(Pokemon * pokePointer);
};

//Class Wartortle is a child of Water class
class Wartortle : public Water {
private: string name;
public:
	//Constructor
	Wartortle(string nickname = "Wartortle") : Water(8){
		name = nickname;
	}
	
	string get_name() {return name;}

	//Virtual function attack2
	virtual int attack2(Pokemon * pokePointer);
};

//Class Blastoise is a child of Water class
class Blastoise : public Water {
private: string name;
public:
	//Constructor
	Blastoise(string nickname = "Blastoise") : Water(9){
		name = nickname;
	}

	string get_name() {return name;}

	//Virtual function attack1 and attack2
	virtual int attack2(Pokemon * pokePointer);
	virtual int attack1(Pokemon * pokePointer);
};


#endif // POKEMON_H
