#pragma once

class Gravity{
    public:
    float gravity = -9.91f;
    float friction = 0.5f;
    
    void apply(float& velocity, double dt){
        velocity += gravity * float(dt);
        velocity *= (1.0f - friction * float(dt));
    }
};