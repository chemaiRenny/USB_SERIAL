#include "mbed.h"

#define MAXIMUM_BUFFERSIZE 512
#define ON_CHR 'K'
#define OFF_CHR 'D'

DigitalOut myLed(LED1);
BufferedSerial sp(USBTX,USBRX);

int main()
{
    char buf[MAXIMUM_BUFFERSIZE]={0};

    sp.set_baud(115200);
    while(1)
    {
        sp.read(buf,sizeof(buf));
        sp.write(buf,sizeof(buf));

        myLed = !myLed;
        //ThisThread::sleep_for(500ms);

    }
}