/* 
 * File:   bomb_enemy.cpp
 * Author: nmh4553
 * 
 * Created on April 28, 2017, 1:19 PM
 */

#include "bomb_enemy.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>

using namespace std;

namespace csis3700{

    bomb_enemy::bomb_enemy(float initial_x, float initial_y) :
    phys_sprite(initial_x, initial_y){
        image_sequence *flying=new image_sequence;
        image_library *repo = image_library::get();
        int imagewidth=90;
        int imageheight=90;
        int space=20;
        
        
        ALLEGRO_BITMAP *parent = repo->get("flying.png");
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,15+i*imagewidth+i*space,0,imagewidth,imageheight);
            if(i>0)
                flying->add_image(image, 0.05);
            else 
                flying->add_image(image, 0);
        }
        
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,16+i*imagewidth+i*space,115,imagewidth,imageheight);
            flying->add_image(image, 0.05);
        }
        for(int i=0; i<4; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,16+i*imagewidth+i*space,216,imagewidth,imageheight);
            flying->add_image(image, 0.05);
        }
        
        set_image_sequence(flying);
        
    }
    
     void bomb_enemy::advance_by_time(double dt) {
        phys_sprite::advance_by_time(dt);
     }
     
     void bomb_enemy::resolve(const collision& collision, sprite* other){
         if(!collides_with(*other))
            return;
         
         
         
     }


}

