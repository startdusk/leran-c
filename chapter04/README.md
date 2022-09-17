## GCC 编译头文件

```bash
# 头文件路径
chapter04/include/fib.h
# 头文件实现函数文件路径
chapter04/src/fib.c
# 使用该头文件的文件
chapter04/include_file.c
```

头文件实现函数文件必须 include 头文件

```C
// chapter04/src/fib.c
#include "../include/fib.h"
```

编译

```bash
gcc include_file.c -I include ./src/fib.c
```
