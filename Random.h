#ifndef Random
#define Random

int Rolldice(int attackrange, int attackmin){
	int fightvalue = rand()%attackrange + attackmin;
	return fightvalue;
}
#endif
