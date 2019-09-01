/*
 * @Description: 二叉树的三种递归及其非递归遍历
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-01 17:51:14
 * @LastEditTime: 2019-09-01 19:28:41
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define OK 1
#define ERROR 0

#define ELEMTYPE char

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
void PreOrderTraversalTree(TreeNode *);
void PreOrderTraversalTree_Recursion(TreeNode *);
void InOrderTraversalTree(TreeNode *);
void InOrderTraversalTree_Recursion(TreeNode *);
void PostOrderTraversalTree(TreeNode *);
void PostOrderTraversalTree_Recursion(TreeNode *);
void DestroyTree(TreeNode *);

/* Main */
int main(int argc, char *argv[]) {
  TreeNode *treeRoot = BuildTree();

  // Post Order
  printf("Post_Order:\n");
  printf("\tRecursion: \t");
  PreOrderTraversalTree(treeRoot);
  printf("\n\tNon-Recursion: \t");
  PreOrderTraversalTree_Recursion(treeRoot);
  printf("\n");

  // In Order
  printf("In_Order:\n");
  printf("\tRecursion: \t");
  InOrderTraversalTree(treeRoot);
  printf("\n\tNon-Recursion: \t");
  InOrderTraversalTree_Recursion(treeRoot);
  printf("\n");

  // Pre Order
  printf("Pre_Order:\n");
  printf("\tRecursion: \t");
  PostOrderTraversalTree(treeRoot);
  printf("\n\tNon-Recursion: \t");
  PostOrderTraversalTree_Recursion(treeRoot);
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

int StackPop(SqStack *s, TreeNode **pointToCurrentNode) {
  if (s->top == -1) {
    return 0;
  }
  *pointToCurrentNode = s->data[s->top--];
  return 1;
}

void GetStackTop(SqStack *s, TreeNode **pointToCurrentNode) {
  *pointToCurrentNode = s->data[s->top];
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

void PreOrderTraversalTree(TreeNode *root) {
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

void PreOrderTraversalTree_Recursion(TreeNode *node) {
  if (node != NULL) {
    printf("%c ", node->data);
    PreOrderTraversalTree_Recursion(node->lchild);
    PreOrderTraversalTree_Recursion(node->rchild);
  }
}

void InOrderTraversalTree(TreeNode *root) {
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

void InOrderTraversalTree_Recursion(TreeNode *node) {
  if (node != NULL) {
    InOrderTraversalTree_Recursion(node->lchild);
    printf("%c ", node->data);
    InOrderTraversalTree_Recursion(node->rchild);
  }
}

void PostOrderTraversalTree(TreeNode *root) {
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

void PostOrderTraversalTree_Recursion(TreeNode *node) {
  if (node != NULL) {
    PostOrderTraversalTree_Recursion(node->lchild);
    PostOrderTraversalTree_Recursion(node->rchild);
    printf("%c ", node->data);
  }
}

void DestroyTree(TreeNode *node){
  if (node->lchild != NULL) {
    DestroyTree(node->lchild);
  }
  if (node->rchild != NULL) {
    DestroyTree(node->rchild);
  }
  free(node);
}