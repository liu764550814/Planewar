#include"manage.h"

manage::manage(myplane *hero,bulletlist *temp, bulletlist *foebtlist, feolist *foe)
{
	srand(time(NULL));


	myrole = hero;

	foebthead = foebtlist;
	foebthead->pNext = NULL;

	head = temp;
	head->pNext = NULL;

	foehead = foe;
	foehead->pNext = NULL;

	foenumber = 0;
	this->y = 0;
}

void manage::addfoe(foeplane *foe)
{
	feolist *temp = new feolist;//将新敌人点加入链表中
	temp->data = foe;
	temp->pNext = NULL;
	if (foehead == NULL)
	{
		foehead->pNext = temp;
	}
	else
	{
		feolist *p = foehead;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = temp;
	}
}

manage::~manage()
{
}

void manage::start()
{
	IMAGE startimage;
	initgraph(429, 200);
	loadimage(&startimage, _T("res\\name.png"));
	putimage(0,0, 429, 82, &startimage, 0, 0, SRCPAINT);
	
	outtextxy(100, 90, "↑↓←→为方向键，space发子弹");
	outtextxy(150, 130, "按enter继续...");
	getchar();
	closegraph();
}

void manage::drawbg()
{
	loadimage(&bkground, _T("res\\bg.jpg"));
	putimage(0, -800+y,480,1600, &bkground, 0,0, SRCPAINT);
	putimage(0, -2400+y, 480, 1600, &bkground, 0, 0, SRCPAINT);
	bgmove();
	if (y>=1600)
		y = 0;

}



void manage::bgmove()
{
	y+=5;
}


void manage::bulletcontro()
{
	if (head->pNext != NULL)//遍历自己子弹链表
	{
		bulletlist *p = head;
		bulletlist *temp = head;
		while (p->pNext != NULL)
		{
			p = p->pNext;
			p->data->movebullet();
			if(foeisdie(p->data->getps()))
			{
				subfoe();
				if (p->pNext == NULL)//让击中飞机的子弹消失
				{
					temp->pNext = NULL;
					delete p->data;
					delete p;
					break;
				}
				else
				{
					temp->pNext = p->pNext;
					delete p->data;
					delete p;
					p = temp;
					continue;
				}

				
			}
			else
				p->data->drawbullet();
			if (p->data->byondborder())
			{
				if (p->pNext==NULL)
				{
					temp->pNext = NULL;
					delete p->data;
					delete p;
					break;
				}
				else
				{
					temp->pNext = p->pNext;
					delete p->data;
					delete p;
					p = temp;
					continue;
				}
			}
			temp = p;

		}
	}


	if (foebthead->pNext != NULL)//遍历敌人子弹链表
	{
		bulletlist *p = foebthead;
		bulletlist *temp = foebthead;
		while (p->pNext != NULL)
		{
			p = p->pNext;
			p->data->movebullet2();
			if (isdie(p->data->getps()))//判断是否被击中
			{
				if (p->pNext == NULL)//让击中飞机的子弹消失
				{
					temp->pNext = NULL;
					delete p->data;
					delete p;
					break;
				}
				else
				{
					temp->pNext = p->pNext;
					delete p->data;
					delete p;
					p = temp;
					continue;
				}
			}
			else
				p->data->drawbullet2();
			if (p->data->byondborder2())//子弹是否超出屏幕
			{
				if (p->pNext == NULL)
				{
					temp->pNext = NULL;
					delete p->data;
					delete p;
					break;
				}
				else
				{
					temp->pNext = p->pNext;
					delete p->data;
					delete p;
					p = temp;
					continue;
				}
			}
			temp = p;
		}
	}
	
}

void manage::foecontro()
{
	if (foehead->pNext != NULL);
	feolist *p = foehead;
	while (p->pNext!=NULL)
	{
		p = p->pNext;
		p->data->foemove();
		p->data->drawplane();
		if ((rand() % 20)==7)
		{
			p->data->shootbullet();
		}
	}
}

void manage::drawdie(POINT ps)
{
	IMAGE mask, die;
	loadimage(&die, _T("res\\die1.png"));
	loadimage(&mask, _T("res\\die1mask.png"));//先将掩码图指向原图

	putimage(ps.x+25, ps.y, 296, 305, &mask, 0, 0, SRCAND);//贴上掩码图
	putimage(ps.x+25, ps.y, 296, 305, &die, 0, 0, SRCPAINT);
}



BOOL  manage::isdie(POINT ps)//判断是否被击中
{
	POINT tempps = myrole->getpoint();
	if ((tempps.y + 16 < ps.y && ps.y < tempps.y + 32 && tempps.x < ps.x && ps.x < tempps.x + 101) || (tempps.y < ps.y && ps.y < tempps.y + 76 && tempps.x + 43 < ps.x && ps.x < tempps.x + 60))//敌人子弹击中我的飞机
	{
		drawdie(myrole->getpoint());//画出爆炸
		myrole->subHP();
		return TRUE;
	}
	else
		return FALSE;
}

BOOL manage::foeisdie(POINT ps)
{
	feolist *p = foehead;
	feolist *temp = foehead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
		if ((p->data->getps().y < ps.y && ps.y < p->data->getps().y + 116 && p->data->getps().x +70 < ps.x && ps.x < p->data->getps().x + 87) || (p->data->getps().y+65 < ps.y && ps.y < p->data->getps().y + 89 && p->data->getps().x +0 < ps.x && ps.x < p->data->getps().x + 120))
		{
			drawdie(p->data->getps());//画出爆炸
			myrole->addsore();
			if (p->pNext==NULL)
			{
				temp->pNext = NULL;
				delete p->data;
				delete p;
				return TRUE;
			}
			else
			{
				temp->pNext = p->pNext;
				delete p->data;
				delete p;
				return TRUE;
			}
		}	
		temp = p;
	}
	return FALSE;
}



void manage::addfoe()
{
	foenumber++;
}
void manage::subfoe()
{
	foenumber--;
}

int manage::getfoenumber()
{
	return foenumber;
}

