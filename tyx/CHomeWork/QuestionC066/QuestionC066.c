/// <ID>C066</ID>
/// <date>2020/11</date>
/// <summary>
/// ��ҽԺ���Σ����룩��ʱ������������й��ɣ����ǵ�һ�Σ�
/// ͣһ�£�Ȼ��ζ��Σ�ͣһ�£��ٵ����Σ�ͣһ��...��������һ�����⣺
/// ��ƿ��ˮһ����v������ÿһ����d������
/// ÿһ�ε��ٶ���һ�루�������һ�β���d�������򻨷ѵ�ʱ��Ҳ��һ�룩��
/// ͣһ�µ�ʱ��Ҳ��һ�룬��ƿˮʲôʱ���ܵ����أ���0 < d < v < 6000)
/// </summary>
/// <input>һ���Ƕ��ٺ���(ʵ������һƿ��ˮ�ж��ٺ���(ʵ�������м��ÿո����</input>
/// <output>������Ҫ����ʱ�䣨������</output>
/// <sample>
/// 1.2 234.67
/// 215
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	float d, v;
	(void)scanf("%f%f", &d, &v);
	int totalInterval = 0;
	int n = 1;
	int t = (int)(v / d); //�Ƿ���������
	int time = v / d - t > 0 ? t + 1 : t; //ͳ�ƵεĴ���
	while (v > 0) //ͳ�Ƽ������
	{
		for (int i = 0; i < n; i++)
		{
			v = v - d;
			if (v <= 0)
			{
				break;
			}
		}
		totalInterval++; //ͳ�Ƽ������
		n++;
	}
	printf("%d", time + totalInterval - 1);
	return 0;
}
