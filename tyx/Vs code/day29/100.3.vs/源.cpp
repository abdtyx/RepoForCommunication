//һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
#include <stdio.h>
#include <math.h>
int main()
{
    int i = -268;
    for (; i < 7226; i++)
    {
        for (int j = 0; j < 86; j++)
        {
            if (j == sqrt(i + 100))
            {
                if (j == sqrt(i + 268))
                {
                    printf("�����ǣ�%d", i);
                }

            }

        }

    }

}