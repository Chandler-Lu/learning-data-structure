/*
 * @Description: 2017-武汉科技大学(856)-算法设计 03 [二叉树的层序遍历求高度]
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-04 17:52:34
 * @LastEditTime: 2019-09-04 20:14:46
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct BinTreeNode {
  char data;
  struct BinTreeNode *lchild, *rchild;
} TreeNode;

typedef struct SqQueue {
  int front, rear;
  TreeNode **data;
} SqQueue;

TreeNode *BuildTree();
int LevelOrderTraverseTree(TreeNode *);
void DestroyTree(TreeNode *);

int main(int argc, char *argv[]) {
  TreeNode *root = BuildTree();
  printf("Level_Order:");
  printf("\n\tNon-Recursion: \t");
  printf("（%d 层）", LevelOrderTraverseTree(root));
  DestroyTree(root);
}

TreeNode *InitTree(char data) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  if (!node) {
    exit(OVERFLOW);
  }
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

SqQueue *InitQueue() {
  SqQueue *q = (SqQueue *)malloc(sizeof(SqQueue));
  if (!q) {
    exit(OVERFLOW);
  }
  q->rear = q->front = 0;
  q->data = (TreeNode **)malloc(sizeof(TreeNode *) * MAXSIZE);
  if (!q->data) {
    exit(OVERFLOW);
  }
  return q;
}

int QueueEmpty(SqQueue *q) { return (q->rear == q->front) ? 1 : 0; }

int EnQueue(SqQueue *q, TreeNode *node) {
  if ((q->rear + 1) % MAXSIZE == q->front) {
    return ERROR;
  }
  q->data[q->rear] = node;
  q->rear = (q->rear + 1) % MAXSIZE;
  return OK;
}

int DeQueue(SqQueue *q) {
  if (QueueEmpty(q)) {
    return ERROR;
  }
  printf("%c ", q->data[q->front]->data);
  q->front = (q->front + 1) % MAXSIZE;
  return OK;
}

int GetSizeQueue(SqQueue *q) {
  if (QueueEmpty(q)) {
    return 0;
  }
  return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

void GetTopQueue(SqQueue *q, TreeNode **p) { *p = q->data[q->front]; }

int LevelOrderTraverseTree(TreeNode *root) {
  SqQueue *q = InitQueue();
  TreeNode *p = root;
  EnQueue(q, root);
  int count = 0;
  while (!QueueEmpty(q)) {
    int size = GetSizeQueue(q);
    count++;
    while (size--) {
      if (p->lchild) {
        EnQueue(q, p->lchild);
      }
      if (p->rchild) {
        EnQueue(q, p->rchild);
      }
      DeQueue(q);
      GetTopQueue(q, &p);
    }
  }
  free(q);
  return count;
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