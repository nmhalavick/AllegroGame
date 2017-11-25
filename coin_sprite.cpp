/* 
 * File:   coin_sprite.cpp
 * Author: nmh4553
 * 
 * Created on April 29, 2017, 9:29 AM
 */

#include "coin_sprite.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>

using namespace std;

namespace csis3700{
    
    coin_sprite::coin_sprite(float initial_x, float initial_y) :
        phys_sprite(initial_x, initial_y) {
        image_sequence *rotate=new image_sequence;
        image_library *repo = image_library::get();
        int imagewidth=25;
        int imageheight=25;
        int space=0;
        
        ALLEGRO_BITMAP *parent = repo->get("coins.png");
        for(int i=0; i<10; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,0,imagewidth,imageheight);
            if(i>0)
                rotate->add_image(image, 0.1);
            else 
                rotate->add_image(image, 0);
        }
        
        set_image_sequence(rotate);
    }
    
    void coin_sprite::advance_by_time(double dt) {
        phys_sprite::advance_by_time(dt);
     }
     
     void coin_sprite::resolve(const collision& collision, sprite* other){
         if(!collides_with(*other))
            return;
         
         
     }

}


