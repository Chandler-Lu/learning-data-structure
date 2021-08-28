/* algo5-1.c ʵ���㷨5.2�ĳ��� */
#include "../ch1/c1.h"
typedef int ElemType;
#include "c5-2.h"
#include "bo5-2.c"

Status FastTransposeSMatrix(TSMatrix M, TSMatrix *T)
{ /* ������ϡ�����M��ת�þ���T���㷨5.2 */
	int p, q, t, col, *num, *cpot;
	num = (int *)malloc((M.nu + 1)*sizeof(int)); /* �������飨[0]���ã� */
	cpot = (int *)malloc((M.nu + 1)*sizeof(int)); /* �������飨[0]���ã� */
	(*T).mu = M.nu;
	(*T).nu = M.mu;
	(*T).tu = M.tu;
	if ((*T).tu)
	{
		for (col = 1; col <= M.nu; ++col)
			num[col] = 0; /* ���ֵ */
		for (t = 1; t <= M.tu; ++t) /* ��M��ÿһ�к�����Ԫ�ظ��� */
			++num[M.data[t].j];
		cpot[1] = 1;
		for (col = 2; col <= M.nu; ++col) /* ���col���е�һ������Ԫ��(*T).data�е���� */
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (p = 1; p <= M.tu; ++p)
		{
			col = M.data[p].j;
			q = cpot[col];
			(*T).data[q].i = M.data[p].j;
			(*T).data[q].j = M.data[p].i;
			(*T).data[q].e = M.data[p].e;
			++cpot[col];
		}
	}
	free(num);
	free(cpot);
	return OK;
}

void main()
{
	TSMatrix A, B;
	printf("��������A: ");
	CreateSMatrix(&A);
	PrintSMatrix(A);
	FastTransposeSMatrix(A, &B);
	printf("����B(A�Ŀ���ת��): ");
	PrintSMatrix(B);
	DestroySMatrix(&A);
	DestroySMatrix(&B);
}