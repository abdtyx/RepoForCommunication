/// <ID>C069</ID>
/// <date>2020/11</date>
/// <summary>
/// ����һ����������������2���ٽ�����2���������ֵ��������ֵĸ�λ����Ӧ��ŵ���ĸ�����
/// �滻ԭ��0��Ϊa��1��Ϊb��2��Ϊc��...���Դ����ƣ�9��Ϊj��
/// ���磬1234, ����2����617���滻���Ϊgbh
/// </summary>
/// <input>һ��������</input>
/// <output>��2��������������ֺ��ַ������м���һ���ո����</output>
/// <sample>
/// 1234
/// gbh
/// </sample>
/// <sample>
/// 156790
/// 78395 hidjf
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int inputNum;
	(void)scanf("%d", &inputNum);
	inputNum = inputNum / 2;
	printf("%d ", inputNum);
	//��ת����inputnum
	//Invert inputnum
	int resverseInputNum = 0;
	while (inputNum)
	{
		resverseInputNum = resverseInputNum * 10 +
			inputNum % 10;
		inputNum /= 10;
	}
	//����ת������ִӸ�λ���ȡ�����
	//Take out the inverted numbers from each bit one by one and output
	while (resverseInputNum)
	{
		printf("%c", resverseInputNum % 10 + 'a');
		resverseInputNum /= 10;
	}
	return 0;
}
