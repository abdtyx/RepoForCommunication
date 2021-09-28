#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;

typedef struct stack
{
    int top;
    int bottom;
    Datatype *stackArray;
} Stack;

//申明栈的函数
Stack *CreateStack(int length);         //创建一个新的栈
void ClearStack(Stack *stack);          //清空栈
void DestroyStack(Stack *stack);        //销毁栈
Datatype Pop(Stack *stack);             //弹栈
void Push(Stack *stack, Datatype data); //压栈
int GetLength(Stack *stack);            //得到栈的大小
Datatype GetSatckPeek(Stack *stack);    //取得栈顶元素

int main()
{

    return 0;
}

Stack *CreateStack(int length)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (stack)
    {
        stack->stackArray = (Datatype *)malloc(sizeof(Datatype));
        if (stack->stackArray == NULL)
        {
            return NULL;
            stack->bottom = 0;
            stack->top = 0;
        }
    }
    return stack;
}

void ClearStack(Stack *stack)
{
    stack->top = 0;
    stack->bottom = 0;
}

void DestoryStack(Stack *stack)
{
    free(stack->stackArray);
    free(stack);
}

Datatype Pop(Stack *stack)
{
    if (stack->top > stack->bottom)
    {
        return stack->stackArray[--stack->top];
    }
    else
    {
        return 0;
    }
}

void push(Stack *stack, Datatype Data)
{
    stack->stackArray[stack->top++] = Data;
}

int Getlenth(Stack *stack)
{
    return stack->top - stack->bottom;
}

Datatype GetSatckPeek(Stack *stack)
{
    return stack->top > stack->bottom ? stack->stackArray[stack->top - 1] : 0;
}