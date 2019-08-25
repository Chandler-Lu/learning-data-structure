/*
 * @Description: 二叉树非递归先序遍历
 * @version: 1.1
 * @Author: Chandler Lu
 * @Date: 2019-08-23 00:03:56
 * @LastEditTime: 2019-08-23 13:59:27
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
  char data;
  struct TreeNode *lchild, *rchild;
} TreeNode;

typedef struct SqStack {
  TreeNode data[MAXSIZE];
  int top;
} SqStack;

TreeNode *BuildTree();
void PreTraverseTree(TreeNode *);

int main(int argc, char *argv[]) {
  TreeNode *treeRoot = BuildTree();
  PreTraverseTree(treeRoot);
}

SqStack *InitStack() {
  SqStack *s = (SqStack *)malloc(sizeof(SqStack));
  s->top = -1;
  return s;
}

int StackPush(SqStack *s, TreeNode *node) {
  if (s->top == MAXSIZE - 1) {
    return FALSE;
  }
  s->data[++s->top] = *node;
  return TRUE;
}

/**
 * TODO: 掌握此处的参数传递
 * @description: 出栈
 * @param {SqStack *s, TreeNode **p}
 * @return: bool
 */
int StackPop(SqStack *s, TreeNode **p) {
  if (s->top == -1) {
    return FALSE;
  }
  *p = &(s->data[s->top--]);
  return TRUE;
}

int StackEmpty(SqStack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

TreeNode *InitTree(char data) {
  TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
  treeNode->data = data;
  treeNode->lchild = NULL;
  treeNode->rchild = NULL;
  return treeNode;
}

TreeNode *BuildTree() {
  TreeNode *treeRoot = InitTree('A');
  treeRoot->lchild = InitTree('B');
  treeRoot->lchild->rchild = InitTree('C');
  treeRoot->lchild->rchild->lchild = InitTree('D');
  treeRoot->lchild->rchild->rchild = InitTree('E');
  treeRoot->rchild = InitTree('F');
  treeRoot->rchild->rchild = InitTree('G');
  treeRoot->rchild->rchild->lchild = InitTree('H');
  return treeRoot;
}

void PreTraverseTree(TreeNode *root) {
  SqStack *s = InitStack();
  TreeNode *p = root;
  if (p == NULL) {
    return;
  }
  while (p || !StackEmpty(s)) {
    if (p) {
      StackPush(s, p);
      printf("%c ", p->data);
      p = p->lchild;
    } else {
      StackPop(s, &p);
      p = p->rchild;
    }
  }
  free(s);
}