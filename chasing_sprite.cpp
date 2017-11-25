/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chasing_sprite.cpp
 * Author: nmh4553
 * 
 * Created on April 29, 2017, 7:20 PM
 */

#include "chasing_sprite.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>

namespace csis3700{
    chasing_sprite::chasing_sprite(float initial_x, float initial_y) :
    phys_sprite(initial_x, initial_y){
        image_sequence *flying=new image_sequence;
        image_library *repo = image_library::get();
        int imagewidth=195;
        int imageheight=135;
        int space=5;
        
        ALLEGRO_BITMAP *parent = repo->get("chasing.png");
        for(int i=0; i<4; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,0,imagewidth,imageheight);
            if(i>0)
                flying->add_image(image, 0.05);
            else 
                flying->add_image(image, 0);
        }
        
         for(int i=0; i<4; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,imageheight,imagewidth,imageheight);
            flying->add_image(image, 0.05);
        }
        
        set_image_sequence(flying);

        vec2d up(0, -2);

        set_velocity(up);
        
        
}

     void chasing_sprite::advance_by_time(double dt) {
        phys_sprite::advance_by_time(dt);

        if(position.get_y()<10){
            vec2d up(0, 2);
            set_velocity(up);
        }
        else if(position.get_y()>375){
            vec2d down(0,-2);
            set_velocity(down);
        }
        position=position+get_velocity();
            

     }
     
     void chasing_sprite::resolve(const collision& collision, sprite* other){
         if(!collides_with(*other))
            return;
         
         
     }
    
}


