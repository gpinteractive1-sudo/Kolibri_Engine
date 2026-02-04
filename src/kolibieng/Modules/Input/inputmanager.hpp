#pragma once
#include <string>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

class InputManager{
    private:
    bool IsKeyPressed();
    std::string getCommand();
    bool IsDown (char key);

}