#pragma once
#include<graphics.h>
class bullet
{
public:
	bullet(int x,int y);
	~bullet();
	void drawbullet();
	void movebullet();
	BOOL byondborder();

	void drawbullet2();//敌人的子弹
	void movebullet2();//敌人子弹的移动
	BOOL byondborder2();//敌人的子弹

	POINT getps();
	//void addlist(bullet *data);
private:
	IMAGE bullet1, bullet1mask;
	POINT ps;
};

