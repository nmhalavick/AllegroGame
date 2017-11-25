/* 
 * File:   bomb_sprite.h
 * Author: nmh4553
 *
 * Created on May 3, 2017, 9:56 AM
 */

#ifndef BOMB_SPRITE_H
#define BOMB_SPRITE_H
#include "phys_sprite.h"

namespace csis3700{
    class bomb_sprite: public phys_sprite  {
    public:
        bomb_sprite(float initial_x, float initial_y);
        virtual void advance_by_time(double dt);
        virtual bool is_passive() const;
        virtual void resolve(const collision& collision, sprite* other);
        virtual bool is_coin() const {return false;}
        virtual bool is_deadly() const {return true;}
        virtual bool is_platform() const {return false;}
    private:
        vec2d initialpos;

    };
}

#endif /* BOMB_SPRITE_H */

