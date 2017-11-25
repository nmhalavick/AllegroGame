#include "world.h"
#include <cassert>
#include <algorithm>
#include "sprite.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "player_sprite.h"
#include "obstruction_sprite.h"
#include "collision.h"
#include "image_library.h"
#include "bomb_enemy.h"
#include "coin_sprite.h"
#include "explosion_sprite.h"
#include "chasing_sprite.h"
#include "keyboard_manager.h"
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include "bomb_sprite.h"



using namespace std;

namespace csis3700 {

  const float gravity_acceleration = 600;

  void free_sprite(sprite* s) {
    delete s;
  }

  world::world(int number) {
      level1=0;
      count=number;
      over=false;
      
      if(count==0){
          
          for(int i=0; i<50; i++){
            bomb_sprite *bomb = new bomb_sprite(225+i*1404,125);
            sprites.push_back(bomb);
            bomb_enemy *bomber =new bomb_enemy(200+i*1404,100);
            sprites.push_back(bomber);
            coin_sprite *coin=new coin_sprite(700+i*1404,225);
            sprites.push_back(coin);
            explosion_sprite *explosion = new explosion_sprite(350+i*1404,120);
            sprites.push_back(explosion);
             platform = new obstruction_sprite(440+i*1404,330,image_library::get()->get("blank.png"));
            sprites.push_back(platform);
            platform2 = new obstruction_sprite(645+i*1404,250,image_library::get()->get("blank.png"));
            sprites.push_back(platform2);
            platform3 = new obstruction_sprite(910+i*1404,190,image_library::get()->get("blank.png"));
            sprites.push_back(platform3);
          }
          
          player= new player_sprite(0,400);
          sprites.push_back(player);
      }
      
      if(count==1){
      for(int i=0; i<50; i++){
        int rand_y2=rand() % 400;
        int rand_x2=rand() % 1300;
        coin_sprite *coin=new coin_sprite(700+i*1404,225);
        sprites.push_back(coin);
        chasing_sprite *chasing = new chasing_sprite(rand_x2+i*1404,rand_y2);
        sprites.push_back(chasing);
        platform = new obstruction_sprite(440+i*1404,330,image_library::get()->get("blank.png"));
            sprites.push_back(platform);
            platform2 = new obstruction_sprite(645+i*1404,250,image_library::get()->get("blank.png"));
            sprites.push_back(platform2);
            platform3 = new obstruction_sprite(910+i*1404,190,image_library::get()->get("blank.png"));
            sprites.push_back(platform3);

      }
      player= new player_sprite(0,400);
      sprites.push_back(player);
      
      }
      
      if(count==2){
          for(int i=0; i<50; i++){
            bomb_sprite *bomb = new bomb_sprite(225+i*1404,125);
            sprites.push_back(bomb);
            bomb_enemy *bomber =new bomb_enemy(200+i*1404,100);
            sprites.push_back(bomber);
            coin_sprite *coin=new coin_sprite(700+i*1404,225);
            sprites.push_back(coin);
            explosion_sprite *explosion = new explosion_sprite(350+i*1404,120);
            sprites.push_back(explosion);
            int rand_y2=rand() % 400;
            int rand_x2=rand() % 1300;
            chasing_sprite *chasing = new chasing_sprite(rand_x2+i*1404,rand_y2);
            sprites.push_back(chasing);
            platform = new obstruction_sprite(440+i*1404,330,image_library::get()->get("blank.png"));
            sprites.push_back(platform);
            platform2 = new obstruction_sprite(645+i*1404,250,image_library::get()->get("blank.png"));
            sprites.push_back(platform2);
            platform3 = new obstruction_sprite(910+i*1404,190,image_library::get()->get("blank.png"));
          }
          player= new player_sprite(0,400);
      sprites.push_back(player);
      }

  }
  
  
  void world::draw() {
      al_init();
    al_init_font_addon();
    ALLEGRO_FONT *level=al_load_font("Arcade.ttf",72,0);
    image_library *repo = image_library::get();
    ALLEGRO_BITMAP *b1 = repo->get("Background.jpg");
    int backgroundwidth=1404;
    int backgroundheight=672;
    
    
    while(level1==0 && count==0){
        al_clear_to_color(al_map_rgb(25,170,255));
        ALLEGRO_BITMAP *b4 = repo->get("Level1.png");
        al_draw_bitmap(b4, player->get_x()+400,200,0);
        al_flip_display();
        al_rest(3.0);
        level1++;
    }
        ALLEGRO_TRANSFORM transform;
        al_identity_transform(&transform);
        al_translate_transform(&transform, -player->get_x()+50, 0);
        al_use_transform(&transform);
        al_draw_scaled_bitmap(b1, 0, 0, 702, 336, (int(player->get_x()/backgroundwidth))*backgroundwidth, 0, backgroundwidth, backgroundheight, 0);
        al_draw_scaled_bitmap(b1, 0, 0, 702, 336, backgroundwidth+(int(player->get_x())/backgroundwidth)*backgroundwidth, 0, backgroundwidth, backgroundheight, 0);
        al_draw_scaled_bitmap(b1, 0, 0, 702, 336, -backgroundwidth+(int(player->get_x()) / backgroundwidth)*backgroundwidth, 0, backgroundwidth, backgroundheight, 0);
        for(vector<sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
            (*it)->draw();
        if(player->get_score()==0){
            ALLEGRO_BITMAP *b5 = repo->get("zero.png");
            al_draw_scaled_bitmap(b5, 0, 0, 340, 200, player->get_x()+600, 0, 95, 50, 0);
        }
        if(player->get_score()==1){
            ALLEGRO_BITMAP *b6 = repo->get("one.png");
            al_draw_scaled_bitmap(b6, 0, 0, 320, 200, player->get_x()+600, 0, 80, 50, 0);
        }
        
        if(player->get_score()==2){
            ALLEGRO_BITMAP *b7 = repo->get("two.png");
            al_draw_scaled_bitmap(b7, 0, 0, 340, 200, player->get_x()+600, 0, 95, 50, 0);
        }
        
        if(player->get_score()==3){
            ALLEGRO_BITMAP *b8 = repo->get("three.png");
            al_draw_scaled_bitmap(b8, 0, 0, 340, 200, player->get_x()+600, 0, 95, 50, 0);
        }
        
        if(player->get_score()==4){
            ALLEGRO_BITMAP *b9 = repo->get("four.png");
            al_draw_scaled_bitmap(b9, 0, 0, 340, 200, player->get_x()+600, 0, 95, 50, 0);
        }


        
        
        
        
        
        
    
    if(player->get_score()==3 && count==0){
        al_clear_to_color(al_map_rgb(25,170,255));
        ALLEGRO_BITMAP *b2 = repo->get("Level2.png");
        al_draw_bitmap(b2, player->get_x()+400,200,0);
        al_flip_display();
        al_rest(3.0);
        player->set_score(6);
        level1++;
    }
        
    if(player->get_score()==3 && count==1){
        al_clear_to_color(al_map_rgb(25,170,255));
        ALLEGRO_BITMAP *b3 = repo->get("win.png");
        al_draw_bitmap(b3, player->get_x()+400,200,0);
        al_flip_display();
        al_rest(3.0);
        player->set_score(6);
        level1++;
    }
        
    if(player->get_score()==7){
        al_clear_to_color(al_map_rgb(25,170,255));
        ALLEGRO_BITMAP *b3 = repo->get("lose.png");
        al_draw_bitmap(b3, player->get_x()+400,200,0);
        al_flip_display();
        al_rest(3.0);   
    }   
    
  }
  
  

  world::world(const world& other) {
    assert(false); // do not copy worlds
  }

  world& world::operator=(const world& other) {
    assert(false); // do not assign worlds
  }

  world::~world() {
    for_each(sprites.begin(), sprites.end(), free_sprite);
    sprites.clear();
  }

  void world::handle_event(ALLEGRO_EVENT ev) {
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
        keyboard_manager::get() -> get() -> key_down(ev.keyboard.keycode);
    }
    if(ev.type == ALLEGRO_EVENT_KEY_UP){
        keyboard_manager::get() -> get() -> key_up(ev.keyboard.keycode);
    }
   
  }

  void world::resolve_collisions() {
       collision player_obstacle(sprites[1], sprites[0]);
    player -> resolve(player_obstacle, sprites[0]);

    for (int i=1;i<sprites.size();i++){
        collision player_obstacle(sprites[1], sprites[i]);
        player -> resolve(player_obstacle, sprites[i]);
    }
    for(vector<sprite*>::iterator it1 = sprites.begin(); it1 != sprites.end(); ++it1){
        for(vector<sprite*>::iterator it2 = sprites.begin(); it2 != sprites.end(); ++it2){
            collision coll (*it1, *it2);
            coll.resolve();
        }
    }
     
    
  }
  
  bool world:: is_over() const{
      return over;
  }

  void world::advance_by_time(double dt) {
    for(vector<sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
      (*it)->advance_by_time(dt);
    resolve_collisions();
  }

  bool world::should_exit() {
      if(player->get_score()==6 || player->get_score()==7){
          if (count==1){
              over=true;
          }
          return true;
      }
      else
        return false;
  }

}



