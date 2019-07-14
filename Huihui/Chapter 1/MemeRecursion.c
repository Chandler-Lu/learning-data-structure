// 程序调用自身的编程技巧成为递归 (recursion)
#include <stdio.h>
void Recursion (int);

int main(int argc, char *argv[]) {
	printf("吓得我抱起了");
	Recursion(2);
}

void Recursion (int depth) {
	if (depth == 0) {
		printf("我的小鲤鱼");
		printf("的我");
		return;
	}
	printf("抱着");
	Recursion(--depth);
	printf("的我");
}