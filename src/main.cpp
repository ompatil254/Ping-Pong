#include <algorithm>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"

constexpr Color Green = {38, 185, 154, 255};
constexpr Color Yellow = {243, 213, 91, 255};
constexpr Color DGreen = {20, 160, 133, 255};
constexpr Color LGreen = {129, 204, 184, 255};

void collisionCheck(Ball& ball, int& computerScore, int& playerScore, Paddle& player1, Paddle& player2, int& limitX1, int& limitX2) {
    if (CheckCollisionCircleRec(Vector2{static_cast<float>(ball.x), static_cast<float>(ball.y)}, 20, Rectangle{static_cast<float>(player1.x), static_cast<float>(player1.y), static_cast<float>(player1.width), static_cast<float>(player1.height)})) {
        ball.speedX = -ball.speedX;
        ball.x = std::max(ball.x, 35);
    }

    if (CheckCollisionCircleRec(Vector2{static_cast<float>(ball.x), static_cast<float>(ball.y)}, 20, Rectangle{static_cast<float>(player2.x), static_cast<float>(player2.y), static_cast<float>(player2.width), static_cast<float>(player2.height)})) {
        ball.speedX = -ball.speedX;
        ball.x = std::min(ball.x, GetScreenWidth()-35);
    }

    if (ball.x <= limitX1) {
        computerScore++;
        ball.Reset();
    }
    if (ball.x >= limitX2) {
        playerScore++;
        ball.Reset();
    }
}


int main() {
    // Initialize window
    constexpr int screenWidth = 1280, screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Ping Pong!");

    // Set target FPS
    SetTargetFPS(60);



    Ball ball(screenWidth/2, screenHeight/2, 8, 8, Yellow);
    Paddle player1(10, screenHeight/2, 25, 120, 6);
    CpuPaddle player2(screenWidth-35, screenHeight/2, 25, 120, 6);

    int limitX1 = 28;
    int limitX2 = screenWidth-28;

    int playerScore = 0, computerScore = 0;

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DGreen);
        DrawRectangle(screenWidth/2, 0, screenWidth/2, screenHeight, Green);
        DrawCircle(screenWidth/2, screenHeight/2, 150, LGreen);
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
        ball.Draw();
        ball.Update();
        player1.Draw();
        player2.Draw();
        player1.Update();
        player2.Update(ball.y);
        collisionCheck(ball, computerScore, playerScore, player1, player2, limitX1, limitX2);
        DrawText(TextFormat("%i : %i", playerScore, computerScore), screenWidth/2-85, 20, 80, WHITE);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
