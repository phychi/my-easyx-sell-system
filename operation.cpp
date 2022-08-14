#include "operation.h"
#include "function.h"
using namespace std;
ExMessage m_msg;
IMAGE m_bk;
IMAGE road;
IMAGE money;
IMAGE paymoney;
IMAGE slot;//投币口
IMAGE p_line4;
IMAGE p_line5;
IMAGE p_line11;
const string line4[] = { "牛湖","观澜湖","松元厦","观澜","长湖","茜坑","竹村","清湖北","清湖","龙华","龙胜","上塘","红山","深圳北站","白石龙","民乐","上梅林","莲花北","少年宫","市民中心","会展中心","福民","福田口岸" };//4号线
const string line5[] = { "赤湾","荔湾","铁路公园","妈湾","前湾公园","前湾","桂湾","前海湾","临海","宝华","宝安中心","翻身","灵芝","洪浪北","兴东","留仙洞","西丽","大学城","塘朗","长岭陂","深圳北站","民治","五和","坂田","杨美","上水径","下水径","长龙","布吉","百鸽笼","布心","太安","怡景","黄贝岭" };//5号线
const string line11[] = { "福田","车公庙","红树湾南","后海","南山","前海湾","宝安","碧海湾","机场","机场北","福永","桥头","塘尾","马安山","沙井","后亭","松岗","碧头" };//11号线

char* stringtochar(string s, char arr[200])
{
	int len = s.copy(arr, 200);
	arr[len] = '\0';
	return arr;
}
int judgemoney(struct information* pt)
{
	if (pt->money == 1)
		return 1;
	else if (pt->money <= 5)
		return 5;
	else if (pt->money <= 10)
		return 10;
	else if (pt->money <= 20)
		return 20;
	else if (pt->money <= 50)
		return 50;
	else
		return 100;
}
void openwindow()
{
	initgraph(900, 560);
	cleardevice();
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "深圳地铁售票系统");
	setbkmode(TRANSPARENT);
	setbkcolor(WHITE);

}
int welcomepage()
{
	cleardevice();
	loadimage(&m_bk, "welcomepage.png");
	putimage(0, 0, &m_bk);
	settextcolor(BLACK);
	settextstyle(15, 0, "黑体");
	outtextxy(0, 0, "作者:哈尔滨工业大学(深圳)唐崇浩");
	settextstyle(18, 0, "楷体");
	outtextxy(0, 18, "@版权所有");
	settextstyle(16, 0, "黑体");
	outtextxy(0, 36, "联系QQ:2231723192");
	settextcolor(RGB(12, 79, 157));
	settextstyle(65, 0, "隶书");
	outtextxy(125, 214, "模拟地铁自动售票系统");
	settextcolor(BLACK);
	settextstyle(40, 0, "隶书");
	outtextxy(483, 450, "按任意键进入主菜单");
	system("pause");
	return Menu;
}
int showmenu()
{
	cleardevice();
	loadimage(&m_bk, "menu.png");
	putimage(0, 0, &m_bk);
	button(200, 100, 460, 170, "楷书", 40, "1.进入购票");
	button(200, 240, 460, 310, "楷书", 40, "2.查询路线图");
	button(200, 380, 460, 450, "楷书", 40, "3.退出系统");
	outtextxy(200, 505, "请点击进入相应部分 ");
	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://按键
				if (m_msg.vkcode == VK_ESCAPE)//按esc，返回主界面
				{
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //鼠标操作
				if (is_click(200, 100, 460, 170))
				{
					return Instruction;
				}
				else if (is_click(200, 240, 460, 310))
				{
					return Showmap;
				}
				else if (is_click(200, 380, 460, 450))
				{
					return Welcomepage;
				}
				break;
			default:
				break;

			}
		}
	}
}
int showmap()
{
	setbkcolor(RGB(4, 149, 239));//一种蓝色
	setbkmode(TRANSPARENT);
	cleardevice();
	loadimage(&road, "road.jpg");
	putimage(0, 10, &road);
	button(500, 490, 850, 550, "楷书", 40, "返回主界面");
	button(50, 490, 400, 550, "楷书", 40, "查询站点");
	button(740, 100, 880, 170, "宋体", 40, "4号线");
	button(740, 240, 880, 310, "宋体", 40, "5号线");
	button(740, 380, 880, 450, "宋体", 40, "11号线");

	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://按键
				if (m_msg.vkcode == VK_ESCAPE)//按esc，返回主界面
				{
					return Welcomepage;
				}
				break;
			case WM_LBUTTONDOWN:  //鼠标操作
				if (is_click(500, 490, 850, 550))
				{
					return Menu;
				}
				else if (is_click(50, 490, 400, 550))
				{
					return Query;
				}
				else if (is_click(740, 100, 880, 170))
				{
					return lin4;
				}
				else if (is_click(740, 240, 880, 310))
				{
					return lin5;
				}
				else if (is_click(740, 380, 880, 450))
				{
					return lin11;
				}
				break;
			default:
				break;

			}
		}
	}
}
int instruction()
{
	loadimage(&m_bk, "sellbackground.jpg");
	putimage(0, 0, &m_bk);
	settextstyle(60, 0, "隶书");
	outtextxy(90, 45, "欢迎进入深圳地铁购票系统");
	settextstyle(25, 0, "宋体");
	outtextxy(60, 125, "购票流程：乘客选择好出发站和目的站，然后输入需要购买的票数，最后");
	outtextxy(185, 150, "选择投币或者扫码的方式并完成支付。");
	outtextxy(60, 175, "用户需知：1.一笔订单最多可以购买99张车票，更多车票请与公司联系");
	outtextxy(185, 200, "2.车票价格为每站1元");
	outtextxy(185, 225, "3.由于某些原因，现在只能查询4、5、11号线的站点并购买车票");
	outtextxy(185, 250, "4.机器只能接受一张钞票，大于100元时只能使用网上支付，");
	outtextxy(185, 275, "  敬请原谅");
	outtextxy(100, 500, " 按任意键进入购票界面");
	system("pause");
	return BuyTicket;
}

int query()
{
	int the_state[3] = { -1,-1,-1 };
	setbkcolor(RGB(4, 149, 239));//一种蓝色
	cleardevice();
	button(505, 490, 790, 550, "楷书", 40, "返回菜单");
	button(110, 490, 395, 550, "楷书", 40, "开始购票");
	char s[20];
	InputBox(s, 20, "请输入需要查询的站点");
	string str(s);
	whatroute(str, the_state);
	if (the_state[0] + the_state[1] + the_state[2] == -3)
	{
		cleardevice();
		outtextxy(150, 200, "你查询的的站点不存在，请检查输入");
		button(505, 490, 790, 550, "楷书", 40, "返回菜单");
		button(110, 490, 395, 550, "楷书", 40, "重新输入");
		while (true)
		{
			if (peekmessage(&m_msg, EM_MOUSE))
			{
				if (m_msg.message == WM_LBUTTONDOWN)
				{
					if (is_click(110, 490, 395, 550))
					{
						return Query;
					}
					else if (is_click(505, 490, 790, 550))
					{
						return Menu;
					}
				}
			}
		}
	}
	outtextxy(150, 200, "你查询的的站点");
	if (the_state[0] >= 0 && the_state[1] >= 0)
	{
		outtextxy(450, 200, "在四号线与五号线上");
	}
	else if (the_state[1] >= 0 && the_state[2] >= 0)
	{
		outtextxy(450, 200, "在五号线与十一号线上");
	}
	else if (the_state[0] >= 0)
	{
		outtextxy(450, 200, "在四号线上");
	}
	else if (the_state[1] >= 0)
	{
		outtextxy(450, 200, "在五号线上");
	}
	else if (the_state[1] >= 0)
	{
		outtextxy(450, 200, "在十一号线上");
	}

	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://按键
				if (m_msg.vkcode == VK_ESCAPE)//按esc，返回主界面
				{
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //鼠标操作
				if (is_click(110, 490, 395, 550))
				{
					return Instruction;
				}
				else if (is_click(505, 490, 790, 550))
				{
					return Menu;
				}
				break;
			default:
				break;
			}
		}
	}
}

int pay(struct information* pt)
{
	loadimage(&m_bk, "howtopay.jpg");
	putimage(0, 0, &m_bk);
	button(110, 100, 395, 500, "楷书", 40, "现金支付");
	button(505, 100, 790, 500, "楷书", 40, "扫码支付");
	pt->distance = Distance(pt->start_state, pt->end_state);
	pt->money = pt->distance * pt->ticket;
	if (pt->money > 100)
	{
		outtextxy(200, 0, "大于100元只能扫码支付");
	}
	char shouldpay[10];
	_itoa_s(pt->money, shouldpay, 10);
	outtextxy(20, 50, "你需要支付    元");
	int width = (220 + 300 - textwidth(shouldpay)) / 2;
	outtextxy(width, 50, shouldpay);
	loadimage(&money, "money.jpeg");
	putimage(132, 110, &money);
	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://按键
				if (m_msg.vkcode == VK_ESCAPE)//按esc，返回主界面
				{
					emptyStructure(pt);
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //鼠标操作
				if (is_click(110, 100, 395, 500))
				{
					if (pt->money <= 100)
						return OfflinePay;
				}
				else if (is_click(505, 100, 790, 500))
				{
					return OlinePay;
				}
				break;
			default:
				break;

			}
		}
	}
}
int onlinepay(struct information* pt)
{
	loadimage(&m_bk, "howtopay.jpg");
	putimage(0, 0, &m_bk);
	loadimage(&paymoney, "paymoney.png");
	putimage(192, 70, &paymoney);
	outtextxy(130, 20, "请扫码完成支付：你需要支付    元");
	char shouldpay[10];
	_itoa_s(pt->money, shouldpay, 10);
	int width = (650 + 730 - textwidth(shouldpay)) / 2;
	outtextxy(width, 20, shouldpay);
	Sleep(10000);
	return TicketMessage;
}
int offlinepay(struct information* pt)
{
	int bill;
	loadimage(&m_bk, "howtopay.jpg");
	putimage(0, 0, &m_bk);
	loadimage(&slot, "slot.jpg");
	putimage(80, 180, &slot);
	bill = judgemoney(pt);
	char money[10];
	_itoa_s(bill, money, 10);
	int width = (500 + 580 - textwidth(money)) / 2;
	outtextxy(width, 200, money);
	outtextxy(300, 200, "请投入一张    元");
	Sleep(10000);
	return TicketMessage;
}
int  roadsearch(struct information* pt)
{
	whatroute(pt->start_station, pt->start_state);
	whatroute(pt->end_station, pt->end_state);
	if (pt->ticket > 0 && pt->ticket < 100)
		pt->ticket_state = true;
	if (pt->start_state[0] + pt->start_state[1] + pt->start_state[2] != -3)
		pt->the_start_state = true;
	if (pt->end_state[0] + pt->end_state[1] + pt->end_state[2] != -3)
		pt->the_end_state = true;
	if ((pt->ticket_state == false) || (pt->the_start_state == false) || (pt->the_end_state == false))
		return BuyTicket;
	else if ((pt->start_state[0] == pt->end_state[0]) && (pt->start_state[1] == pt->end_state[1]) && (pt->start_state[2] == pt->end_state[2]))
		return BuyTicket;
	else
		return Pay;

}

void whatroute(string c, int state[3])
{
	int size4, size5, size11;
	size4 = sizeof(line4) / sizeof(line4[0]);
	size5 = sizeof(line5) / sizeof(line5[0]);
	size11 = sizeof(line11) / sizeof(line11[0]);

	for (int i = 0; i < size4; i++)
	{
		if (c == line4[i])
		{
			state[0] = i;
		}
	}
	for (int i = 0; i < size5; i++)
	{
		if (c == line5[i])
		{
			state[1] = i;
		}
	}
	for (int i = 0; i < size11; i++)
	{
		if (c == line11[i])
		{
			state[2] = i;
		}
	}
}

int Distance(int state1[3], int state2[3])
{
	if (state1[0] >= 0 && state2[0] >= 0)
	{
		return fabs(state1[0] - state2[0]);
	}
	else if (state1[1] >= 0 && state2[1] >= 0)
	{
		return fabs(state1[1] - state2[1]);
	}
	else if (state1[2] >= 0 && state2[2] >= 0)
	{
		return fabs(state1[2] - state2[2]);
	}//
	else if (state1[0] >= 0 && state2[1] >= 0)
	{
		return fabs(state1[0] - 13) + fabs(state2[1] - 20);
	}
	else if (state1[1] >= 0 && state2[0] >= 0)
	{
		return fabs(state1[1] - 13) + fabs(state2[0] - 20);
	}//
	else if (state1[1] >= 0 && state2[2] >= 0)
	{
		return fabs(state1[1] - 7) + fabs(state2[2] - 5);
	}
	else if (state1[2] >= 0 && state2[1] >= 0)
	{
		return fabs(state1[2] - 7) + fabs(state2[1] - 5);
	}
	else if (state1[2] >= 0 && state2[0] >= 0)
	{
		return fabs(state1[2] - 5) + fabs(state2[0] - 13) + 13;
	}
	else if (state1[0] >= 0 && state2[2] >= 0)
	{
		return fabs(state1[0] - 5) + fabs(state2[2] - 13) + 13;
	}
	else
		return 0;
}

char* theway(int state1[3], int state2[2])
{
	string way;
	char theme[200];
	if ((state1[0] >= 0 && state2[0] >= 0))
	{
		if (state1[0] > state2[0])
			way = "4号线，牛湖方向，" + to_string(state1[0] - state2[0]) + "站到达" + line4[state2[0]];
		else
			way = "4号线，福田口岸方向，" + to_string(state2[0] - state1[0]) + "站到达" + line4[state2[0]];
	}
	else if (state1[1] >= 0 && state2[1] >= 0)
	{
		if (state1[1] > state2[1])
			way = "5号线，赤湾方向，" + to_string(state1[1] - state2[1]) + "站到达" + line5[state2[1]];
		else
			way = "5号线，黄贝岭方向，" + to_string(state2[1] - state1[1]) + "站到达" + line5[state2[1]];
	}
	else if (state1[2] >= 0 && state2[2] >= 0)
	{
		if (state1[1] > state2[1])
			way = "11号线，福田方向，" + to_string(state1[2] - state2[2]) + "站到达" + line11[state2[2]];
		else
			way = "11号线，碧头方向，" + to_string(state2[2] - state1[2]) + "站到达" + line11[state2[2]];
	}
	else if (state1[0] >= 0 && state2[1] >= 0)
	{
		if (state1[0] > 13)
			way = "4号线，牛湖方向，" + to_string(state1[0] - 13) + "站到达" + line4[state1[13]] + "换乘";
		else
			way = "4号线，福田口岸方向，" + to_string(13 - state1[0]) + "站到达" + line4[state1[13]] + "换乘";
		if (state2[1] > 20)
			way = way + "5号线，黄贝岭方向，" + to_string(state2[1] - 20) + "站到达" + line5[state2[1]];
		else
			way = way + "5号线，赤湾方向，" + to_string(20 - state2[1]) + "站到达" + line5[state2[1]];
	}
	else if (state1[1] >= 0 && state2[0] >= 0)
	{
		if (state1[1] > 20)
			way = "5号线，赤湾方向，" + to_string(state1[1] - 20) + "站到达" + line5[state1[1]] + "换乘";
		else
			way = "5号线，黄贝岭方向，" + to_string(20 - state1[1]) + "站到达" + line5[state1[1]] + "换乘";
		if (state2[0] > 13)
			way = way + "4号线，福田口岸方向，" + to_string(state2[0] - 13) + "站到达" + line4[state2[0]];
		else
			way = way + "4号线，牛湖方向，" + to_string(13 - state2[0]) + "站到达" + line4[state2[0]];
	}
	else if (state1[1] >= 0 && state2[2] >= 0)
	{
		if (state1[1] > 7)
			way = "5号线，赤湾方向，" + to_string(state1[1] - 7) + "站到达" + line5[state1[1]] + "换乘";
		else
			way = "5号线，黄贝岭方向，" + to_string(7 - state1[1]) + "站到达" + line5[state1[1]] + "换乘";
		if (state2[2] > 5)
			way = way + "11号线，碧头方向，" + to_string(state2[2] - 5) + "站到达" + line11[state2[2]];
		else
			way = way + "11号线，福田方向，" + to_string(5 - state2[2]) + "站到达" + line11[state2[2]];
	}
	else if (state1[2] >= 0 && state2[1] >= 0)
	{
		if (state1[2] > 5)
			way = "11号线，福田方向，" + to_string(state1[2] - 5) + "站到达" + line11[state1[2]] + "换乘";
		else
			way = "11号线，碧头方向，" + to_string(5 - state1[2]) + "站到达" + line11[state1[2]] + "换乘";
		if (state2[1] > 7)
			way = way + "5号线，黄贝岭方向，" + to_string(state2[1] - 7) + "站到达" + line5[state2[1]];
		else
			way = way + "5号线，赤湾方向，" + to_string(7 - state2[1]) + "站到达" + line5[state2[1]];
	}
	else if (state1[2] >= 0 && state2[0] >= 0)
	{
		if (state1[2] > 5)
			way = "11号线，福田方向，" + to_string(state1[2] - 5) + "站到达前海湾换乘5号线，黄贝岭方向，15站到达深圳北站，换乘";
		else
			way = "11号线，碧头方向，" + to_string(5 - state1[2]) + "站到达前海湾换乘5号线，黄贝岭方向，15站到达深圳北站，换乘";
		if (state2[0] > 13)
			way += "4号线，福田口岸方向，" + to_string(state2[0] - 13) + "站到达" + line4[state2[0]];
		else
			way += "4号线，牛湖方向，" + to_string(13 - state2[0]) + "站到达" + line4[state2[0]];
	}
	else if (state1[0] >= 0 && state2[2] >= 0)
	{
		if (state1[0] > 13)
			way = "4号线，牛湖方向，" + to_string(state2[0] - 13) + "站到达深圳北站换乘5号线，赤湾方向，15站到达前海湾，换乘";
		else
			way = "4号线，福田口岸方向，" + to_string(13 - state2[0]) + "站到达深圳北站换乘5号线，赤湾方向，15站到达前海湾，换乘";
		if (state2[2] > 5)
			way += "11号线，碧头方向，" + to_string(state2[2] - 5) + "站到达" + line11[state2[2]];
		else
			way += "11号线，福田方向，" + to_string(5 - state2[2]) + "站到达" + line11[state2[2]];
	}
	return stringtochar(way, theme);
}

int ticketmessage(information* pt)
{
	char themessage[200];
	loadimage(&m_bk, "howtopay.jpg");
	putimage(0, 0, &m_bk);
	outtextxy(300, 200, "支付成功！");
	strcpy_s(themessage, 200, theway(pt->start_state, pt->end_state));
	settextstyle(20, 0, "宋体");
	outtextxy(0, 300, themessage);
	Sleep(10000);
	return Welcomepage;
}


int showline4()
{
	setbkcolor(RGB(4, 149, 239));//一种蓝色
	cleardevice();
	loadimage(&p_line4, "line4.png");
	putimage(0, 0, &p_line4);
	outtextxy(300, 0, "观看完毕后按任意键返回地图查询");
	system("pause");

	return Showmap;
}
int showline5()
{
	setbkcolor(RGB(4, 149, 239));//一种蓝色
	cleardevice();
	loadimage(&p_line5, "line5.png");
	putimage(0, 0, &p_line5);
	outtextxy(300, 0, "观看完毕后按任意键返回地图查询");
	system("pause");

	return Showmap;
}
int showline11()
{
	setbkcolor(RGB(4, 149, 239));//一种蓝色
	cleardevice();
	loadimage(&p_line11, "line11.png");
	putimage(0, 0, &p_line11);
	outtextxy(300, 0, "观看完毕后按任意键返回地图查询");
	system("pause");

	return Showmap;
}

int buyticket(struct information* pt)
{
	cleardevice();
	loadimage(&m_bk, "sellbackground.jpg");
	putimage(0, 0, &m_bk);
	button(200, 100, 460, 170, "楷书", 40, "");
	button(200, 240, 460, 310, "楷书", 40, "");
	button(200, 380, 460, 450, "楷书", 40, "");
	button(50, 470, 350, 540, "楷书", 40, "退出购票");
	button(550, 470, 850, 540, "楷书", 40, "确定");

	outtextxy(50, 115, "起点站：");
	outtextxy(50, 255, "终点站：");
	outtextxy(90, 395, "票数：");

	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://按键
				if (m_msg.vkcode == VK_ESCAPE)//按esc，返回主界面
				{
					emptyStructure(pt);
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //鼠标操作
				if (m_msg.x > 200 && m_msg.x < 460)
				{
					if (m_msg.y > 100 && m_msg.y < 170)
					{
						clearroundrect(200, 100, 460, 170, 10, 10);
						fillroundrect(200, 100, 460, 170, 10, 10);
						char start_station[20];
						InputBox(start_station, 20, "请输入您的起始站点");
						strcpy_s(pt->start_station, 20, start_station);
						int position_x = (200 + 460 - textwidth(start_station)) / 2;
						int position_y = (100 + 170 - textheight(start_station)) / 2;
						outtextxy(position_x, position_y, start_station);
					}
					else if (m_msg.y > 240 && m_msg.y < 310)
					{
						clearroundrect(200, 240, 460, 310, 10, 10);
						fillroundrect(200, 240, 460, 310, 10, 10);
						char end_station[20];
						InputBox(end_station, 20, "请输入需要您想到达的站点");
						strcpy_s(pt->end_station, 20, end_station);
						int position_x = (200 + 460 - textwidth(end_station)) / 2;
						int position_y = (240 + 310 - textheight(end_station)) / 2;
						outtextxy(position_x, position_y, end_station);
					}
					else if (m_msg.y > 380 && m_msg.y < 450)
					{
						clearroundrect(200, 380, 460, 450, 10, 10);
						fillroundrect(200, 380, 460, 450, 10, 10);
						char s[4];
						InputBox(s, 4, "请输入需要购买的票数");
						int ticket = atoi(s);
						pt->ticket = ticket;
						int position_x = (200 + 460 - textwidth(s)) / 2;
						int position_y = (380 + 450 - textheight(s)) / 2;
						outtextxy(position_x, position_y, s);
					}

				}
				if (m_msg.y > 470 && m_msg.y < 540)
				{
					if (m_msg.x > 50 && m_msg.x < 350)
					{
						emptyStructure(pt);
						return Menu;
					}
					else if (m_msg.x > 550 && m_msg.x < 850)
					{
						int checkresult;
						checkresult = roadsearch(pt);
						if (checkresult == BuyTicket)
						{
							outtextxy(480, 250, "输入错误或信息不完整");
							Sleep(2000);
						}
						return checkresult;
					}

				}
				break;
			default:
				break;

			}
		}
	}
}