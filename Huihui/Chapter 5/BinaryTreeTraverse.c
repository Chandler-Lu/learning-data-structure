/*
 * @Description: 二叉树的三种递归及其非递归遍历
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-01 17:51:14
 * @LastEditTime: 2019-09-04 20:16:53
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define OK 1
#define ERROR 0

typedef char ELEMTYPE;

/* Declare Struction */
typedef struct TreeNode {
  ELEMTYPE data;
  struct TreeNode *lchild, *rchild;
} TreeNode;

typedef struct SqStack {
  int top;
  TreeNode *data[MAXSIZE];
} SqStack;

/* Declare Function */
TreeNode *BuildTree();
void PreOrderTraverseTree(TreeNode *);
void PreOrderTraverseTree_Recursion(TreeNode *);
void InOrderTraverseTree(TreeNode *);
void InOrderTraverseTree_Recursion(TreeNode *);
void PostOrderTraverseTree(TreeNode *);
void PostOrderTraverseTree_Recursion(TreeNode *);
void DestroyTree(TreeNode *);

/* Main */
int main(int argc, char *argv[]) {
  TreeNode *treeRoot = BuildTree();

  // Post Order
  printf("Post_Order:\n");
  printf("\tRecursion: \t");
  PreOrderTraverseTree(treeRoot);
  printf("\n\tNon-Recursion: \t");
  PreOrderTraverseTree_Recursion(treeRoot);
  printf("\n");

  // In Order
  printf("In_Order:\n");
  printf("\tRecursion: \t");
  InOrderTraverseTree(treeRoot);
  printf("\n\tNon-Recursion: \t");
  InOrderTraverseTree_Recursion(treeRoot);
  printf("\n");

  // Pre Order
  printf("Pre_Order:\n");
  printf("\tRecursion: \t");
  PostOrderTraverseTree(treeRoot);
  printf("\n\tNon-Recursion: \t");
  PostOrderTraverseTree_Recursion(treeRoot);
  printf("\n");

  // Free
  DestroyTree(treeRoot);
}

SqStack *InitStack() {
  SqStack *s = (SqStack *)malloc(sizeof(SqStack));
  if (!s) {
    exit(0);
  }
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
    return 0;
  }
  s->data[++s->top] = currentRoot;
  return 1;
}

int StackPop(SqStack *s, TreeNode **p) {
  if (s->top == -1) {
    return 0;
  }
  *p = s->data[s->top--];
  return 1;
}

void GetStackTop(SqStack *s, TreeNode **p) {
  *p = s->data[s->top];
}

TreeNode *InitTree(ELEMTYPE data) {
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
  treeRoot->rchild->rchild->rchild = InitTree('I');
  return treeRoot;
}

void PreOrderTraverseTree(TreeNode *root) {
  SqStack *s = InitStack();
  TreeNode *cur = root;
  while (cur || !StackEmpty(s)) {
    if (cur) {
      StackPush(s, cur);
      printf("%c ", cur->data);
      cur = cur->lchild;
    } else {
      StackPop(s, &cur);
      cur = cur->rchild;
    }
  }
  free(s);
}

void PreOrderTraverseTree_Recursion(TreeNode *node) {
  if (node != NULL) {
    printf("%c ", node->data);
    PreOrderTraverseTree_Recursion(node->lchild);
    PreOrderTraverseTree_Recursion(node->rchild);
  }
}

void InOrderTraverseTree(TreeNode *root) {
  SqStack *s = InitStack();
  TreeNode *cur = root;
  while (cur || !StackEmpty(s)) {
    if (cur) {
      StackPush(s, cur);
      cur = cur->lchild;
    } else {
      StackPop(s, &cur);
      printf("%c ", cur->data);
      cur = cur->rchild;
    }
  }
  free(s);
}

void InOrderTraverseTree_Recursion(TreeNode *node) {
  if (node != NULL) {
    InOrderTraverseTree_Recursion(node->lchild);
    printf("%c ", node->data);
    InOrderTraverseTree_Recursion(node->rchild);
  }
}

void PostOrderTraverseTree(TreeNode *root) {
  SqStack *s = InitStack();
  TreeNode *cur = root;
  TreeNode *pre = NULL;
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
  free(s);
}

void PostOrderTraverseTree_Recursion(TreeNode *node) {
  if (node != NULL) {
    PostOrderTraverseTree_Recursion(node->lchild);
    PostOrderTraverseTree_Recursion(node->rchild);
    printf("%c ", node->data);
  }
}

void DestroyTree(TreeNode *node) {
  if (node->lchild != NULL) {
    DestroyTree(node->lchild);
  }
  if (node->rchild != NULL) {
    DestroyTree(node->rchild);
  }
  free(node);
}