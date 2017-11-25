/* 
 * File:   coin_sprite.cpp
 * Author: nmh4553
 * 
 * Created on April 29, 2017, 9:29 AM
 */

#include "bomb_sprite.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>

using namespace std;

namespace csis3700{
    
    bomb_sprite::bomb_sprite(float initial_x, float initial_y) :
        phys_sprite(initial_x, initial_y) {
        vec2d init(initial_x, initial_y);
        initialpos=init;
        image_sequence *rotate=new image_sequence;
        image_library *repo = image_library::get();
        int imagewidth=25;
        int imageheight=30;
        int space=0;
        
        ALLEGRO_BITMAP *parent = repo->get("bomb.png");
        ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,0, 0,imagewidth,imageheight);
        rotate->add_image(image, 0);
        
        set_image_sequence(rotate);
    }
    
    void bomb_sprite::advance_by_time(double dt) {
        phys_sprite::advance_by_time(dt);
        vec2d move(2.5,1.5);
        position+=move;
        
     }
    
    bool bomb_sprite::is_passive() const {
    return false;
  }
     
     void bomb_sprite::resolve(const collision& collision, sprite* other){
         if(!collides_with(*other))
            return;
         
         if(other->is_platform()){
             position=initialpos;
         }
         
        
         
         
     }

}