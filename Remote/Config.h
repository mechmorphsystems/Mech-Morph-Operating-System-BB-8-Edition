#pragma once

#define DEBUG

// left top Joystick
#define LEFT_TOP_JOYSTICK_X_PIN 34
#define LEFT_TOP_JOYSTICK_Y_PIN 35
#define LEFT_TOP_JOYSTICK_BUTTON_PIN 3

// right top Joystick
#define RIGHT_TOP_JOYSTICK_X_PIN 36
#define RIGHT_TOP_JOYSTICK_Y_PIN 39
#define RIGHT_TOP_JOYSTICK_BUTTON_PIN 1

// left bottom Joystick
#define LEFT_BOTTOM_JOYSTICK_X_PIN 32

// right bottom Joystick
#define RIGHT_BOTTOM_JOYSTICK_X_PIN 33

//left buttons
#define LEFT_LEFT_BUTTON_PIN 19
#define LEFT_UP_BUTTON_PIN 18
#define LEFT_DOWN_BUTTON_PIN 5
#define LEFT_RIGHT_BUTTON_PIN 17

//right buttons
#define RIGHT_LEFT_BUTTON_PIN 16
#define RIGHT_UP_BUTTON_PIN 4
#define RIGHT_DOWN_BUTTON_PIN 0
#define RIGHT_RIGHT_BUTTON_PIN 2

#define MOTOR_ENABLE_PIN 15

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
