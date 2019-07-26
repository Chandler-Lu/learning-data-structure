# Chapter 1

## Class 1

### 一.	数据结构的三要素
1. 数据的逻辑结构
	1. 指数据元素之间的逻辑关系
	2. 与数据的存储无关，独立于计算机
	3. 分为线性结构和非线性结构
		1. 线性结构：线性表、栈、队列、串、数组、广义表
		2. 非线性结构：图、树、集合
2. 数据的存储结构
	1. 指数据在计算机中的表示，“物理结构”
	2. 是逻辑结构用计算机语言的实现
	3. 分为 4 类，顺序存储，链式存储，散列存储，索引存储
3. 数据的运算
	1. 施加在数据上的运算
	2. 一般为数据的增、删、改、查、排序等
	3. 运算的定义是针对逻辑结构
	4. 运算的实现是针对物理结构

## Class 2
算法的定义：对特定问题求解步骤的一种描述，是指令的有限序列

**特征**：有穷性，确定性，可行性，输入，输出
**目标**：正确性，可读性，健壮性，效率，低存储

算法原地工作：算法所需的辅助空间是常量，S(n) = O(1)