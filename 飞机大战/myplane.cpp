#include "myplane.h"


myplane::myplane(int x,int y,bulletlist *temp)
{
	isover = FALSE;
	head = temp;
	ps.x = x;
	ps.y = y;
	HP = 100;
	sore = 0;
}


myplane::~myplane()
{
}

void myplane::drawHP()//显示HP
{
	char a[10];
	sprintf_s(a, "HP:%d", HP);
	outtextxy(0, 750, a);
}
void myplane::drawsore()//显示分数
{
	char a[10];
	sprintf_s(a, "分数:%d", sore);
	outtextxy(0, 780, a);
}


void myplane::drawplane()
{
	loadimage(&planeiamge, _T("res\\hero.png"));
	loadimage(&rolemask, _T("res\\heromask.png"));//先将掩码图指向原图

	putimage(ps.x, ps.y, 101, 78, &rolemask, 0, 0, SRCAND);//贴上掩码图
	putimage(ps.x, ps.y, 101, 78, &planeiamge, 0, 0, SRCPAINT);
}


POINT myplane::getpoint()
{
	return ps;
}
void myplane::shootbullet(int x,int y)
{
	bullet *data = new bullet(x,y);
	bulletlist *temp=new bulletlist;//将新节点加入链表中
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
void myplane::contro()
{

	int up = 0, down = 0, left = 0, right = 0, space = 0;

	left = GetKeyState(VK_LEFT);//获取上下左右按键的状态
	right = GetKeyState(VK_RIGHT);
	up = GetKeyState(VK_UP);
	down = GetKeyState(VK_DOWN);
  	space = GetKeyState(VK_SPACE);//发射子弹
	if (space<0)
	{
		shootbullet(ps.x+42, ps.y-50);
	}
	if (up < 0)
	{
		ps.y -= 10;
		if (ps.y < 0)
			ps.y = 0;
	}
	if (down < 0)
	{
		ps.y += 10;
		if (ps.y > 800-78)
			ps.y = 800 - 78;
	}
			
	if (left < 0)
	{
		ps.x -= 10;
		if (ps.x < 0)
			ps.x = 0;
	}	
	if (right < 0)
	{
		ps.x += 10;
		if (ps.x > 480-101)
			ps.x = 480 - 101;
	}
			


}

void myplane::getmask(IMAGE *pImage, IMAGE* pMask)//得到掩码图
{
	DWORD *pmemImage = GetImageBuffer(&planeiamge);
	DWORD *pmemMask = GetImageBuffer(&rolemask);
	COLORREF mask = pmemImage[0];
	int w = pImage->getwidth();
	int h = pImage->getheight();

	for (int i = 0; i < w*h; i++)
	{
		if (pmemImage[i] <= 0x555555 && pmemImage[i] >= 0x000000)//这个地方他全部执行的else
			pmemMask[i] = WHITE;
		else
			pmemMask[i] = BLACK;
	}

}

void myplane::subHP()
{
	HP -= 10;
	if (HP <= 0)
	{
		if (IDOK == MessageBox(NULL, "你输了", "提示", MB_OK))
			isover = TRUE;
	}
}
void myplane::addsore()
{
	sore += 10;
	if (sore >= 200)
	{
		if (IDOK == MessageBox(NULL, "你赢了", "提示", MB_OK))
			isover = TRUE;
	}
}
BOOL myplane::getisover()
{
	return isover;
}
