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
Queue *CreateQueue(int length)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue) //不为空
    {
        //申请内存
        queue->queArray = (DataType *)malloc(length * sizeof(DataType));
        //失败则返回NULL
        if (queue->queArray == NULL)
            return NULL;
        //清空队列
        queue->front = 0;
        queue->rear = 0;
        queue->maxLength = length;
    }
    return queue;
}
/**
*@brief  销毁队列
*@param queue 指向队列的指针
*/
void DestroyQueue(Queue *queue)
{
    free(queue->queArray);
    free(queue);
}
/**
*@brief  清空队列
*@param queue 指向队列的指针
*/
void ClearQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}
/**
*@brief  得到队列的长度
*@param queue 指向队列的指针
*@return 队列中的元素个数
*/
int GetQueueLength(Queue *queue)
{
    return queue->rear >= queue->front ? queue->rear - queue->front : queue->rear - queue->front + queue->maxLength;
}
/**
*@brief  入队
*@param queue 指向队列的指针
*@param data 要入队的元素
*/
void EnQueue(Queue *queue, DataType data)
{
    if ((queue->rear + 1) % queue->maxLength == queue->front)
    {
        printf("队列已满，无法完成入队操作");
    }
    else
    {
        //队尾向后移动1位
        queue->rear = (queue->rear + 1) % queue->maxLength;
        //入队
        queue->queArray[queue->rear] = data;
    }
}
/**
*@brief  出队
*@param queue 指向队列的指针
*@return 出队的元素值，如队空，返回0
*/
DataType DlQueue(Queue *queue)
{
    if (GetQueueLength(queue) > 0) //队不空
    {
        queue->front = (queue->front + 1) % queue->maxLength;
        return queue->queArray[queue->front];
    }
    else
    {
        return 0; //队是空的，返回0
    }
}