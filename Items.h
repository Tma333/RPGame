#ifndef Items
#define Items

class Item{
	struct{
		int attack, defense;
		std::string name, desc;
	};

	Item(){};
	void Clubfill(){
		attack = 10;
		defense = 0;
		name = "club";
	}
};

int Getitem(){
	if (Player_character.inventorycount < 5){
		// look for empty slot
		int Emptyslot = 0;
		while(Player_character.inventory[Emptyslot] != "\0"){
			Emptyslot++;
		}

		std::cout << "You put " << my_world[grid_y][grid_x].item << " into your backpack.\n";
		Player_character.inventory[Emptyslot] = my_world[grid_y][grid_x].item;
		Player_character.inventorycount++;
		my_world[grid_y][grid_x].item = "Empty";
	}
	else {
		std::cout << "You're backpack is full.\n";
		std::cout << "You put " << my_world[grid_y][grid_x].item << " back down.\n";
	}
	return 0;
}

int Dropitem(std::string itemname){
	for (int i=0;i<5;i++){
		int matchfound = Player_character.inventory[i].find(itemname);
		if (matchfound >= 0){
			std::cout << "Are you sure you want to drop " << Player_character.inventory[i] << "?\n";
			std::cout << "$ ";
			// check for yes or no answer.
			std::string answer;
			std::getline(std::cin, answer);
			answer = Lowercase(answer);
			if (answer == "yes"){
				std::cout << "You take " << Player_character.inventory[i] << " from your backpack.\n";
				std::cout << "As the " << Player_character.inventory[i] << " hits the floor, it vanishes.\n";
				Player_character.inventorycount--;
				Player_character.inventory[i] = "\0";
			}
			else {
				std::cout << "You place " << Player_character.inventory[i] << " back into your backpack.\n";
				return 0;
			}
		}
	}
	return 0;
}
#endif
