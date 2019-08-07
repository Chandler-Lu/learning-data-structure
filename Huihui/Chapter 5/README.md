# 七夕快乐
![](https://raw.githubusercontent.com/Chandler-Lu/picbed/master/HappyMagpie.png)

# Chapter 5

# 树

## 一、树的基本概念

### 定义
N (N \>= 0) 个节点的的有限集合，对任意非空树应满足
1. 有且仅有一个特定的成为根的节点
2. 当 N \>= 1 时，其余节点可分为 m (m\>0) 个互不相交的有限集合，其中每个集合本身又是一棵树，并且称为根结点的子树

### 特点
1. 定义是递归的
2. 非线性结构
3. 根节点没有前驱节点，除根节点外，所有节点有且只有一个前驱节点
4. 叶节点没有后继节点，除叶节点以外，所有节点有一个或多个后继节点

### 基本术语
1. 祖先节点，子孙节点
2. 双亲节点，孩子节点
3. 兄弟节点
4. 一个结点的**孩子结点个数**称为**结点**的**度**
5. 树中**结点的最大度数**称为**树**的**度**
6. 度大于 0 的结点称为**分支结点**（也称**非终端结点**）
7. 度为 0 的结点称为**叶结点**（也称**终端结点**）
8. 节点的**层次**
9. 树的**高度**（深度）是树中结点的最大层数
10. 路径
11. 路径长度
12. 有序树，无序树，森林

### 树的性质

## 二、树的存储结构
1. 双亲表示法：采用一组连续空间来存储每个结点，同时在每个结点中增设一个伪指针，指示其双亲结点在数组中的位置
2. 孩子表示法：每个结点的孩子结点都用单链表链接起来形成一个线性结构
3. 孩子兄弟表示法：每个结点包含三部分内容：指向第一个孩子结点的指针、结点值、指向结点下一个兄弟结点的指针。

## 三、树与森林的遍历

### 树的遍历
1. 先根遍历
2. 后根遍历
3. 层序遍历

### 森林的遍历
1. 先序遍历
2. 中序遍历

# 二叉树

## 一、二叉树的基本概念

### 定义
二叉树是 n (n ≥ 0) 个结点的有限集合，特点是每个结点至多只有两棵子树，并且二叉树的子树有左右之分，其次序不能颠倒。

### 几个特殊的二叉树
1. 满二叉树
2. 完全二叉树

### 二叉树的性质

## 二、二叉树的存储结构
1. 顺序存储结构
2. 链式存储结构

## 三、二叉树的遍历
1. 先序遍历
2. 中序遍历
3. 后序遍历
4. 层序遍历

### 由遍历序列构造二叉树
可以唯一确定一棵二叉树的遍历序列：
1. 先序+中序
2. 后续+中序
3. 中序+层序