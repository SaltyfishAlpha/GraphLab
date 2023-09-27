//
// Created by 19144 on 2023/9/27.
//

#include "Ball2D.h"

Ball2D::Ball2D(glm::vec2 pos, glm::vec3 col = glm::vec3(1.f), float r = 10) : cur_pos(pos), last_pos(pos), color(col), radius(r){}

void Ball2D::updatepos(float delta_t) {
    glm::vec2 tmp = cur_pos;
    cur_pos = (cur_pos * 2.0f) - last_pos + (force * delta_t);
    last_pos = tmp;
}