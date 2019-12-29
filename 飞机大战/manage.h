#pragma once
#include"bulletlist.h"
#include"myplane.h"
#include"feolist.h"
#include"foeplane.h"
class manage
{
public:
	void start();
	void drawbg();
	void bgmove();
	void bulletcontro();
	void drawdie(POINT ps);
	void addfoe(foeplane *foe);
	void foecontro();
	void addfoe();
	void subfoe();
	int getfoenumber();
	BOOL isdie(POINT ps);//判断子弹是否击中目标
	BOOL foeisdie(POINT ps);
	manage(myplane *hero,bulletlist *temp, bulletlist *foebtlist,feolist *foe);
	~manage();
private:	
	int y;
	int foenumber;
	IMAGE bkground;
	bulletlist *foebthead;//敌人子弹
	bulletlist *head;//我方子弹
	feolist *foehead;//敌人
	myplane *myrole;
};

