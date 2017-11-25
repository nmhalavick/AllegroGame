/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chasing_sprite.h
 * Author: nmh4553
 *
 * Created on April 29, 2017, 7:20 PM
 */

#ifndef CHASING_SPRITE_H
#define CHASING_SPRITE_H
#include "phys_sprite.h"


namespace csis3700{
class chasing_sprite : public phys_sprite {
    public:
        chasing_sprite(float initial_x, float initial_y);
        virtual void advance_by_time(double dt);
        virtual void resolve(const collision& collision, sprite* other);
        virtual bool is_coin() const {return false;}
        virtual bool is_deadly() const {return true;}
        virtual bool is_platform() const {return false;}
    private:

    };
}

#endif /* CHASING_SPRITE_H */

