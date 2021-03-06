#include <iostream>
#include <string>
#include <stdlib.h>
#include "battle.h"

battle::battle(){
	//be careful, think about what might happen if you construct and empty battle array with nothing in it. Remember to take precautions with this (later on though because too lazy).
}

battle::battle(player user, enemy enemy1){
	battlearray=new gameobject[2];
	battlearray[0]=user;
	battlearray[1]=enemy1;
	currentturn=0;
	currentlyattacking=0;
	participants=2;
	p();
	//std::cout << battlearray[0].getname() << " you are now in a battle with a " << battlearray[1].getname() << std::endl;
}

void battle::battleturn(){
	currentturn++;
	currentlyattacking=currentturn%(participants-1);
	std::cout << currentturn << std::endl;
	//if(battlearray[1].dead()==false){
	//	enemyatk();
	//}
}
/*
void battle::checkalive(gameobject obj){
	for(int i=0;i<participants;i++){
		if(obj.dead()==true){
			participants--;		
		}
	}
}*/

void battle::chooseatk(){
		std::cout << "which attack would you like to use?" << std::endl;

		while(ischoosing==true){
			std::cin >> atknumber;

			if(atknumber=="0"){ //could use an attack array here to speed things up
				ischoosing=false;
				battlearray[1].takedmg(0);  //need to determine an algorithm for damage taken
				battlearray[0].basicattack();  //this needs to be better defined 
				std::cout<<"Enemy 1 has  "<<battlearray[1].check_hp()<<"  hp"<<std::endl;
				//ischoosing=true;
			}

			else if(atknumber=="1"){
				ischoosing=false;
				battlearray[1].takedmg(1);
				battlearray[0].attack1();
				std::cout<<"Enemy 1 has  "<<battlearray[1].check_hp()<<"  hp"<<std::endl;
				//ischoosing=true;
			}

			else if(atknumber=="2"){
				ischoosing=false;
				battlearray[1].takedmg(2);
				battlearray[0].attack2();
				std::cout<<"Enemy 1 has  "<<battlearray[1].check_hp()<<"  hp"<<std::endl;
				//ischoosing=true;
			}

			else if(atknumber=="3"){
				ischoosing=false;
				battlearray[1].takedmg(3);
				battlearray[0].attack3();
				std::cout<<"Enemy 1 has  "<<battlearray[1].check_hp()<<"  hp"<<std::endl;
				//ischoosing=true;
			}

			else if(atknumber=="4"){
				ischoosing=false;
				battlearray[1].takedmg(4);
				battlearray[0].attack4();
				std::cout << "Enemy 1 has  "<<battlearray[1].check_hp()<<"  hp"<<std::endl;
				//ischoosing=true;
			}

			else{
				std::cout << "you only have a basic attack (0) and 4 special attacks (1-4) at the moment, please choose a number between 1-4 for your basic attack" << std::endl;
			}
		}
		if(battlearray[1].check_hp()>0){
			battleturn();
			enemyatk();
		}	
		else{
			//destroy enemy
		}	
}

void battle::enemyatk(){
	int random=rand()%5;
		if(random>4||random<0){
				std::cout << "Enemy attack error" << std::endl;
			}

			else if(random==0){
				battlearray[1].basicattack();
				battlearray[0].takedmg(0);
				std::cout<<"Reimu has  "<<battlearray[0].check_hp()<<"  hp"<<std::endl;
			}

			else if(random==1){
				battlearray[1].attack1();
				battlearray[0].takedmg(1);
				std::cout<<"Reimu has  "<<battlearray[0].check_hp()<<"  hp"<<std::endl;
			}

			else if(random==2){
				battlearray[1].attack2();
				battlearray[0].takedmg(2);
				std::cout<<"Reimu has  "<<battlearray[0].check_hp()<<"  hp"<<std::endl;
			}

			else if(random==3){
				battlearray[1].attack3();
				battlearray[0].takedmg(3);
				std::cout<<"Reimu has  "<<battlearray[0].check_hp()<<"  hp"<<std::endl;
			}

			else if(random==4){
				battlearray[1].attack4();
				battlearray[0].takedmg(4);
				std::cout<<"Reimu has  "<<battlearray[0].check_hp()<<"  hp"<<std::endl;
			}
			
		if(battlearray[0].check_hp()>0){
			ischoosing=true;
			chooseatk();
		}
			
}

void battle::p(){
	if(battlearray[1].dead()==false){  // this is no longer needed if the above stuff works
		chooseatk();
	}
}

battle::~battle(){
	delete[] battlearray;
}
/*
Test cases for attacking and taking damage

Run game and go through attacks 0-4. Enemy is taking damage accordingly. 
Type in any other number and it gives the error string. 

Now to test if it dies? 
*/