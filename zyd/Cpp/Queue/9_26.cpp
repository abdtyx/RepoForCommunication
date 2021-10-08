#include <stdlib.h>
#include <stdio.h>

typedef char DataType;

typedef struct QUEUE
{
    DataType * queArray;
    int front;
    int rear;
}Queue;

Queue* CreateQueue(int length);   //创建一个队列
void DestroyQueue(Queue*  queue);   //销毁队列
void ClearQueue(Queue* queue);  //清空队列
int GetQueueLength(Queue* queue);   //得到队列的长度
void EnQueue(Queue* queue, DataType data);   //入队
DataType DlQueue(Queue* queue);   //出队

int main()
{
    return 0;
}

Queue* CreateQueue (int length)
{
    Queue* queue = (Queue*)malloc (sizeof(Queue));
        
}



