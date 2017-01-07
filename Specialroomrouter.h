#ifndef Specialroomrouter
#define Specialroomrouter

// special instructions for room exceptions
void Special_three();
void Special_five();
int Special_eight(std::string command);

void Isspecial(){
	if (my_world[grid_y][grid_x].room_id == 3){
		Special_three();
	}
	else if (my_world[grid_y][grid_x].room_id == 5){
		Special_five();
	}
}
int Isspecial(std::string &command){
	if (my_world[grid_y][grid_x].room_id == 8){
		return Special_eight(command);
	}
	return 0;
}

void Special_three(){
	my_world[1][0].monster = "goblin";
	Get_input();
}
void Special_five(){
	int counter =10; std::cout << "\nAs you struggle for air the world starts to go dark.\n" << std::endl;
	for (int i = 0;i<10;i++){
		std::cout << counter << "...\n";
		system("pause");
		counter--;
	}
	std::cout << "\n\nYour head explodes in the vaccum.\nYou are dead...\n";
	system("pause");
	End_game();
}
int Special_eight(std::string command){
	if (command == "drink"){
		std::cout << "Drink what?\n";
		return 1;
	}
	else if (command == "drink water"|| command == "drink from fountain" || command =="drink fountain"){
		Player_character.health = 100;
		Player_character.magic = 50;
		std::cout << "\nA warmth spreads thru you.  You feel refreshed.\n";
		Player_character.Displayhealth();
		return 1;
	}
	return 0;
}
#endif