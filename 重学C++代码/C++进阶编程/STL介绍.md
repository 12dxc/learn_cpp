#### STL(Standard Template Library)

+ STL算法是泛型的(generic)，不与任何特定数据结构和对象绑定，不必在环境类似的情况下重写代码。
+ STL算法可以量身定做，并且具有很高效率。
+ STL可以进行扩充，你可以编写自己的组件并且能与STL标准的组件进行很好的配合。



##### STL的大致框架

![](C:\Users\dxc\Desktop\C++进阶编程\imgs\01.jpg)



##### 组件之间如何配合：

![](C:\Users\dxc\Desktop\C++进阶编程\imgs\02.jpg)

#### 容器（container）

##### 容器用于存放数据；STL的容器分为两大类：

+ 序列式容器(Sequence Containers):
  + 其中的元素都是可排序的(ordered)，STL提供了vector,list,deque等序列式容器，而stack，queue,priority_queue则是容器适配器；

+ 关联式容器(Associative Containers):
  + 每个数据元素都是由一个键(key)和值(Value)组成，当元素被插入到容器时，按其键以某种特定规则放入适当位置；常见的STL关联容器如：setmultiset,map,multimap;



#### 仿函数（functor）

+ 仿函数一般不会单独使用，主要是为了搭配STL算法使用。
+ 函数指针不能满足STL对抽象性的要求，不能满足软件积木的要求，无法和STL其他组件搭配。
+ 本质就是类重载了一个operator()，创建一个行为类似函数的对象。
  



#### 算法(algorithm)

+ STL中算法大致分为四类：包含于\<algorithm>，\<numeric>，\<functional>
  1. 非可变序列算法：指不直接修改其所操作的容器内容的算法；
  2. 可变序列算法： 指可以修改它们所操作的容器内容的算法；
  3. 排序算法： 包括对序列进行排序和合并的算法、搜索算法以及有序序列上的集合操作；
  4. 数值算法： 对容器内容进行数值计算；
+ 最常见的算法包括：
     + 查找，排序和通用算法，排列组合算法，数值算法，集合算法等算法；




#### 迭代器(iterator)

+ 是一种smart pointer,用于访问顺序容器和关联容器中的元素，相当于容器和操作容器的算法之间的中介。
+ 迭代器按照定义方式分成以下四种：
  1. 正向迭代器：     	 iterator;
  2. 常量正向迭代器：  const_iterator
  3. 反向迭代器：          reverse_iterator
  4. 常量反向迭代器：  const_reverse_iterator

##### 容器和迭代器：

|      容器      |  迭代器功能  |
| :------------: | :----------: |
|     vector     |   随机访问   |
|     deque      |   随机访问   |
|      list      |   双向访问   |
|  set/multiset  |   双向访问   |
|  map/multimap  |   双向访问   |
|     stack      | 不支持迭代器 |
|     queue      | 不支持迭代器 |
| priority_queue | 不支持迭代器 |



#### 容器适配器(adapter)

+ __stack 堆栈：__
  + 一种”先进后出“的容器，底层数据结构是使用的deque；
+ __queue 队列：__
  + 一种”先进先出“的容器，底层数据结构是使用的deque；
+ __priority_queu 优先队列：__
  + 一种特殊的队列，它能够在队列中进行排序（堆排序），底层实现结构是vector或者deque；

​	

#### STL总结

+ STL的六大组件给软件编程带来了新的多态和复用，是现代C++语言高效的精髓；
+ 泛型和STL的学习路线很陡，建议初学者先学会基本使用和简单扩展；
+ 掌握了一定基础的情况下，可以通过进一步的学习和分析源码，编写自己的组件来提升能力；
