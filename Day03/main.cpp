//lecture 03

#include <string>
#include <iostream>
#include <vector>

class Pokemon{
public:

	Pokemon(const std::string& nm, const std::string& tp, int& lvl, int& hlth):name(nm), type(tp), level(lvl), health(hlth){}

	std::string getName(){return name;}
	int getHealth(){return health;}
	std::string getType(){return type;}
	int getLevel(){return level;}

private:
	std::string name; //using qualifiers instead of namespace declaration
	int age;
	int level;
	int health;
	std::string type;
};

struct PkmnTrainer
{
	std::string name;
	double badges;
	std::string starter;
	std::vector<Pokemon*> pkmn;
};

int main(){

	Pokemon myShinx("Luxray", "electric", 36, 122);
	Pokemon myStarly("Staraptor", "flying", 34, 111);

	Pokemon myOtherStarly = myStarly;

	Pokemon* starlyPointer = &myStarly;// WAYYYYY AHEAD

	//std::cout<< starlyPointer->name << std::endl;

	PkmnTrainer *Lucas = new PkmnTrainer; //pokemon trainer on heap
	//WAYYYYYY AHEAD

	Lucas->name = "Lucas";
	Lucas->badges = 8;
	Lucas->starter = "Turtwig";

	Pokemon* shinxPointer = &myShinx;

	Lucas->pkmn.push_back(shinxPointer);
	if (&myStarly == starlyPointer)
	{
			Lucas->pkmn.push_back(starlyPointer);
	} else {
		std::cout<<"Woah, your Starly mutated!"<<std::endl;
	}

	for (int i = 0; i < Lucas->pkmn.size(); ++i)
	{
		std::cout<<Lucas->pkmn[i]->getName()<<std::endl;
		std::cout<<Lucas->pkmn[i]->getType()<<std::endl;
		std::cout<<Lucas->pkmn[i]<<std::endl;
	}

}

