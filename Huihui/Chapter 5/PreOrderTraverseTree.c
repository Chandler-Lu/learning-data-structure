/*
 * @Description: 二叉树非递归先序遍历
 * @version: 1.2
 * @Author: Chandler Lu
 * @Date: 2019-08-23 00:03:56
 * @LastEditTime: 2019-09-04 20:12:28
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define OK 1
#define ERROR 0

typedef struct TreeNode {
  char data;
  struct TreeNode *lchild, *rchild;
} TreeNode;

typedef struct SqStack {
  TreeNode data[MAXSIZE];
  int top;
} SqStack;

TreeNode *BuildTree();
void PreOrderTraverseTree(TreeNode *);

int main(int argc, char *argv[]) {
  TreeNode *treeRoot = BuildTree();
  PreOrderTraverseTree(treeRoot);
}

SqStack *InitStack() {
  SqStack *s = (SqStack *)malloc(sizeof(SqStack));
  s->top = -1;
  return s;
}

int StackPush(SqStack *s, TreeNode *currentRoot) {
  if (s->top == MAXSIZE - 1) {
    return ERROR;
  }
  s->data[++s->top] = *currentRoot;
  return OK;
}

/**
 * @description: 出栈
 * @param {SqStack *s, TreeNode **p}
 * @return: bool
 */
int StackPop(SqStack *s, TreeNode **pointToCurrentRoot) {
  if (s->top == -1) {
    return ERROR;
  }
  *pointToCurrentRoot = &(s->data[s->top--]);
  return OK;
}

int StackEmpty(SqStack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

TreeNode *InitTree(char data) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->data = data;
  node->lchild = NULL;
  node->rchild = NULL;
  return node;
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

void PreOrderTraverseTree(TreeNode *root) {
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