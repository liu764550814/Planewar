#pragma once
#include"bulletlist.h"
//#include"feolist.h"
#include<graphics.h>
#include<time.h>


class foeplane
{
public:
	foeplane(bulletlist *temp);
	~foeplane();
	void drawplane();
	void foemove();
	void shootbullet();
	POINT getps();
private:
	//feolist *listhead;
	int turndire;
	bulletlist *head;//敌人发射的子弹
	IMAGE planeiamge;
	IMAGE rolemask;
	POINT ps;

};

