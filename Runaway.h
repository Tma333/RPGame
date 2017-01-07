#ifndef Runaway
#define Runaway

// east = 1, west = 2, north = 3, south = 4;
// flee from combat in a random direction
void Flee(){
	std::cout << "\nPanic sets in as you escape from combat!\n";
	int Result = Rolldice(4, 1);
	bool Exitexists = false;
	while (Exitexists == false){
		if (my_world[grid_y][grid_x].east == false && Result == 1){
			std::cout << "You try to flee east, but you cannot flee that direction!!!\n";
			Result++;
		}
		else if (my_world[grid_y][grid_x].east != false && Result == 1){
			Exitexists = true;
		}
		else if (my_world[grid_y][grid_x].west == false && Result == 2){
			std::cout << "\nYou try to flee west, but you cannat flee that way!!!\n";
			Result++;
		}
		else if (my_world[grid_y][grid_x].west != false && Result == 2){
			Exitexists = true;
		}
		else if (my_world[grid_y][grid_x].north == false && Result == 3){
			std::cout << "\nYou try to flee north, but you cannat flee that way!!!\n";
			Result++;
		}
		else if (my_world[grid_y][grid_x].north != false && Result == 3){
			Exitexists = true;
		}
		else if (my_world[grid_y][grid_x].south == false && Result == 4){
			std::cout << "\nYou try to flee south, but you cannat flee that way!!!\n";
			Result = 1;
		}
		else if (my_world[grid_y][grid_x].south != false && Result == 4){
			Exitexists = true;
		}
	}

	if (Result == 1){
		std::cout << "\nIn your paniced state you manage to run east!\n\n";
		Move("east");
	}
	else if (Result == 2){
		std::cout << "\nIn your paniced state you manage to run west!\n\n";
		Move("west");
	}
	else if (Result == 3){
		std::cout << "\nIn your paniced state you manage to run north!\n\n";
		Move("north");
	}
	else if (Result == 4){
		std::cout << "\nIn your paniced state you manage to run south!\n\n";
		Move ("south");
	}
}
#endif