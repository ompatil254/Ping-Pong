//
// Created by Om Patil on 17/06/25.
//

#include "CpuPaddle.h"
#include "raylib.h"
#include <algorithm>

void CpuPaddle::Update(int ballY) {
    if (y + midY > ballY) y = std::max(y-speed, 10);
    else y = std::min(y + speed, GetScreenHeight()-height - 10);
}
