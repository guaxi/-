/******************************************************
*Author          :   wangDong
*Email           :   
*Last modified   :   2015-06-02 00:14
*Filename        :   bits.c
*Description     :   
******************************************************/
/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here
 * >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

//备注：1.没有必要插入<stdio>头文件 2.printf函数还是可以正常使用，但是编译器//会报错，但是报了错在这个实验中也要紧
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
//整数编程规则
//用一条或者多条c代码来代替每个函数中的return，代码必须遵循下面的形式
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 //代码模板
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
  //1.常量必须在0～255之间，不能使用大的常量
  //2.函数注释和本地变量可以使用，不能使用全局变量
  //3.一元运算符只能使用 ！ ～
  //4.二元运算符只能使用 & ^ | + << >>
  //5.每一个表达式可以使用多个操作符，并没有规定每条语句只能使用一个操作符
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.
//以下的行为是被禁止的
//1.使用任何的控制构造如  if  do while for switch
//2.定义或使用任何的宏定义
//3.在这个文件中定义额外的函数
//4.调用任何的函数
//5.使用别的操作符 如 && || - ?:
//6.使用任何形式的计算(将多个数加起来)
//7.使用除过int之外的数据结构
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }
//浮点数编程规则
FLOATING POINT CODING RULES
//可以使用循环 和 传统的控制
//可以使用  ints  和  unsigneds
//可以使用任意的  整数 和 无符号 常量
For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.
//禁止使用宏定义
//禁止在这个文件中定义额外的函数
//禁止调用任何的函数
//只能使用  int  和  unsigned 数据类型
//禁止使用浮点型数据 操作 和 常量
You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.

//1.使用dlc编译器来检查解决问题的方法的合法性
//2.每一个函数的操作符的使用量都有一个最大的限额，dlc编译器会自动检查，=不算
//3.使用btest test harness 来检查函数的正确性
//4.使用 BDD checker来检查你的函数在形式上的正确性
//5.在每个函数开始的地方给出了这个函数最多的可以使用的运算符
NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */
//1.使用dlc编译器检查你的方案遵循了编码规则
//2.使用BDD checker 验证你的方案产生了正确的结果

#endif
/* 
 *   lsbZero - set 0 to the least significant bit of x 
 *   Example: lsbZero(0x87654321) = 0x87654320
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */
int lsbZero(int x) {
    return  (~((x&0) + 1))&x;

}
/* 
 * byteNot - bit-inversion to byte n from word x  
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int byteNot(int x, int n) {
    return x^(255<<((n<<3))); 
}
/* 
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2 
 */
int byteXor(int x, int y, int n) {
    return  ((255<<(n<<3))&x) ^ ((255<<(n<<3))&y);
}
/* 
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalAnd(int x, int y) {
    return (!!x)&(!!y); 
}
/* 
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalOr(int x, int y) {
    return (!!x)|(!!y);  
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
	unsigned ux = x;
	unsigned a = ux>>(32+(~n)+1);
	int t = (!n) +(~1)+1;
	return ((~t)&x)+(t&((x<<n)+a));
}
/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int parityCheck(int x) {
	unsigned ux = x;
	unsigned a = ux>>16;
	unsigned uy = a^(ux<<16>>16);
	unsigned b = uy>>8;
	unsigned uz = b^(uy<<24>>24);
	unsigned c = uz>>4;
	unsigned ua = c^(uz<<28>>28);
	unsigned d = ua>>2;
	unsigned ub = d^(ua<<30>>30);
	unsigned e = ub>>1;
	return e^(ub<<31>>31);
}
/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *         
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int mul2OK(int x) {
	unsigned ux = x;
	unsigned a = ux>>31;
	unsigned b = ux<<1>>31;
	return !(a^b);
}
/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int mult3div2(int x) {
	int y = (x<<1)+x;
	int z = y>>1;
	unsigned uy = y;
	//3*x的符号位
	unsigned a = uy>>31;
	//3*x的最后一位
	unsigned b = uy&1;
	unsigned flag = (!(a&b))+(~1)+1;
	
	return (flag&(z+1))+((~flag)&z);
}

/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
	
	unsigned ux = x;
	unsigned uy = y;
	unsigned result = x+(~y)+1;
	
	unsigned a = ux>>31;
	unsigned b = uy>>31;
	unsigned r = result>>31;

	unsigned t = a^b;

	return !(((!t)+(~1)+1)&(a^r));

}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	
	unsigned ux = x;
	unsigned a = ux>>31;
	unsigned t = (!a)+(~1)+1;

	return (t&(~(x+(~1)+1)))+((~t)&x);

}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	
	unsigned b = uf<<1>>24;
	unsigned c = uf<<9>>9;
	unsigned flag = b^255;
	if(!flag && c)	return uf;
	return uf<<1>>1;

}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {

	unsigned a = uf>>31;
	unsigned b = uf<<1>>24;
	unsigned c = uf<<9>>9;
	unsigned e,result;
	unsigned flag = (!a)-1;

	//阶码为全1的情况 	
	if(!(b^25))		return 0x80000000;
	//阶数为负数的情况返回0
	if((b-127)>>31)		return 0;
	//超过可以表示的最大整数
	if(!((b-157)>>31))	return 0x80000000;
	if((b-150)>>31)		c = c>>(150-b);
	else	c = c<<(b-150);
	e = 1<<(b-127);
	result = e+c;
	return  (flag&(-result)) + ((~flag)&result);
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *  当参数是未定义数，返回参数
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  	
	unsigned a = uf>>31;
	unsigned b = uf<<1>>24;
	unsigned c = uf<<9>>9;
	unsigned result;

	//阶码为全1的情况,即为未定义数和无穷大，无穷小，返回参数 	
	if(!(b^255))		return uf;
	//-0的情况 与 0 的情况不一样
	if(a&&(!b)&&(!c))	return uf;
	//0的情况
	if((!b)&&(!c))		return 0;
	//阶码为1的情况
	if(!(b-1)){
		//尾数最后一位为 0
		if (!(c&1))	c = ((1<<23)+c)>>1;
		else {
			//尾数为1
			if(!(c^1))	c = ((1<<23)+c)>>1;
			else {
				c = ((1<<23)+c)>>1;
				//运算后尾数末尾为1
				if(c&1)	 c = (c+1)<<9>>9;
			}
		}
		result = (a<<31)+c;
		return result;	
	}
	//非规格化的数
	if((!b)&&c)	
	{
		//尾数最后一位为 0
		if (!(c&1))	return result = (a<<31)+(c>>1);
		else {
			//尾数为1
			if(!(c^1))	return result = (a<<31)+(c>>1);
			result = (a<<31)+(c>>1);
			//运算后尾数末尾为0
			if(!(result&1))	return result;
			return result = (a<<31)+(c>>1)+1;
		}
	}
	//规格化的非0数
	b = b-1;
	result = (a<<31)+(b<<23)+c;
	return  result;
}
