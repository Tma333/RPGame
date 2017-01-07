#ifndef Combat
#define Combat

// combat engine

int Rolldice(int attackrange, int attackmin);
std::string Get_input();
int Playerdamage(Creature &Mob, int &Magicregen);
int Firedamage(Creature &Mob);
int Monsterdamage(Creature &Mob);
void Flee();
int Coinloot(Creature Mob);

int Fight(){
	// determine which monster to create for the room according to map prefill
	Creature Thismonster;
	int Magicregen = 0;
	Thismonster.Goblinfill();
	if (my_world[grid_y][grid_x].monster== "goblin"){
		Thismonster.Goblinfill();
	}
	else if (my_world[grid_y][grid_x].monster=="rabbit"){
		Thismonster.Rabbitfill();
	}
	else if (my_world[grid_y][grid_x].monster=="bob"){
		Thismonster.Bobfill();
	}
	// inital damage for engaging in combat
	Monsterdamage(Thismonster);
	Playerdamage(Thismonster, Magicregen);
	//while combat is not over
	std::string command;
	while(Player_character.health >0 && Thismonster.health > 0 && command != "exit"){
		std::cout << Thismonster.name << ':' << Thismonster.health << std::endl;
		Player_character.Displayhealth();
		std::cout << " [attack][cast*][defend][runaway]" << std::endl;
		std::cout << "> ";
		std::getline(std::cin,command);
		// convert to lowercase
		Lowercase(command);
		if (command == "attack"){
			int Orginalattackmin = Player_character.attackmin;
			Player_character.attackmin= Player_character.attackmin +5;
			Monsterdamage(Thismonster);
			Playerdamage(Thismonster, Magicregen);
			Player_character.attackmin = Orginalattackmin;
		}
		else if (command == "defend"){
			std::cout << "You steady yourself for an incoming attack.\n";
			// remember orginal values
			int Orginaldefense = Player_character.defense;
			int Orginalattackrange = Player_character.attackrange;
			// double defense half attack
			Player_character.defense = Player_character.defense * 2;
			Player_character.attackrange = Player_character.attackrange / 2;

			// call combat engine
			Monsterdamage(Thismonster);
			Playerdamage(Thismonster, Magicregen);
			// return to orginal value
			Player_character.defense = Orginaldefense;
			Player_character.attackrange = Orginalattackrange;
		}
		else if (command == "cast"){
			std::cout << "Spell[heal][fireball]\n";
			std::cout << "> ";
			std::getline(std::cin,command);
			if (command == "heal" || command == "cast heal"){
				if (Player_character.Healspell() == 0){
					std::cout << "1 While you are distracted casting a spell " << Thismonster.name << " attacks you.\n";
					Playerdamage(Thismonster, Magicregen);
				}
			}
			else if (command =="fireball" || command == "cast fireball"){
				if (Player_character.magic >=5){
					Player_character.magic = Player_character.magic -5;
					Firedamage(Thismonster);
					std::cout << "2 While you are distracted casting a spell " << Thismonster.name << " attacks you.\n";
					Playerdamage(Thismonster, Magicregen);
				}
				else {
					std::cout << "Not enough magic!\n";
				}
			}
			else {
				std::cout << command << " is not a valid spell.\n";
			}
		}
		else if (command == "cast fireball"){
			if (Player_character.magic >=5){
				Player_character.magic = Player_character.magic -5;
				Firedamage(Thismonster);
				std::cout << "3 While you are distracted casting a spell " << Thismonster.name << " attacks you.\n";
				Playerdamage(Thismonster, Magicregen);
			}
			else {
				std::cout << "Not enough magic!\n";
			}
		}
		else if (command == "cast heal"){
			if (Player_character.Healspell() == 0){
				std::cout << "4 While you are distracted casting a spell " << Thismonster.name << " attacks you.\n";
				Playerdamage(Thismonster, Magicregen);
			}
		}
		else if (command=="runaway"){
			Flee();
			Get_input();
			return 0;
		}
		else if (command == "help?"){
			std::cout << "Can't do that in combat\n";
		}
		else if (command=="exit"){
			End_game();
		}
		else{
			if (command != "\0"){
				std::cout << "Cannot understand \"" << command << "\".\n";	
			}
			std::cout << "The skirmish continues.\n";
			Monsterdamage(Thismonster);
			Playerdamage(Thismonster, Magicregen);
		}
	}
	return 0;
}

// player's attack on monster
int Monsterdamage(Creature &Mob){
	int herodamage = Rolldice(Player_character.attackrange, Player_character.attackmin) - Mob.defense;
	if (herodamage <= 0){
		std::cout << "Your attack misses the " << Mob.name << ".\n";
		herodamage = 0;
	}
	else {
		std::cout << "Your attack does " << herodamage << " damage to the " << Mob.name << '.' << std::endl;
	}
	Mob.health = Mob.health - herodamage;
	if (Mob.health <= 0){
		Mob.health = 0;
		std::cout << Mob.name << " is dead!!!\n";
		int lootcoin = Coinloot(Mob);
		std::cout << "You gain " << lootcoin << " coins.\n\n";
		Player_character.coin = Player_character.coin + lootcoin;
		my_world[grid_y][grid_x].monster = "Empty";
		Displaymap();
		Get_input();
		return 0;
	}
	return 0;
}
// player's attack on monster
int Firedamage(Creature &Mob){
	int firedamage = Rolldice(Player_character.magicattackrange, Player_character.magicattackmin);
	if (firedamage <= 0){
		std::cout << "Your fireball misses the " << Mob.name << ".\n";
		firedamage = 0;
	}
	else {
		std::cout << "Your fireball does " << firedamage << " damage to the " << Mob.name << '.' << std::endl;
	}
	Mob.health = Mob.health - firedamage;
	if (Mob.health <= 0){
		Mob.health = 0;
		std::cout << Mob.name << " is burnt to a crisp!!!\n\n";
		my_world[grid_y][grid_x].monster = "Empty";
		Displaymap();
		Get_input();
		return 0;
	}
	return 0;
}

// monster's attack on player
int Playerdamage(Creature &Mob, int &Magicregen){
		if (Player_character.health >0){
		// Hero 
		int mobdamage = Rolldice(Mob.attackrange, Mob.attackmin) - Player_character.defense;
	
		// health and magic regeneration during combat
		Magicregen++;
		if (Magicregen == 5){
			Player_character.magic = Player_character.magic +3;
			if (Player_character.magic > 50){
				Player_character.magic = 50;
			}
			Player_character.health = Player_character.health +5;
			if (Player_character.health > 100){
				Player_character.health = 100;
			}
			Magicregen = 0;
		}
		if (mobdamage <= 0 ){
			std::cout<< Mob.name << "'s attack misses you\n";
			mobdamage =0;
		}
		else {
			std::cout << "The " << Mob.name << " does " << mobdamage << " damage to you.\n";
		}
		Player_character.health = Player_character.health - mobdamage;
		if (Player_character.health <= 0){
			Player_character.health = 0;
			std::cout << "You are dead!\n";
			system("pause");
			End_game();
			return 0;
		}
	}
	return 0;
}

int Coinloot(Creature Mob){
	return Rolldice(Mob.coin, Mob.coinmin);
}
#endif