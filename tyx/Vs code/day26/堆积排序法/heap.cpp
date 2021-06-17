#include <stdio.h>
void heap(int data[], int size)
{
	void ad_heap(int* data, int i, int size);
	int i, j, tmp;
	for (i = (size / 2); i > 0; i--)	/*�����ѻ����ڵ�*/
		ad_heap(data, i, size - 1);
	printf("\n�ѻ�����: ");
	for (i = 1; i < size; i++)	/*ԭʼ�ѻ�������*/
		printf("[%2d] ", data[i]);
	printf("\n");
	for (i = size - 2; i > 0; i--)	/*�ѻ�����*/
	{
		tmp = data[i + 1];	/*ͷβ�ڵ㽻��*/
		data[i + 1] = data[1];
		data[1] = tmp;
		ad_heap(data, 1, i);	/*����ʣ��ڵ�*/
		printf("\n�������: ");
		for (j = 1; j < size; j++)
			printf("[%2d] ", data[j]);
	}
}
void ad_heap(int* data, int i, int size)
{
	int j, tmp, post;
	j = 2 * i;
	tmp = data[i];
	post = 0;
	while (j<=size && post == 0)
	{
		if (j < size)
		{
			if (data[j] < data[j + 1]);	/*�ҳ����ڵ�*/
			j++;
		}
		if (tmp >= data[j])	/*�������ϴ󣬽����ȽϹ���*/
			post = 1;
		else
		{
			data[j / 2] = data[j];	/*��������С��������Ƚ�*/
			j = 2 * j;
		}
	}
	data[j / 2] = tmp;	/*ָ������Ϊ���ڵ�*/
}