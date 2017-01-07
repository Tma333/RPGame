#ifndef Environment
#define Environment

// function prototypes
void Displayexits();
void Isspecial();

// display map
void Displaymap() {
	//system("cls");
	std::cout << my_world[grid_y][grid_x].room_desc << std::endl;
	
	// display monster in environment
	if (my_world[grid_y][grid_x].monster != "Empty"){
		std::cout << "-There is a " << my_world[grid_y][grid_x].monster << " here.\n";}
	// display items in environment
	if (my_world[grid_y][grid_x].item != "Empty"){
		std::cout << "-There is a " << my_world[grid_y][grid_x].item << " here.\n";}

	// display exits with no exit case
	if (my_world[grid_y][grid_x].south == false&&my_world[grid_y][grid_x].north == false&&my_world[grid_y][grid_x].east == false&&my_world[grid_y][grid_x].west == false){
		std::cout<<"There are no ways out!!!";
	}
	else {
		Displayexits();
	}
	if (my_world[grid_y][grid_x].special == true){
		Isspecial();
	}
}

// display possible exits for the map
void Displayexits(){
	if (my_world[grid_y][grid_x].south == true || my_world[grid_y][grid_x].north == true || my_world[grid_y][grid_x].east == true || my_world[grid_y][grid_x].west == true){
		std:: cout << "\nYou can travel in these directions: ";
	}
	if (my_world[grid_y][grid_x].west == true){
		std::cout<<"west ";
	}
	if (my_world[grid_y][grid_x].east == true){
		std::cout<<"east ";
	}
	if (my_world[grid_y][grid_x].north == true){
		std::cout<<"north ";
	}
	if (my_world[grid_y][grid_x].south == true){
		std::cout<<"south ";
	}
}

// move around in environment
void Move(std::string User_input){
	// check for no exit conditions
	if (my_world[grid_y][grid_x].south == false&&my_world[grid_y][grid_x].north == false&&my_world[grid_y][grid_x].east == false&&my_world[grid_y][grid_x].west == false){
		std::cout<<"There are no ways out!!!(Type \"exit\" to quit)";
	}

	// standard east west south north movements
	else if (User_input == "east" && my_world[grid_y][grid_x].east == true){
		grid_x++;
		Displaymap();
	}
	else if(User_input == "west" && my_world[grid_y][grid_x].west == true){
		grid_x--;
		Displaymap();
	}
	else if(User_input == "north" && my_world[grid_y][grid_x].north == true){
		grid_y--;
		Displaymap();
	}
	else if(User_input == "south" && my_world[grid_y][grid_x].south == true){
		grid_y++;
		Displaymap();
	}
	// none direction inputs
	else{
		std::cout << User_input << " is not a valid direction\n";
	}
}

#endif