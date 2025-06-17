//
// Created by Om Patil on 17/06/25.
//

#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
    public:
    int x, y;
    int width, height, midY;
    int speed;

    Paddle(int x, int y, int width, int height, int speed);

    void Draw() const;
    void Update();
};



#endif //PADDLE_H
