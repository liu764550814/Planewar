#pragma once
#include<process.h>
#include"bulletlist.h"
#include<stdio.h>

class myplane
{
public:
	myplane(int x, int y, bulletlist *temp);
	~myplane();
	void drawplane();
	 void shootbullet(int x, int y);
     void contro();
	void getmask(IMAGE *pImage, IMAGE* pMask);
	POINT getpoint();
	void drawsore();
	void drawHP();
	void subHP();
	void addsore();
	BOOL getisover();
private:
	bulletlist *head;
	IMAGE planeiamge;
	IMAGE rolemask;
	POINT ps;
	BOOL isover;//ÊÇ·ñ½áÊø
	int HP;
	int sore;
	
};

