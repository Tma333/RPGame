#ifndef Character
#define Character

int Rolldice(int range, int min);

class MyCharacter
{
private:
public:
	struct {
		std::string name, race, info, gender, inventory[5], weapon;
		int health, attack, attackrange, attackmin, defense, coin, magic, magicattackrange, magicattackmin, inventorycount;
	};
	MyCharacter(){
		health=100;
		magic = 50;
		magicattackrange = 50;
		magicattackmin = 1;
		attackrange = 10;
		attackmin = 1;
		weapon = "Empty";
		defense=3;
		coin =0;
		inventorycount=0;
	}
	void Resetcharacter(){
		health=100;
		magic = 50;
		magicattackrange = 50;
		magicattackmin = 1;
		attackrange = 10;
		attackmin = 1;
		weapon = "Empty";
		defense=3;
		coin =0;
		inventorycount =0;
	}
	void Displayinventory(){
		if (inventorycount == 0){
			std::cout << "Your backpack is empty.\n";
		}
		else {
			std::cout << "Your backpack contains:\n";
			for (int i =0;i<5;i++){
				if (inventory[i] != "\0"){
					std::cout <<'-' << inventory[i] << std::endl;
				}
			}
		}
	}
	void Displaycoin(){
		std::cout << "Coins:" << coin << std::endl;
	}
	void Displayhealth(){
		std::cout << "Health:" << health << " Magic:" << magic;
	}
	int Healspell(){
		if (magic < 10){
			std::cout << "Not enough magic!\n";
			return 1;
		}
		int healfor = Rolldice(25, 25);
		std::cout << "You cast a spell of healing, which heals you for " << healfor << " health.\n";
		magic = magic - 10;
		health = health +healfor;
		if (health > 100){
			health = 100;
			return 0;
		}
		return 0;
	}
};

extern MyCharacter Player_character;

#endif