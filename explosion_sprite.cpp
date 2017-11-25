/* 
 * File:   explosion_sprite.cpp
 * Author: nmh4553
 * 
 * Created on April 28, 2017, 4:55 PM
 */

#include "explosion_sprite.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>

using namespace std;


namespace csis3700{
    explosion_sprite::explosion_sprite(float initial_x, float initial_y) :
        phys_sprite(initial_x, initial_y){
        image_library *repo = image_library::get();
        int imagewidth=300;
        int imageheight=230;
        int space=20;
        
        ALLEGRO_BITMAP *parent = repo->get("explosion.png");
        
        ALLEGRO_BITMAP *image2=al_create_sub_bitmap(parent, 0, 0, 10, 10);
        fire->add_image(image2, 0);
        
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,0,imagewidth,imageheight);
            if(i>0)
                fire->add_image(image, 0.05);
            else 
                fire->add_image(image, 4);
        }
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,imageheight,imagewidth,imageheight);
            fire->add_image(image, 0.05);
        }
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,2*imageheight,imagewidth,imageheight);
            fire->add_image(image, 0.05);
        }
        
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,3*imageheight,imagewidth,imageheight);
            fire->add_image(image, 0.05);
        }
        
        for(int i=0; i<5; i++){
            ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,4*imageheight,imagewidth,imageheight);
            fire->add_image(image, 0.05);
        }
        ALLEGRO_BITMAP *image1=al_create_sub_bitmap(parent, 0, 0, 10, 10);
        fire->add_image(image1, .05);
        
        set_image_sequence(fire);
        
        
    }
    
    bool explosion_sprite:: is_deadly() const {
        if(fire->get_loop_index()>-1 && fire->get_loop_index()<21){
            return true;
        }
        else{
            return false;
        }
            
    }
    
    void explosion_sprite::advance_by_time(double dt) {
        phys_sprite::advance_by_time(dt);
     }
     
     void explosion_sprite::resolve(const collision& collision, sprite* other){
         
     }
}


