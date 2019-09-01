# Chapter 6

# 图

## 一、图的基本概念

### 定义

图由数据元素和连接数据元素的线构成，其中数据元素称为顶点，连接顶点的线称为边。

### 注意

- 线性表有空表，树有空树，图没有空图
- 图的顶点集 V 一定非空，但边集 E 可以为空
- |V| 表示图 G 中顶点的个数，也成为图 G 的阶

### 相关术语

1. 有向图
2. 无向图
3. 简单图
4. 多重图
5. 完全图
6. 生成子图
7. 连通、连通图和连通分量（无向图）
8. 强连通图、强连通分量（有向图）
9. 生成树、生成森林
10. 顶点的度、入度和初度
11. 边的权和网
12. 稀疏图、稠密图
13. 路径、路径长度和回路
14. 简单路径、简单回路
15. 距离
16. 有向树

## 二、图的存储结构

### 邻接矩阵法

数组存储图中顶点的信息，用一个二维数组存储图中边的信息，存储顶点之间邻接关系的二维数组称为邻接矩阵

```c
#define MaxVertexNum 100 // 图中顶点数目的最大值
typedef char Vertextype; // 顶点的数据类型
typedef int EdgeType;    // 带权图中边上权值的数据类型
typedef struct {
  Vertextype Vex[MaxVertexNum];              //顶点表
  EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
  int vexnum, arcnum;                        // 图的当前顶点数和弧数
}
```

### 邻接表法

对图 G 中的每个顶点 vi 建立一个单链表，第个单链表中的结点表示依附于顶点 vi 的边（对有向图是以顶点 vi 为尾的弧），这个单链表称为顶点 vi 的边表（对有向图称为出边表）
邻接表中有两种结点：**顶点表结点**和**边表结点**

```c
#define MaxVertexNum 100 // 图中顶点数目的最大值
typedef struct ArcNode { // 边表节点
  int adjvex;            // 该弧指向的顶点位置
  struct ArcNode *next;  // 指向下一条弧的指针
  // InfoType info; // 网的权值
} ArcNode;
typedef struct VNode { // 顶点表结点
  VertexType data;     // 顶点信息
  ArcNode *first;      // 指向第一条依附于该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct {
  AdjList vertices;   // 邻接表
  int vexnum, arcnum; // 图的顶点数与弧数
} ALGraph;
```

### 十字链表（有向图）
十字链表是有向图的一种链式在值结构，在十字链表中对应于有向图的每条弧有一个结点，对应于每个顶点也有一个结点。

```c
#define MaxVertexNum 100 // 图中顶点数目的最大值
typedef struct ArcNode { // 边表节点
  int tailvex, headvex;
  struct ArcNode *hlink, *tlink;
  // InfoType info;
} ArcNode;
typedef struct VNode { // 顶点表结点
  VertexType data;
  ArcNode *firstin, *firstout;
} VNode;
typedef struct {
  VNode xlist[MaxVertexNum]; // 邻接表
  int vexnum, arcnum;        // 图的顶点数与弧数
} GLGraph;
```

### 邻接多重表（无向图）

邻接多重表是向图的一种链式存储结构，在邻接多重表中对应于无向图的每条边有一个结点，对应于每个顶点也有一个结点。

```c
#define MaxVertexNum 100  // 图中顶点数目的最大值
typedef struct ArcNodel { // 边表节点
  int ivex, jvex;
  struct ArcNode *ilink, *jlink;
  // InfoType info;
} ArcNode;
typedef struct VNode { // 顶点表节点
  VertexType data;
  ArcNode *firstedge;
} VNode;
typedef struct { // 邻接表
  VNode adjmulist[MaxVertexNum];
  int vexnum, arcnum; // 图的顶点数和边数
} AMLGraph;
```

## 三、图的遍历
 
### 广度优先遍历（BFS: Breadth First Search）

#### 广度优先生成树

##### 注意

- 若图是非连通的,则会产生广度优先生成森林
- 图的邻接矩阵表示是唯一的，故广度优先生成树也唯
- 图的邻接表表示不唯一，故广度优先生成树也不唯一