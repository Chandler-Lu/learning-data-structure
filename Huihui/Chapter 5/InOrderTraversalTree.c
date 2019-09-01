/*
 * @Description: 二叉树非递归中序遍历
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-08-26 09:58:07
 * @LastEditTime: 2019-09-01 12:12:37
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
void InOrderTraversalTree(TreeNode *);

int main(int argc, char *argv[]) {
  TreeNode *root = BuildTree();
  InOrderTraversalTree(root);
  return 0;
}

SqStack *InitStack() {
  SqStack *s = (SqStack *)malloc(sizeof(SqStack));
  s->top = -1;
  return s;
}

int StackEmpty(SqStack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

int StackPush(SqStack *s, TreeNode *currentRoot) {
  if (s->top == MAXSIZE - 1) {
    return ERROR;
  }
  s->data[++s->top] = *currentRoot;
  return OK;
}

int StackPop(SqStack *s, TreeNode **pointToCurrentRoot) {
  if (s->top == -1) {
    return ERROR;
  }
  *pointToCurrentRoot = &(s->data[s->top--]);
  return OK;
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

void InOrderTraversalTree(TreeNode *root) {
  SqStack *s = InitStack();
  TreeNode *p = root;
  if (p == NULL) {
    return;
  }
  while (p != NULL || !StackEmpty(s)) {
    if (p) {
      StackPush(s, p);
      p = p->lchild;
    } else {
      StackPop(s, &p);
      printf("%c ", p->data);
      p = p->rchild;
    }
  }
  free(s);
}