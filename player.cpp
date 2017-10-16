#include "player.h"
#include <string>
#include <iostream>

player::player(){
	name="Reimu Harukei";

	hpstat=500;
	atkstat=420;
	spatkstat=30;
	defstat=40;
	spdefstat=15;
	spdstat=65;

	hp=hpstat;
	atk=atkstat;
	spatk=spatkstat;
	def=defstat;
	spdef=spdefstat;
	spd=spdstat;
}

player::player(std::string initialname, int initialhp, int initialatk, int initialspatk, int initialspdef, int initialdef, int initialspd){
	name=initialname;

	hpstat=initialhp;
	atkstat=initialatk;
	spatkstat=initialspatk;
	defstat=initialspd;
	spdefstat=initialspdef;
	spdstat=initialspd;

	hp=hpstat;
	atk=atkstat;
	spatk=spatkstat;
	def=defstat;
	spdef=spdefstat;
	spd=spdstat;
}

void player::basicattack(){
	atktype=0;
	ismagic=false;
	dmgout=5;
	std::cout<<name<<" Attacks with a basic attack!"<<std::endl<<std::endl;
}

void player::attack1(){
	atktype=std::rand()%5;
	ismagic=false;
	dmgout=15;
	std::cout<<name<<" Used Supersonic Elemental Drill!"<<std::endl<<std::endl;
}

void player::attack2(){
	atktype=0;
	ismagic=true;
	dmgout=15;

	hp=hp+10;

	checkhpover();

	std::cout<<name<<" Used Demon Sealing Prayer: Holy Life Steal!"<<std::endl<<std::endl;
}

void player::attack3(){
	atktype=0;
	ismagic=true;
	dmgout=25;
	std::cout<<name<<" Used Max Power Bullet Barrage!"<<std::endl<<std::endl;
	atk=atk+5;
}

void player::attack4(){
	atktype=6;
	ismagic=true;
	dmgout=99;
	std::cout<<name<<" Used Eastern Spell of the Gensokyo Magical Girls: Bullet Hell!"<<std::endl<<std::endl;
}

player::~player(){

}
