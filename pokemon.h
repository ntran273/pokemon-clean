#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
<<<<<<< HEAD
using namespace std;

enum class element {
	fire = 0, water = 1, grass = 2
=======
#include <cmath>
#include <list>

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
>>>>>>> d5ce0ac15b86ee03f43283aebe028af000ee4dc2
};



class Pokemon {
private:
	std::string name = "Sparky";
	int index = 14321;
	int level = 1;
protected:
	
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
<<<<<<< HEAD
	
=======
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

#endif // POKEMON_H
