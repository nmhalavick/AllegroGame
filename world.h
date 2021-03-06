#ifndef __CDS_WORLD_H
#define __CDS_WORLD_H

#include "allegro5/allegro.h"
#include "sprite.h"
#include "player_sprite.h"
#include "obstruction_sprite.h"
#include <vector>

namespace csis3700 {
  class world {
  public:
    /**
     * Construct the world. The display is passed in simply to make it
     * possible to modify options or access the backbuffer. DO NOT
     * store the display in an instance variable. DO NOT start drawing
     * on the screen. Just load bitmaps etc.
     */
    world(int number);

    /**
     * Free any resources being used by the world.
     */
    ~world();

    /**
     * Block the copy constructor.  Worlds should not be copied to
     * just assert(false)
     */
    world(const world& other);

    /**
     * Block operator =.  Worlds should not be assigned.
     */
    world& operator =(const world& other);
 
    /**
     * Update the state of the world based on the event ev.
     */
    void handle_event(ALLEGRO_EVENT ev);

    /**
     * Advance the state of the world forward by the specified time.
     */
    void advance_by_time(double dt);

    /**
     * Draw the world. Note that the display variable is passed only
     * because it might be needed to switch the target bitmap back to
     * the backbuffer.
     */
    void draw();
    
    bool is_over() const;
    

    /**
     * Return true iff game is over and window should close
     */
    bool should_exit();

  private:
    void resolve_collisions();
    player_sprite *player;
    std::vector<sprite*> sprites;
    int count;
    int level1;
    bool over;
    obstruction_sprite *platform;
    obstruction_sprite *platform2;
    obstruction_sprite *platform3;
  };
}

#endif /* WORLD_H */
