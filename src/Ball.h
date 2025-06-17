//
// Created by Om Patil on 17/06/25.
//

#ifndef BALL_H
#define BALL_H
#include "raylib.h"

class Ball {
    public:
    int x, y;
    int speedX, speedY;
    Color color{};

    Ball(int x, int y, int speedX, int speedY, Color color);

    void Draw() const;
    void Update();
    void Reset();
};



#endif //BALL_H
