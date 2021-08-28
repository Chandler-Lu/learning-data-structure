/* algo3-2.c ���㷨3.1��10���ơ�16���� */
typedef int SElemType; /* ����ջԪ������Ϊ���� */
#include "../ch1/c1.h"
#include "c3-1.h" /* ����˳��ջ */
#include "bo3-1.c" /* ����˳��ջ�Ļ������� */

void conversion()
{ /* �������������һ���Ǹ�10������������ӡ��������ֵ��16������ */
	SqStack s;
	unsigned n; /* �Ǹ����� */
	SElemType e;
	InitStack(&s); /* ��ʼ��ջ */
	printf("n(>=0)=");
	scanf("%u", &n); /* ����Ǹ�ʮ��������n */
	while (n) /* ��n������0 */
	{
		Push(&s, n % 16); /* ��ջn����16������(16���Ƶĵ�λ) */
		n = n / 16;
	}
	while (!StackEmpty(s)) /* ��ջ���� */
	{
		Pop(&s, &e); /* ����ջ��Ԫ���Ҹ�ֵ��e */
		if (e <= 9)
			printf("%d", e);
		else
			printf("%c", e + 55);
	}
	printf("\n");
}

void main()
{
	conversion();
}