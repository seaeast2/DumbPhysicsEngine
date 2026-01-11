
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
        
public:
    
};
