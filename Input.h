#ifndef Input
#define Input

// input router

void Showhelp();

// simple input convert to lower
std::string Lowercase(std::string &sentence){
	std::transform(sentence.begin(),sentence.end(),sentence.begin(),::tolower);
	return sentence;
}

// input in orginal format used when capitals are ok, for non command inputs
std::string Orginal_input(){
	std::string User_input, Unchanged_input;
	
	while(User_input == "\0"){
		std::cout << "\n$ ";
		std::getline(std::cin, User_input);
	}
	Unchanged_input = User_input;

	// check to see if user wants to quit game
	User_input = Lowercase(User_input);
	if (User_input =="exit"){
		End_game();
	}
	else if (User_input=="help?"){
		Showhelp();
		Orginal_input();
	}
	else if(User_input == "yes"|| User_input =="no" || User_input == "male" || User_input =="female"){
		return User_input;
	}

	return Unchanged_input;
}

#endif