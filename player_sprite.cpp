#include "player_sprite.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "keyboard_manager.h"
#include "coin_sprite.h"
#include "collision.h"
#include <cmath>
using namespace std;

namespace csis3700 {

  player_sprite::player_sprite(float initial_x, float initial_y) :
    phys_sprite(initial_x, initial_y) {
        on_ground = true;
        jumping = false;
        platform = false;
        right = true;
        falling = false;
        time = 0;
        forwardX = 0;
        forwardY = 0;
        score=0;

        int imagewidth=63;
        int imageheight = 90;
        int space=3;

        image_library *repo = image_library::get();
        ALLEGRO_BITMAP *parent = repo->get("spritesheet.png");
        image_sequence *initial_seq = new image_sequence;
        ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,540,28,imagewidth,imageheight);
        initial_seq->add_image(image,0);
        set_image_sequence(initial_seq);

        walk_right = new image_sequence;

        for(int i=0; i<12; i++){
          ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,28,imagewidth,imageheight);
          walk_right->add_image(image,0.05);
        }
        for(int i=0; i<12; i++){
          ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,54+imageheight,imagewidth,imageheight);
          walk_right->add_image(image,0.05);
        }
          ALLEGRO_BITMAP *image1 =al_create_sub_bitmap(parent,0,82+2*imageheight,imagewidth,imageheight);
          ALLEGRO_BITMAP *image2 =al_create_sub_bitmap(parent,imagewidth+space,82+2*imageheight,imagewidth,imageheight);
          walk_right->add_image(image1,0.05);
          walk_right->add_image(image2,0.05);

          ALLEGRO_BITMAP *parent2 = repo->get("spritesheet_left.png");
          walk_left = new image_sequence;
        for(int i=1; i<13; i++){
          ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent2,819-(i*imagewidth)-((i-1)*space),28,imagewidth,imageheight);
          walk_left->add_image(image,0.05);
        }
        for(int i=1; i<13; i++){
          ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent2,819-(i*imagewidth)-((i-1)*space),54+imageheight,imagewidth,imageheight);
          walk_left->add_image(image,0.05);
        }
          ALLEGRO_BITMAP *image3 =al_create_sub_bitmap(parent2,819-imagewidth,141,imagewidth,imageheight);
          ALLEGRO_BITMAP *image4 =al_create_sub_bitmap(parent2,819-imagewidth*2-space,141,imagewidth,imageheight);
          walk_left->add_image(image3,0.05);
          walk_left->add_image(image4,0.05);

  }

  bool player_sprite::is_passive() const {
    return false;
  }

  void player_sprite::still_right(){
        image_library *repo = image_library::get();
        ALLEGRO_BITMAP *parent = repo->get("spritesheet.png");
        image_sequence *initial_seq = new image_sequence;
        ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,540,28,63,90);
        initial_seq->add_image(image,0);
        set_image_sequence(initial_seq);
        set_velocity(vec2d(0,0));
        on_ground = true;
  }

  void player_sprite::still_left(){
        image_library *repo = image_library::get();
        ALLEGRO_BITMAP *parent = repo->get("spritesheet_left.png");
        image_sequence *initial_seq = new image_sequence;
        ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,233,28,63,90);
        initial_seq->add_image(image,0);
        set_image_sequence(initial_seq);
        set_velocity(vec2d(0,0));
        on_ground = true;
  }

  void player_sprite::jump_left(){
            image_sequence *jump = new image_sequence;
            image_library *repo = image_library::get();
            int imagewidth = 63;
            int imageheight = 90;
            int space = 3;

            ALLEGRO_BITMAP *parent = repo->get("spritesheet_left.png");

            for(int i=3;i<13;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),258,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=1;i<3;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),358,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=3;i<5;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),361,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=5;i<7;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),357,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=7;i<9;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),352,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=9;i<13;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),353,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=1;i<3;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),473,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=3;i<5;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),477,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=5;i<7;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),486 ,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=7;i<9;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),497,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=9;i<13;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),501,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=1;i<5;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,819-(i*imagewidth)-((i-1)*space),614,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }

            set_image_sequence(jump);
  }

  void player_sprite::jump_right(){
            image_sequence *jump = new image_sequence;
            image_library *repo = image_library::get();
            int imagewidth = 63;
            int imageheight = 90;
            int space = 3;

            ALLEGRO_BITMAP *parent = repo->get("spritesheet.png");

            for(int i=2;i<12;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,258,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=0;i<2;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,358,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=2;i<4;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,361,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=4;i<6;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,357,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=6;i<8;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,352,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=8;i<12;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,353,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=0;i<2;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,473,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=2;i<4;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,477,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=4;i<6;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,486,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=6;i<8;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,497,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=8;i<12;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,501,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            for(int i=0;i<4;i++){
                ALLEGRO_BITMAP *image =al_create_sub_bitmap(parent,i*imagewidth+i*space,614,imagewidth,imageheight);
                jump->add_image(image, 0.05);
            }
            set_image_sequence(jump);
  }

  void player_sprite::set_on_ground(bool v) {
    on_ground = v;
    //set_velocity(vec2d(0,0));
  }

  void player_sprite::advance_by_time(double dt) {
    phys_sprite::advance_by_time(dt);
    //vec2d forward (get_forwardX(),get_forwardY());
    //position+=(forward);
    int jump_height = 200;
    int current_y;

    if(keyboard_manager::get()->is_key_down(ALLEGRO_KEY_RIGHT)&&keyboard_manager::get()->is_key_down(ALLEGRO_KEY_SPACE)&&on_ground ){
        jumping = true;
        jump_right();
        set_velocity(vec2d(200,get_velocity().get_y()));
        set_velocity(vec2d(get_velocity().get_x(),-300));
        set_on_ground(false);
    }
    else if(keyboard_manager::get()->is_key_down(ALLEGRO_KEY_LEFT)&&keyboard_manager::get()->is_key_down(ALLEGRO_KEY_SPACE)&&on_ground ){
        jumping = true;
        jump_left();
        set_velocity(vec2d(-200,get_velocity().get_y()));
        set_velocity(vec2d(get_velocity().get_x(),-300));
        set_on_ground(false);
    }
    else if(keyboard_manager::get()->is_key_down(ALLEGRO_KEY_SPACE) && on_ground ){
        if(right){
            jumping = true;
            jump_right();
            set_velocity(vec2d(get_velocity().get_x(),-300));
        }
        else if(!right){
            jumping = true;
            jump_left();
            set_velocity(vec2d(get_velocity().get_x(),-300));
        }
        set_on_ground(false);
    }
    else if(keyboard_manager::get()->is_key_down(ALLEGRO_KEY_RIGHT)&&on_ground){
      if(platform){
        if(position.get_x()>350){
            right = true;
            set_image_sequence(walk_right);
            set_velocity(vec2d(175,get_velocity().get_y()));
        }
        else
            platform=false;
            on_ground=false;
            set_velocity(vec2d(100,300));
      }
      else{
        right = true;
        set_image_sequence(walk_right);
        set_velocity(vec2d(150,get_velocity().get_y()));
      }
    }
    else if(keyboard_manager::get()->is_key_down(ALLEGRO_KEY_LEFT)&&on_ground ){
      if(platform){
        if(position.get_x()>350){
            right = false;
            set_image_sequence(walk_left);
            set_velocity(vec2d(-175,get_velocity().get_y()));
        }
        else
            platform = false;
            on_ground = false;
            set_velocity(vec2d(-100,300));
      }
    else{
      right = false;
      set_image_sequence(walk_left);
      set_velocity(vec2d(-150,get_velocity().get_y()));
    }
    }
    else if(!keyboard_manager::get()->is_key_down(ALLEGRO_KEY_SPACE)&&!keyboard_manager::get()->is_key_down(ALLEGRO_KEY_LEFT)&& on_ground  && !right){
        still_left();
    }
    else if(!keyboard_manager::get()->is_key_down(ALLEGRO_KEY_SPACE)&&!keyboard_manager::get()->is_key_down(ALLEGRO_KEY_RIGHT)&& on_ground && right){
        still_right();
    }
    /*else if(position.get_y()<400&&(position.get_x()>0&&position.get_x()<410)){
        on_ground=false;
    }*/
    else if(!on_ground){
        if(!platform){
        if(position.get_y()<=200){
            set_velocity(vec2d(get_velocity().get_x(),300));
            falling = true;
            platform = false;
        }
        else if(position.get_y()>400){
            if(!right){
                set_on_ground(true);
                falling = false;
                platform = false;
                current_y = get_position().get_y();
                jumping = false;
                still_left();
            }
            else{
                set_on_ground(true);
                falling = false;
                platform = false;
                current_y = get_position().get_y();
                jumping = false;
                still_right();
            }
        }
        }
        else if(platform){
            if(position.get_y()<=50){
                set_velocity(vec2d(get_velocity().get_x(),300));
                falling = true;
            }
            else if(position.get_y()>400){
            if(!right){
                set_on_ground(true);
                platform = false;
                falling = false;
                current_y = get_position().get_y();
                jumping = false;
                still_left();
            }
            else{
                set_on_ground(true);
                platform = false;
                falling = false;
                current_y = get_position().get_y();
                jumping = false;
                still_right();
            }
            }
        }
    }
    else if(on_ground){
        jumping = false;
        if(!right){
            still_left();
            platform = false;
            falling = false;
        }
        else{
            still_right();
            platform = false;
            falling = false;
        }
    }
    else{
        set_on_ground(false);
        platform = false;
    }
  }
  void player_sprite::resolve(const collision& collision, sprite *other) {
    if(!collides_with(*other))
        return;
    else if(other->is_platform()){
    if(collision_rectangle(*other).get_height() < collision_rectangle(*other).get_width() && bounding_box().lower_right_corner().get_y() > other -> get_position().get_y()&&falling){
        set_on_ground(true);
        platform=true;
        set_velocity(vec2d(get_velocity().get_x(),0));
        set_position(vec2d(get_position().get_x(), other->get_position().get_y() - (bounding_box().get_height()+1)));
    }
    else if(collision_rectangle(*other).get_height() > collision_rectangle(*other).get_width() && bounding_box().upper_left_corner().get_y() < other -> get_position().get_y()){
        platform = false;
        set_on_ground(false);
        falling = true;
        set_velocity(vec2d(0,325));
    }
    }
    else if(other->is_coin()){
        vec2d pos(-5000,-2500);
        other->set_position(pos);
        score++;
    }
    
    else if(other->is_deadly()){
        score=7;
    }
  }

}






