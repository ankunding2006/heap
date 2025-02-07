# 二叉堆(Binary Heap)实现

这是一个用C语言实现的最小堆(Min Heap)数据结构。该实现包含了二叉堆的基本操作，并提供了可视化打印功能。

## 功能特性

- 创建和初始化二叉堆
- 插入元素 (Insert)
- 删除最小元素 (DeleteMin)
- 查找最小元素 (FindMin)
- 判断堆是否为空/已满
- 可视化打印堆结构

## 主要接口

```c
PriorityQueue Initialize(int MaxElements);    // 初始化堆
void Insert(ElementType X, PriorityQueue H);  // 插入元素
ElementType DeleteMin(PriorityQueue H);       // 删除并返回最小元素
ElementType FindMin(PriorityQueue H);         // 查找最小元素
void PrintHeap(PriorityQueue H);             // 打印堆结构
```

## 使用示例

```c
PriorityQueue H = Initialize(200);  // 创建容量为200的堆
Insert(5, H);                       // 插入元素
Insert(3, H);
Insert(7, H);
PrintHeap(H);                       // 打印当前堆结构
ElementType min = DeleteMin(H);     // 删除最小元素
```

## 编译和运行

项目使用gcc编译器，可以直接编译运行：

```bash
gcc binheap.c -o heap
./heap
```

## 实现细节

- 使用数组实现完全二叉树结构
- 数组索引0位置存放哨兵值(MinData)
- 支持动态内存分配
- 包含上滤(percolate up)和下滤(percolate down)操作
- 包含错误处理机制

## 注意事项

- 最小堆容量不能小于 `MinPQSize` (10)
- 堆中元素类型为 `int`
- 程序包含内存检查以避免内存泄漏

## 文件结构

- binheap.h - 头文件，包含数据结构定义和接口声明
- binheap.c - 源文件，包含具体实现
- fatal.h - 错误处理相关函数
