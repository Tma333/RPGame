#ifndef Story
#define Story

// story line at checkpoints.

void Welcomesplash(){
	system("cls");
	std::cout << std::setfill('*') <<std::setw(50)<< '*'<< std::endl; 
	std::cout << std::setfill('*') <<std::setw(50)<< '*'<< std::endl; 
	std::cout << "**" << std::setw(48) <<std::setfill(' ') << "**" << std::endl;
	std::cout << "**" << " WELCOME TO DUNGEONS AND DRAGONS WITHOUT \t**" << std::endl;
	std::cout << "**" << " THE DUNGEONS AND DRAGRONS" << std::setw(22) << "**" << std::endl;
	std::cout << "**" << std::setw(48) <<std::setfill(' ') << "**" << std::endl;
	std::cout << std::setfill('*') <<std::setw(50)<< '*'<< std::endl; 
	std::cout << std::setfill('*') <<std::setw(50)<< '*'<< std::endl; 
	std::cout << std::endl;
	std::cout << "(Type \"exit\" to quit game.)\n";
	std::cout << "(Type \"help?\" to see help file.)\n\n";

	//system("pause");
}

bool SetCharacter(MyCharacter &Player_Character){
	std::string Answer;
	//welcome message
	std::cout << 
		"There is a blinding flash of light and your eyes becomes heavy as they \n" << 
		"close. You slowly awaken. There's a dull throbing sensation in your head. \n" <<
		"You must have been asleep for hours. As you being to regain your senses \n" <<
		"you look up to see a green Alien staring down at you. Startled by the \n" <<
		"alien you spring to your feet and quickly back away.\n\n" <<
		"The green alien beings to speak without moving its mouth. \n" <<
		"\"Why, hello there Earthling. What brings you here?\"";
	Player_Character.name = Orginal_input();
		
		
		if (Playagain== false){
		return false;}
		system("cls");
	std::cout << "The Green alien looks confused by your answer.  He stops and \n" <<
		"thinks for awhile then responds \"Yeah... thats umm... very interesting.\"\n" <<
		"The alien begins speaking again. \"So do you have a name Earthling?\"\n" <<
		"\"By what name should I call you by?\"";
	
	// get name
	Player_Character.name = Orginal_input();
	//std::cin.ignore();

		if (Playagain== false){
		return false;}
		system("cls");

	std::cout << "\"You wish to be known as " << Player_Character.name<< " is that correct?\"";
	Answer = Orginal_input();

		if (Playagain== false){
		return false;}

	if (Answer=="no"){
		system("cls");
		std::cout<<"\"My apologies, what is it that you call yourself?\"";
		Player_Character.name = Orginal_input();
		system("cls");
		std::cout << "\"Okay then " <<Player_Character.name << ".\"\n";
	}
	else if (Answer=="yes"){
		system("cls");
		std::cout<<"\"Greetings " << Player_Character.name<< ".\"" << std::endl;
	}
	else {
		system("cls");
		std::cout << "\"Sorry my English isn't great I don't understand " << Answer << "\"" << std::endl <<
			"\"I'll just call you Gobblat\"\n";
		Player_Character.name = "Gobblat";
	}

	// gender question.
	std:: cout << "\"I'm not too familar with Earthlings physiology or names are you Male \nor Female?\"";
	Player_Character.gender = Orginal_input();

		if (Playagain== false){
		return false;}

	if (Player_Character.gender == "male" || Player_Character.gender == "female"){
		system("cls");
		std::cout << "\"I never meet an earthling " << Player_Character.gender << " before.\"\n";
	}
	else {
		system("cls");
		std::cout << "\"What is " << Player_Character.gender << "...?\"\n";
	}
	std::cout <<
			"\"Anyways, I've taken up enough of your time.  I'm sure you're\n" <<
			"eager to get home, or 'phone home' or whatever it is that you\n" <<
			"do. It was a pleasure meeting you.\"\n" <<
			"\nWith that, the green alien disappears in a flash of light. Leaving\n"<<
			"you alone with no one else around.\n";	
	return false;
}

#endif