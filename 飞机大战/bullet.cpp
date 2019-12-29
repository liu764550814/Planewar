#include"bullet.h"
bullet::bullet(int x, int y)
{
	ps.x = x;
	ps.y = y;
}


bullet::~bullet()
{
}
void bullet::drawbullet()
{
	loadimage(&bullet1, _T("res\\bullet1.png"));
	loadimage(&bullet1mask, _T("res\\bulle1tmask.png"));

	putimage(ps.x, ps.y, 19, 78, &bullet1mask, 0, 0, SRCAND);//贴上掩码图
	putimage(ps.x, ps.y, 19, 78, &bullet1, 0, 0, SRCPAINT);
}


void bullet::drawbullet2()
{
	loadimage(&bullet1, _T("res\\bullet2.png"));
	loadimage(&bullet1mask, _T("res\\bulle2tmask.png"));

	putimage(ps.x, ps.y, 11, 33, &bullet1mask, 0, 0, SRCAND);//贴上掩码图
	putimage(ps.x, ps.y, 11, 33, &bullet1, 0, 0, SRCPAINT);
}

void bullet::movebullet()
{
	ps.y -=10;
}

void bullet::movebullet2()
{
	ps.y += 10;
}

/*
void bullet::addlist(bullet *data)
{
	bulletlist *temp = NULL;
	temp->data = data;
	temp->pNext = NULL;
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
*/
BOOL bullet::byondborder()
{
	if (ps.y < 0)
		return TRUE;
	else
		return FALSE;
/*
	bulletlist *p = head;//循环到的节点
	bulletlist *temp = head;//前一个节点
	while (p->pNext != NULL)
	{
		p = p->pNext;
		if (p->data->ps.y<0)
		{
			if (p->pNext==NULL)
			{
				temp->pNext = NULL;
				delete p;
				p = temp;
				break;
			}
			temp->pNext = p->pNext;
			delete p;
			p = temp;
			continue;
		}
		temp = p;
	}
*/
}

BOOL bullet::byondborder2()
{
	if (ps.y > 800)
		return TRUE;
	else
		return FALSE;
}


POINT bullet::getps()
{
	return ps;
}