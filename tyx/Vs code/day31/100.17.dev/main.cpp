#include <stdio.h>
int main()
{
    char c;
    printf("������һ���ַ���");
    int en_ch = 0, space = 0, digits = 0, others = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c >= 'a' && c <= 'z')||(c >='A' && c <= 'Z'))
            en_ch++;
        else if (c == ' ')
            space++;
        else if (c >= '0' && c <= '9')
            digits++;
        else
            others++;
    }
    printf("Ӣ����ĸ��%d\n�ո�%d\n���֣�%d\n�����ַ���%d", en_ch, space, digits, others);
    return 0;
}
