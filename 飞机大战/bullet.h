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

	void drawbullet2();//���˵��ӵ�
	void movebullet2();//�����ӵ����ƶ�
	BOOL byondborder2();//���˵��ӵ�

	POINT getps();
	//void addlist(bullet *data);
private:
	IMAGE bullet1, bullet1mask;
	POINT ps;
};

