#include "Display.h"

void Display::init()
{
    display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        for(;;); // Don't proceed, loop forever
    }

    prepareForPrint();

    display.println(F("====================="));
    display.println(F("     Joe's Drive"));
    display.println(F("====================="));

    display.display();

    Serial.println("Ready");

    delay(1000);
}

void Display::setPointer(int pointer)
{
    pointer = pointer;
}

void Display::prepareForPrint()
{
    display.clearDisplay();
    display.setCursor(0,0); 

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
}

void Display::printPointer()
{
    printPointer(0);
}

void Display::printPointer(int alignment)
{
    display.setCursor(0, 8 * (pointer + alignment));
    display.print(">");
}

void Display::infoScreen(int speed, int direction, float bodyBattery, float domeBattery)
{
    prepareForPrint();

    // TODO:: реализовать логику
    display.print(speedNameMap[speed]); display.println(directionNameMap[direction]);
    display.println(F(""));
    display.print("Body: ");
    if (bodyBattery > 0) {
        display.print(bodyBattery); display.println("V");
    } else {
        display.println("dissconnected");
    }

    display.println(F(""));
    display.print("Dome: ");
    if (domeBattery > 0) {
        display.print(domeBattery); display.println("V");
    } else {
        display.println("dissconnected");
    }

    display.display();
}

void Display::menuScreen()
{
    prepareForPrint();

    display.print(F(
        "      Main meny\n"
        "=====================\n"
        " Reverse Dome\n"
        " Dome Config\n"
        " Body Config\n"
        " Joystick calibration\n"
    ));

    printPointer(2);

    display.display();
}

void Display::domeReverseScreen()
{
    prepareForPrint();

    display.print(F(
        " Reverse Dome\n"
    ));

    display.display();
}

void Display::domeConfigScreen()
{
    prepareForPrint();

    display.print(F(
        " Dome Config\n"
    ));

    display.display();
}

void Display::bodyConfigScreen()
{
    prepareForPrint();

    display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Adjust dome tilt\n"
        "until the dome is\n"
        "centered front to back.\n"
        "\n"
        "Then press 'Ok"
    ));

    display.display();
}

void Display::joystickConfigScreen()
{
    prepareForPrint();

    display.print(F(
        "Joystick calibration\n"
        "   select joystick\n"
        "=====================\n"
        " Top left\n"
        " Top right\n"
        " Bottom left\n"
        " Bottom right\n"
    ));

    printPointer(3);

    display.display();
}

void Display::joystickCalibrationStep1Screen(char *joystickName, int valX, int valY)
{
    prepareForPrint();

    display.println(F("  Center calibration"));
    display.println(joystickName);
    display.print(F(
        "=====================\n"
        "  Release joystick\n"
    ));
    display.print(F("X center: ")); display.println(valX);
    display.print(F("Y center: ")); display.println(valY);
    display.print(F(
        "\n"
        "Press OK to save\n"
    ));

    display.display();
}
void Display::joystickCalibrationStep2Screen(char *joystickName, int minX, int maxX, int minY, int maxY)
{
    prepareForPrint();

    display.println(F("  min/max calibration"));
    display.println(joystickName);
    display.print(F(
        "=====================\n"
        "  Rotate joystick\n"
    ));
    display.print(F("X min:")); display.print(minX); display.print(F(" X max:")); display.println(maxX);
    display.print(F("Y min:")); display.print(minY); display.print(F(" Y max:")); display.println(maxY);
    display.print(F(
        "\n"
        "Press OK to save\n"
    ));

    display.display();
}

void Display::joystickCalibrationStep3Screen()
{
    prepareForPrint();

    display.print(F(
        "Config saved!!\n"
        "=====================\n"
    ));

    display.display();
}

void Display::bodyConfigStep1Screen()
{
    prepareForPrint();

    display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Dome tilt offset\n"
        "and pitch offset\n"
        "saved to eeprom\n"
        "\n"
        "Press 'Ok"
    ));

    display.display();
}

void Display::bodyConfigStep2Screen()
{
    prepareForPrint();

    display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Adjust Side to Side\n"
        "until BB-8\n"
        "is straight.\n"
        "\n"
        "Then press 'Ok"
    ));

    display.display();
}

void Display::bodyConfigStep3Screen()
{
    prepareForPrint();

    display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Body Calibration\n"
        "Complete!\n"
        "\n"
        "Press 'Ok"
    ));

    display.display();
}