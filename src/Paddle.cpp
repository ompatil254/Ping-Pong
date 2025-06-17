//
// Created by Om Patil on 17/06/25.
//
#include "Paddle.h"
#include "raylib.h"
#include "algorithm"

Paddle::Paddle(int x, int y, int width, int height, int speed) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
    midY = height / 2;
}

void Paddle::Draw() const {
    DrawRectangleRounded(Rectangle{static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height)}, 0.8, 0, WHITE);
}

void Paddle::Update() {
    if (IsKeyDown(KEY_UP)) y = std::max(y-speed, 10);
    if (IsKeyDown(KEY_DOWN)) y = std::min(y + speed, GetScreenHeight()-height - 10);
}
