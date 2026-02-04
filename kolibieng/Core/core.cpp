#include <iostream>
#include <string>
#include "../Modules/Renderer/framerenderer.hpp"
#include "../Modules/Physics/gravity.hpp"
#include <chrono>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

class Monolith {
private:
    bool isrunning; 
    bool initialized;
    string inputa;
    FrameRenderer renderer;
    Gravity gravity;

    bool WaitingForInput = false ;

    float posY = 100.0f;
    float velocityY = 0.0f;
    float posX = 0.0f;
    float velocityX = 0.0f;
    
    bool kbhit() {
    termios term;
    tcgetattr(0, &term);
    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    tcsetattr(0, TCSANOW, &term);
    return byteswaiting > 0;
}


    void init(){
        cout << "system initializing..." << endl;
    
    }
    void processinput(){
        if(!WaitingForInput){
        cout << "Enter command: " << flush;
        WaitingForInput = true;
     }
        if(kbhit()){
        getline(cin, inputa);

        WaitingForInput = false;

        if(inputa == "exit" || inputa == "ext"){
            isrunning = false;
            cout << "shutting down..." << endl;
        }
        else if(inputa == "core --version" || inputa == "core --v"){
            cout << "0.0.0.1" << endl;
            
        }
        else if(inputa == "help"){
            cout << "available commands: help, exit, ext, status, core --version / core --v" << endl;

        }
        else if(inputa == "status"){
            cout << "--- Kolibri Status ---" << endl;
            cout << "--- Position Y: " << posY << endl;
            cout << "--- Velocity Y: " << velocityY << endl;
            cout << "--- Position X: " << posX << endl;
            cout << "--- Velocity X: " << velocityX << endl;
            cout << "---------------------------------" << endl;

        }
        else{
            cout << "unknown command" << endl;
        }
        
     }
    }
        
public:
       void run(){
        isrunning = true;
        initialized = false;
        
        auto LastTime = chrono::high_resolution_clock::now();

        while(isrunning){
            if(!initialized){
                init();
                initialized = true;
            }
        auto CurrentTime = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = CurrentTime - LastTime;
        double dt = elapsed.count();
        LastTime = CurrentTime;
        
        if(dt >0.1){
            dt = 0.1;
        }
        
        //Рендер

        renderer.FrameRender(dt);
        
        //Гравітація
        
        gravity.apply(velocityY, dt);

        posY += velocityY * (float)dt;
        velocityX *= (1.0f - gravity.friction *(float)dt);
        posX += velocityX * (float)dt;
        
        if (posY < 0.0f){
            posY = 0.0f;
            velocityY = 0.0f;
        }

        processinput();
        if(isrunning){
          
        }
         
        }
       }
  
};

int main(){

   Monolith core;
   core.run();
   return 0;
}
