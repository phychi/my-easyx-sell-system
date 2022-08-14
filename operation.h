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
extern IMAGE slot;//Ͷ�ҿ�
extern IMAGE p_line4;
extern IMAGE p_line5;
extern IMAGE p_line11;
extern void openwindow();
//stringת��Ϊchar������
extern char* stringtochar(std::string s, char arr[200]);
//��ӭ����
extern int welcomepage();
//���˵�
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
//����վ��֮�����̾���
extern int Distance(int state1[3], int state2[3]);
extern int ticketmessage(struct information* pt);
extern int judgemoney(struct information* pt);

extern int showline4();
extern int showline5();
extern int showline11();
//��սṹ��


enum Operator//�û���������������ӭ���桢�˵�����Ʊ�������������ݣ���չʾ��ͼ����վ�㣨ǰһ�����ܵ�һ���֣���֧��������֧��������֧��
{
	Welcomepage = 0, Menu = 1, BuyTicket = 2, Showmap = 3, Query = 4, Pay = 5, OlinePay = 6, OfflinePay = 7, Instruction = 8, TicketMessage = 9, lin4 = 10, lin5 = 11, lin11 = 12
};
typedef struct information//�û��Ĺ�Ʊ������
{
	char start_station[20];//����վ��
	char end_station[20];//Ŀ��վ��
	int start_state[3];//����վ���״̬
	int end_state[3];//Ŀ��վ���״̬
	bool the_start_state;//����վ���״̬
	bool the_end_state;//Ŀ��վ���״̬
	bool ticket_state;
	int distance;
	int ticket;
	int money;
}INFORMATION;
#endif 
#pragma once
