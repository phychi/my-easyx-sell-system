#ifndef _OPERATION_H_
#define _OPERATION_H_
#include<iostream>
#include<easyx.h>
#include<cstdlib>
#include<cstring>
#include<sstream>
using namespace std;
extern ExMessage m_msg;
extern IMAGE m_bk;
extern IMAGE road;
extern IMAGE money;
extern IMAGE paymoney;
extern IMAGE slot;//投币口
extern IMAGE p_line4;
extern IMAGE p_line5;
extern IMAGE p_line11;
extern void openwindow();
//string转化为char型数组
extern char* stringtochar(std::string s, char arr[200]);
//欢迎界面
extern int welcomepage();
//主菜单
extern int showmenu();
extern int showmap();
extern int instruction();
extern int buyticket(struct information* pt);
extern int query();
extern int pay(struct information* pt);
extern int onlinepay(struct information* pt);
extern int offlinepay(struct information* pt);
extern int roadsearch(struct information* pt);
extern void whatroute(string c, int state[3]);
//计算站点之间的最短距离
extern int Distance(int state1[3], int state2[3]);
extern int ticketmessage(struct information* pt);
extern int judgemoney(struct information* pt);

extern int showline4();
extern int showline5();
extern int showline11();
//清空结构体


enum Operator//用户操作，包括：欢迎界面、菜单、买票（输入三个数据）、展示地图、查站点（前一个功能的一部分）、支付、网上支付、线下支付
{
	Welcomepage = 0, Menu = 1, BuyTicket = 2, Showmap = 3, Query = 4, Pay = 5, OlinePay = 6, OfflinePay = 7, Instruction = 8, TicketMessage = 9, lin4 = 10, lin5 = 11, lin11 = 12
};
typedef struct information//用户的购票的数据
{
	char start_station[20];//出发站点
	char end_station[20];//目的站点
	int start_state[3];//出发站点的状态
	int end_state[3];//目的站点的状态
	bool the_start_state;//出发站点的状态
	bool the_end_state;//目的站点的状态
	bool ticket_state;
	int distance;
	int ticket;
	int money;
}INFORMATION;
#endif 
#pragma once
