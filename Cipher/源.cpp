#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<string.h>
#include<math.h>
#include "gra.cpp"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define CIPHERROOM 50
#define ROOMSHOW 100
#define Caesarseed 4
#define Multseed 7
#define Affadd 17
#define Affmult 15
typedef struct cipher
{
	int type = 0;
	char id[CIPHERROOM] = { 0 };
	char password[CIPHERROOM] = { 0 };
} cip;
cip p;//明文
cip c;//密文
int gslot = 0;
int offset = 0;
int getopt(FILE* fp)
{
	initgraph(1000, 500);
	MOUSEMSG m;
	cip ci;
	int distan;
	int i, j, w = 1;
	int x, y, opt = 0;
	char k[5];
	char numgslot[5];
	char stroff[5];
	setfillcolor(RED);
	solidcircle(700, 270, 20);
	outtextxy(740, 270, "已使用");
	setfillcolor(GREEN);
	solidcircle(850, 270, 20);
	outtextxy(890, 270, "未使用");
	rectangle(100, 300, 300, 400);
	outtextxy(150, 340, "输入一组数据");
	rectangle(400, 300, 600, 400);
	outtextxy(450, 340, "输出一组数据");
	rectangle(700, 300, 900, 400);
	outtextxy(790, 340, "退出");
	outtextxy(100, 250, "槽位选择：");

	if (gslot)
	{
		outtextxy(100, 420, "槽位:");
		_itoa_s(gslot, numgslot, 10);
		outtextxy(140, 420, numgslot);
		outtextxy(100, 440, "用户名:");
		outtextxy(160, 440, p.id);
		outtextxy(100, 460, "密码:");
		outtextxy(160, 460, p.password);
	}
	else
	{
		outtextxy(160, 440, "该槽未存贮值");
		outtextxy(160, 460, "该槽未存贮值");
	}
	for (j = 20; j < 210; j += 60)
	{
		for (i = 20; i < 1000; i += 40)
		{

			_itoa_s(w, k, 10);
			outtextxy(i - 5, j + 20, k);

			fseek(fp, (w - 1) * sizeof(cip), SEEK_SET);
			fread(&ci, sizeof(cip), 1, fp);
			if (ci.type)
			{
				setfillcolor(RED);
				solidcircle(i, j, 20);
				ci.type = 0;
			}
			else
			{
				setfillcolor(GREEN);
				solidcircle(i, j, 20);
			}
			w++;
		}
	}
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			char s[24];
			x = m.x / 100;
			y = m.y / 100;
			opt = 99;
			sprintf_s(s, "[%d,%d,%d]", m.x, m.y, opt);
			setfillcolor(BLACK);
			solidrectangle(10, 450, 100, 480);
			outtextxy(10, 450, s);
			if (y == 3)
			{
				if ((x - 1) / 2 == 0) { opt = 1; break; }
				if ((x - 4) / 2 == 0) { opt = 2; break; }
				if ((x - 7) / 2 == 0) { opt = 0; break; }
			}
			if (m.y <= 221)
			{
				for (j = 20; j < 210; j += 60)
				{
					for (i = 20; i < 1000; i += 40)
					{
						distan = pow(i - m.x, 2) + pow(j - m.y, 2);
						if (distan <= 400)
						{
							offset = 25 * ((j - 20) / 60) + ((i - 20) / 40)+1;
							_itoa_s(offset, stroff, 10);
							setfillcolor(BLACK);
							solidrectangle(200, 250, 300, 270);
							outtextxy(200, 250, stroff);
						}
					}
				}
			}
		}
	}
	closegraph();
	return opt;
}
void read(cip* x, FILE* fp)
{
	fseek(fp, (offset - 1) * sizeof(cip), SEEK_SET);
	fread(x, sizeof(cip), 1, fp);
}
void write(cip* x, FILE* fp)
{
	fseek(fp, (offset-1) * sizeof(cip), SEEK_SET);
	fwrite(x, sizeof(cip), 1, fp);
}
void show(FILE* fp)
{
	cip x;
	fseek(fp, (offset - 1) * sizeof(cip), SEEK_SET);
	fread(&x, sizeof(cip), 1, fp);
	printf_s("储存槽：%d\n",offset);
	printf_s("用户名：%s\n",x.id);
	printf_s("密码：%s\n",x.password);
}
void input(cip *x)
{
	printf_s("输入用户名\n");
	scanf("%s",x->id);
	printf_s("输入密码\n");
	scanf("%s", x->password);
}
void roomcheck(FILE* fp)
{
	cip x;
	int offst;
	for (offst = 1; offst < ROOMSHOW + 1; offst++)
	{
		fseek(fp, (offst - 1) * sizeof(cip), SEEK_SET);
		fread(&x, sizeof(cip), 1, fp);
		if (x.type)
		{
			x.type = 0;
		}
	}
	printf("\n");
}
void Plaintext()
{
	c = p;
	c.type = 1;
}
void invPlaintext()
{
	p = c;
}
void Caesar()
{
	int i;
	for (i = 0; i < CIPHERROOM; i++)
	{
		c.id[i] = (p.id[i]+ Caesarseed)%128;
		c.password[i] = (p.password[i]+ Caesarseed) % 128;
	}
	c.type = 2;
}
void invCaesar()
{
	int i;
	for (i = 0; i < CIPHERROOM; i++)
	{
		p.id[i] =( c.id[i] - Caesarseed) % 128;
		p.password[i] = (c.password[i] - Caesarseed) % 128;
	}
}
void Mult()
{
	int i;
	for (i = 0; i < CIPHERROOM; i++)
	{
		c.id[i] = (p.id[i] * Multseed) % 128;
		c.password[i] = (p.password[i] * Multseed) % 128;
	}
	c.type = 3;
}
void invMult()
{
	int i;
	int k = 1;
	while ((k*Multseed)%128!=1)
	{
		k = k + 1;
	}
	for (i = 0; i < CIPHERROOM; i++)
	{
		p.id[i] = (c.id[i] * k) % 128;
		p.password[i] = (c.password[i] * k) % 128;
	}
}
void Affine()
{
	int i;
	for (i = 0; i < CIPHERROOM; i++)
	{
		c.id[i] = (p.id[i] * Affmult+ Affadd + 12800) % 128;
		c.password[i] = (p.password[i] * Affmult + Affadd + 12800) % 128;
		//printf("明文：%c：%d",c.id[i],c.id[i]);
	}
	c.type = 4;
}
void invAffine()
{
	int i;
	int k = 1;
	while ((k * Affmult + 12800) % 128 != 1)
	{
		k = k + 1;
		//printf_s("逆元：%d\n",k);
	}
	for (i = 0; i < CIPHERROOM; i++)
	{
		p.id[i] =((c.id[i] - Affadd )* k+12800) % 128;
		p.password[i] =((c.password[i] - Affadd) * k+12800) % 128;
		//printf("c:%d",c.id[i]);
		//printf("密文：%c：%d\n", p.id[i], p.id[i]);
	}
}
int encrypt()
{
	int typ = 99;
	printf("选择加密方式\n");
	printf("1.明文写入\n");
	printf("2.凯撒密码\n");
	printf("3.乘法密码\n");
	printf("4.仿射密码\n");
	scanf_s("%d", &typ);
	switch (typ)
	{
	case 1:
		Plaintext();
		break;
	case 2:
		Caesar();
		break;
	case 3:
		Mult();
		break;
	case 4:
		Affine();
		break;
	}
	return typ;
}
int decrypt(FILE* fp)
{
	int typ; 
	fseek(fp, (offset - 1) * sizeof(cip), SEEK_SET);
	fread(&c, sizeof(cip), 1, fp);
	//printf("type:%d", c.type);
	if (c.type)
	{
		typ = c.type;
		gslot = offset;
		switch (typ)
		{
		case 1:
			invPlaintext();
			break;
		case 2:
			invCaesar();
			break;
		case 3:
			invMult();
			break;
		case 4:
			invAffine();
			break;
		}
		//printf_s("储存槽：%d\n", offset);
		//printf_s("用户名：%s\n", p.id);
		//printf_s("密码：%s\n", p.password);
		return typ;
	}
	else
	{
		//printf("该槽未存贮值");
		gslot = 0;
	}
}
int main()
{
	FILE* fp;
	int opt=99;
	errno_t err;
	err = fopen_s(&fp, "D:\\cipher.txt", "ab+");
	fclose(fp);
	err = fopen_s(&fp,"D:\\cipher.txt","rb+");
	while (opt)
	{

		opt=getopt(fp);
		switch (opt)
		{
		case 1:
				input(&p);
				c.type = 0;
				encrypt();
				write(&c,fp);
				printf_s("数据已储存\n");
					break;
		case 2:
			decrypt(fp);
			break;
		}
	}
	fclose(fp);
	return 0;
}