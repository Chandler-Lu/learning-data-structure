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

int StackPop(SqStack *s) {
  if (s->top == -1) {
    return ERROR;
  }
  s->top--;
  return OK;
}

void GetStackTop(SqStack *s, TreeNode **pointToCurrentNode) {
  *pointToCurrentNode = &(s->data[s->top]);
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

void LastTraverseTree(TreeNode *root) {
  SqStack *s;
  TreeNode *cur = NULL, *pre = NULL;
  s = InitStack();
  if (root == NULL) {
    return;
  }
  StackPush(s, root);
  
  // 死循环，暂时手动控制
  int a = 10;
  while (a--) {
    cur = NULL;
    GetStackTop(s, &cur);
    
    // 调试
    if(pre != NULL) {
      printf("%c", cur->data);
      printf("%c ", pre->data);
    }
    
    if ((cur->lchild == NULL && cur->rchild == NULL) ||
        (pre != NULL && (cur->lchild == pre || cur->rchild == pre))) {
//      printf("%c ", cur->data);
      pre = cur;
      StackPop(s);
    } else {
      if (cur->rchild != NULL) {
        StackPush(s, cur->rchild);
      }
      if (cur->lchild != NULL) {
        StackPush(s, cur->lchild);
      }
    }
  }
  free(s);
}

int main() {
  TreeNode *treeRoot = BuildTree();
  LastTraverseTree(treeRoot);
  return 0;
}