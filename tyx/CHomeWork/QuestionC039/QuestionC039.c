/// <ID>C039</ID>
/// <date>2020/11</date>
/// <summary>
/// ĳ������ߵ�¥��һ�����ݣ��õ�����������¥�������Ⱥ�������С�
/// ���������0�㡣������һ���������к��ֹͣ�ڸ�¥�㣬������0��
/// ��д��������������һ�����е�ʱ�䡣
/// ����ÿ��1����Ҫ6�롣ÿ��1����Ҫ4�롣����ĳ��ͣ�������������˶��٣���ͣ��5�롣
/// ¥���ֵ���ڵ���1��С��100, 0�������б�ʾ�����������롣
/// ������������������У������������ʱ�䣨�룩��
/// </summary>
/// <input>�����������У��ո�ָ���0����</input>
/// <output>��������ʱ��</output>
/// <sample>
/// 4 0
/// 29
/// </sample>
/// <sample>
/// 2 4 8 4 2 1 0
/// 106
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int sum = 0;
	//The elevator is initially at floor 0
	int floor = 0; //���������0��
	//The elevator move to next floor
	int nextFloor; //�����˶�����һ��

	(void)scanf("%d", &nextFloor);
	while (nextFloor > 0)
	{
		int floorNum = nextFloor - floor;
		sum = sum + 5 +
			(floorNum > 0 ? floorNum * 6 : -floorNum * 4);
		floor = nextFloor;
		(void)scanf("%d", &nextFloor);
	}
	printf("%d", sum);
	return 0;
}
