#ifndef __CDS_PLAYER_SPRITE_H
#define __CDS_PLAYER_SPRITE_H
#include "phys_sprite.h"
#include "vec2d.h"

namespace csis3700 {
  class player_sprite : public phys_sprite {
  public:
    player_sprite(float initial_x=0, float initial_y=0);
    virtual bool is_passive() const;
    virtual void set_on_ground(bool v);
    virtual void advance_by_time(double dt);
    virtual bool is_jumping() { return jumping; }
    virtual bool is_right() { return right; }
    virtual void resolve(const collision& collision, sprite* other);
    virtual float get_forwardX() { return forwardX; }
    virtual float get_forwardY() { return forwardY; }
    virtual void still_right();
    virtual void still_left();
    virtual bool is_coin() const { return false; }
    virtual bool is_deadly() const { return false; }
    virtual bool is_platform() const { return false; }
    virtual void jump_right();
    virtual void jump_left();
    int get_score() { return score; }
    void set_score(int i) { score = i; }
    virtual void set_jumping(bool jumping) { this->jumping = jumping; }
    virtual void set_forwardX(float forwardX) { this->forwardX = forwardX; }
    virtual void set_forwardY(float forwardY) { this->forwardY = forwardY; }

  private:
    bool on_ground;
    bool platform;
    bool falling;
    int score;
    bool jumping;
    image_sequence *walk_right;
    image_sequence *walk_left;
    bool right;
    float forwardX;
    float forwardY;
  };
}


#endif /* PLAYER_SPRITE_H */









