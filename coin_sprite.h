/* 
 * File:   coin_sprite.h
 * Author: nmh4553
 *
 * Created on April 29, 2017, 9:29 AM
 */

#ifndef COIN_SPRITE_H
#define COIN_SPRITE_H
#include "phys_sprite.h"

namespace csis3700{
    class coin_sprite: public phys_sprite {
    public:
        coin_sprite(float initial_x, float initial_y);
        virtual void advance_by_time(double dt);
        virtual void resolve(const collision& collision, sprite* other);
        virtual bool is_coin() const {return true;}
        virtual bool is_deadly() const {return false;}
        virtual bool is_platform() const {return false;}
    private:

    };
}

#endif /* COIN_SPRITE_H */

