#include<stdio.h>
#include"main.h"


int main()
{
	



	bulletlist *mybtlist = new bulletlist;
	bulletlist *foebtlist = new bulletlist;
	feolist *foelist = new feolist;
	//list->data = NULL;
	//list->pNext = NULL;

	myplane role(200, 650, mybtlist);
	manage manager(&role, mybtlist, foebtlist, foelist);
	
	manager.start();

	initgraph(480, 800);
	while (!role.getisover())
	{

		cleardevice();
		BeginBatchDraw();//∑¿÷π…¡∆¡

		manager.drawbg();

		role.drawplane();
		role.contro();

		manager.foecontro();

		manager.bulletcontro();

		role.drawHP();
		role.drawsore();
		if (manager.getfoenumber() < 6 && rand() % 10 == 2)
		{
			foeplane *foe = new foeplane(foebtlist);
			manager.addfoe(foe);
			manager.addfoe();
		}


		FlushBatchDraw();//∑¿÷π…¡∆¡
		EndBatchDraw();//∑¿÷π…¡∆¡
		Sleep(100);

	}

	delete foebtlist;
	delete mybtlist;
	delete foelist;
	closegraph();
	return 0;
	
}