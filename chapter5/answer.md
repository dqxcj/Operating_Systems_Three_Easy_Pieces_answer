# 第五章 插叙：进程API

## 1
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/1.c)

改变后，x在各进程中的值变为各进程中修改的那个值。

## 2
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/2.c)

都可以访问文件描述符。无法做到同时，父进程总是比子进程先执行。

## 3
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/3.c)

做不到。

## 4
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/4.c)

不同的exec变体从调参方式、环境配置等方面提供不同的选择，详见[这里](https://blog.csdn.net/zjwson/article/details/53337212)

简略总结如下：
```markdown
1. 带字母l的表示参数需要逐个给出, 以NULL结尾。如: execl("/bin/ls", "ls", "-a", NULL)
2. 带字母v的表示参数可以以数组的形式给出。如: char *arr = {"ls", "-a", NULL}; execv("/bin/ls", arr);
3. 带字母p的表示文件路径可以只填写文件名。如: execvp("ls", arr);
4. 带字母e的表示新进程（就是替换子进程的那个进程）的环境变量可以在envp[]数组中自定义。如execve("ls", arr, envp);
```

## 5
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/5.c)

父进程wait()返回其子进程的pid，子进程调用wait()会出错并返回-1，原因是子进程没有自己的子进程。

## 6
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/6.c)

waitpid可以指定等待哪一个子进程，更灵活，详见[这里](https://blog.csdn.net/kevinhg/article/details/7001719)

## 7
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/7.c)

关闭标准输出后，使用printf无输出，此时若打开一个文件，则printf会将输出内容写入该文件。

## 8
[代码](https://github.com/dqxcj/Operating_Systems_Three_Easy_Pieces_answer/tree/main/chapter5/8.c)
