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
	BOOL isdie(POINT ps);//�ж��ӵ��Ƿ����Ŀ��
	BOOL foeisdie(POINT ps);
	manage(myplane *hero,bulletlist *temp, bulletlist *foebtlist,feolist *foe);
	~manage();
private:	
	int y;
	int foenumber;
	IMAGE bkground;
	bulletlist *foebthead;//�����ӵ�
	bulletlist *head;//�ҷ��ӵ�
	feolist *foehead;//����
	myplane *myrole;
};

