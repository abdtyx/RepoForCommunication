#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define e 1230
int main()
{
    double duration;
    clock_t start, finish;
    start = clock();
    FILE* fp;
    fopen_s(&fp, "prime.txt", "w");
    fprintf(fp, "2\n3\n5\n");
    long a[e] = { 2, 3, 5 };        //��������
    long b[e] = { 4, 9, 25 };       //������ƽ���������ظ�����
    int i = 3, k, m = 1, gab = 2; //������������
    long n;                       //��������
    for (n = 7; i < e; n += 2)    //����������ֱ����e������
    {
        for (k = 1; b[k] <= n; k++) //��n������������
        {
            m = 1;        //bool��������
            if (n % a[k]) //�ж��Ƿ�Ϊ����
                continue;
            else
            {
                m = 0;
                break;
            }
        }
        if (m == 1)
        {
            a[i] = n; //¼����������
            b[i] = n * n;
            fprintf(fp, "%d\n", n); //¼���ļ�
            i++;
        }
    }
    //��һ�δ�ѭ�������������������ǰe����
    for (; b[e - 1] > n; n += gab ^= 6)  //�ڶ���ѭ�����õ�������ֱ��¼���ļ�
    {                               //�Ż�2����n+=2�ĳ���gab���Ƶ�һ��+2һ��+4
        for (k = 2; b[k] <= n; k++) /*�Ż�1��ɾ����&&��������1.5s�ٶ�*/
        {                           //�Ż�3����5��ʼ�Գ�����Ϊ6n-1��6n+1�����ܱ�2��3����
            //m = 1;
            if (n % a[k])
                continue;
            else
            {
                //m = 0;
                break;
            }
        }
        /*if (m == 1)
        {
            //fprintf(fp, "%d\n", n);
        }*/
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    fprintf(fp, "%f seconds\n", duration);
    printf("%f\n", duration);
    return 0;
}
