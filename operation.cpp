#include "operation.h"
#include "function.h"
using namespace std;
ExMessage m_msg;
IMAGE m_bk;
IMAGE road;
IMAGE money;
IMAGE paymoney;
IMAGE slot;//Ͷ�ҿ�
IMAGE p_line4;
IMAGE p_line5;
IMAGE p_line11;
const string line4[] = { "ţ��","������","��Ԫ��","����","����","���","���","�����","���","����","��ʤ","����","��ɽ","���ڱ�վ","��ʯ��","����","��÷��","������","���깬","��������","��չ����","����","����ڰ�" };//4����
const string line5[] = { "����","����","��·��԰","����","ǰ�幫԰","ǰ��","����","ǰ����","�ٺ�","����","��������","����","��֥","���˱�","�˶�","���ɶ�","����","��ѧ��","����","������","���ڱ�վ","����","���","����","����","��ˮ��","��ˮ��","����","����","�ٸ���","����","̫��","����","�Ʊ���" };//5����
const string line11[] = { "����","������","��������","��","��ɽ","ǰ����","����","�̺���","����","������","����","��ͷ","��β","��ɽ","ɳ��","��ͤ","�ɸ�","��ͷ" };//11����

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
	SetWindowText(hnd, "���ڵ�����Ʊϵͳ");
	setbkmode(TRANSPARENT);
	setbkcolor(WHITE);

}
int welcomepage()
{
	cleardevice();
	loadimage(&m_bk, "welcomepage.png");
	putimage(0, 0, &m_bk);
	settextcolor(BLACK);
	settextstyle(15, 0, "����");
	outtextxy(0, 0, "����:��������ҵ��ѧ(����)�Ƴ��");
	settextstyle(18, 0, "����");
	outtextxy(0, 18, "@��Ȩ����");
	settextstyle(16, 0, "����");
	outtextxy(0, 36, "��ϵQQ:2231723192");
	settextcolor(RGB(12, 79, 157));
	settextstyle(65, 0, "����");
	outtextxy(125, 214, "ģ������Զ���Ʊϵͳ");
	settextcolor(BLACK);
	settextstyle(40, 0, "����");
	outtextxy(483, 450, "��������������˵�");
	system("pause");
	return Menu;
}
int showmenu()
{
	cleardevice();
	loadimage(&m_bk, "menu.png");
	putimage(0, 0, &m_bk);
	button(200, 100, 460, 170, "����", 40, "1.���빺Ʊ");
	button(200, 240, 460, 310, "����", 40, "2.��ѯ·��ͼ");
	button(200, 380, 460, 450, "����", 40, "3.�˳�ϵͳ");
	outtextxy(200, 505, "����������Ӧ���� ");
	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://����
				if (m_msg.vkcode == VK_ESCAPE)//��esc������������
				{
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //������
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
	setbkcolor(RGB(4, 149, 239));//һ����ɫ
	setbkmode(TRANSPARENT);
	cleardevice();
	loadimage(&road, "road.jpg");
	putimage(0, 10, &road);
	button(500, 490, 850, 550, "����", 40, "����������");
	button(50, 490, 400, 550, "����", 40, "��ѯվ��");
	button(740, 100, 880, 170, "����", 40, "4����");
	button(740, 240, 880, 310, "����", 40, "5����");
	button(740, 380, 880, 450, "����", 40, "11����");

	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://����
				if (m_msg.vkcode == VK_ESCAPE)//��esc������������
				{
					return Welcomepage;
				}
				break;
			case WM_LBUTTONDOWN:  //������
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
	settextstyle(60, 0, "����");
	outtextxy(90, 45, "��ӭ�������ڵ�����Ʊϵͳ");
	settextstyle(25, 0, "����");
	outtextxy(60, 125, "��Ʊ���̣��˿�ѡ��ó���վ��Ŀ��վ��Ȼ��������Ҫ�����Ʊ�������");
	outtextxy(185, 150, "ѡ��Ͷ�һ���ɨ��ķ�ʽ�����֧����");
	outtextxy(60, 175, "�û���֪��1.һ�ʶ��������Թ���99�ų�Ʊ�����೵Ʊ���빫˾��ϵ");
	outtextxy(185, 200, "2.��Ʊ�۸�Ϊÿվ1Ԫ");
	outtextxy(185, 225, "3.����ĳЩԭ������ֻ�ܲ�ѯ4��5��11���ߵ�վ�㲢����Ʊ");
	outtextxy(185, 250, "4.����ֻ�ܽ���һ�ų�Ʊ������100Ԫʱֻ��ʹ������֧����");
	outtextxy(185, 275, "  ����ԭ��");
	outtextxy(100, 500, " ����������빺Ʊ����");
	system("pause");
	return BuyTicket;
}

int query()
{
	int the_state[3] = { -1,-1,-1 };
	setbkcolor(RGB(4, 149, 239));//һ����ɫ
	cleardevice();
	button(505, 490, 790, 550, "����", 40, "���ز˵�");
	button(110, 490, 395, 550, "����", 40, "��ʼ��Ʊ");
	char s[20];
	InputBox(s, 20, "��������Ҫ��ѯ��վ��");
	string str(s);
	whatroute(str, the_state);
	if (the_state[0] + the_state[1] + the_state[2] == -3)
	{
		cleardevice();
		outtextxy(150, 200, "���ѯ�ĵ�վ�㲻���ڣ���������");
		button(505, 490, 790, 550, "����", 40, "���ز˵�");
		button(110, 490, 395, 550, "����", 40, "��������");
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
	outtextxy(150, 200, "���ѯ�ĵ�վ��");
	if (the_state[0] >= 0 && the_state[1] >= 0)
	{
		outtextxy(450, 200, "���ĺ������������");
	}
	else if (the_state[1] >= 0 && the_state[2] >= 0)
	{
		outtextxy(450, 200, "���������ʮһ������");
	}
	else if (the_state[0] >= 0)
	{
		outtextxy(450, 200, "���ĺ�����");
	}
	else if (the_state[1] >= 0)
	{
		outtextxy(450, 200, "���������");
	}
	else if (the_state[1] >= 0)
	{
		outtextxy(450, 200, "��ʮһ������");
	}

	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://����
				if (m_msg.vkcode == VK_ESCAPE)//��esc������������
				{
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //������
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
	button(110, 100, 395, 500, "����", 40, "�ֽ�֧��");
	button(505, 100, 790, 500, "����", 40, "ɨ��֧��");
	pt->distance = Distance(pt->start_state, pt->end_state);
	pt->money = pt->distance * pt->ticket;
	if (pt->money > 100)
	{
		outtextxy(200, 0, "����100Ԫֻ��ɨ��֧��");
	}
	char shouldpay[10];
	_itoa_s(pt->money, shouldpay, 10);
	outtextxy(20, 50, "����Ҫ֧��    Ԫ");
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
			case WM_KEYDOWN://����
				if (m_msg.vkcode == VK_ESCAPE)//��esc������������
				{
					emptyStructure(pt);
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //������
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
	outtextxy(130, 20, "��ɨ�����֧��������Ҫ֧��    Ԫ");
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
	outtextxy(300, 200, "��Ͷ��һ��    Ԫ");
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
			way = "4���ߣ�ţ������" + to_string(state1[0] - state2[0]) + "վ����" + line4[state2[0]];
		else
			way = "4���ߣ�����ڰ�����" + to_string(state2[0] - state1[0]) + "վ����" + line4[state2[0]];
	}
	else if (state1[1] >= 0 && state2[1] >= 0)
	{
		if (state1[1] > state2[1])
			way = "5���ߣ����巽��" + to_string(state1[1] - state2[1]) + "վ����" + line5[state2[1]];
		else
			way = "5���ߣ��Ʊ��뷽��" + to_string(state2[1] - state1[1]) + "վ����" + line5[state2[1]];
	}
	else if (state1[2] >= 0 && state2[2] >= 0)
	{
		if (state1[1] > state2[1])
			way = "11���ߣ����﷽��" + to_string(state1[2] - state2[2]) + "վ����" + line11[state2[2]];
		else
			way = "11���ߣ���ͷ����" + to_string(state2[2] - state1[2]) + "վ����" + line11[state2[2]];
	}
	else if (state1[0] >= 0 && state2[1] >= 0)
	{
		if (state1[0] > 13)
			way = "4���ߣ�ţ������" + to_string(state1[0] - 13) + "վ����" + line4[state1[13]] + "����";
		else
			way = "4���ߣ�����ڰ�����" + to_string(13 - state1[0]) + "վ����" + line4[state1[13]] + "����";
		if (state2[1] > 20)
			way = way + "5���ߣ��Ʊ��뷽��" + to_string(state2[1] - 20) + "վ����" + line5[state2[1]];
		else
			way = way + "5���ߣ����巽��" + to_string(20 - state2[1]) + "վ����" + line5[state2[1]];
	}
	else if (state1[1] >= 0 && state2[0] >= 0)
	{
		if (state1[1] > 20)
			way = "5���ߣ����巽��" + to_string(state1[1] - 20) + "վ����" + line5[state1[1]] + "����";
		else
			way = "5���ߣ��Ʊ��뷽��" + to_string(20 - state1[1]) + "վ����" + line5[state1[1]] + "����";
		if (state2[0] > 13)
			way = way + "4���ߣ�����ڰ�����" + to_string(state2[0] - 13) + "վ����" + line4[state2[0]];
		else
			way = way + "4���ߣ�ţ������" + to_string(13 - state2[0]) + "վ����" + line4[state2[0]];
	}
	else if (state1[1] >= 0 && state2[2] >= 0)
	{
		if (state1[1] > 7)
			way = "5���ߣ����巽��" + to_string(state1[1] - 7) + "վ����" + line5[state1[1]] + "����";
		else
			way = "5���ߣ��Ʊ��뷽��" + to_string(7 - state1[1]) + "վ����" + line5[state1[1]] + "����";
		if (state2[2] > 5)
			way = way + "11���ߣ���ͷ����" + to_string(state2[2] - 5) + "վ����" + line11[state2[2]];
		else
			way = way + "11���ߣ����﷽��" + to_string(5 - state2[2]) + "վ����" + line11[state2[2]];
	}
	else if (state1[2] >= 0 && state2[1] >= 0)
	{
		if (state1[2] > 5)
			way = "11���ߣ����﷽��" + to_string(state1[2] - 5) + "վ����" + line11[state1[2]] + "����";
		else
			way = "11���ߣ���ͷ����" + to_string(5 - state1[2]) + "վ����" + line11[state1[2]] + "����";
		if (state2[1] > 7)
			way = way + "5���ߣ��Ʊ��뷽��" + to_string(state2[1] - 7) + "վ����" + line5[state2[1]];
		else
			way = way + "5���ߣ����巽��" + to_string(7 - state2[1]) + "վ����" + line5[state2[1]];
	}
	else if (state1[2] >= 0 && state2[0] >= 0)
	{
		if (state1[2] > 5)
			way = "11���ߣ����﷽��" + to_string(state1[2] - 5) + "վ����ǰ���廻��5���ߣ��Ʊ��뷽��15վ�������ڱ�վ������";
		else
			way = "11���ߣ���ͷ����" + to_string(5 - state1[2]) + "վ����ǰ���廻��5���ߣ��Ʊ��뷽��15վ�������ڱ�վ������";
		if (state2[0] > 13)
			way += "4���ߣ�����ڰ�����" + to_string(state2[0] - 13) + "վ����" + line4[state2[0]];
		else
			way += "4���ߣ�ţ������" + to_string(13 - state2[0]) + "վ����" + line4[state2[0]];
	}
	else if (state1[0] >= 0 && state2[2] >= 0)
	{
		if (state1[0] > 13)
			way = "4���ߣ�ţ������" + to_string(state2[0] - 13) + "վ�������ڱ�վ����5���ߣ����巽��15վ����ǰ���壬����";
		else
			way = "4���ߣ�����ڰ�����" + to_string(13 - state2[0]) + "վ�������ڱ�վ����5���ߣ����巽��15վ����ǰ���壬����";
		if (state2[2] > 5)
			way += "11���ߣ���ͷ����" + to_string(state2[2] - 5) + "վ����" + line11[state2[2]];
		else
			way += "11���ߣ����﷽��" + to_string(5 - state2[2]) + "վ����" + line11[state2[2]];
	}
	return stringtochar(way, theme);
}

int ticketmessage(information* pt)
{
	char themessage[200];
	loadimage(&m_bk, "howtopay.jpg");
	putimage(0, 0, &m_bk);
	outtextxy(300, 200, "֧���ɹ���");
	strcpy_s(themessage, 200, theway(pt->start_state, pt->end_state));
	settextstyle(20, 0, "����");
	outtextxy(0, 300, themessage);
	Sleep(10000);
	return Welcomepage;
}


int showline4()
{
	setbkcolor(RGB(4, 149, 239));//һ����ɫ
	cleardevice();
	loadimage(&p_line4, "line4.png");
	putimage(0, 0, &p_line4);
	outtextxy(300, 0, "�ۿ���Ϻ���������ص�ͼ��ѯ");
	system("pause");

	return Showmap;
}
int showline5()
{
	setbkcolor(RGB(4, 149, 239));//һ����ɫ
	cleardevice();
	loadimage(&p_line5, "line5.png");
	putimage(0, 0, &p_line5);
	outtextxy(300, 0, "�ۿ���Ϻ���������ص�ͼ��ѯ");
	system("pause");

	return Showmap;
}
int showline11()
{
	setbkcolor(RGB(4, 149, 239));//һ����ɫ
	cleardevice();
	loadimage(&p_line11, "line11.png");
	putimage(0, 0, &p_line11);
	outtextxy(300, 0, "�ۿ���Ϻ���������ص�ͼ��ѯ");
	system("pause");

	return Showmap;
}

int buyticket(struct information* pt)
{
	cleardevice();
	loadimage(&m_bk, "sellbackground.jpg");
	putimage(0, 0, &m_bk);
	button(200, 100, 460, 170, "����", 40, "");
	button(200, 240, 460, 310, "����", 40, "");
	button(200, 380, 460, 450, "����", 40, "");
	button(50, 470, 350, 540, "����", 40, "�˳���Ʊ");
	button(550, 470, 850, 540, "����", 40, "ȷ��");

	outtextxy(50, 115, "���վ��");
	outtextxy(50, 255, "�յ�վ��");
	outtextxy(90, 395, "Ʊ����");

	while (true)
	{
		if (peekmessage(&m_msg, EM_MOUSE | EM_KEY))
		{
			switch (m_msg.message)
			{
			case WM_KEYDOWN://����
				if (m_msg.vkcode == VK_ESCAPE)//��esc������������
				{
					emptyStructure(pt);
					return Menu;
				}
				break;
			case WM_LBUTTONDOWN:  //������
				if (m_msg.x > 200 && m_msg.x < 460)
				{
					if (m_msg.y > 100 && m_msg.y < 170)
					{
						clearroundrect(200, 100, 460, 170, 10, 10);
						fillroundrect(200, 100, 460, 170, 10, 10);
						char start_station[20];
						InputBox(start_station, 20, "������������ʼվ��");
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
						InputBox(end_station, 20, "��������Ҫ���뵽���վ��");
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
						InputBox(s, 4, "��������Ҫ�����Ʊ��");
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
							outtextxy(480, 250, "����������Ϣ������");
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