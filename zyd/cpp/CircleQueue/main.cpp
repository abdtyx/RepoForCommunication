#include <stdio.h>
#include <stdlib.h>

typedef char DataType; //假设是字符队列
//定义队列结构
typedef struct QUEUE
{
    DataType *queArray;
    int front;     //队头
    int rear;      //队尾
    int maxLength; //队的最大容量
} Queue;

//声明队列的方法
Queue *CreateQueue(int length);            //创建一个队列
void DestroyQueue(Queue *queue);           //销毁队列
void ClearQueue(Queue *queue);             //清空队列
int GetQueueLength(Queue *queue);          //得到队列的长度
void EnQueue(Queue *queue, DataType data); //入队
DataType DlQueue(Queue *queue);            //出队

// 主函数
int main()
{
    const int QueueMax = 100; //队列最大容量
    //创建队列
    Queue *queue = CreateQueue(QueueMax);
    if (queue == NULL)
        return 1; //创建失败，程序退出
    //入队操作，3个元素进入队列
    EnQueue(queue, 'A');
    EnQueue(queue, 'B');
    EnQueue(queue, 'C');
    //一个元素出队,并显示
    printf("出队：%c\n", DlQueue(queue));
    //再入队3个后打印队列
    EnQueue(queue, 'D');
    EnQueue(queue, 'E');
    EnQueue(queue, 'F');
    //所有元素依次出队直到队空
    while (GetQueueLength(queue) > 0)
        printf("出队：%c\n", DlQueue(queue));
    DestroyQueue(queue);
    return 0;
}

/**
*@brief 创建一个队列
*@param length 对列的容量
*@return 指向队列的指针，失败返回NULL
*/

/**
*@brief  销毁队列
*@param queue 指向队列的指针
*/

/**
*@brief  清空队列
*@param queue 指向队列的指针
*/

/**
*@brief  得到队列的长度
*@param queue 指向队列的指针
*@return 队列中的元素个数
*/

/**
*@brief  入队
*@param queue 指向队列的指针
*@param data 要入队的元素
*/

/**
*@brief  出队
*@param queue 指向队列的指针
*@return 出队的元素值，如队空，返回0
*/
