# 第四章 抽象：进程

[process-run.py](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter4/process-run.py)

[README-process-run](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter4/README-process-run)

## 1
CPU利用率为100%。
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071259739.png)

## 2
需要10个时间，其中CPU5个时间，IO4个时间，IO结束需要1个时间。
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071303600.png)

## 3
与交换前大有不同。如图，先运行进程0，进程0申请IO时使用CPU，进程1进入就绪态，消耗1个时间；之后进程0使用IO，进程1使用CPU，都使用了4个时间；最后结束。CPU和IO可以同时使用，大大提高了运行效率，只需要6个时间即可完成。交换顺序很重要。
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071311706.png)

## 4
回归到交换之前即第二题的状态，仅仅只是IO和CPU顺序变化，总的运行时间减1（IO结束的时间和运行CPU的时间重合）。IO和CPU不会同时运行。
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071316321.png)

## 5
和第三题一样。
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071317427.png)

## 6
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071717946.png)

## 7
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071720959.png)

运行一个刚刚完成IO的进程可以在IO等待期将CPU交给另一个进程。如果等其他进程运行完再运行IO，那么IO运行期间就无法将CPU交给其他进程，CPU利用率将会大大降低；同时，IO进程在等待其他进程时，IO设备会闲置，Io利用率也会降低。

## 8
a. IO_RUN_IMMEDIATE & SWITCH_ON_IO（完成IO时立即运行发出它的进程，等待IO时切换到另一进程）
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071749094.png)
b. IO_RUN_IMMEDIATE & SWITCH_ON_END（完成IO时立即运行发出它的进程，等待IO时不切换到另一进程）
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071751861.png)
c. IO_RUN_LATER & SWITCH_ON_IO（完成IO时仍运行已经运行的进程，等待IO时切换到另一进程）
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071752080.png)
d. IO_RUN_LATER & SWITCH_ON_END（完成IO时仍运行已经运行的进程程，等待IO时不切换到另一进程）
![](https://raw.githubusercontent.com/dqxcj/Study/test/test2/test7/test8/202209071753996.png)