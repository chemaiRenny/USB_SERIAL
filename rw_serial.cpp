#include "mbed.h"

#define MAXIMUM_BUFFERSIZE 512
#define BAUDRATE 115200

DigitalOut myLed(LED1);
BufferedSerial sp(USBTX,USBRX);

int main()
{
    char buf[MAXIMUM_BUFFERSIZE]={0};

    sp.set_baud(BAUDRATE); //baudrate
    while(1)
    {
        if(sp.read(buf,sizeof(buf)));  //read serial Object
        {
            sp.write(buf,sizeof(buf)); //write to serial object
            myLed = !myLed;
        }
        //ThisThread::sleep_for(500ms); //no need for wait
    }
}
 