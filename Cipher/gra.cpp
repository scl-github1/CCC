//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<graphics.h>
//#include <stdlib.h>
//#include<string.h>
//int getopt(int mode[])
//{
//	//int mode[100] = { 0,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1 };
//	initgraph(1000, 500);
//	MOUSEMSG m;
//	int i, j, w = 1;
//	int x, y, opt = 0;
//	char k[5];
//	setfillcolor(RED);
//	solidcircle(700, 270, 20);
//	outtextxy(740, 270, "已使用");
//	setfillcolor(GREEN);
//	solidcircle(850, 270, 20);
//	outtextxy(890, 270, "未使用");
//	rectangle(100, 300, 300, 400);
//	outtextxy(150, 340, "输入一组数据");
//	rectangle(400, 300, 600, 400);
//	outtextxy(450, 340, "输出一组数据");
//	rectangle(700, 300, 900, 400);
//	outtextxy(790, 340, "退出");
//	for (j = 20; j < 210; j += 60)
//	{
//		for (i = 20; i < 1000; i += 40)
//		{
//
//			_itoa_s(w, k, 10);
//			outtextxy(i - 5, j + 20, k);
//			w++;
//			if (mode[w - 1])
//			{
//				setfillcolor(RED);
//				solidcircle(i, j, 20);
//			}
//			else
//			{
//				setfillcolor(GREEN);
//				solidcircle(i, j, 20);
//			}
//		}
//	}
//	while (1)
//	{
//		m = GetMouseMsg();
//		if (m.uMsg == WM_LBUTTONDOWN)
//		{
//			char s[24];
//			x = m.x / 100;
//			y = m.y / 100;
//			opt = 99;
//			sprintf_s(s, "[%d,%d,%d]", x, y, opt);
//			outtextxy(10, 450, s);
//			if (y == 3)
//			{
//				if ((x - 1) / 2 == 0) { opt = 1; break; }
//				if ((x - 4) / 2 == 0) { opt = 2; break; }
//				if ((x - 7) / 2 == 0) { opt = 0; break; }
//			}
//		}
//	}
//	closegraph();
//	return opt;
//}