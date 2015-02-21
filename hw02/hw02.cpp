//hw02
//Rafi Rizwan
//N12265380


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Weapon{
public:
	Weapon(){}
	Weapon(const string& nm, const int stg):name(nm), power(stg){}

	string getName()const{return name;}
	int getStrength()const{return power;}
	void setStrength(const int s){
		power = s;
	}

private:
	string name;
	int power;
};

class Warrior{
public:
	Warrior(const string& nm, const string& wnm, const int wpPwr):name(nm){
	Weapon w(wnm, wpPwr);
	weapon = w;
	}

	string getName()const{return name;}
	int getStrength()const{return weapon.getStrength();}
	void setStrength(const int s){
		// cout << "NEW WEAPON POWER: " << s << endl;
		weapon.setStrength(s);
		// cout << weapon.getStrength() << endl;
	}
	bool isAlive()const{return alive;}
	void getWeapon(){
		// cout << "\t Weapon Name: "<< weapon.getName() << endl;
		// cout << "\t Weapon Strength: " << weapon.getStrength() << endl;
	}

	void reportWarriorStatus(){
		cout << "WARRIOR: " << name << "\n \t WEAPON: " << weapon.getName() << endl;
		cout << "Status: ";
		if (weapon.getStrength() > 0){
			cout << "ALIVE\n";
		} else {
			cout << "DEAD\n";
		}
		cout << "\n------------------------------\n\n"; 
	}

	void fight(Warrior& opponent, vector<Warrior>& warriors){

		// cout << endl << opponent.getStrength() << endl;
		// cout << endl << weapon.getStrength() << endl;

		cout << "------------------------------\n";
		cout << name << " is set to face off against " << opponent.getName() << "!\n";


		if (weapon.getStrength() > 0 && opponent.getStrength() > 0){
			if (weapon.getStrength() > opponent.getStrength()){
				weapon.setStrength(weapon.getStrength()-opponent.getStrength());
				opponent.setStrength(0);
				cout << name <<" wins" << endl;
			} else if (weapon.getStrength() < opponent.getStrength()){
				opponent.setStrength(opponent.getStrength()-weapon.getStrength());
				weapon.setStrength(0);
				cout << opponent.getName() << " wins" << endl;
			} else {
				weapon.setStrength(0);
				opponent.setStrength(0);
				cout << "WHAT A MATCH!!!\nMutual Annihilation! Both are dead!" << endl;
			}
		} else {
			if (weapon.getStrength() <= 0)
			{
				cout << name <<" is already dead!\n" << "The opponent " << opponent.getName() << " wins by default!\n";
			} else {
				cout << "The opponent, "<< opponent.getName() <<" is already dead!\n" << name << " wins by default!\n";
			}
			
		}
		
		cout << "------------------------------\n";
	}

private:
	Weapon weapon;
	string name;
	bool alive;

};

void createWarrior(ifstream& datafile, vector<Warrior>& fighters){
	cout << "The following are our contenders today!\n\n";
	string name;
	string weaponName;
	int strength;
	string infoType;
	while(datafile >> infoType >> name >> weaponName >> strength){
		if (infoType == "Warrior"){
			Warrior somebody(name, weaponName, strength);
			fighters.push_back(somebody);
		}
	}
	datafile.clear();
	datafile.seekg(0);
}

void reportStatus(vector<Warrior>& v){
	for (Warrior w : v){
		w.reportWarriorStatus();
	}
}

void executeProgram(ifstream& datafile, vector<Warrior>& fightingFighters){
	string name;
	string name2;
	string infoType;
	int strength1;
	int strength2;
	//cout << "LET THE GAMES BEGIN!" << endl;

	while(datafile >> infoType){
		if (infoType == "Status"){
			reportStatus(fightingFighters);
			datafile.ignore();
		}
		else if (infoType == "Battle"){
			datafile >> name >> name2;
			for (int k = 0; k < fightingFighters.size(); ++k){
				if (fightingFighters[k].getName() == name){
					for (int i = 0; i < fightingFighters.size(); ++i){
						if (fightingFighters[i].getName() == name2){
							fightingFighters[k].fight(fightingFighters[i], fightingFighters);
						}
					}
				}
			}
		}
	}

	cout << "Our victors are: \n";
	for (Warrior w: fightingFighters){
		if (w.getStrength()>0){
			cout << w.getName() << endl;
		}
	}			
}


int main(){

	vector<Warrior> warriors;
	ifstream datafile("warriors.txt");
	if (!datafile){
		cerr << "File not found. Please provide a valid file for use." << endl;
		exit(1);
	}
	createWarrior(datafile, warriors);
	executeProgram(datafile, warriors);

	return 0;
}