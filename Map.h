#ifndef Map
#define Map

// generate and fill map.

struct MAP{
	std::string room_desc, monster, item;
	bool north, south, east, west, special;
	int room_id;
};

extern MAP my_world[4][4];
extern int grid_y,grid_x;

void Generate_Map(){
	grid_x=1;
	grid_y=1;
	
	// fill created array of maps with default values
	MAP mapfill;
	mapfill.room_id = 0;
	mapfill.room_desc = "Empty";
	mapfill.north = false;
	mapfill.south = false;
	mapfill.east  = false;
	mapfill.west  = false;
	mapfill.monster = "Empty";
	mapfill.special = "Empty";
	mapfill.item = "Empty";
	mapfill.special = false;

	// fill iteration
	for (int i=0;i<3;i++){
		std::fill_n(my_world[i], 3, mapfill);
	}
	
	// room 0:0
	my_world[0][0].room_desc = "You arrive at what seems to be the north west corner.\nAn invisible force blocks your path to the west and to the north.";
	my_world[0][0].east = true;
	my_world[0][0].west = false;
	my_world[0][0].north = false;
	my_world[0][0].south = true;
	my_world[0][0].room_id = 0;
	my_world[0][0].item = "rock";

	// room 0:1
	my_world[0][1].room_desc = "You come accross a field of bones. \nThe floor is covered with bones from dead creatures.\nYou are filled with a sense of dread and danger.";
	my_world[0][1].east = true;
	my_world[0][1].west = true;
	my_world[0][1].north = false;
	my_world[0][1].south = true;
	my_world[0][1].room_id = 1;
	my_world[0][1].monster = "rabbit";
	my_world[0][1].item = "bleached bone";

	// room 0:2
	my_world[0][2].room_desc = "You are in the middle of a small field.\nThere is unclimable mountain to the north \nand inpassable forrest to the east.\nTo the south there dense ominous fog.";
	my_world[0][2].east = false;
	my_world[0][2].west = true;
	my_world[0][2].north = false;
	my_world[0][2].south = true;
	my_world[0][2].room_id = 2;

	// room 1:0
	my_world[1][0].room_desc = "You enter the room of infinite goblins.\nGoblins as far as the eyes can see block your way west.";
	my_world[1][0].east = true;
	my_world[1][0].west = false;
	my_world[1][0].north = true; 
	my_world[1][0].south = true;
	my_world[1][0].monster = "goblin";
	my_world[1][0].room_id = 3;
	my_world[1][0].special = true;

	// room 1:1
	my_world[1][1].room_desc = "You find yourself standing in the middle of an empty void.  \nThere is nothing around but vast darkness.\nYou have a feeling that going east from here would be bad.";
	my_world[1][1].east = true;
	my_world[1][1].west = true;
	my_world[1][1].north = true;
	my_world[1][1].south = true;
	my_world[1][1].room_id = 4;
	my_world[1][1].monster = "bob";
	my_world[1][1].item = "test stuff";

	// room 1:2
	//there are no exit in from this room
	my_world[1][2].room_desc = 
		"Suddenly a huge dome of descends from the skies trapping \nyou underneath it. The air in the doom is quickly vaccumed out.\nThe last remaining breath in your lungs is sucked out.\nYou've gasped your last breath.";
	my_world[1][2].east = false;
	my_world[1][2].west = false;
	my_world[1][2].north = false;
	my_world[1][2].south = false;
	my_world[1][2].room_id = 5;
	my_world[1][2].special = true;

	my_world[2][0].room_desc = "This is my test room [2][0]";
	my_world[2][0].east = true;
	my_world[2][0].west = false;
	my_world[2][0].north = true;
	my_world[2][0].south = false;
	my_world[2][0].room_id = 6;

	my_world[2][1].room_desc = "This is my test room [2][1]";
	my_world[2][1].east = true;
	my_world[2][1].west = true;
	my_world[2][1].north = true;
	my_world[2][1].south = false;
	my_world[2][1].room_id = 7;

	my_world[2][2].room_desc = "There is a fountain in the middle of the room.\nCrystal clear water flows from the fountain.\nYou don't want to go north from here.\nThe way east and south are blocked by an invisable force.";
	my_world[2][2].east = false;
	my_world[2][2].west = true;
	my_world[2][2].north = true;
	my_world[2][2].south = false;
	my_world[2][2].room_id = 8;	
	my_world[2][2].special = true;
}

#endif