/* algo3-11.c ���÷�ѭ��˳����в��ù������������Թ�����(һ��·��) */
#include "../ch1/c1.h"
#define M 5 /* �Թ�����(������ǽ) */
#define N 5 /* �Թ�����(������ǽ) */
#define D 8 /* �ƶ�������,ֻ��ȡ4��8��(8��,��б��;4��,ֻ��ֱ��) */

typedef struct /* �������Ԫ�غ�ջԪ��Ϊͬ���͵Ľṹ�� */
{
	int x, y; /* ��ǰ�����ֵ����ֵ */
	int pre; /* ǰһ���ڶ����е���� */
}QElemType, SElemType; /* ����ջԪ�غͶ���Ԫ�� */
#include "c3-1.h" /* ջ�Ĵ洢�ṹ */
#include "bo3-1.c" /* ջ�Ļ������� */
#include "c3-3.h" /* ���еĴ洢�ṹ */
#include "bo3-4.c" /* ���еĻ������� */

struct /* �ƶ�����,�ƶ�������������˳ʱ��ת */
{
	int x, y;
#if D==8
}move[D] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
#endif
#if D==4
 }move[D] = { {0,1},{1,0},{0,-1},{-1,0} };
#endif

 Status Path(int maze[M][N]) /* �����������һ���Թ�·�� */
 {
	 SqQueue q; /* ���÷�ѭ��˳����� */
	 QElemType qf, qt; /* ��ǰ�����һ�� */
	 SqStack s; /* ����˳��ջ */
	 int i, j, flag = 1; /* ���ҵ�����,flag=0 */
	 int x1, y1; /* �յ������ */
	 printf("��������ڵ���,��(���Ͻ�Ϊ1,1)\n");
	 scanf("%d,%d", &qf.x, &qf.y);
	 printf("��������ڵ���,��(���½�Ϊ%d,%d)\n", M - 2, N - 2);
	 scanf("%d,%d", &x1, &y1);
	 qf.pre = -1; /* �����(��һ��)����һ������=-1 */
	 maze[qf.x][qf.y] = -1; /* ��ʼ����Ϊ-1(�ѷ��ʹ�) */
	 InitQueue(&q);
	 EnQueue(&q, qf); /* ������ */
	 while (!QueueEmpty(q) && flag)
	 { /* �����л���û������������ĵ��һ�û�ҵ����� */
		 DeQueue(&q, &qf); /* ����qfΪ��ǰ�� */
		 for (i = 0; i < D; i++) /* ����������� */
		 {
			 qt.x = qf.x + move[i].x; /* ��һ������� */
			 qt.y = qf.y + move[i].y;
			 if (maze[qt.x][qt.y] == 1)
			 { /* �˵���ͨ���Ҳ��������ʹ� */
				 maze[qt.x][qt.y] = -1; /* �ѷ��ʹ� */
				 qt.pre = q.front - 1; /* ��һ�㴦�ڶ������ֶ�ͷ��һ��λ��(ûɾ��) */
				 EnQueue(&q, qt); /* ��� */
				 if (qt.x == x1&&qt.y == y1) /* �����յ� */
				 {
					 flag = 0;
					 break;
				 }
			 }
		 }
	 }
	 if (flag) /* �������������л�û�����յ� */
	 {
		 printf("û��·���ɵ����յ㣡\n");
		 return ERROR;
	 }
	 else
	 {
		 InitStack(&s); /* ��ʼ��sջ */
		 i = q.rear - 1; /* iΪ����ջԪ���ڶ����е�λ�� */
		 while (i >= 0) /* û����� */
		 {
			 Push(&s, *(q.base + i));
			 i = (*(q.base + i)).pre; /* iΪǰһԪ���ڶ����е�λ�� */
		 }
		 i = 0; /* iΪ�߳��Թ��Ĳ��� */
		 while (!StackEmpty(s))
		 {
			 Pop(&s, &qf);
			 i++;
			 maze[qf.x][qf.y] = i;
		 }
		 printf("�߳��Թ���һ��������\n");
		 for (i = 1; i < M - 1; i++) /* ���maze[][],��ֵ���߳��Թ��Ĳ��� */
		 {
			 for (j = 1; j < N - 1; j++)
				 printf("%3d", maze[i][j]);
			 printf("\n");
		 }
		 return OK;
	 }
 }

 void main()
 {
	 int i, j;
	 int maze[M][N]; /* �Թ����� */
	 printf("%d��%d���Թ�(��������ǽ)\n", M - 2, N - 2);
	 for (i = 0; i < N; i++)
	 { /* 0Ϊǽ,1Ϊͨ�� */
		 maze[0][i] = 0; /* ��ǽ */
		 maze[M - 1][i] = 0; /* ��ǽ */
	 }
	 for (i = 1; i < M - 1; i++)
	 {
		 maze[i][0] = 0; /* ��ǽ */
		 maze[i][N - 1] = 0; /* ��ǽ */
	 }
	 printf("�밴�������Թ��ṹ(�������ܱ�,0Ϊǽ,1Ϊͨ��),��1 0 0 1\n");
	 for (i = 1; i < M - 1; i++)
		 for (j = 1; j < N - 1; j++)
			 scanf("%d", &maze[i][j]);
	 printf("�Թ��ṹ(������ǽ):\n");
	 for (i = 0; i < M; i++)
	 {
		 for (j = 0; j < N; j++)
			 printf("%3d", maze[i][j]);
		 printf("\n");
	 }
	 Path(maze);
 }