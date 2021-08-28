#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PolyNode {
	int coef;
	int expon;
	struct PolyNode *link;
}PolyNode, *Polynomial;

void Attach(int c, int e, Polynomial *pRear) {
	PolyNode *P;
	P = (PolyNode *)malloc(sizeof(PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial ReadPoly() {
	PolyNode *P, *Rear, *t;
	int c, e, N;
	scanf("%d", &N);
	P = (PolyNode *)malloc(sizeof(PolyNode));
	P->link = NULL;
	Rear = P;
	while (N--) {
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

//void PrintPoly(PolyNode *P) {
//	int flag = 0;
//	if (!P) {
//		printf("0 0\n");
//		return;
//	}
//	while (P) {
//		if(!flag) {
//			flag = 1;
//		}
//		else {
//			printf(" ");
//		}
//		printf("%d %d", P->coef, P->expon);
//		P = P->link;
//	}
//	printf("\n");
//}

int CalculatePoly(PolyNode *P) {
	int x0;
	scanf("%d", &x0);
	int result = 0;
	if (!P) {
		return result;
	}
	while (P) {
		result += (P->coef * pow(x0, P->expon));
		P = P->link;
	}
	return result;
}

int main(int argc, char *argv[]) {
	Polynomial P;
	P = ReadPoly();
	printf("%d", CalculatePoly(P));
	return 0;
}