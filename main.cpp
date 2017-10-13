#include "game.h"
#include "player.h"
#include "enemy.h"
#include "gameobject.h"
#include "battle.h"

using namespace std;

int main(){
	game newgame = game();
	newgame.gameIntro();
	game* gameptr=&newgame;
	
	std::cout << "Please enter character name..." << std::endl;
	
	string your_name;
	
	std::cin >> your_name;
	
	//e x t e n s i v e t e s t i n g
	player user = player(your_name,69,420,8008135,15);

	enemy enemy1 = enemy();
	enemy enemy2 = enemy();
	enemy enemy3 = enemy();

	enemy1.changename("Monster A");
	enemy2.changename("Monster B");
	enemy3.changename("Monster C");

	//player * reimuptr = &reimu;
	//enemy * enemyptr = &basicenemy;

	battle firstbattle = battle(user,enemy1,enemy2,enemy3,gameptr);
	//std::cout << reimu.getname() << " you are now in a battle with a " << basicenemy.getname() << std::endl;
	//firstbattle.chooseatk();

	/*
	//name and stats testing testing
	std::cout << "The name of your player is " << reimu.getname() << std::endl;
	reimu.changename("Marisa Kirisame");
	std::cout << "The name of your player is now " << reimu.getname() << std::endl;
	*/
	
	return 0;
	
}
