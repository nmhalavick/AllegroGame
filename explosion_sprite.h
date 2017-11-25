/* 
 * File:   explosion_sprite.h
 * Author: nmh4553
 *
 * Created on April 28, 2017, 4:55 PM
 */

#ifndef EXPLOSION_SPRITE_H
#define EXPLOSION_SPRITE_H
#include "phys_sprite.h"

namespace csis3700{
    class explosion_sprite: public phys_sprite {
    public:
        explosion_sprite(float initial_x, float initial_y);
        virtual void advance_by_time(double dt);
        virtual void resolve(const collision& collision, sprite* other);
        virtual bool is_coin() const {return false;}
        virtual bool is_deadly() const;
        virtual bool is_platform() const {return false;}
    private:
        image_sequence *fire=new image_sequence;

    };
}

#endif /* EXPLOSION_SPRITE_H */

