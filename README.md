# StudentManagementSystem
> 作者：朱旭东
>
> 大一c/c++个人结课作业：学生成绩管理系统

## 简介

系统面向中国传媒大学以学院为划分的所有同学和老师。主要进行学生成绩的录入，修改，删除，查找，简单的成绩分析以及多个维度的成绩统计排序。涉及面向对象中的封装、继承、多态以及文件IO流。

## 运行环境

软件编写运行于Windows 10 的64位操作系统，Dev-C++ IDE开发环境。软件需满足Intel PentiumIII以上级别的CPU，大于64MB的内存，以及Window 7及以上级别操作系统，Dev-C++或更高版本开发环境。

## 课题分析

### 系统基本需求

定义学生类，其中至少包括姓名、性别、学号、班级和四门功课的成绩。

功能要求：

1、设计菜单实现功能选择； 

2、输入功能：输入学生信息，并保存到文件中；

3、计算每个学生的总分与平均分并排序

4、能根据学号修改学生信息 

5、能根据学号删除学生信息

6、查询功能：

 （1）能够根据学号查询学生信息；

 （2）能够根据姓名、班级查询学生信息

 （3）统计学生成绩，按照班级和科目计算平均分。

### 系统增加需求

1.增加学生基类，并派生出不同学院学生的派生类，并基于多态，面向学校的其他学院的所有学生；

2.增加四门功课学分属性，并增加计算加权平均分功能；

3.增加按照学院和班级两个范围的GPA排序功能；

4.在结构上，增加教师端页面和学生端页面，实现不同身份不同权限；

5.通过学号查找学生时进行简单的成绩分析（分析优势、劣势学科）。

![image-20231001113232278](C:\Users\朱旭东\AppData\Roaming\Typora\typora-user-images\image-20231001113232278.png)

(图3.2.1 加权平均分计算公式 Xi 为参加测评的第 i 门课程的成绩，W i为第 i 门课程的学分，n j为第 j 个同学参加测评的课程总数。)

## 主要模块的功能

系统主要功能可以实现不同学院所有同学成绩的增删改查。

1. 身份模块：支持教师端和学生端两种身份权限访问系统。
2. 输入模块：主要完成将数据存入一个数据文件中，在本管理系统中，记录可以数据文件读入，也可以从键盘逐个输入学生成绩信息。
3. 删除模块：主要完成对所有学生成绩的维护，支持删除学生信息。
4. 修改模块：主要完成对学生成绩的维护，实现对学生记录的修改（支持单独修改班级、姓名、各科成绩）。
5. 查询模块：主要完成以查询班级成绩信息，以姓名和学号等方式查找学生信息，以及学号查找提供简单的成绩分析功能。
6. 统计模块：主要完成对各学生的信息和成绩进行统计。支持展示以学院和班级两个不同维度范围按总分和GPA两种方式的排序和平均分的统计。
7. 输出模块：主要完成基于多态技术实现将不同学院学生记录的成绩信息在屏幕上输出。
8. 文件操作模块：主要完成对数据的读取、初始化和保存至文件。

## 总结

### 在知识的应用角度：

#### 优点：

1. CUCer ** 维护了一个创建在堆区的不定数量的不同子对象的数组，使得不同学院的学生维护在同一个是数组。
2. 在不同学院的学生类书写采用继承CUCer基类（排名相互独立，课程相对独立，信息展示函数不同），在展示信息和获取学院函数 采用了多态技术，发挥了c++语言的对象、继承、多态优势。

#### 缺点：

1. 受限于制表符逢’8‘进，当有些信息超过8个字符时会”对不齐“，页面不太美观。

### 在系统框架方面：

#### 优点：

1. 提供面向老师和学生不同页面，实现不同身份有不同的系统权限
2. 支持读写文件，可以直接在对应的文本中直接录入学生成绩信息
3. 提供不同范围的5种学生成绩排序方式
4. 程序仍可扩展至更多学院，面向所有CUC学生（目前只有信通学院和计网学院）
5. 提供简单的成绩分析功能（包括以整体加权平均分为依托分析优势学科 劣势学科 核心竞争力的分析（这部分功能尚未实现））

#### 缺点：

1. 代码过千行，统计学生排序部分有代码重复。
2. 只支持将一个功能执行完毕，才能执行其他任务，不支持中途退出。
