/*
 * @Description: 二叉树非递归后序遍历（王道）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-01 11:07:40
 * @LastEditTime: 2019-09-01 12:11:07
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
  TreeNode *data[MAXSIZE];
  int top;
} SqStack;

TreeNode *BuildTree();
void PostOrderTraversalTree(TreeNode *);

int main(int argc, char *argv[]) {
  TreeNode *treeRoot = BuildTree();
  PostOrderTraversalTree(treeRoot);
  return 0;
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
  s->data[++s->top] = currentRoot;
  return OK;
}

int StackPop(SqStack *s, TreeNode **pointToCurrentNode) {
  if (s->top == -1) {
    return ERROR;
  }
  *pointToCurrentNode = s->data[s->top--];
  return OK;
}

int StackEmpty(SqStack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

void GetStackTop(SqStack *s, TreeNode **pointToCurrentNode) {
  *pointToCurrentNode = s->data[s->top];
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

void PostOrderTraversalTree(TreeNode *root) {
  SqStack *s = InitStack();
  TreeNode *pre = NULL;
  TreeNode *cur = root;
  while (cur || !StackEmpty(s)) {
    if (cur) {
      StackPush(s, cur);
      cur = cur->lchild;
    } else {
      GetStackTop(s, &cur);
      if (cur->rchild && cur->rchild != pre) {
        cur = cur->rchild;
        StackPush(s, cur);
        cur = cur->lchild;
      } else {
        StackPop(s, &cur);
        printf("%c ", cur->data);
        pre = cur;
        cur = NULL;
      }
    }
  }
}