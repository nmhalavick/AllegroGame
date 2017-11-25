/* 
 * File:   bomb_enemy.h
 * Author: nmh4553
 *
 * Created on April 28, 2017, 1:19 PM
 */

#ifndef BOMB_ENEMY_H
#define BOMB_ENEMY_H
#include "phys_sprite.h"


namespace csis3700{
    class bomb_enemy : public phys_sprite {
    public:
        bomb_enemy(float initial_x, float initial_y);
        virtual void advance_by_time(double dt);
        virtual void resolve(const collision& collision, sprite* other);
        virtual bool is_coin() const {return false;}
        virtual bool is_deadly() const {return true;}
        virtual bool is_platform() const {return false;}
    private:

};
}

#endif /* BOMB_ENEMY_H */

