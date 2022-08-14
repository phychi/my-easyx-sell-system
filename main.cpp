#include "operation.h"
#include "function.h"
using namespace std;

int main(void)
{
	openwindow();
	INFORMATION passenger{ "/0","/0",{-1,-1,-1},{-1,-1,-1},false,false,false,0,0 };//初始乘客信息
	int op = Welcomepage;//初始化操作进入
	while (true)
	{
		cleardevice();
		switch (op)
		{
		case Welcomepage:
			op = welcomepage();
		case Menu:
			op = showmenu();
			break;
		case BuyTicket:
			op = buyticket(&passenger);
			break;
		case Showmap:
			op = showmap();
			break;
		case Instruction:
			op = instruction();
			break;
		case Query:
			op = query();
			break;
		case  Pay:
			op = pay(&passenger);
			break;
		case OlinePay:
			op = onlinepay(&passenger);
			break;
		case OfflinePay:
			op = offlinepay(&passenger);
			break;
		case TicketMessage:
			op = ticketmessage(&passenger);
			break;
		case lin4:
			op = showline4();
			break;
		case lin5:
			op = showline5();
			break;
		case lin11:
			op = showline11();
			break;
		default:
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}