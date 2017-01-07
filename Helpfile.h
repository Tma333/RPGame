#ifndef Helpfile
#define Helpfile

// display helpfile text "command list"

void Showhelp(){
	std::string linefile;
	std::fstream f;
	f.open("command list.txt",std::ios::in);
	while(true){
		getline(f, linefile);
		if(f.fail())break;
		std::cout << linefile << std::endl;
	}
	f.close();
	system("pause");
}
#endif