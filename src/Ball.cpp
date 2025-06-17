//
// Created by Om Patil on 17/06/25.
//
#include "Ball.h"


Ball::Ball(int x, int y, int speedX, int speedY, Color color) {
    this->x = x;
    this->y = y;
    this->speedX = speedX;
    this->speedY = speedY;
    this->color = color;
}

void Ball::Draw() const {
    DrawCircle(x, y, 20, color);
}

void Ball::Update() {
    x += speedX;
    y += speedY;
    if (y + 20 >= GetScreenHeight() || y - 20 <= 0) speedY = -speedY;
    if (x + 20 >= GetScreenWidth() || x - 20 <= 0) speedX = -speedX;
}

void Ball::Reset() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    int arr[2] = {-1, 1};
    speedX *= arr[GetRandomValue(0, 1)];
    speedY *= arr[GetRandomValue(0, 1)];
}

