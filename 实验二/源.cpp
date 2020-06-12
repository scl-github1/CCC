#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct player
{
	char player[10];
	int id[5];
};
struct player p1 = { "Player1",0};
struct player p2 = { "Player2",0 };
int card[52];//洗牌后
int cardnum;
struct strcolor
{
	char cha[5];
}color[4] = { "红桃","黑桃","梅花","方片" };
struct strpoint
{
	char cha[3];
}point[13]= { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
struct strclass
{
	char cha[11];
}cardclass[9] = { "takeplace ","flush     ","straight  ","four      ","full_house","three     ","two_paires","pair      ","nothing   " };
int inc(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
//洗牌
void Shuffle()
{
	int i,j;
	int lib[52];
	int cardleft = 52;
	int temp;
	cardnum = 52;
	for (i = 0; i < 52; i++)
	{
		lib[i] = i;
	}
	for (j = 0; j < 52;j++)
	{
		temp = rand()% cardleft;
		cardleft = cardleft - 1;
		card[j] = lib[temp];
		for (i = temp; i <cardleft; i++)
		{
			lib[i] = lib[i + 1];
		}
	}
}
//切牌
void Cut()
{
	int i, temp;
	for (i = 0; i < 26; i++)
	{
		temp = card[i];
		card[i] = card[i + 26];
		card[i + 26] =temp;
	}
}
//发牌
void newcard(int n)
{
	int i;
	if (n == 1)
	{
		for (i = 0; i < 5; i++)
		{
			p1.id[i] = card[i];
		}
	}
	else if (n == 2)
	{
		for (i = 0; i < 5; i++)
		{
			p2.id[i] = card[i];
		}
	}
	for (i =0; i < cardnum-5; i++)
	{
		card[i] = card[i + 5];
	}
	cardnum = cardnum - 5;
}
int analyse(int n)
{
	int i;
	struct player ana;
	int diffcolor = 0;//不同花为1，同花0
	int num1 = 0;
	int num0 = 0;
	int num00 = 0;
	int ladder[4] = { 2,2,2,2 };
	int storec[5];
	int storep[5];
	int cardclass=0;
	if (n == 1)
	{
		ana = p1;
	}
	else if (n == 2)
	{
		ana = p2;
	}
	for (i = 0; i < 5; i++)
	{
		storep[i] = ana.id[i] % 13;
		storec[i] = ana.id[i]  /  13;
	}
	/////////////////////////////花色////////////////////////////
	for (i = 0; i < 4; i++)
	{
		if (storec[i] != storec[i + 1])
		{
			diffcolor++;
		}
	}
	/////////////////////////////点数////////////////////////////
	qsort(storep, 5 ,sizeof(int),inc);
	for (i = 0; i < 4; i++)
	{
		ladder[i] = storep[i + 1] - storep[i];
	}
	for (i = 0; i < 4; i++)
	{
		if (ladder[i] == 1) { num1++; }
		if (ladder[i] == 0) { num0++; }
	}
	for (i = 0; i < 3; i++)
	{
		if ((ladder[i] == 0)&&(ladder[i+1] == 0))
		{ num00++; }
	}
	if ((diffcolor == 0) && (num1 == 4)) { cardclass = 1; }
	else	if ((diffcolor == 1) && (num1 == 4)) { cardclass = 2; }
	else	if ((num0 == 3) && (num00 == 2)) { cardclass = 3; }
	else	if ((num0 == 3) && (num00 == 1)) { cardclass = 4; }
	else	if ((num0 == 2) && (num00 == 1)) { cardclass = 5; }
	else	if ((num0 == 2) && (num00 == 0)) { cardclass = 6; }
	else	if ((num0 == 1)) { cardclass = 7; }
	else { cardclass = 8; }
	return cardclass;
}
void show(int n)
{
	struct player user;
	int cardcla = analyse(n);
	if (n == 1)
	{
		user = p1;
	}
	else if (n == 2)
	{
		user = p2;
	}
	int i;
	int c, p;
	printf_s("--------------------------------------------------\n");
	printf_s("玩家%s的手牌是\n", user.player);
	for (i = 0; i < 5; i++)
	{
		c = user.id[i] / 13;
		p = user.id[i] % 13;
		printf_s("%s-%s\t", color[c].cha, point[p].cha);
	}
	printf_s("\n--------------------------------------------------\n");
	printf_s("是");
	printf_s("%s\n", cardclass[cardcla].cha);
	printf_s("--------------------------------------------------\n" );
}
void cheat()
{
	int i;
	int cardser[5] = {13*0+0,13*0+1,13*0+2,13*0+3,13*0+4 };
	for (i = 0; i < 5; i++)
	{
		p1.id[i] = cardser[i];
	}
}
void statisic()
{
	int i;
	 double times = 1000000;
	double statcla[9] = { 0 };
	double per;
	printf_s("共进行了%.0f次实验\n", times);
	for (i = 0; i <times; i++)
	{
		Shuffle();
		newcard(1);
		statcla[analyse(1)]++;
	}
	for (i = 1; i < 9; i++)
	{
		per =( statcla[i] / times)*100;
		printf_s("%s\t出现了%.0f次\t\t占%.3f%%",cardclass[i].cha,statcla[i],per);
		printf_s("\n");
	}

}
void comp()
{
	int class1 = analyse(1);
	int class2 = analyse(2);
	printf_s("--------------------------------------------------\n");
	if (class1 > class2)
	{
		printf_s("玩家2胜出\n");
	}
	else if (class1< class2)
	{
		printf_s("玩家1胜出\n");
	}
	else
	{
		printf_s("平局\n");
	}
	printf_s("--------------------------------------------------\n" );
}
int main()
{
	int opt=8;
	Shuffle();
	newcard(1);
	newcard(2);
	printf_s("已经初始洗牌发牌\n");
	while (opt)
	{
		printf_s("\n\n\n");
		if (cardnum < 20)
		{
			printf_s("牌库快空了，请洗牌!!!\n");
		}
		printf_s("输入对应序号以进行操作\n");
		printf_s("1.再次洗牌\n");
		printf_s("2.再次为玩家1发牌\n");
		printf_s("3.再次为玩家2发牌\n");
		printf_s("4.亮牌\n");
		printf_s("5.再次洗牌并切牌\n");
		printf_s("9.运行统计程序\n");
		printf_s("0.退出\n");
		scanf_s("%d",&opt);
		printf_s("%d\n",opt);

		switch (opt)
		{
		case 1:Shuffle();	break;
		case 2:newcard(1); break;
		case 3:newcard(2); break;
		case 4:
			show(1);
			show(2);
			comp();
			break;
		case 5:Shuffle(); Cut(); break;
		case 6:cheat(); break;
		case 9:statisic();break;
		}
	}
	printf_s("程序");
	return 0;

}
