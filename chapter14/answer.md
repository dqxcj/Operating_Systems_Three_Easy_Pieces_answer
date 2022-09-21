# 第14章 插叙：内存操作API

## 1.
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter14/1.c)

毫无问题

## 2.
运行:
```c
gcc -g 1.c -o 1
gdb 1
run
```

正常运行，输出如下
```c++
Starting program: /media/sf_VM_share/Operating_system_introduction/chapter14/1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[Inferior 1 (process 2934) exited normally]
```

## 3.
运行：
```c
gcc -g 1.c -o 1
valgrind --leak-check=yes ./1
```

输出如下
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209210951824.png)
解释：
>1. 2821是进程pid
>2. HEAP SUMMARY是堆区信息总结

## 4. 
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter14/4.c)
### gdb
运行:
```c
gcc -g 4.c -o 4
gdb 4
run
```
输出:
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209211003679.png)
未发现问题

### valgrind
运行:
```c
gcc -g 4.c -o 4
valgrind --leak-check=yes ./4
```
输出:
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209211007924.png)
LEAK SUMMARY显示肯定泄露(definitely lost)的有1个块中的4个字节，正好对应我未释放的int大小的内存。

## 5. 
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter14/5.c)  
直接运行未报错
### valgrind
运行:
```c
gcc -g 5.c -o 1
valgrind --leak-check=yes ./5
```
输出:
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209211024107.png)
程序不正确。  
data[100]的地址0x4a941d0在分配的数组后，即访问数组越界；  
未释放数组，所以内存泄漏了400个字节。

## 6.
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter14/6.c)  
程序能正常运行并正确打印。
### valgrind
运行:
```c
gcc -g 6.c -o 6
valgrind --leak-check=yes ./6
```
输出:
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209211033711.png)
Invalid read 无效读取
free释放内存并不会清除内存的值，所以仍能正确打印data[10]。

## 7.
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter14/7.c)  
程序编译运行报错。
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209211041497.png)

## 8.

## 9.


