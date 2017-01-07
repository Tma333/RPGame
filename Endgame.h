#ifndef Endgame
#define Endgame

// exit or replay game 

bool Answer;
extern bool Playagain;
std::string Lowercase(std::string &sentence);

void End_game(){
	system("cls");
	std::cout << "\t**Game over**\n\nDo you want to play again?\n";
	std::string ans;
	std::cout << "$ ";
	std::getline(std::cin,ans);
	Lowercase(ans);
	if (ans == "yes"){
		Playagain = false;
	}
	else {
		Answer = false;
		std::cout<<"\n**\tThanks for playing\t**\n\n";
		system("pause");
		exit(0);
	}
}

#endif