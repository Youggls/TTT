#define _CRT_SECURE_NO_WARNINGS
#define level_A 10000                                              //定义AI识别度为A级的情况
#define level_B 1000                                               //定义AI识别度为B级的情况

#pragma comment(lib,"winmm.lib")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>



int type;
int type2;
int first, first1;
int end = 0;
int count = 0;
int count_try = 0;

/********************************************************************************************************************/
/*                                                                                                                  */
/*                                                主函数部分                                                        */
/*                                                                                                                  */
/********************************************************************************************************************/

int main()
{
	void FlushMouseMsgBuffer();
	void PVP(int a[3][3]);
	void PVE(int a[3][3]);
	void AI_Hardcore1(int a[3][3]);
	void AI_Hardcore2(int a[3][3]);
	void AI_Hardcore3(int a[3][3]);
	void printBoard(int a[3][3]);
	void win(int a[3][3]);
	initgraph(720, 720);

start1:
	FlushMouseMsgBuffer();
	count = 0;
	count_try = 0;
	end = 2;
	first = 0;
	first1 = 0;
	type = 0;
	type2 = 0;
	

	int Board[3][3] = { 0 };                                          //定义棋盘数组，并初始化为0
		//C is qipan//
	MOUSEMSG m1,m2,mm,m;

	m1 = GetMouseMsg();
	m2 = GetMouseMsg();
	mm = GetMouseMsg();
	m = GetMouseMsg();

	IMAGE img[3];// 1是X 0是O
	srand((unsigned)time(NULL));
	FlushMouseMsgBuffer();


	int x[120];
	int y[120];
	int i;

	for (i = 0; i < 120; i++)
	{
		x[i] = rand() % 720;
		y[i] = rand() % 720;
	}

	FlushMouseMsgBuffer();


D1:
	do
	{
		settextstyle(16, 0, _T("宋体"));

		setlinestyle(PS_SOLID, 5);
		setlinecolor(WHITE);

		line(120, 440, 280, 440);
		line(120, 440, 120, 520);
		line(280, 520, 280, 440);
		line(280, 520, 120, 520);
		outtextxy(130, 473, _T("PLAY WITH COMPUTER"));

		line(440, 440, 600, 440);
		line(440, 440, 440, 520);
		line(600, 520, 600, 440);
		line(600, 520, 440, 520);
		outtextxy(454, 473, _T("PLAY WITH ANOTHER"));

		settextstyle(64, 0, _T("楷体"));
		outtextxy(230, 170, _T("井 字 棋"));

		if (MouseHit()) m1 = GetMouseMsg();
		else
		{
			for (i = 0; i < 120; i++)
			{

				putpixel(x[i], y[i], BLACK);
				y[i] += 7;
				if (y[i] >= 720) y[i] = 0;
				putpixel(x[i], y[i], WHITE);
			}
			Sleep(40);
		}
	} while (m1.uMsg != WM_LBUTTONDOWN);

		if (m1.x > 120 && m1.x <= 280 && m1.y >= 440 && m1.y <= 520)
		{
			type = 1;
			goto A;//A go to nandu//
			
		}

		else if (m1.x > 440 && m1.x <= 600 && m1.y >= 440 && m1.y <= 520)
		{
			type = 2;
			goto C;
			
		}

		else
		{
			goto D1;
		}

	A:
		FlushMouseMsgBuffer();
		cleardevice();



		FlushMouseMsgBuffer();

	D2:
		do 
		{
		settextstyle(16, 0, _T("宋体"));

		setlinestyle(PS_SOLID, 5);
		setlinecolor(WHITE);

		line(240, 100, 480, 100);
		line(240, 100, 240, 220);
		line(480, 220, 480, 100);
		line(480, 220, 240, 220);
		outtextxy(290, 152, _T("       EASY   "));

		line(240, 300, 480, 300);
		line(240, 300, 240, 420);
		line(480, 420, 480, 300);
		line(480, 420, 240, 420);
		outtextxy(285, 352, _T("       NORMAL     "));

		line(240, 500, 480, 500);
		line(240, 500, 240, 620);
		line(480, 620, 480, 500);
		line(480, 620, 240, 620);
		outtextxy(290, 552, _T("       HARD     "));

		if (MouseHit()) m2 = GetMouseMsg();
		else
		{
			for (i = 0; i < 120; i++)
			{

				putpixel(x[i], y[i], BLACK);
				y[i] += 7;
				if (y[i] >= 720) y[i] = 0;
				putpixel(x[i], y[i], WHITE);
			}
			Sleep(40);
		}
	} while (m2.uMsg != WM_LBUTTONDOWN);

	if (m2.x > 240 && m2.x <= 480 && m2.y >= 100 && m2.y <= 220)
	{
		type2 = 1;
		goto B; //B go to shuixianxia//
		
	}

	else if (m2.x > 240 && m2.x <= 480 && m2.y >= 300 && m2.y <= 420)
	{
		type2 = 2;
		goto B; //B go to shuixianxia//
		
	}

	else if (m2.x > 240 && m2.x <= 480 && m2.y >= 500 && m2.y <= 620)
	{
		type2 = 3;
		goto B; //B go to shuixianxia//
		
	}
	else 
	{
		goto D2;
	}

B:
	FlushMouseMsgBuffer();
	cleardevice();
D3:
	FlushMouseMsgBuffer();
	do 
	{
		line(240, 180, 480, 180);
		line(240, 180, 240, 300);
		line(480, 300, 480, 180);
		line(480, 300, 240, 300);
		outtextxy(308, 232, _T("  YOU FIRST"));

		line(240, 420, 480, 420);
		line(240, 420, 240, 540);
		line(480, 540, 480, 420);
		line(480, 540, 240, 540);
		outtextxy(310, 472, _T("COMPUTER FIRST"));

		if (MouseHit()) mm = GetMouseMsg();
		else
		{
			for (i = 0; i < 120; i++)
			{
				putpixel(x[i], y[i], BLACK);
				y[i] += 7;
				if (y[i] >= 720) y[i] = 0;
				putpixel(x[i], y[i], WHITE);
			}
			Sleep(40);
		}
	} while (mm.uMsg != WM_LBUTTONDOWN);


	if (mm.x > 240 && mm.x <= 480 && mm.y >= 180 && mm.y <= 300)
	{
		first = 1;
		goto F;
	}

	else if (mm.x > 240 && mm.x <= 480 && mm.y >= 420 && mm.y <= 540)
	{	
		first = 2;
		goto F;
	}

	else 
	{
		goto D3;
	}

	cleardevice();
	setlinestyle(PS_SOLID, 1);

	//玩家对弈部分

	if (type == 2)
	{
	C:
		cleardevice();
		MOUSEMSG m;

		IMAGE img[3];// 1是X 2是O
		loadimage(&img[1], _T("X.jpg"));
		loadimage(&img[0], _T("O.jpg"));

		setlinecolor(WHITE);
		setlinestyle(PS_SOLID, 1);

		line(287, 144, 287, 576);
		line(432, 144, 432, 576);
		line(144, 287, 576, 287);
		line(144, 432, 576, 432);

		int count_try = 0;
		int a[9] = { 0 };
		while (true)
		{
			m = GetMouseMsg();

			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:// 0 144 ! 288 ! 432 ! 576 720

				if (m.x > 144 && m.x <= 288 && m.y >= 144 && m.y <= 288)			// 第一个格子
				{
					if (a[0] == 0)
					{
						putimage(143, 143, &img[count_try % 2]);
						count_try += 1;
						a[0] += 1;
						if (count_try % 2 == 1) Board[0][0] = 1;
						else if (count_try % 2 == 0) Board[0][0] = -1;
					}
				}
				else if (m.x > 288 && m.x <= 432 && m.y >= 144 && m.y <= 288)		// 第二个格子
				{
					if (a[1] == 0)
					{
						putimage(288, 143, &img[count_try % 2]);
						count_try += 1;
						a[1]++;
						if (count_try % 2 == 1) Board[0][1] = 1;
						else if (count_try % 2 == 0) Board[0][1] = -1;
					}
				}


				else if (m.x > 432 && m.x <= 576 && m.y >= 144 && m.y <= 288)		// 第三个格子
				{
					if (a[2] == 0)
					{
						putimage(433, 143, &img[count_try % 2]);
						count_try += 1;
						a[2]++;
						if (count_try % 2 == 1) Board[0][2] = 1;
						else if (count_try % 2 == 0) Board[0][2] = -1;
					}
				}


				else if (m.x > 144 && m.x <= 288 && m.y >= 288 && m.y <= 432)		// 第四个格子
				{
					if (a[3] == 0)
					{
						putimage(143, 288, &img[count_try % 2]);
						count_try += 1;
						a[3]++;
						if (count_try % 2 == 1) Board[1][0] = 1;
						else if (count_try % 2 == 0) Board[1][0] = -1;
					}

				}

				else if (m.x > 288 && m.x <= 432 && m.y >= 288 && m.y <= 432)		// 第五个格子
				{
					if (a[4] == 0)
					{
						putimage(288, 288, &img[count_try % 2]);
						count_try += 1;
						a[4]++;
						if (count_try % 2 == 1) Board[1][1] = 1;
						else if (count_try % 2 == 0) Board[1][1] = -1;
					}
				}


				else if (m.x > 432 && m.x <= 576 && m.y >= 288 && m.y <= 432)		// 第六个格子
				{
					if (a[5] == 0)
					{
						putimage(433, 288, &img[count_try % 2]);
						count_try += 1;
						a[5]++;
						if (count_try % 2 == 1) Board[1][2] = 1;
						else if (count_try % 2 == 0) Board[1][2] = -1;
					}
				}


				else if (m.x > 144 && m.x <= 288 && m.y >= 432 && m.y <= 576)		// 第七个格子
				{
					if (a[6] == 0)
					{
						putimage(143, 433, &img[count_try % 2]);
						count_try += 1;
						a[6]++;
						if (count_try % 2 == 1) Board[2][0] = 1;
						else if (count_try % 2 == 0) Board[2][0] = -1;
					}
				}


				else if (m.x > 288 && m.x <= 432 && m.y >= 432 && m.y <= 576)		// 第八个格子
				{
					if (a[7] == 0)
					{
						putimage(288, 433, &img[count_try % 2]);
						count_try += 1;
						a[7]++;
						if (count_try % 2 == 1) Board[2][1] = 1;
						else if (count_try % 2 == 0) Board[2][1] = -1;
					}
				}


				else if (m.x > 432 && m.x <= 576 && m.y >= 432 && m.y <= 576)		// 第九个格子
				{
					if (a[8] == 0)
					{
						putimage(433, 433, &img[count_try % 2]);
						count_try += 1;
						a[8]++;
						if (count_try % 2 == 1) Board[2][2] = 1;
						else if (count_try % 2 == 0) Board[2][2] = -1;
					}
				}
				win(Board);
				switch (end)
				{
				case  1:	
				{
					Sleep(200);
					cleardevice();
					putimage(90, 135, &img[0]); 
					settextstyle(50, 0, _T("Adamas"));
					outtextxy(260, 130, _T(" WINNER"));
					outtextxy(350, 220, _T(" WINNER"));
					settextstyle(65, 0, _T("Adamas"));
					outtextxy(60, 340, _T("CHICKEN DINNER"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(250, 435, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG _m;
					while (true)
					{
						_m = GetMouseMsg();
						if (_m.uMsg == WM_LBUTTONDOWN)
						{
						start:
							if (_m.x > 60 && _m.x <= 180 && _m.y >= 620 && _m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (_m.x > 540 && _m.x <= 660 && _m.y >= 620 && _m.y <= 675)
							{
								goto OUT1;
							}
						}
					}
					break; 
				}
				case -1:	
				{
					Sleep(200);
					cleardevice();
					putimage(90, 135, &img[1]);
					settextstyle(50, 0, _T("Adamas"));
					outtextxy(260, 130, _T(" WINNER"));
					outtextxy(350, 220, _T(" WINNER"));
					settextstyle(65, 0, _T("Adamas"));
					outtextxy(60, 340, _T("CHICKEN DINNER"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(250, 435, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG _m;
					while (true)
					{
						_m = GetMouseMsg();
						if (_m.uMsg == WM_LBUTTONDOWN)
						{
							if (_m.x > 60 && _m.x <= 180 && _m.y >= 620 && _m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (_m.x > 540 && _m.x <= 660 && _m.y >= 620 && _m.y <= 675)
							{
								goto OUT1;
							}
						}
					}

					break;
				}
				case 0:
				{
					cleardevice();
					putimage(420, 135, &img[0]);
					putimage(150, 135, &img[1]);

					settextstyle(100, 0, _T("Adamas"));
					outtextxy(150, 340, _T("DARW"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(300, 455, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG ___m;

					___m = GetMouseMsg();
					if (___m.uMsg != WM_LBUTTONDOWN)
					{
						if (___m.x > 60 && ___m.x <= 180 && ___m.y >= 620 && ___m.y <= 675)
						{
							cleardevice();
							goto start1;
						}

						else if (___m.x > 540 && ___m.x <= 660 && ___m.y >= 620 && ___m.y <= 675)
						{
							goto OUT1;
						}
					}

				}
				}
				

			}
		}
	}

OUT1:
     	//人机对弈部分


	if (type == 1)
	{
	F:
		cleardevice();


		first1 = first;
		void(*p_hard)(int a[3][3]);


		p_hard = AI_Hardcore1;
		if (type2 == 1) p_hard = AI_Hardcore1;
		else if (type2 == 2) p_hard = AI_Hardcore2;
		else if (type2 == 3) p_hard = AI_Hardcore3;


		MOUSEMSG m;

		IMAGE img[3];// 1是X 2是O
		loadimage(&img[1], _T("X.jpg"));
		loadimage(&img[2], _T("O.jpg"));

		setlinecolor(WHITE);
		setlinestyle(PS_SOLID, 1);
		line(287, 144, 287, 576);
		line(432, 144, 432, 576);
		line(144, 287, 576, 287);
		line(144, 432, 576, 432);

		int a[9] = { 0 };


		while (true)
		{
			if (first == 2) {
				first = 1;
				goto AI;
			}
		st:
			m = GetMouseMsg();

			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:// 0 144 ! 288 ! 432 ! 576 720

				if (m.x > 144 && m.x <= 288 && m.y >= 144 && m.y <= 288&& Board[0][0] == 0)			// 第一个格子
				{
					if (Board[0][0] == 0)
					{
						putimage(143, 143, &img[2]);
						Board[0][0] = 1;
						count_try += 1;
						a[0] += 1;

					}
				}
				else if (m.x > 288 && m.x <= 432 && m.y >= 144 && m.y <= 288&& Board[0][1] == 0)		// 第二个格子
				{
					if (Board[0][1] == 0)
					{
						putimage(288, 143, &img[2]);
						Board[0][1] = 1;
						count_try += 1;
						a[1]++;

					}
				}


				else if (m.x > 432 && m.x <= 576 && m.y >= 144 && m.y <= 288&& Board[0][2] == 0)		// 第三个格子
				{
					if (Board[0][2] == 0)
					{
						putimage(433, 143, &img[2]);
						Board[0][2] = 1;
						count_try += 1;
						a[2]++;

					}
				}


				else if (m.x > 144 && m.x <= 288 && m.y >= 288 && m.y <= 432&& Board[1][0] == 0)		// 第四个格子
				{
					if (Board[1][0] == 0)
					{
						putimage(143, 288, &img[2]);
						Board[1][0] = 1;;
						count_try += 1;
						a[3]++;

					}

				}

				else if (m.x > 288 && m.x <= 432 && m.y >= 288 && m.y <= 432&& Board[1][1] == 0)		// 第五个格子
				{
					if (Board[1][1] == 0)
					{
						putimage(288, 288, &img[2]);
						Board[1][1] = 1;
						count_try += 1;
						a[4]++;

					}
				}


				else if (m.x > 432 && m.x <= 576 && m.y >= 288 && m.y <= 432&& Board[1][2] == 0)		// 第六个格子
				{
					if (Board[1][2] == 0)
					{
						putimage(433, 288, &img[2]);
						Board[1][2] = 1;
						count_try += 1;
						a[5]++;

					}
				}


				else if (m.x > 144 && m.x <= 288 && m.y >= 432 && m.y <= 576&& Board[2][0] == 0)		// 第七个格子
				{
					if (Board[2][0] == 0)
					{
						putimage(143, 433, &img[2]);
						Board[2][0] = 1;
						count_try += 1;
						a[6]++;

					}
				}


				else if (m.x > 288 && m.x <= 432 && m.y >= 432 && m.y <= 576&& Board[2][1] == 0)		// 第八个格子
				{
					if (Board[2][1] == 0)
					{
						putimage(288, 433, &img[2]);
						Board[2][1] = 1;
						count_try += 1;
						a[7]++;

					}
				}


				else if (m.x > 432 && m.x <= 576 && m.y >= 432 && m.y <= 576&& Board[2][2] == 0)		// 第九个格子
				{
					if (Board[2][2] == 0)
					{
						putimage(433, 433, &img[2]);
						Board[2][2] = 1;
						count_try += 1;
						a[8]++;

					}
				}

				else goto st;

				win(Board);
				switch (end)
				{
				case  1:
				{
					Sleep(200);
					cleardevice();
					putimage(90, 135, &img[2]);
					settextstyle(50, 0, _T("Adamas"));
					outtextxy(260, 130, _T(" WINNER"));
					outtextxy(350, 220, _T(" WINNER"));
					settextstyle(65, 0, _T("Adamas"));
					outtextxy(60, 340, _T("CHICKEN DINNER"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(250, 435, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG _m;
					while (true)
					{
						_m = GetMouseMsg();
						if (_m.uMsg == WM_LBUTTONDOWN)
						{
							if (_m.x > 60 && _m.x <= 180 && _m.y >= 620 && _m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (_m.x > 540 && _m.x <= 660 && _m.y >= 620 && _m.y <= 675)
							{
								exit(-1);
							}
						}
					}
					break;
				}
				case -1:
				{
					Sleep(200);
					cleardevice();
					putimage(90, 135, &img[1]);

					settextstyle(58, 0, _T("Adamas"));
					outtextxy(250, 130, _T(" LOSER"));
					outtextxy(340, 230, _T(" LOSER"));
					settextstyle(75, 0, _T("Adamas"));
					outtextxy(150, 350, _T("NO DINNER"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(250, 445, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG __m;
					while (true)
					{
						__m = GetMouseMsg();
						if (__m.uMsg == WM_LBUTTONDOWN)
						{
							if (__m.x > 60 && __m.x <= 180 && __m.y >= 620 && __m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (__m.x > 540 && __m.x <= 660 && __m.y >= 620 && __m.y <= 675)
							{
								exit(-1);

							}
						}
						break;
					}
				}
				case 0:
				{
					Sleep(200);
					cleardevice();

					putimage(420, 135, &img[2]);
					putimage(150, 135, &img[1]);

					settextstyle(100, 0, _T("Adamas"));
					outtextxy(150, 340, _T("DARW"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(300, 455, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG ___m;
					___m = GetMouseMsg();
					while (true)
					{
						___m = GetMouseMsg();
						if (___m.uMsg == WM_LBUTTONDOWN)
						{
							if (___m.x > 60 && ___m.x <= 180 && ___m.y >= 620 && ___m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (___m.x > 540 && ___m.x <= 660 && ___m.y >= 620 && ___m.y <= 675)
							{
								exit(-1);
							}
						}
					}

				}
				}
				if (m.x < 144 && m.x>576 && m.y < 144 && m.y>576) goto st;
			AI:
				int k = count_try;
				(*p_hard)(Board);

				count_try++;

				for (int i = 0; i <= 2; i++)
				{
					for (int j = 0; j <= 2; j++)
					{
						if (Board[i][j] == -1) {
							if (i == 0 && j == 0) putimage(143, 143, &img[1]);
							if (i == 0 && j == 1) putimage(288, 143, &img[1]);
							if (i == 0 && j == 2) putimage(433, 143, &img[1]);
							if (i == 1 && j == 0) putimage(143, 288, &img[1]);
							if (i == 1 && j == 1) putimage(288, 288, &img[1]);
							if (i == 1 && j == 2) putimage(433, 288, &img[1]);
							if (i == 2 && j == 0) putimage(143, 433, &img[1]);
							if (i == 2 && j == 1) putimage(288, 433, &img[1]);
							if (i == 2 && j == 2) putimage(433, 433, &img[1]);
						}
					}
				}
				win(Board);
				switch (end)
				{
				case  1:
				{
					Sleep(200);
					cleardevice();
					putimage(90, 135, &img[2]);
					settextstyle(50, 0, _T("Adamas"));
					outtextxy(260, 130, _T(" WINNER"));
					outtextxy(350, 220, _T(" WINNER"));
					settextstyle(65, 0, _T("Adamas"));
					outtextxy(60, 340, _T("CHICKEN DINNER"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(250, 435, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG _m;
					while (true)
					{
						_m = GetMouseMsg();
						if (_m.uMsg == WM_LBUTTONDOWN)
						{
							if (_m.x > 60 && _m.x <= 180 && _m.y >= 620 && _m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (_m.x > 540 && _m.x <= 660 && _m.y >= 620 && _m.y <= 675)
							{
								exit(-1);
							}
						}
					}
					break;
				}
				case -1:
				{
					Sleep(200);
					cleardevice();
					putimage(90, 135, &img[1]);

					settextstyle(58, 0, _T("Adamas"));
					outtextxy(250, 130, _T(" LOSER"));
					outtextxy(340, 230, _T(" LOSER"));
					settextstyle(75, 0, _T("Adamas"));
					outtextxy(150, 350, _T("NO DINNER"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(250, 445, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG __m;
					while (true)
					{
						__m = GetMouseMsg();
						if (__m.uMsg == WM_LBUTTONDOWN)
						{
							if (__m.x > 60 && __m.x <= 180 && __m.y >= 620 && __m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (__m.x > 540 && __m.x <= 660 && __m.y >= 620 && __m.y <= 675)
							{
								exit(-1);

							}
						}
					}
					break;
				}
				case 0:
				{
					Sleep(200);
					cleardevice();
					putimage(420, 135, &img[2]);
					putimage(150, 135, &img[1]);

					settextstyle(100, 0, _T("Adamas"));
					outtextxy(150, 340, _T("DARW"));
					settextstyle(95, 0, _T("Adamas"));
					outtextxy(300, 455, _T("! ! !"));

					setlinestyle(PS_SOLID, 2);
					setlinecolor(WHITE);

					line(60, 620, 180, 620);
					line(60, 620, 60, 675);
					line(180, 675, 180, 620);
					line(180, 675, 60, 675);

					line(660, 620, 540, 620);
					line(660, 620, 660, 675);
					line(540, 675, 540, 620);
					line(540, 675, 660, 675);

					settextstyle(27, 0, _T("华文行楷"));
					outtextxy(87, 633, _T("Retry"));
					outtextxy(573, 633, _T("Exit"));

					MOUSEMSG ___m;
					while (true)
					{
						___m = GetMouseMsg();
						if (___m.uMsg == WM_LBUTTONDOWN)
						{
							if (___m.x > 60 && ___m.x <= 180 && ___m.y >= 620 && ___m.y <= 675)
							{
								cleardevice();
								goto start1;
							}

							else if (___m.x > 540 && ___m.x <= 660 && ___m.y >= 620 && ___m.y <= 675)
							{
								exit(-1);
							}
						}
					}

				}
				}
			}
		}
	OUT2:
		printf("游戏结束\n");
		if (type == 1)
		{
			if (end == 1)
				PlaySound(TEXT("1761.wav"), NULL, SND_FILENAME | SND_ASYNC);
			else if (end == -1)
				PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		system("pause");
		return 0;
	}

}


/********************************************************************************************************************/
/*                                                                                                                  */
/*                                                胜负判定函数部分                                                  */
/*                                                                                                                  */
/********************************************************************************************************************/


void win(int arry[3][3])                                                         //定义检查胜负函数
{
	for (int i = 0; i <= 2; i++)                                                 //横列检查
	{
		if (arry[i][0] + arry[i][1] + arry[i][2] == 3)
		{
			if (type == 1) printf("YOU WIN!\n");
			else printf("Player(O) win!\n");
			end = 1;
			return;
		}
		else
			if (arry[i][0] + arry[i][1] + arry[i][2] == -3)
			{
				if (type == 1) printf("AI win!\n");
				else printf("Player(X) win!\n");
				end = -1;
				return;
			}
	}
	for (int i = 0; i <= 2; i++)                                                 //纵列检查
	{
		if (arry[0][i] + arry[1][i] + arry[2][i] == 3)
		{
			if (type == 1) printf("YOU WIN!\n");
			else printf("Player(O) win!\n");
			end = 1;
			return;
		}
		else
			if (arry[0][i] + arry[1][i] + arry[2][i] == -3)
			{
				if (type == 1) printf("AI win!\n");
				else printf("Player(X) win!\n");
				end = -1;
				return;
			}
	}
	if (arry[0][0] + arry[1][1] + arry[2][2] == 3)                               //主对角线检查
	{
		if (type == 1) printf("YOU WIN!\n");
		else printf("Player(O) win!\n");
		end = 1;
		return;
	}
	else
		if (arry[0][0] + arry[1][1] + arry[2][2] == -3)
		{
			if (type == 1) printf("AI win!\n");
			else printf("Player(X) win!\n");
			end = -1;
			return;
		}
	if (arry[2][0] + arry[1][1] + arry[0][2] == 3)                               //副对角线检查
	{
		if (type == 1) printf("YOU WIN!\n");
		else printf("Player(O) win!\n");
		end = 1;
		return;
	}
	else
		if (arry[2][0] + arry[1][1] + arry[0][2] == -3)
		{
			if (type == 1) printf("AI win!\n");
			else printf("Player(X) win!\n");
			end = -1;
			return;
		}
	int k = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (arry[i][j] != 0) k++;
		}
	}
	if (k == 9) {
		end = 0;
		return;
	}
}

/********************************************************************************************************************/
/*                                                                                                                  */
/*                                               人机简单                                                           */
/*                                                                                                                  */
/********************************************************************************************************************/


void AI_Hardcore1(int ar[3][3])
{
	int blank_site[9][2];
	int s = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (ar[i][j] == 0)
			{
				blank_site[s][0] = i;
				blank_site[s][1] = j;
				s++;
			}
		}
	}
	if (s == 0) return;
	int ran = rand() % (s);
	int x = blank_site[ran][0];
	int y = blank_site[ran][1];
	ar[x][y] = -1;
	count = 1;
	return;
}


/********************************************************************************************************************/
/*                                                                                                                  */
/*                                               人机一般                                                           */
/*                                                                                                                  */
/********************************************************************************************************************/


void AI_Hardcore2(int ar[3][3])
{
	void check_win(int a[3][3], int b[3][3]);
	int level[3][3] = { 0 };                                       //定义识别度等级数组
	for (int i = 0; i <= 2; i++)
	{
		if (ar[0][i] + ar[1][i] + ar[2][i] == 2)                   //查找纵列的情况，若某纵列之和为2则表示该列有2个其他玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[j][i] == 0)
					level[j][i] = level_B;
			}
		}
		else
			if (ar[0][i] + ar[1][i] + ar[2][i] == -2)              //查找纵列的情况，若某纵列之和为-2则表示该列有2个自己玩家的棋子
			{
				for (int j = 0; j <= 2; j++)
				{
					if (ar[j][i] == 0) level[j][i] = level_A;
				}
			}
		if (ar[i][0] + ar[i][1] + ar[i][2] == 2)                    //查横列的情况，若某横列之和为2则表示该列有2个其他玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[i][j] == 0)
					level[i][j] = level_B;
			}
		}
		else
			if (ar[i][0] + ar[i][1] + ar[i][2] == -2)               //查横列的情况，若某横列之和为-2则表示该列有2个自己玩家的棋子
			{
				for (int j = 0; j <= 2; j++)
				{
					if (ar[i][j] == 0) level[i][j] = level_A;
				}
			}
	}
	if (ar[0][0] + ar[1][1] + ar[2][2] == 2)                        //查找主对角线的情况，若主对角线之和为2则表示该列有2个其他玩家的棋子
	{
		for (int j = 0; j <= 2; j++)
		{
			if (ar[j][j] == 0)
				level[j][j] = level_B;
		}
	}
	else
		if (ar[0][0] + ar[1][1] + ar[2][2] == -2)                   //查找主对角线的情况，若主对角线之和为-2则表示该列有2个自己玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[j][j] == 0) level[j][j] = level_A;
			}
		}
	if (ar[0][2] + ar[1][1] + ar[2][0] == 2)                        //查找副对角线的情况，若副对角线之和为2则表示该列有2个其他玩家的棋子
	{
		for (int j = 0; j <= 2; j++)
		{
			if (ar[j][2 - j] == 0)
				level[j][2 - j] = level_B;
		}
	}
	else
		if (ar[0][2] + ar[1][1] + ar[2][0] == -2)                   //查找副对角线的情况，若副对角线之和为-2则表示该列有2个自己玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[j][2 - j] == 0) level[j][2 - j] = level_A;
			}
		}
	check_win(level, ar);                                           //令AI检查是否存在哪一个位置可能获胜会输
	if (count)                                                      //判断count变量是否非0，若非零则表示该轮游戏AI已经下过一子
	{
		count = 0;
		return;
	}
	else                                                            //若该轮AI仍未下子，则找到第一个无子的位置落子
	{
		int blank_site[9][2];
		int s = 0;
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[i][j] == 0)
				{
					blank_site[s][0] = i;
					blank_site[s][1] = j;
					s++;
				}
			}
		}
		if (s == 0) return;
		int ran = rand() % (s);
		int x = blank_site[ran][0];
		int y = blank_site[ran][1];
		ar[x][y] = -1;
		return;
	}
}



/********************************************************************************************************************/
/*                                                                                                                  */
/*                                               人机困难                                                           */
/*                                                                                                                  */
/********************************************************************************************************************/


void AI_Hardcore3(int ar[3][3])
{
	void check_win(int a[3][3], int b[3][3]);
	int level[3][3] = { 0 };                                       //定义识别度等级数组
	for (int i = 0; i <= 2; i++)
	{
		if (ar[0][i] + ar[1][i] + ar[2][i] == 2)                   //查找纵列的情况，若某纵列之和为2则表示该列有2个其他玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[j][i] == 0)
					level[j][i] = level_B;
			}
		}
		else
			if (ar[0][i] + ar[1][i] + ar[2][i] == -2)              //查找纵列的情况，若某纵列之和为-2则表示该列有2个自己玩家的棋子
			{
				for (int j = 0; j <= 2; j++)
				{
					if (ar[j][i] == 0) level[j][i] = level_A;
				}
			}
		if (ar[i][0] + ar[i][1] + ar[i][2] == 2)                    //查横列的情况，若某横列之和为2则表示该列有2个其他玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[i][j] == 0)
					level[i][j] = level_B;
			}
		}
		else
			if (ar[i][0] + ar[i][1] + ar[i][2] == -2)               //查横列的情况，若某横列之和为-2则表示该列有2个自己玩家的棋子
			{
				for (int j = 0; j <= 2; j++)
				{
					if (ar[i][j] == 0) level[i][j] = level_A;
				}
			}
	}
	if (ar[0][0] + ar[1][1] + ar[2][2] == 2)                        //查找主对角线的情况，若主对角线之和为2则表示该列有2个其他玩家的棋子
	{
		for (int j = 0; j <= 2; j++)
		{
			if (ar[j][j] == 0)
				level[j][j] = level_B;
		}
	}
	else
		if (ar[0][0] + ar[1][1] + ar[2][2] == -2)                   //查找主对角线的情况，若主对角线之和为-2则表示该列有2个自己玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[j][j] == 0) level[j][j] = level_A;
			}
		}
	if (ar[0][2] + ar[1][1] + ar[2][0] == 2)                        //查找副对角线的情况，若副对角线之和为2则表示该列有2个其他玩家的棋子
	{
		for (int j = 0; j <= 2; j++)
		{
			if (ar[j][2 - j] == 0)
				level[j][2 - j] = level_B;
		}
	}
	else
		if (ar[0][2] + ar[1][1] + ar[2][0] == -2)                   //查找副对角线的情况，若副对角线之和为-2则表示该列有2个自己玩家的棋子
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[j][2 - j] == 0) level[j][2 - j] = level_A;
			}
		}
	check_win(level,ar);                                           //令AI检查是否存在哪一个位置可能获胜会输
	if (count) {
		count = 0;
		return;
	}
	if (first1 == 1)
	{
		switch (count_try)
		{
		case 1:
		{
			if (ar[1][1] == 0)
			{
				ar[1][1] = -1;
				return;
			}
		}
		case 3:
		{
			if (ar[0][0] == 1 && ar[1][1] == 1) {
				ar[2][0] = -1;
				return;
			}
			if (ar[2][0] == 1 && ar[1][1] == 1) {
				ar[0][0] = -1;
				return;
			}
			if (ar[0][2] == 1 && ar[1][1] == 1) {
				ar[0][0] = -1;
				return;
			}
			if (ar[2][2] == 1 && ar[1][1] == 1) {
				ar[0][0] = -1;
				return;
			}
			if ((ar[0][0] == 1 && ar[2][2] == 1) || (ar[0][2] == 1 && ar[2][0] == 1)) {
				ar[0][1] = -1;
				return;
			}
			if (ar[0][1] == 1)
			{
				if (ar[2][0] == 1) {
					ar[1][2] = -1;
					return;
				}
				if (ar[2][2] == 1) {
					ar[1][0] = -1;
					return;
				}
			}
			if (ar[1][0] == 1) {
				if (ar[1][2] == 1) {
					ar[2][1] = -1;
					return;
				}
				if (ar[2][2] == 1) {
					ar[0][1] = -1;
					return;
				}
			}
			if (ar[1][2] == 1) {
				if (ar[0][0] == 1) {
					ar[2][1] = -1;
					return;
				}
				if (ar[2][0] == 1) {
					ar[0][1] = -1;
					return;
				}
			}
			if (ar[2][1] == 1) {
				if (ar[0][0] == 1) {
					ar[1][2] = -1;
					return;
				}
				if (ar[0][2] == 1) {
					ar[1][0] = -1;
					return;
				}
			}
		}
		}
	}
	if (first1 == 2)
	{
		switch (count_try)
		{
		case 0:
		{
			ar[0][0] = -1;
			return;
		}
		case 2:
		{
			if (ar[1][1] == 0) {
				ar[1][1] = -1;
				return;
			}
			if (ar[1][1] = 1) {
				ar[2][2] = -1;
				return;
			}
		}
		case 4:
		{
			if (ar[0][0] == -1 && ar[1][1] == -1) {
				if (ar[2][0] == 0) {
					ar[2][0] = -1;
					return;
				}
				if (ar[0][2] == 0) {
					ar[0][2] = -1;
					return;
				}
			}
			if (ar[0][0] == -1 && ar[2][2] == -1) {
				if (ar[2][0] == 0)
				{
					ar[2][0] = -1;
					return;
				}
				if (ar[0][2] == 0)
				{
					ar[0][2] = -1;
					return;
				}
			}
		}
		}
	}
	if (count)                                                      //判断count变量是否非0，若非零则表示该轮游戏AI已经下过一子
	{
		count = 0;
		return;
	}
	else                                                            //若该轮AI仍未下子，则找到第一个无子的位置落子
	{
		int blank_site[9][2];
		int s = 0;
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (ar[i][j] == 0)
				{
					blank_site[s][0] = i;
					blank_site[s][1] = j;
					s++;
				}
			}
		}
		if (s == 0) return;
		int ran = rand() % (s);
		int x = blank_site[ran][0];
		int y = blank_site[ran][1];
		ar[x][y] = -1;
		return;
	}
}


/********************************************************************************************************************/
/*                                                                                                                  */
/*                                               AI自检部分                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


void check_win(int a[3][3], int b[3][3])                            //定义AI判断是否将要获胜或是失败的函数
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (a[i][j] == level_A)                                //若某个位置识别度为A级，则将该位置赋值为-1表示该位置下一棋子，并返回
			{
				b[i][j] = -1;
				count = 1;                                         //令count变量为1，以表示该轮对局存在识别度为A的情况并且已经落子
				return;
			}
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (a[i][j] == level_B)                            //若某个位置识别度为B级，则将该位置赋值为-1表示该位置下一棋子，并返回
			{
				b[i][j] = -1;
				count = 1;                                     //令count变量为1，以表示该轮对局存在识别度为B的情况并且已经落子
				return;
			}
		}
	}
}