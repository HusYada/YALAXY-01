// ================== YALAXY-01 ==================  //
//  ================== HusYada ===================  //

// Butano
#include "bn_bg_palettes.h"
#include "bn_bg_palette_color_hbe_ptr.h"
#include "bn_bg_palettes_transparent_color_hbe_ptr.h"
#include "bn_colors.h"
#include "bn_core.h"
#include "bn_display.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_math.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_palette_actions.h"
#include "bn_sprite_palettes_actions.h"
#include "bn_sstream.h"
#include "bn_optional.h"

// Sprites
#include "bn_sprite_items_gear_head.h"
#include "bn_sprite_items_gear_body.h"
// #include "bn_sprite_items_gear_ammo.h"
#include "bn_sprite_items_gear_fire.h"
#include "bn_sprite_items_gear_arm.h"
#include "bn_sprite_items_gear_saber.h"
#include "bn_sprite_items_gon_p.h"
#include "bn_sprite_items_gon_m.h"
#include "bn_sprite_items_tl_ui.h"
#include "bn_sprite_items_point_ui.h"
#include "bn_sprite_items_title.h"
#include "bn_sprite_items_congrats.h"
#include "bn_sprite_items_notaball.h"

#include "collision.h"

// Palettes
#include "bn_sprite_palette_items_gear_palm.h"
#include "bn_sprite_palette_items_gear_palo.h"
#include "bn_sprite_palette_items_gear_pala.h"
#include "bn_sprite_palette_items_gear_palp.h"

// Player Variables
int plyrx = -40;

// Head Animation
int headturn = 0; int headturntimer = 0; bool headturningl = false; bool headturningr = false;
int headofset = 0; bool headreleft = false; bool headreright = false; int headofset2 = 0; int headofsety = 0;

// Body Animation
bool running = false; int runturn = 0; int runturntimer = 0;

// Fire Animation
bool flaming = false; int fireturn = 0; int fireturntimer = 0; int firey = 37;

// Saber Animation
bool slashing = false; int saberturn = 0; int saberturntimer = 0; int saberx = -11; int sabery = 30; int fcsbrx = 0;

// Arm Stuff
int armturn = 0; int armx = 20; int army = 24; bool facingleft = false;

// P-Gon
bool pgoning = false; int pgonx = 24; int pgonturn = 0; int pgontimer = 0;

// M-Gon
bool mgoning = false; int mgonx = 36; int mgony = -36; int mgonturn = 0; int mgontimer = 0; int mgonseedy = -36; //amazingvariavlenaebtw

// Timers
int timet = 120; int timeb = 120; int scene = 0; int ttimer = 0; int bossx = 120; bool bossmovingright = true;

void the_big_show() {

        // Overlap Function
        colli::sion ocol;

        const bn::sprite_palette_item& gear_palm = bn::sprite_palette_items::gear_palm;
        const bn::sprite_palette_item& gear_palo = bn::sprite_palette_items::gear_palo;
        const bn::sprite_palette_item& gear_pala = bn::sprite_palette_items::gear_pala;
        const bn::sprite_palette_item& gear_palp = bn::sprite_palette_items::gear_palp;
        
        bn::sprite_ptr title = bn::sprite_items::title.create_sprite(-1000, -1000);
        bn::sprite_ptr congrats = bn::sprite_items::congrats.create_sprite(-1000, -1000);
        title.set_scale(1.2, 1.2);
        bn::sprite_ptr gear_fire = bn::sprite_items::gear_fire.create_sprite(plyrx+1,37);
        bn::sprite_ptr gear_body = bn::sprite_items::gear_body.create_sprite(plyrx+1,37);
        bn::sprite_ptr gear_saber = bn::sprite_items::gear_saber.create_sprite(plyrx+1, 37);
        bn::sprite_ptr gear_head = bn::sprite_items::gear_head.create_sprite(plyrx, 0);
        bn::sprite_ptr gear_arm = bn::sprite_items::gear_arm.create_sprite(plyrx, 0);
        bn::sprite_ptr tl_ui = bn::sprite_items::tl_ui.create_sprite(-105, -65);
        bn::sprite_ptr point_uit = bn::sprite_items::point_ui.create_sprite(timet, -72);
        bn::sprite_ptr point_uib = bn::sprite_items::point_ui.create_sprite(timeb, -63);
        bn::sprite_ptr gon_p = bn::sprite_items::gon_p.create_sprite(0, -1000);
        bn::sprite_ptr gon_m = bn::sprite_items::gon_m.create_sprite(0, -1000);
        bn::sprite_ptr gon_mseed = bn::sprite_items::gon_m.create_sprite(0, -1000);
        bn::sprite_ptr boss = bn::sprite_items::notaball.create_sprite(bossx, -1000);
        point_uib.set_tiles(bn::sprite_items::point_ui.tiles_item().create_tiles(1));
        bn::sprite_palette_ptr p_gonpal = gon_p.palette();

        bn::sprite_palette_ptr gear_pal = gear_body.palette();
        gear_pal.set_colors(gear_palm);

        // this is where the ifsanity begins, will clean later
    	while(!bn::keypad::start_pressed()) {

            if(scene == 0) { title.set_position(0, 0); } else { title.set_position(-1000, -1000); }
            if(scene == 2) { congrats.set_position(0, 0); } else { congrats.set_position(-1000, -1000); }
            if(bn::keypad::start_released() && scene == 0) { scene = 1; bossx = 100; bossmovingright = true;}
            if(scene == 1) { ttimer++; boss.set_position(bossx, 0);}
            if(ttimer > 10) {timet--; ttimer = 0;}
            if(scene == 1 && timet < -120) { timeb = 120; timet = 120; scene = 0; boss.set_position(0, -1000);}
            if(bossmovingright) { bossx--; } else { bossx++; }
            if(bossx < -100) { bossmovingright = false; }
            if(bossx > 100) { bossmovingright = true; }
            //Collision
            if(scene == 1 && slashing && !facingleft && ocol.overlap(plyrx,87,64,64, bossx-30, -30, 60, 57) == true) { timeb--; }
            if(scene == 1 && slashing && facingleft && ocol.overlap(plyrx-64,23,64,64, bossx-30, -30, 60, 57) == true) { timeb--; }
            if(scene == 1 && ocol.overlap(pgonx-8, -8, 16, 16, bossx-30, -30, 60, 57) == true) { timeb--; }
            if(scene == 1 && ocol.overlap(mgonx-8, mgonseedy-8, 16, 16, bossx-30, -30, 60, 57) == true) { timeb--; }
            //
            if(scene == 1 && timeb < -100) { boss.set_position(0, -1000); scene = 2; }
            if(scene == 2 && bn::keypad::select_released()) { timeb = 120; timet = 120; scene = 0; }

            if(bn::keypad::left_pressed()) {
                if(!headturningl && !headturningr) { headturningl = true; }
                running = true; gear_body.set_horizontal_flip(true);
                gear_fire.set_horizontal_flip(true);
                gear_saber.set_horizontal_flip(true);
                headofset2 = 2;
                fireturn = 3;
                fireturntimer = 0;
                saberx = 11;
                facingleft = true;
            }
    		if(bn::keypad::left_held()) {
    			plyrx-= 2;
    			if(headofset < 4 && !headreleft && !headreright) { headofset++; }
                running = true;
    		}
    		if(bn::keypad::left_released()) {
    			headreleft = true;
                running = false;
                runturn = 0;
                runturntimer = 0;
                fireturn = 0;
                fireturntimer = 0;
    		}

            if(bn::keypad::right_pressed()) {
                if(!headturningl && !headturningr) { headturningr = true; }
                running = true; gear_body.set_horizontal_flip(false);
                gear_fire.set_horizontal_flip(false);
                gear_saber.set_horizontal_flip(false);
                headofset2 = 0;
                fireturn = 3;
                fireturntimer = 0;
                saberx = -11;
                facingleft = false;
            }
    		if(bn::keypad::right_held()) {
    			plyrx+= 2;
    			if(headofset > -4 && !headreleft && !headreright) { headofset--; }
                running = true;
    		}
    		if(bn::keypad::right_released()) {
    			headreright = true;
                running = false;
                runturn = 0;
                runturntimer = 0;
                fireturn = 0;
                fireturntimer = 0;
    		}
            if(bn::keypad::b_pressed() && !slashing) {
                slashing = true;
            }

            if(headreleft) { if(headofset != 0) { headofset--; } else { headreleft = 0;}}
            if(headreright) { if(headofset != 0) { headofset++; } else { headreright = 0;}}

            if(headturningl) { 
                headturntimer++;
                if(headturntimer > 5 && headturn != 4) { 
                    headturn++;
                    headturntimer = 0;
                }
                if(headturn == 4) {
                    headturntimer = 0;
                    headturningl = false;
                }
            }
            if(headturningr) { 
                headturntimer++;
                if(headturntimer > 5 && headturn != 0) { 
                    headturn--;
                    headturntimer = 0;
                }
                if(headturn == 0) {
                    headturntimer = 0;
                    headturningr = false;
                }
            }

            if(running){
                runturntimer++;
                if(runturn < 5 && runturntimer > 4) { 
                    runturn++;
                    runturntimer = 0;
                }
                if(runturn == 5 && runturntimer > 4) {
                    runturn = 2;
                    runturntimer = 0;
                }
            }

            flaming = true;

            if(flaming && !running){
                fireturntimer++;
                if(fireturn < 2 && fireturntimer > 2) { 
                    fireturn++;
                    fireturntimer = 0;
                }
                if(fireturn == 2 && fireturntimer > 2) {
                    fireturn = 0;
                    fireturntimer = 0;
                }
            }

            if(flaming && running){
                fireturntimer++;
                if(fireturn < 14 && fireturntimer > 2) { 
                    fireturn++;
                    fireturntimer = 0;
                }
                if(fireturn == 14 && fireturntimer > 2) {
                    fireturn = 9;
                    fireturntimer = 0;
                }
            }

            if(slashing){
                saberturntimer++;
                headofsety--;
                if(saberturn < 3 && saberturntimer > 5) { 
                    saberturn++;
                    saberturntimer = 0;
                }
                if(saberturn == 3 && saberturntimer > 5) {
                    saberturn = 0;
                    saberturntimer = 0;
                    headofsety = 0;
                    slashing = false;
                }
            }
            if(saberturn < 2){ saberx = -11; sabery = 30; if (facingleft){ fcsbrx = 24;}if (!facingleft){ fcsbrx = 0;}}
            if(saberturn == 2){ saberx = 30; sabery = 5; headofsety+=2; if (facingleft){ fcsbrx = -40;}}
            if(saberturn == 3){ saberx = 9; sabery = -17; headofsety+=2; if (facingleft){ fcsbrx = -18;}}

            if(bn::keypad::l_pressed() && armturn > 0){armturn--; }
            if(bn::keypad::r_pressed() && armturn < 3 ){armturn++; }

            if(facingleft) { armx = -25; gear_arm.set_horizontal_flip(true); gon_p.set_horizontal_flip(true); pgonx-= 5;}
            if(!facingleft) { armx = 20; gear_arm.set_horizontal_flip(false); gon_p.set_horizontal_flip(false); pgonx+= 5;}

            //pgonx += 2;
            pgonturn++;
            if(pgonturn > 4) {
                 pgonturn = 0;
            }

            if(bn::keypad::a_pressed() && armturn > 0) {
                pgoning = true;
            }
            if(bn::keypad::a_pressed() && armturn == 0 && mgonturn == 0 && !mgoning) {
                mgoning = true;
            }
            if(bn::keypad::a_pressed() && armturn == 0 && mgonturn == 3 && mgoning) {
                mgonturn = 0;
                mgontimer = 0;
                mgoning = false;
            }
            if(bn::keypad::a_held() && armturn > 0) {
                pgoning = true;
            }

            if(bn::keypad::a_released() && armturn > 0) {
                pgoning = false;
            }

            if(pgoning){
                pgontimer++;
                if(pgontimer > 5) { 
                    //pgonx = 0;
                    pgonx = plyrx+armx;
                    gon_p.set_position(plyrx+armx, army);
                    pgontimer = 0;
                }
            }
            // setup mgon
            if(mgoning && mgonturn < 3){
                mgontimer++;
                if(mgontimer > 3) { 
                    mgonx = plyrx+armx;
                    mgonturn++;
                    gon_m.set_position(mgonx, mgony);
                    mgontimer = 0;
                }
            }
            // mgon up
            if(mgonturn == 3) {
                mgontimer++;
                if(mgontimer > 10) { 
                    mgonseedy = mgony;
                    mgontimer = 0;
                }
            }
            mgonseedy+=5;

            if(bn::keypad::down_held() && !slashing && !pgoning && !bn::keypad::right_held() && !bn::keypad::left_held()) {
                gear_fire.set_scale(2, 2);
                firey = 7;
                gear_saber.set_horizontal_flip(true);
            }
            if(bn::keypad::down_released()) {
                gear_fire.set_scale(1, 1);
                firey = 37;
                gear_saber.set_horizontal_flip(false);
            }
            if(bn::keypad::down_held() && bn::keypad::right_pressed()) {
                plyrx = plyrx + 80;
                gear_fire.set_scale(1, 1);
                firey = 37;
                gear_saber.set_vertical_flip(false);
            }
            if(bn::keypad::down_held() && bn::keypad::left_pressed()) {
                plyrx = plyrx - 80;
                gear_fire.set_scale(1, 1);
                firey = 37;
                gear_saber.set_vertical_flip(false);
            }

            if(armturn == 2) { 
                p_gonpal.set_inverted(true); gon_p.set_scale(4, 4);
            } else { p_gonpal.set_inverted(false); gon_p.set_scale(1, 1);}

            if(armturn == 0) { gear_pal.set_colors(gear_palm); }
            if(armturn == 1) { gear_pal.set_colors(gear_palo); }
            if(armturn == 2) { gear_pal.set_colors(gear_pala); }
            if(armturn == 3) { gear_pal.set_colors(gear_palp); }
            
            gear_fire.set_position(plyrx+1,firey);
            gear_fire.set_tiles(bn::sprite_items::gear_fire.tiles_item().create_tiles(fireturn));
            gear_body.set_position(plyrx+1,37);
            gear_body.set_tiles(bn::sprite_items::gear_body.tiles_item().create_tiles(runturn));
            gear_saber.set_position(plyrx+saberx+fcsbrx,sabery);
            gear_saber.set_tiles(bn::sprite_items::gear_saber.tiles_item().create_tiles(saberturn));
            gear_head.set_position(plyrx+headofset+headofset2,headofsety);
            gear_head.set_tiles(bn::sprite_items::gear_head.tiles_item().create_tiles(headturn));
            gear_arm.set_position(plyrx+armx, army);
            gear_arm.set_tiles(bn::sprite_items::gear_arm.tiles_item().create_tiles(armturn));
            gon_p.set_position(pgonx, army);
            gon_p.set_tiles(bn::sprite_items::gon_p.tiles_item().create_tiles(pgonturn));
            gon_m.set_tiles(bn::sprite_items::gon_m.tiles_item().create_tiles(mgonturn));
            gon_mseed.set_position(mgonx, mgonseedy);
            point_uit.set_position(timet, -72);
            point_uib.set_position(timeb, -63);
         	bn::core::update();
     	}
    }

int main() {
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(10, 10, 10));

    while(true) {
    	the_big_show();
        bn::core::update();
    }
};