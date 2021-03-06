#ifndef PLAYER_H_
#define PLAYER_H_

#include "Point2.h"
#include "Vector2.h"

class Player
{
    public:
        Player() : position(Point2<float>(0,0)), velocity(Vector2<float>(0,0)), frontDirection(DEFAULT_FRONT_DIRECTION){};

        void setPosition(const Point2<float>&);
        void setVelocity(const Vector2<float>&);
        void setFrontDirection(const Vector2<float>&);
        
        Point2<float> getPosition() const;
        Vector2<float> getVelocity() const;
        Vector2<float> getFrontDirection() const;

    private:
        static const Vector2<float> DEFAULT_FRONT_DIRECTION;

        Point2<float> position;
        Vector2<float> velocity;
        Vector2<float> frontDirection;
};

#endif /* PLAYER_H_ */
