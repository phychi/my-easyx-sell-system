#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include "operation.h"
extern void emptyStructure(struct information* pt);
extern bool is_on(int x1, int y1, int x2, int y2);
//�Ƿ���
extern bool is_click(int x1, int y1, int x2, int y2);
//����һ����ť������ʹ���־���
extern void button(int x1, int y1, int x2, int y2, const char TextStyle[10], int TextHeight, const char word[20], int r = 10);
#endif 
#pragma once