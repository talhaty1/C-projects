#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

class startGame {
protected:
	int  level, experience, health;
	int powerSayian, attackSayian, defenceSayian;
	string specialAttack[4];
	int specialAttackDamage[4];
	bool levelUpCheck;

	int enemytype;
	int ePower[3], eDefence[3], eAttack[3];
	int ehealth;
	string especialAttack[3][4];
	int especialAttackDamage[3][4];
	int sAttackSelect, eAttackSelect;

public:
	void setExperience(int experienceParameter) {
		levelUpCheck = false;
		if (level <= 100) {
			experience += experienceParameter;
			if (experience >= 100) {
				if(level <= 100){
					while (level <= 100 && experience >= 100) {
						level++;
						levelUpCheck = true;
						experience -= 100;
					}
				}
				else
					experience = 100;
				if (powerSayian <= 100)
					powerSayian++;
				if (attackSayian <= 100)
					attackSayian++;
				if (defenceSayian <= 100)
					defenceSayian++;
			}
		}
	}
	void updateSAttacks(string attackname, int damage) {
		for (int i = 0; i < 4; i++)
		{
			if (specialAttack[i] == "NULL")
			{
				specialAttack[i] = attackname;
				specialAttackDamage[i] = damage;
				return;
			}
		}
		int option;
		cout << "\nSPECIAL ATTACK LIST IS FULL !\n"
			<< "Do you want to replace any of the following attacks: \n";
		for (int i = 0; i < 4; i++){
			cout << i + 1 << ". " << specialAttack[i] << "\t Damage: " << specialAttackDamage[i] << endl;
		}
		cout << "\nEnter the S.no of the attack which you want to replace OR any other key to skip: ";
		cin >> option;

		if (option >= 1 && option <= 4){
			specialAttack[option-1] = attackname;
			specialAttackDamage[option - 1] = damage;
			return;
		}
		return;
	}

	void eatSenzuBean()
	{
		health = 100;
	}

	void saveGame(){
		ofstream data;
		data.open("DATA");
		data<<level<<endl<<experience<<endl<<health<<endl<<powerSayian<<endl<<attackSayian<<endl<<defenceSayian<<endl;
		data<<specialAttack[0]<<endl<<specialAttack[1]<<endl<<specialAttack[2]<<endl<<specialAttack[3]<<endl;
		data<<specialAttackDamage[0]<<endl<<specialAttackDamage[1]<<endl<<specialAttackDamage[2]<<endl<<specialAttackDamage[3]<<endl;
		data.close();
	}

	void loadGame(){
		ifstream data;
		data.open("DATA");
		if(!data){
			cout<<"\nRECORD NOT FOUND\n";
		}
		else{
			data>>level;
			data>>experience;
			data>>health;
			data>>powerSayian;
			data>>attackSayian;
			data>>defenceSayian;
			data.ignore(100,'\n');
			getline(data,specialAttack[0]);
			getline(data,specialAttack[1]);
			getline(data,specialAttack[2]);
			getline(data,specialAttack[3]);
			
			data>>specialAttackDamage[0];
			data>>specialAttackDamage[1];
			data>>specialAttackDamage[2];
			data>>specialAttackDamage[3];
			data.close();
		}
	}

};

class Sayian : public startGame {
public:
	void printAttributes(){
		cout << "\n\t\tSAYIAN\n\n"
			<< "POWER: " << powerSayian << "\tDEFENCE: " << defenceSayian << "\tATTACK: " << attackSayian
			<< "\tHEALTH: " << health << "\tEXPERIENCE: " << experience <<"\tLEVEL: "<<level<< endl
			<< "\nSPECIAL ATTACKS:\n";
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << ". " << specialAttack[i] << "\t Damage: " << specialAttackDamage[i] << endl;
		}
	}

	void levelUP() {
		string newAttack;
		int damage;
		if (level == 5) {
			cout << "\nNew Special Attack Unlocked:  Kamehameha\n";
			newAttack = "Kamehameha";
			damage = 15;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 10) {
			cout << "\nNew Special Attack Unlocked:  Kaioken\n";
			newAttack = "Kaioken";
			damage = 14;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 16) {
			cout << "\nNew Special Attack Unlocked:  Spirit Bomb\n";
			newAttack = "Spirit Bomb";
			damage = 40;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 23) {
			cout << "\nNew Special Attack Unlocked:  Galick Gun\n";
			newAttack = "Galick Gun";
			damage = 16;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 25) {
			cout << "\nNew Special Attack Unlocked:  Super Sayian\n";
			newAttack = "Super Sayian";
			damage = 40;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 30) {
			cout << "\nNew Special Attack Unlocked:  Final Flash\n";
			newAttack = "Final Flash";
			damage = 20;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 35) {
			cout << "\nNew Special Attack Unlocked:  Super Sayian 2\n";
			newAttack = "Super Sayian 2";
			damage = 50;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 40) {
			cout << "\nNew Special Attack Unlocked:  Instant Transmission\n";
			newAttack = "Instant Transmission";
			damage = 15;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 42) {
			cout << "\nNew Special Attack Unlocked:  Super Sayian 3\n";
			newAttack = "Super Sayian 3";
			damage = 55;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 50) {
			cout << "\nNew Special Attack Unlocked:  Super Sayian God\n";
			newAttack = "Super Sayian God";
			damage = 70;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 60) {
			cout << "\nNew Special Attack Unlocked:  Super Sayian Blue\n";
			newAttack = "Super Sayian Blue";
			damage = 78;
			updateSAttacks(newAttack, damage);
		}
		else if (level == 70) {
			cout << "\nNew Special Attack Unlocked:  Ultra Instinct\n";
			newAttack = "Ultra Instict";
			damage = 85;
			updateSAttacks(newAttack, damage);
		}
	}

	
	void setEnemyAttributes() {
		for (int i = 0; i < 3; i++) {
			ePower[i] = 10 + (i * 25);
			eDefence[i] = 5 + (i * 23);
			eAttack[i] = 7 + (i * 20);
		}
		especialAttack[0][0] = "Kick"; especialAttack[0][1] = "Punch";
		especialAttack[0][2] = "NULL"; especialAttack[0][3] = "NULL";

		especialAttack[1][0] = "Power Blast"; especialAttack[1][1] = "Special Beam Cannon";
		especialAttack[1][2] = "Distructo Disk"; especialAttack[1][3] = "Masenko";

		especialAttack[2][0] = "Tri Beam"; especialAttack[2][1] = "Big Bang Attack";
		especialAttack[2][2] = "Death Storm"; especialAttack[2][3] = "Transformation";

		especialAttackDamage[0][0] = 2; especialAttackDamage[0][1] = 3;
		especialAttackDamage[0][2] = 0; especialAttackDamage[0][3] = 0;

		especialAttackDamage[1][0] = 10; especialAttackDamage[1][1] = 15;
		especialAttackDamage[1][2] = 20; especialAttackDamage[1][3] = 25;

		especialAttackDamage[2][0] = 30; especialAttackDamage[2][1] = 40;
		especialAttackDamage[2][2] = 45; especialAttackDamage[2][3] = 50;
	}
	void ecalculateDamage(int attackType) {
		if(specialAttackDamage[attackType]!=0){
			ehealth = (ehealth - (specialAttackDamage[attackType] + attackSayian + powerSayian) / 3) +
				eDefence[enemytype] / 10;
		}
	}

	void scalculateDamage(int attackType) {
			if(especialAttackDamage[enemytype][attackType]!=0){
			health = (health - (especialAttackDamage[enemytype][attackType] + eAttack[enemytype] + ePower[enemytype]) / 3) + defenceSayian/10;
		}
	}

	bool fight() {
		srand(time(0));
		while (health > 0 && ehealth > 0) {
			system("CLS");
			cout << "\nYOUR HEALTH :  " << health << "\t\tENEMY HEALTH :  " << ehealth << endl;
			cout << "\n\nENTER S.NO OF THE ATTACK: \n";
			for (int j = 0; j < 4; j++) {
				cout << j + 1 << ". " << specialAttack[j] << "\t Damage: " << specialAttackDamage[j] << endl;
			}
			cin >> sAttackSelect;
			sAttackSelect--;
			ecalculateDamage(sAttackSelect);
			if(enemytype==0)
				eAttackSelect = rand() % 2;
			else
				eAttackSelect = rand() % 4;

			cout << "\n\nENEMY ATTACK: " << especialAttack[enemytype][eAttackSelect] << endl << endl;
			scalculateDamage(eAttackSelect);
			system("PAUSE");
		}

		if (health <= 0) {
			cout << "YOU LOST !";
			return false;
		}
		else if(ehealth <= 0){
			if (enemytype == 0)
				setExperience(70);
			else if (enemytype == 1)
				setExperience(95);
			else if (enemytype == 2)
				setExperience(150);
		}
		if (levelUpCheck == true)
			levelUP();
		return true;
	}

	void setEnemyType() {
		cout << "ENEMIES:\n\n1.EASY\t\t2.NORMAL\t\t3.HARD\n\n"
			<< "\nEnter the S.NO of the Enemy you want to face: ";
		cin >> enemytype;
		enemytype--;
		ehealth = 100;
		if (enemytype < 0 && enemytype >2)
			cout << "WRONG INPUT !  TRY AGAIN";
	}


	Sayian() {
		level = 1; experience = 0; health = 100;
		powerSayian = 10; attackSayian = 8; defenceSayian = 7;
		specialAttack[0] = "Power Blast"; specialAttack[1] = "Flying kick";
		specialAttack[2] = "NULL"; specialAttack[3] = "NULL";
		specialAttackDamage[0] = 3; specialAttackDamage[1] = 2;
		specialAttackDamage[2] = 0; specialAttackDamage[3] = 0;
	}
};


int main()
{
	bool gameOver = true;
	Sayian s;
	int option;
	while (gameOver) {
		cout << "\n1. print Attributes\n"
			<< "2. Eat Senzu Bean\n"
			<< "3. Fight\n"
			<<"4. SAVE GAME\n"
			<<"5. LOAD GAME\n";
		cin >> option;
		if (option == 1) {
			s.printAttributes();
			system("PAUSE");
			system("CLS");
		}
		else if (option == 2) {
			s.eatSenzuBean();
			cout << "\n\nHEALTH == MAX\n";
		}
		else if (option == 3) {
			s.setEnemyAttributes();
			s.setEnemyType();
			gameOver = s.fight();
		}
		else if(option==4){
			s.saveGame();
		}
		else if(option==5){
			s.loadGame();
		}
	}
}