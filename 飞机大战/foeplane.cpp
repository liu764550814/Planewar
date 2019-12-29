#include "foeplane.h"



foeplane::foeplane(bulletlist *temp)
{
	srand(time(NULL));
	Sleep(100);
	head = temp;
	ps.x = rand()% 324;//敌人的出现位置随机
	ps.y = rand() % 100 - 50;
	turndire = rand() % 6;
}


foeplane::~foeplane()
{
}


void foeplane::drawplane()
{
	loadimage(&planeiamge, _T("res\\enemy.png"));
	loadimage(&rolemask, _T("res\\enemymask.png"));//先将掩码图指向原图

	putimage(ps.x, ps.y, 156, 124, &rolemask, 0, 0, SRCAND);//贴上掩码图
	putimage(ps.x, ps.y, 156, 124, &planeiamge, 0, 0, SRCPAINT);
}



void foeplane::shootbullet()
{

	bullet *data = new bullet(ps.x+54, ps.y+90);
	bullet *data1 = new bullet(ps.x + 100, ps.y + 90);
	bulletlist *temp = new bulletlist;//将新节点加入链表中
	bulletlist *temp1 = new bulletlist;
	temp->data = data;
	temp->pNext = temp1;

	temp1->data = data1;
	temp1->pNext = NULL;

	if (head == NULL)
	{
		head->pNext = temp;
	}
	else
	{
		bulletlist *p = head;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = temp;
	}
}


void foeplane::foemove()
{

	switch (turndire)
	{
	case 0:
	{	
		ps.x += 10;
		if (ps.x >= 324)
			turndire = rand() % 6;
	}
		break;
	case 1:
	{
		ps.x -= 10;
		if (ps.x <= 0)
			turndire = rand() % 6;
	}
		break;
	case 2:
	{
		ps.x -= 5;
		ps.y -= 10;
		if (ps.x<=0 || ps.y<=0)
		{
			turndire = rand() % 6;
		}
	}
		break;
	case 3:
	{
		ps.x += 5;
		ps.y -= 10;
		if (ps.x >= 324 || ps.y <= 0)
		{
			turndire = rand() % 6;
		}
	}
		break;
	case 4:
	{
		ps.x += 5;
		ps.y += 10;
		if (ps.x >= 324 || ps.y >= 400)
		{
			turndire = rand() % 6;
		}
	}
	break;
	case 5:
	{
		ps.x -= 5;
		ps.y += 10;
		if (ps.x <= 0 || ps.y >= 400)
		{
			turndire = rand() % 6;
		}
	}
	break;
	default:
		break;
	}

	//int a = rand() % 10;
	//if (1 == a % 2)
	//{
	//	if (1 == rand() % 2)
	//	{	
	//		if (ps.x + 10<=324)
	//		{
	//			ps.x += 10;
	//		}
	//	}
	//	else
	//	{
	//		if (ps.x - 10 >= 0)
	//		{
	//			ps.x -= 10;
	//		}
	//		
	//	}
	//	
	//}
	//else
	//{
	//	if (1 == rand() % 2)
	//	{		
	//		if (ps.y + 10 <= 400)
	//		{
	//			ps.y += 10;
	//		}
	//	}
	//	else
	//	{
	//		
	//		if (ps.y - 10 >= 0)
	//		{
	//			ps.y -= 10;
	//		}
	//	}
	//}
	
}


POINT foeplane::getps()
{
	return ps;
}