#include <iostream>
#include "framerenderer.hpp"
using namespace std;

    void FrameRenderer::FrameRender(double DeltaTime) {
        static double timer = 0;
        counter++;
        timer += DeltaTime;

        if (timer >= 1.0) {   // кожні 100 кадрів
            cout << "fps: " << counter << " | FrameTime: " << DeltaTime * 1000 << "ms" << endl;
            counter = 0;
            timer = 0;
        }
    }


