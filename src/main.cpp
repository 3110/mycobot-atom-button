#include <MycobotBasic.h>
#include <ParameterList.h>

MycobotBasic myCobot;

void setup(void)
{
    myCobot.setup();
    myCobot.powerOn();
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    myCobot.setPinMode(39, INPUT);
}

void loop(void)
{
    M5.update();
    if (myCobot.getDigitalInput(39) == 0)
    {
        M5.Lcd.fillScreen(TFT_GREEN);
        myCobot.setLEDRGB(0x00, 0xff, 0x00);
    }
    else
    {
        M5.Lcd.fillScreen(TFT_BLACK);
        myCobot.setLEDRGB(0x00, 0x00, 0x00);
    }
    delay(200);
}