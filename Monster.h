#ifndef Monster
#define Monster

class Creature{
private:
public:
	struct{
		int attackrange, attackmin, defense, health, coin, coinmin;
		std::string desc, name, loot;
		bool aggresive;
	};
	Creature(){
		attackmin = 0;
		attackrange = 5;
		health = 50;
		defense = 0;
		coin = 100;
		coinmin = 1;
		name = "Name";
		aggresive = false;
	}
	void Goblinfill();
	void Rabbitfill();
	void Bobfill();
};
void Creature::Bobfill(){
	attackmin = 1;
	attackrange = 10;
	health = 50;
	defense = 5;
	coin = 25;
	coinmin = 25;
	name = "Bob";
}
void Creature::Rabbitfill(){
	attackmin = 50;
	attackrange = 50;
	health = 15000;
	defense = 10;
	coin = 1000;
	coinmin = 0;
	name = "Rabbit";
}
void Creature::Goblinfill(){
	attackmin = 5;
	attackrange = 9;
	health = 50;
	defense = 0;
	coin = 25;
	coinmin = 25;
	name = "Goblin";
}

#endif