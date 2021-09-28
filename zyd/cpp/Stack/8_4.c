#include <stdlib.h>
#include<stdio.h>

//定义一个字符栈
typedef char DataType;
//定义栈
typedef struct STACK
{
	DataType* stackArray;
	int top;
	int bottom;
}Stack;

//申明栈的函数
Stack* CreateStack(int length);     //创建一个新的栈
void ClearStack(Stack* stack);      //清空栈
void DestroyStack(Stack* stack);   //销毁栈
DataType Pop(Stack* stack);    //弹栈
void Push(Stack* stack, DataType data);   //压栈
int GetLength(Stack* stack);  //得到栈的大小
DataType GetSatckPeek(Stack* stack);   //取得栈顶元素

//测试主函数
int main()
{
	//定义栈的大小
	const int MAXLENGTH = 100;
	//创建一个栈
	Stack* stack = CreateStack(MAXLENGTH);
	//输入10个字符并入栈
	for (int i = 0; i <10; i++)
	{
		char ch;
		scanf("%c", &ch);
		//入栈
		Push(stack, ch);
	}
	//弹栈并输出直到栈空
	while (GetLength(stack)>0)
		printf("%c", Pop(stack));
	DestroyStack(stack);
	return 0;
}

//栈函数的实现
/**
  *@brief 创建一个新的栈
  *@param length 栈的大小
  *@return 指向栈的指针，如创建失败，返回NULL
  */
Stack* CreateStack(int length)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack)
	{
		//分配栈空间
		stack->stackArray = (DataType*)malloc(length*sizeof(DataType));
		if (stack->stackArray == NULL)
			return NULL;
		//置为空栈
		stack->bottom = 0;
		stack->top = 0;
	}
	return stack;
}
/**
*@brief 清空栈
*@param stack 指向栈的指针
*/
void ClearStack(Stack* stack)
{
	stack->bottom = 0;
	stack->top = 0;
}
/**
*@brief 销毁栈
*@param stack 指向栈的指针
*/
void DestroyStack(Stack* stack)
{
	free(stack->stackArray);
	free(stack);
}
/**
*@brief 弹栈
*@param stack 指向栈的指针
*@return 弹出的栈顶元素，如果弹栈失败，返回0
*/
DataType Pop(Stack* stack)
{
	if (stack->top > stack->bottom)
	{
		//如果栈不空，则出栈
		//stack->top -= 1;
		return stack->stackArray[--stack->top];
	}
	else
	{
		//栈已经空了，出栈失败
		return 0;
	}
}
/**
*@brief 压栈
*@param stack 指向栈的指针
*@param data 要入栈的元素
*/
void Push(Stack* stack, DataType data)
{
	//此处没有处理栈满的情况，因为无法取得栈的最大容量！
	stack->stackArray[stack->top++] = data;
	//stack->top++;
}
/**
*@brief 得到栈的大小
*@param stack 指向栈的指针
*@return 栈大小
*/
int GetLength(Stack* stack)
{
	return stack->top - stack->bottom;
}
/**
*@brief 取得栈顶元素, 但是不出栈
*@param stack 指向栈的指针
*@return 栈顶元素，失败返回0
*/
DataType GetSatckPeek(Stack* stack)
{
	return stack->top > stack->bottom ?
		stack->stackArray[stack->top - 1] : 0;
}