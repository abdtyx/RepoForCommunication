#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* create();
	int isEmpty(int top);
	int push(int data, int* ptr_top, int* stack);
	int pop(int* ptr_top, int stack[]);
	void scan(int* ptr_top, int stack[]);
	int i = 0, top = -1, data = 0;
	int* ptr_stack, * ptr_top = &top;
	ptr_stack = create();
	do
	{
		printf("Ҫѹ���ջ��������1������������0��ֹͣ����������-1��");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			printf("������Ԫ��ֵ��");
			scanf_s("%d", &data);
			push(data, ptr_top, ptr_stack);
			break;
		case 0:
			data = pop(ptr_top, ptr_stack);
			data == -1 ? printf("��ջ�ѿ�\n") : printf("������Ԫ��Ϊ��%d\n", data);
			break;
		default:
			break;
		}
	}while (i != -1);
	printf("============================\n");
	scan(ptr_top, ptr_stack);
	printf("==========================\n");
	free(ptr_stack);
	return 0;
}