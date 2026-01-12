#pragma once

#include <glm/glm.hpp>

/**
* 입자는 물리 시스템에서 시뮬레이션하는 가장 단순한 개체이다.
*/
class Particle
{
protected:
    // 월드 공간에서 입자의 위치를 나타낸다.
    glm::vec3 position;

    // 입자의 속도를 나타낸다.
    glm::vec3 velocity;

    // 입자의 가속도를 나타낸다. 중력 가속도나 그 밖의 가속도를 계산하는데 사용
    glm::vec3 acceleration;

    // 직선운동에 대한 댐핑의 정도를 저장한다.
    // 적분기에서 수치 연산 오차로 인해 증가한 에너지를 줄여주는 역할을 한다.
    glm::float32 damping; // 속도 감쇠 계수
        
public:
    Particle();
    virtual ~Particle();
};
