//
// Created by 19144 on 2023/9/27.
//

#ifndef GRAPHLAB_BALL2D_H
#define GRAPHLAB_BALL2D_H

#include "glm/glm.hpp"

class Ball2D {
    glm::vec2 last_pos, cur_pos;
    glm::vec2 force;

    glm::vec3 color;

    float radius;

    // init
    Ball2D(glm::vec2 pos, glm::vec3 col, float r);

    // physical
    void updatepos(float delta_t);
};


#endif //GRAPHLAB_BALL2D_H
