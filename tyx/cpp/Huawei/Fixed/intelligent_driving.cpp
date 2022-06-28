#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

struct HumiturePara {
    int pin;
    int mode;
    int pull;
    int speed;
};

struct HumitureData {
    int humiHigh8Bit;
    int humiLow8bit;
    int tempHigh8bit;
    int tempLow8bit;
    int checkSum;
    int humidity;
    int temperature;
};

namespace Wsf {
    constexpr int RESET_SATE = 0;
    constexpr int SET_SATE = 0;
    constexpr int PIN_A = 0;
    constexpr int PIN_B = 1;
    constexpr int PIN_C = 2;
    constexpr int PIN_D = 3;
    constexpr int PIN_E = 4;

    void HumitureInit(HumiturePara &para)
    {
        cout<< "%s" << __FUNCTION__ <<endl;
    }

    bool HumitureReadData()
    {
        srand(int(time(NULL)));

        return (rand() % 2) == 0 ? true : false ;
    }

    void HumitureReset()
    {
        cout<< "%s" << __FUNCTION__ <<endl;
    }

    void HumitureSet()
    {
        cout<< "%s" << __FUNCTION__ <<endl;
    }

    int HumitureReadByte()
    {
        srand(int(time(NULL)));

        return rand();
    }

    void DrivingWrite(int pin, int state)
    {
        cout<< "%s" << __FUNCTION__ <<endl;
    }

    void DrivingClear()
    {
        cout<< "%s" << __FUNCTION__ <<endl;
    }

    bool DrivingReadData()
    {
        srand(int(time(NULL)));

        return (rand() % 2) == 0 ? true : false ;
    }

}

class IntelligentDriving {
    int input;
    char rxBuffer[256];

    // 向左
    int ExecFrontLeft(int direction, int F, int B)
    {
        //左前轮驱动
        switch (direction)
        {
            case 0:
                Wsf::DrivingWrite(Wsf::PIN_A, Wsf::RESET_SATE);
                break;
            case 1:
                Wsf::DrivingWrite(Wsf::PIN_B, Wsf::SET_SATE);
                break;
            default:
                Wsf::DrivingWrite(Wsf::PIN_E, Wsf::RESET_SATE);
        }
        return 1;
    }


    int ExecFrontRight(int direction, int F, int B)
    {
        //右前轮驱动
        switch (direction)
        {
            case 0:
                Wsf::DrivingWrite(Wsf::PIN_B, Wsf::RESET_SATE);
                break;
            case 1:
                Wsf::DrivingWrite(Wsf::PIN_B, Wsf::SET_SATE);
                break;
            default:
                Wsf::DrivingWrite(Wsf::PIN_E, Wsf::RESET_SATE);
        }
        return 1;
    }

    int ExecBehindLeft(int direction, int F, int B)
    {
        //左后轮驱动
        switch (direction)
        {
            case 0:
                Wsf::DrivingWrite(Wsf::PIN_C, Wsf::RESET_SATE);
                break;
            case 1:
                Wsf::DrivingWrite(Wsf::PIN_C, Wsf::SET_SATE);
                break;
            default:
                Wsf::DrivingWrite(Wsf::PIN_E, Wsf::RESET_SATE);
        }
        return 1;
    }

/**
 * @brief control the rolling direction of behind-right wheel
 * @param the direction 0: advance
 *											1: back
 *											other: stop
 * @retval 1:success
 */
    int ExecBehindRight(int direction, int F, int B)
    {
        //右后轮驱动
        switch (direction)
        {
            case 0:
                Wsf::DrivingWrite(Wsf::PIN_D, Wsf::RESET_SATE);
                break;
            case 1:
                Wsf::DrivingWrite(Wsf::PIN_D, Wsf::SET_SATE);
                break;
            default:
                Wsf::DrivingWrite(Wsf::PIN_E, Wsf::RESET_SATE);
        }
        return 1;
    }

    void DrivingAdvance(void)
    {
        //前进
        ExecFrontLeft(0, 300, 0);
        ExecFrontRight(0, 300, 0);
        ExecBehindLeft(0, 300, 0);
        ExecBehindRight(0, 300, 0);
    }

    void DrivingStop(void)
    {
        //停止
        DrivingAdvance();
        ExecFrontLeft(2, 0, 0);
        ExecFrontRight(2, 0, 0);
        ExecBehindLeft(2, 0, 0);
        ExecBehindRight(2, 0, 0);
    }

    void DrivingBack(void)
    {
        //后退
        ExecFrontLeft(1, 0, 700);
        ExecFrontRight(1, 0, 700);
        ExecBehindLeft(1, 0, 700);
        ExecBehindRight(1, 0, 700);
    }
    void DrivingLeft(void)
    {
        //左转
        ExecFrontRight(0, 400, 0);
        ExecBehindRight(0, 400, 0);
        ExecFrontLeft(1, 0, 300);
        ExecBehindLeft(1, 0, 300);
    }
    void DrivingRight(void)
    {
        //右转
        ExecFrontLeft(0, 400, 0);
        ExecBehindLeft(0, 400, 0);
        ExecFrontRight(1, 0, 300);
        ExecBehindRight(1, 0, 300);
    }

    void ExecuteAdvance()
    {
        //前进
        char *strx = strstr((const char *)rxBuffer, (const char *)"advance\":1");
        if (strx == NULL)
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        else
        {
            Wsf::DrivingClear();
            DrivingAdvance();
        }
    }

    void ExecuteBack()
    {
        //后退
        char *strx = strstr((const char *)rxBuffer, (const char *)"behind\":1");
        if (strx == NULL)
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        else
        {
            Wsf::DrivingClear();
            DrivingBack();
        }
    }
    void ExecuteLeft()
    {
        //左转
        char *strx = strstr((const char *)rxBuffer, (const char *)"left_advance\":1");
        if (strx == NULL)
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        else
        {
            Wsf::DrivingClear();
            DrivingLeft();
        }
    }
    void ExecuteRight()
    {
        //右转
        char *strx = strstr((const char *)rxBuffer, (const char *)"right_advance\":1");
        if (strx == NULL)
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        else
        {
            Wsf::DrivingClear();
            DrivingRight();
        }
    }

    void HandMmove()
    {
        //手动驾驶
        if (strstr((const char *)rxBuffer, (const char *)"advance\":1"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        if (strstr((const char *)rxBuffer, (const char *)"behind\":1"))
        {
            Wsf::DrivingClear();
            DrivingBack();
        }
        if (strstr((const char *)rxBuffer, (const char *)"left\":1"))
        {
            Wsf::DrivingClear();
            DrivingLeft();
        }
        if (strstr((const char *)rxBuffer, (const char *)"right\":1"))
        {
            Wsf::DrivingClear();
            DrivingRight();
        }
        if (strstr((const char *)rxBuffer, (const char *)"stop\":1"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        if (strstr((const char *)rxBuffer, (const char *)"advance\":0"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        if (strstr((const char *)rxBuffer, (const char *)"behind\":0"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        if (strstr((const char *)rxBuffer, (const char *)"left\":0"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        if (strstr((const char *)rxBuffer, (const char *)"right\":0"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
        if (strstr((const char *)rxBuffer, (const char *)"stop\":0"))
        {
            Wsf::DrivingClear();
            DrivingStop();
        }
    }

    void AutoMove()
    {
        //自动驾驶
        DrivingAdvance();
        //避障检测左
        if (Wsf::DrivingReadData())
        {
            DrivingStop();
            DrivingRight();
        }

        //红外避障检测右
        if(Wsf::DrivingReadData())
        {
            DrivingStop();
            DrivingLeft();
        }
    }

    //自动驾驶和手动驾驶的切换
    void ModeSwitch()
    {
        while (strstr((const char *)rxBuffer, (const char *)"driving_mode\":0"))
        {
            HandMmove();
        }
        while(strstr((const char *)rxBuffer, (const char *)"driving_mode\":1"))
        {
            Wsf::DrivingClear();
            AutoMove();
        }

    }

    // Humiture功能
    void HumitureDelay(int time)
    {
        while (time)
        {
            unsigned char i;
            i = 20;
            while (--i)
            {
            }
            time--;
        }
    }

    //初始化
    void HumitureParaSet(int mode){
        HumiturePara humiturePara = {0};
        if(mode == input)
        {
            humiturePara.pin = 11;
            humiturePara.mode = 22;
            humiturePara.pull = 33;
            humiturePara.speed = 44;
            Wsf::HumitureInit(humiturePara);
        }
        else{
            humiturePara.pin = 11;
            humiturePara.mode = 22;
            humiturePara.speed = 44;
            Wsf::HumitureInit(humiturePara);
        }
    }


    int HumitureParaReadByte(void)
    {
        int i, temp = 0;
        for (i = 0; i < 8; i++)
        {
            /* Humiture 以 26~28us 的高电平表示“0”，以 70us 高电平表示“1”，
            *  通过检测 x us 后的电平即可区别这两个状 ，x 即下面的延时
            */

            if (Wsf::HumitureReadData()) /* x us 后仍为高电平表示数据“1” */
            {
                /* 等 待 数 据 1 的 高 电 平 结 束 */
                while (Wsf::HumitureReadData());
                temp |= (uint8_t)(0x01 << (7 - i)); //把第 7-i 位置 1，MSB 先行
            }
            else // x us 后为低电平表示数据“0”
            {
                temp &= (uint8_t) ~(0x01 << (7 - i)); //把第 7-i 位置 0，MSB 先行
            }
        }
        return temp;
    }


    int HumitureTempAndHumidity(HumitureData *data)
    {
        int temp;
        int humiTemp;

        /* 主 机 拉 低 */
        Wsf::HumitureReset();
        /*设置*/
        Wsf::HumitureSet();
        /*判断从机是否有低电平响应信号 如不响应则跳出，响应则向下运行*/
        if (Wsf::HumitureReadData()){
            /*轮询直到从机发出 的 80us 低电平 响应信号结束*/
            while (Wsf::HumitureReadData());
            /*轮询直到从机发出的 80us 高电平 标置信号结束*/
            while (Wsf::HumitureReadData());
            /*开始接收数据*/
            data->humiHigh8Bit = Wsf::HumitureReadByte();
            data->humiLow8bit = Wsf::HumitureReadByte();
            data->tempHigh8bit = Wsf::HumitureReadByte();
            data->tempLow8bit = Wsf::HumitureReadByte();
            data->checkSum = Wsf::HumitureReadByte();
            /* 主 机 拉 高 */
            Wsf::HumitureSet();
            /* 对数据进行处理 */
            humiTemp = data->humiHigh8Bit * 100 + data->humiLow8bit;
            data->humidity = (float)humiTemp / 100;
            humiTemp = data->tempHigh8bit * 100 + data->tempLow8bit;
            data->temperature = (float)humiTemp / 100;
            /*检查读取的数据是否正确*/
            temp = data->humiHigh8Bit + data->humiLow8bit + data->tempHigh8bit + data->tempLow8bit;
            if (data->checkSum == temp)
            {
                return 0;
            }
            else
                return -1;
        }
        else
            return -1;
    }
};