#include <stdio.h>
#include <stdlib.h>

int main()
{

    enum class day
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    };

    int a = 1;
    enum class day weekend;
    weekend = (enum day)a;  //����ת��
    //weekend = a; //����
    printf("weekend:%d", weekend);
    return 0;
}