// ����  ���տ���

#include <windows.h>
using namespace std;



int main()
{

    unsigned FREQUENCY[] = { 392,392,440,392,523,494,

              392,392,440,392,587,523,

              392,392,784,659,523,494,440,

              689,689,523,587,523 };

    unsigned DELAY[] = { 375,125,500,500,500,1000,

              375,125,500,500,500,1000,

              375,125,500,500,500,500,1000,

              375,125,500,500,500,1000 };

    int i;

    for (i = 0; i < 25; i++)

    {

        Beep(FREQUENCY[i], DELAY[i]);

    }

}