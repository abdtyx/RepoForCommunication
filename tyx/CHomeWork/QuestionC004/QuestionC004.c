/// <ID>C004</ID>
/// <date>2020/11</date>
/// <summary>
/// ĳ����˾���ù��õ绰�������ݣ���������λ��������
/// �ڴ��ݹ������Ǽ��ܵģ����ܹ������£�
/// 1. ÿλ���ֶ����������5��ĺͳ���10���������棬
/// ��1��6���棬8��3���棻��3768��ת��Ϊ8213��
/// 2. �ٽ���һ�����ɵ����ֵĵ�һλ�͵���λ������
/// �ڶ�λ�͵���λ������ ��8213ת��Ϊ3128����Ϊ���յļ������롣
/// </summary>
/// <input>1������</input>
/// <output>һ������</output>
/// <sample>
/// 1234
/// 9876
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int teleNum;
	(void)scanf("%d", &teleNum);
	//�ֽⲢ����
	//Decompose and encrypt
	int a0 = (teleNum % 10 + 5) % 10;
	int a1 = ((teleNum / 10) % 10 + 5) % 10;
	int a2 = ((teleNum / 100) % 10 + 5) % 10;
	int a3 = (teleNum / 1000 + 5) % 10;

	printf("%d", a0 * 1000 +
	       a1 * 100 + a2 * 10 + a3);
	return 0;
}
