# 第七章 进程调度：介绍
[README-scheduler](README-scheduler.md)
[scheduler.py](scheduler.py)

## 1.
Execution trace:
    [time 0]    Run job 0 for 200 secs (DONE)
    [time 200]  Run job 1 for 200 secs (DONE)
    [time 400]  Run job 2 for 200 secs (DONE)

Final statistics:
    Job 0 -- Response: 0    Turnaround: 200
    Job 1 -- Response: 200  Turnaround: 400
    Job 3 -- Response: 400  Turnaround: 600
    Avg   -- Response: 200  Turnaround: 400

## 2. 
Execution trace:
    [time 0]    Run job 0 for 100 secs (DONE at 100)
    [time 100]  Run job 1 for 200 secs (DONE at 300)
    [time 300]  Run job 2 for 300 secs (DONE at 600)

Final statistics:
    Job 0 -- Response: 0    Turnaround: 100
    Job 1 -- Response: 100  Turnaround: 300
    Job 3 -- Response: 300  Turnaround: 600
    Avg   -- Response: 133  Turnaround: 333

## 3.
Execution trace:
    [time 0]  Run job 0 for 1 secs (DONE at 298)
    [time 1]  Run job 1 for 1 secs (DONE at 499)
    [time 2]  Run job 2 for 1 secs (DONE at 600)
    [time 3]  Run job 0 for 1 secs 
    ......

Final statistics:
    Job 0 -- Response: 0  Turnaround: 298
    Job 1 -- Response: 1  Turnaround: 499
    Job 3 -- Response: 2  Turnaround: 600
    Avg   -- Response: 1  Turnaround: 465.67

## 4
工作时间长度相同或按工作时间长度从短到长顺序到达的；

## 5
？

## 6
变长

## 7
变长