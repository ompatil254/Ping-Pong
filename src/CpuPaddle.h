//
// Created by Om Patil on 17/06/25.
//

#ifndef CPUPADDLE_H
#define CPUPADDLE_H

#include "Paddle.h"


class CpuPaddle : public Paddle{
    public:
    using Paddle::Paddle;

    void Update(int ballY);
};



#endif //CPUPADDLE_H
