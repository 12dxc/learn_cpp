#pragma once
#ifndef __SOMEFILE_H__   //#ifndef 如果没有定义这个宏名
#define __SOMEFILE_H__   //则#define 定义它

/*为了避免同一文件被include多次，有两种方式:
	1、 #ifndef __SOMEFILE_H__
	   #define __SOMEFILE_H__
	   ......
	   #endif

	   使用宏来防止一个文件重复包含；
	   	优点：可移植性好；
	   	缺点：无法防止宏名重复。难以排错；


	2、 #pragma once
	   使用编译器来防止同一文件被多次包含；
	   优点：可以防止宏名重复，易排错；
	   缺点：可移植性不好；


	总结：只考虑Windows系统可以使用方案2，否则用方案1


#endif    //结束