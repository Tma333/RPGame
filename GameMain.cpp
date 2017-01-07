#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <algorithm>

#include "Map.h"
#include "Environment.h"
#include "Endgame.h"
#include "Input.h"
#include "Character.h"
#include "Story.h"
#include "Helpfile.h"
#include "Monster.h"
#include "Combat.h"
#include "Items.h"
#include "Specialroomrouter.h"
#include "Runaway.h"
#include "Random.h"

int grid_x,grid_y;
MAP my_world[4][4];
MyCharacter Player_character;
bool Playagain;


int main()
{
	// seed for prng 
	srand((unsigned int) time(0));
	
	// play again false will repeat loop and turn off remain function calls. Yes answer to play again will set to false.

	do {
		Playagain = true;
		Player_character.Resetcharacter();

		if (Playagain == true) {
			Welcomesplash();
		}
		if (Playagain == true) {
			Generate_Map();	
		}

		// TURNED OFF: false to turn off
		if (Playagain == true) {
			SetCharacter(Player_character);
		}
		if (Playagain == true) {
			Displaymap();
		}

		if (Playagain == true) {
			Get_input();
		}
	} while (Playagain == false);

	system("pause");
	return 0;
}

// route inputs
std::string Get_input() {	
	// playagain check to ensure input function is called after play again is answer yes.
	std::string User_input;
	if(Playagain == true)
	{
		std::string Store_input[5];
		std::cout << "\n$ ";
		std::getline(std::cin, User_input);
		Lowercase(User_input);

		// break into tokens for longer inputs size of 5
		int startcounter =0, foundatcounter, endcounter, maxloopcounter=0;
		endcounter = User_input.length();
		foundatcounter = User_input.find(' ');
		if (foundatcounter==-1){
			Store_input[0] = User_input;
		}
		while(foundatcounter!=-1 && maxloopcounter < 4){
			Store_input[maxloopcounter] = User_input.substr(startcounter, foundatcounter-startcounter);
			startcounter = foundatcounter+1;
			maxloopcounter++;
			foundatcounter = User_input.find(' ',startcounter);
			if(foundatcounter == -1){
				Store_input[maxloopcounter] = User_input.substr(startcounter, endcounter - foundatcounter);
			}
		}

		int Specialcalled;
		if (my_world[grid_y][grid_x].special == true){
			Specialcalled = Isspecial(User_input);
		}

		// check for zero inputs
		if (User_input == "\0"){
			Get_input();
		}
		
		// check to see if user wants to quit game or help file
		else if (User_input =="exit"){
			End_game();
		}
		else if(User_input== "help?"){
			Showhelp();
			Get_input();
		}

		// look around function
		else if(User_input== "look around"){
			system("cls");
			Displaymap();
			Get_input();
		}

		//movement inputs
		else if (Store_input[0] == "go" ||Store_input[0] =="travel"||Store_input[0] =="head"||Store_input[0] =="move"){
			if (Store_input[1] == "west"||Store_input[1] =="east"||Store_input[1] =="north"||Store_input[1] =="south"){
				system("cls");
				Move(Store_input[1]);
				Get_input();
			}
		}
		else if (User_input == "west"||User_input == "north"||User_input == "east"||User_input == "south"){
			system("cls");
			Move(User_input);
			Get_input();
		}
		// combat commands attack, fight 
		else if (Store_input[0]== "fight"||Store_input[0]=="attack"||Store_input[0]=="kill"||Store_input[0]=="kick"){
			if (my_world[grid_y][grid_x].monster == "Empty"){
				std::cout << "Calm down. There is nothing to " << Store_input[0] << " here.\n";
				Get_input();
			}
			else if(Store_input[1]==my_world[grid_y][grid_x].monster){
				system("cls");
				std::cout << "You engage the " << my_world[grid_y][grid_x].monster << " in combat!\n\n";
				Fight();
			}
			else if(Store_input[1]!=my_world[grid_y][grid_x].monster){
				std::cout << "Who do you want to " << Store_input[0] << "?\n";
				Get_input();
			}
		}
		else if (Store_input[0]== my_world[grid_y][grid_x].monster){
			std::cout << "What about " << Store_input[0] << "?\n";
			Get_input();
		}

		//item pick up
		else if (Store_input[0]== "get"||Store_input[0]=="take"||Store_input[0]=="pickup"){
			int matchfound = my_world[grid_y][grid_x].item.find(Store_input[1]);
			// no items to pick up
			if (my_world[grid_y][grid_x].item == "Empty"){
				std::cout << "There is nothing to " << Store_input[0] << " here.\n";
				Get_input();
			}
			// get item
			else if(Store_input[1]==my_world[grid_y][grid_x].item || matchfound > 0){
				std::cout << "You " << Store_input[0] << ' ' << my_world[grid_y][grid_x].item << ".\n";
				// call item function here
				Getitem();
				Get_input();
			}
			// item name does not match
			else if(Store_input[1]!=my_world[grid_y][grid_x].item){
				std::cout << "You can't " << Store_input[0] << ' ' << Store_input[1] << ".\n";
				Get_input();
			}
		}
		
		// drop item
		else if (Store_input[0] == "drop"){
			if (Store_input[1] == "\0"){
				std::cout << "Drop what?\n";
				Get_input();
			}
			else {
				Dropitem(Store_input[1]);
				Get_input();
			}
		}

		// message echo for monster input
		else if (Store_input[0]== my_world[grid_y][grid_x].monster){
			std::cout << "What about " << Store_input[0] << "?\n";
			Get_input();
		}

		// check inventory
		else if (User_input == "inventory"){
			Player_character.Displayinventory();
			std::cout << std::endl;
			Player_character.Displaycoin();
			Get_input();
		}
		else if (Store_input[0] == "cast"){
			std::cout << "You can't do that outside of combat.\n";
			Get_input();
		}
	
		// display health outside combat
		else if (User_input == "health"){
			Player_character.Displayhealth();
			Get_input();
		}

		// catch all statement
		else {
			if (Specialcalled != 1){
				std::cout << "Cannot understand " << User_input << std::endl;
				Get_input();
			}
			else{
				Get_input();
			}
		}
	}
	return User_input;
}
