// ================== YALAXY-01 ==================  // 
//  ================== HusYada ===================  //
//225
// Butano
#include "bn_bg_palettes.h"
#include "bn_bg_palette_color_hbe_ptr.h"
#include "bn_bg_palettes_transparent_color_hbe_ptr.h"
#include "bn_colors.h"
#include "bn_core.h"
#include "bn_display.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_math.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sound_items.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_actions.h"
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
// =======================================
#include "bn_sprite_items_plyrsq.h"
#include "bn_sprite_items_anothersq.h"
#include "bn_sprite_items_dot.h"
#include "bn_sprite_items_paa_title.h"
// =======================================
#include "bn_sprite_items_f_cumba.h"
#include "bn_sprite_items_f_dot.h"
#include "bn_sprite_items_f_nana.h"
#include "bn_sprite_items_f_poon.h"
#include "bn_sprite_items_f_wire.h"

// Palettes
#include "bn_sprite_palette_items_gear_palm.h"
#include "bn_sprite_palette_items_gear_palo.h"
#include "bn_sprite_palette_items_gear_pala.h"
#include "bn_sprite_palette_items_gear_palp.h"

// Backgrounds
#include "bn_regular_bg_items_lovenue_1th.h"
#include "bn_regular_bg_items_lovenue_1t1.h"
#include "bn_regular_bg_items_lovenue_1t2.h"
#include "bn_regular_bg_items_lovenue_1t3.h"
#include "bn_regular_bg_items_lovenue_1t4.h"
#include "bn_regular_bg_items_lvl1s0.h"
#include "bn_regular_bg_items_lvl1s1.h"
#include "bn_regular_bg_items_lvl1s2.h"
#include "bn_regular_bg_items_lvl1s3.h"
#include "bn_regular_bg_items_lvl1s4.h"
// =======================================
#include "bn_regular_bg_items_flipoon_testlevel1.h"

#include "collision.h"
#include "flipoon.h"

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

//================================================================================================================
// Perfect Angles Advance

// Player Transform
int paplyrx = -60; float plyry = 0; float plyrw = 16; float plyrh = 16; float grv = 2; float fy = 2;
int size = 0;    int colour = 0;  float hscm = 0;   float vscm = 0;

// Player Middles (Left Middle + Top Middle = Top Left Corner)
float lm; float rm; float tm; float bm;

// Player Collision Offsets
int lox = 0; int loy = 1; int loh = -2; int rox = 0; int roy = 1; int roh = -2; 
int uox = 1; int uoy = 0; int uow = -2; int dux = 1; int doy = 0; int dow = -2;

// Sizing
bool flatten = false; bool spindly = false; bool jumping = false;
int actiontimer = 0;
int soundtimer = 0;

// Game Variables
int stage = 0; int lvl1s0x = 0; int lvl1s0y = -44;

// Other Shape Co-Ordinates
// LEVEL 1
float gndx = -300; float gndy = 60; float gndw = 600;
float rc1x =  8; float rc1y = 44; float rc1w = 64; float rc1h = 16;
float rc2x = 16; float rc2y = 28; float rc2w = 16; float rc2h = 16;
float rc3x = 64; float rc3y = 12; float rc3w = 32; float rc3h = 16;
float rc4x = 96; float rc4y = -20; float rc4w = 32; float rc4h = 16;
float rc5x = 56; float rc5y = -52; float rc5w = 16; float rc5h = 16;
float rc6x = 16; float rc6y = -52; float rc6w = 16; float rc6h = 16;
float rc7x = -88; float rc7y = -52; float rc7w = 48; float rc7h = 16;
float rc8x = -100; float rc8y = -65; float rc8w = 8; float rc8h = 8;
// LEVEL 3
float mc1x = -16; float mc1y = 44; float mc1w = 16; float mc1h = 16;
float mc2x = -16; float mc2y = 20; float mc2w = 16; float mc2h = 16;
float mc3x = -16; float mc3y = -4; float mc3w = 16; float mc3h = 16;
float mc4x = -24; float mc4y = -28; float mc4w = 32; float mc4h = 16;
float mc5x = -32; float mc5y = 10; float mc5w = 16; float mc5h = 86;
float mc6x = -92; float mc6y = 48; float mc6w = 8; float mc6h = 8;

//================================================================================================================
// Flipoon Advance

int f_poonx = -70; int f_poony = -70; int f_startx = -70; int f_starty = -70;
int f_firex = 1; int f_firey = -2; bool f_poonfiring = false;
int f_dist; float f_planet = 23;

//================================================================================================================

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

            // scene 0 = title, 1 = yearlysis, 2 = end, 3 = dream
            if(scene == 0) { title.set_position(0, -40); } else { title.set_position(-1000, -1000); }
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
                if(runturn < 11 && runturntimer > 4) { 
                    runturn++;
                    runturntimer = 0;
                }
                if(runturn == 11 && runturntimer > 4) {
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
            //gear_body.set_position(plyrx+1,37); FINISH RUN CYCLE!
            gear_body.set_tiles(bn::sprite_items::gear_body.tiles_item().create_tiles(runturn));
            gear_saber.set_position(plyrx+saberx+fcsbrx,sabery);
            gear_saber.set_tiles(bn::sprite_items::gear_saber.tiles_item().create_tiles(saberturn));
            //gear_head.set_position(plyrx+headofset+headofset2,headofsety); READ ABOVE ^^
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

void the_big_showtwo() {

    // Player Sprite
    bn::sprite_ptr plyrsq = bn::sprite_items::anothersq.create_sprite(paplyrx, plyry);
    // Title Sprite
    bn::sprite_ptr paa_title = bn::sprite_items::paa_title.create_sprite(0, -90);

    bn::regular_bg_ptr lvl1s0 = bn::regular_bg_items::lvl1s0.create_bg(lvl1s0x,lvl1s0y);
    bn::regular_bg_move_loop_action moveback(lvl1s0, 60, 4, 2);
    // lvl1s0.set_priority(1);
    bn::regular_bg_ptr lvl1s1 = bn::regular_bg_items::lvl1s1.create_bg(0,-44); 
    //lvl1s1.set_priority(2);
    //bn::regular_bg_ptr lvl1s2 = bn::regular_bg_items::lvl1s2.create_bg(0,-44);
    //lvl1s2.set_priority(0);
    bn::regular_bg_ptr lvl1s3 = bn::regular_bg_items::lvl1s3.create_bg(0,-44);
    //lvl1s3.set_priority(0);
    bn::regular_bg_ptr lvl1s4 = bn::regular_bg_items::lvl1s4.create_bg(0,-44);
    //lvl1s4.set_priority(0);

    // Overlap Function
    colli::sion ocol;
    
    // Player Debug Dots (no for)
    bn::sprite_ptr dot0 = bn::sprite_items::dot.create_sprite(paplyrx,plyry);
    // Vertical Rect
    bn::sprite_ptr dot1 = bn::sprite_items::dot.create_sprite(paplyrx-(plyrw/2), plyry-(plyrh/2));
    bn::sprite_ptr dot2 = bn::sprite_items::dot.create_sprite(paplyrx+(plyrw/2), plyry-(plyrh/2));
    bn::sprite_ptr dot3 = bn::sprite_items::dot.create_sprite(paplyrx-(plyrw/2), plyry+(plyrh/2));
    bn::sprite_ptr dot4 = bn::sprite_items::dot.create_sprite(paplyrx+(plyrw/2), plyry+(plyrh/2));
    // Horizontal Rect
    bn::sprite_ptr dot5 = bn::sprite_items::dot.create_sprite(paplyrx-(plyrw/2), plyry-(plyrh/2));
    bn::sprite_ptr dot6 = bn::sprite_items::dot.create_sprite(paplyrx+(plyrw/2), plyry-(plyrh/2));
    bn::sprite_ptr dot7 = bn::sprite_items::dot.create_sprite(paplyrx-(plyrw/2), plyry+(plyrh/2));
    bn::sprite_ptr dot8 = bn::sprite_items::dot.create_sprite(paplyrx+(plyrw/2), plyry+(plyrh/2)); 
    // Level Debug Dots
    // LEVEL 1 ==============================================================================
    // bn::sprite_ptr dot11 = bn::sprite_items::dot.create_sprite(rc1x-(rc1w/2), rc1y-(rc1h/2));
    // bn::sprite_ptr dot12 = bn::sprite_items::dot.create_sprite(rc1x+(rc1w/2), rc1y-(rc1h/2));
    // bn::sprite_ptr dot13 = bn::sprite_items::dot.create_sprite(rc1x-(rc1w/2), rc1y+(rc1h/2));
    // bn::sprite_ptr dot14 = bn::sprite_items::dot.create_sprite(rc1x+(rc1w/2), rc1y+(rc1h/2));
    // bn::sprite_ptr dot21 = bn::sprite_items::dot.create_sprite(rc2x-(rc2w/2), rc2y-(rc2h/2));
    // bn::sprite_ptr dot22 = bn::sprite_items::dot.create_sprite(rc2x+(rc2w/2), rc2y-(rc2h/2));
    // bn::sprite_ptr dot23 = bn::sprite_items::dot.create_sprite(rc2x-(rc2w/2), rc2y+(rc2h/2));
    // bn::sprite_ptr dot24 = bn::sprite_items::dot.create_sprite(rc2x+(rc2w/2), rc2y+(rc2h/2));
    // bn::sprite_ptr dot31 = bn::sprite_items::dot.create_sprite(rc3x-(rc3w/2), rc3y-(rc3h/2));
    // bn::sprite_ptr dot32 = bn::sprite_items::dot.create_sprite(rc3x+(rc3w/2), rc3y-(rc3h/2));
    // bn::sprite_ptr dot33 = bn::sprite_items::dot.create_sprite(rc3x-(rc3w/2), rc3y+(rc3h/2));
    // bn::sprite_ptr dot34 = bn::sprite_items::dot.create_sprite(rc3x+(rc3w/2), rc3y+(rc3h/2));
    // bn::sprite_ptr dot41 = bn::sprite_items::dot.create_sprite(rc4x-(rc4w/2), rc4y-(rc4h/2));
    // bn::sprite_ptr dot42 = bn::sprite_items::dot.create_sprite(rc4x+(rc4w/2), rc4y-(rc4h/2));
    // bn::sprite_ptr dot43 = bn::sprite_items::dot.create_sprite(rc4x-(rc4w/2), rc4y+(rc4h/2));
    // bn::sprite_ptr dot44 = bn::sprite_items::dot.create_sprite(rc4x+(rc4w/2), rc4y+(rc4h/2));
    // bn::sprite_ptr dot51 = bn::sprite_items::dot.create_sprite(rc5x-(rc5w/2), rc5y-(rc5h/2));
    // bn::sprite_ptr dot52 = bn::sprite_items::dot.create_sprite(rc5x+(rc5w/2), rc5y-(rc5h/2));
    // bn::sprite_ptr dot53 = bn::sprite_items::dot.create_sprite(rc5x-(rc5w/2), rc5y+(rc5h/2));
    // bn::sprite_ptr dot54 = bn::sprite_items::dot.create_sprite(rc5x+(rc5w/2), rc5y+(rc5h/2));
    // bn::sprite_ptr dot61 = bn::sprite_items::dot.create_sprite(rc6x-(rc6w/2), rc6y-(rc6h/2));
    // bn::sprite_ptr dot62 = bn::sprite_items::dot.create_sprite(rc6x+(rc6w/2), rc6y-(rc6h/2));
    // bn::sprite_ptr dot63 = bn::sprite_items::dot.create_sprite(rc6x-(rc6w/2), rc6y+(rc6h/2));
    // bn::sprite_ptr dot64 = bn::sprite_items::dot.create_sprite(rc6x+(rc6w/2), rc6y+(rc6h/2));
    // bn::sprite_ptr dot71 = bn::sprite_items::dot.create_sprite(rc7x-(rc7w/2), rc7y-(rc7h/2));
    // bn::sprite_ptr dot72 = bn::sprite_items::dot.create_sprite(rc7x+(rc7w/2), rc7y-(rc7h/2));
    // bn::sprite_ptr dot73 = bn::sprite_items::dot.create_sprite(rc7x-(rc7w/2), rc7y+(rc7h/2));
    // bn::sprite_ptr dot74 = bn::sprite_items::dot.create_sprite(rc7x+(rc7w/2), rc7y+(rc7h/2));
    // bn::sprite_ptr dot81 = bn::sprite_items::dot.create_sprite(rc8x-(rc8w/2), rc8y-(rc8h/2));
    // bn::sprite_ptr dot82 = bn::sprite_items::dot.create_sprite(rc8x+(rc8w/2), rc8y-(rc8h/2));
    // bn::sprite_ptr dot83 = bn::sprite_items::dot.create_sprite(rc8x-(rc8w/2), rc8y+(rc8h/2));
    // bn::sprite_ptr dot84 = bn::sprite_items::dot.create_sprite(rc8x+(rc8w/2), rc8y+(rc8h/2));
    // LEVEL 3 ==============================================================================
    // bn::sprite_ptr dot11 = bn::sprite_items::dot.create_sprite(mc1x-(mc1w/2), mc1y-(mc1h/2));
    // bn::sprite_ptr dot12 = bn::sprite_items::dot.create_sprite(mc1x+(mc1w/2), mc1y-(mc1h/2));
    // bn::sprite_ptr dot13 = bn::sprite_items::dot.create_sprite(mc1x-(mc1w/2), mc1y+(mc1h/2));
    // bn::sprite_ptr dot14 = bn::sprite_items::dot.create_sprite(mc1x+(mc1w/2), mc1y+(mc1h/2));
    // bn::sprite_ptr dot21 = bn::sprite_items::dot.create_sprite(mc2x-(mc2w/2), mc2y-(mc2h/2));
    // bn::sprite_ptr dot22 = bn::sprite_items::dot.create_sprite(mc2x+(mc2w/2), mc2y-(mc2h/2));
    // bn::sprite_ptr dot23 = bn::sprite_items::dot.create_sprite(mc2x-(mc2w/2), mc2y+(mc2h/2));
    // bn::sprite_ptr dot24 = bn::sprite_items::dot.create_sprite(mc2x+(mc2w/2), mc2y+(mc2h/2));
    // bn::sprite_ptr dot31 = bn::sprite_items::dot.create_sprite(mc3x-(mc3w/2), mc3y-(mc3h/2));
    // bn::sprite_ptr dot32 = bn::sprite_items::dot.create_sprite(mc3x+(mc3w/2), mc3y-(mc3h/2));
    // bn::sprite_ptr dot33 = bn::sprite_items::dot.create_sprite(mc3x-(mc3w/2), mc3y+(mc3h/2));
    // bn::sprite_ptr dot34 = bn::sprite_items::dot.create_sprite(mc3x+(mc3w/2), mc3y+(mc3h/2));
    // bn::sprite_ptr dot41 = bn::sprite_items::dot.create_sprite(mc4x-(mc4w/2), mc4y-(mc4h/2));
    // bn::sprite_ptr dot42 = bn::sprite_items::dot.create_sprite(mc4x+(mc4w/2), mc4y-(mc4h/2));
    // bn::sprite_ptr dot43 = bn::sprite_items::dot.create_sprite(mc4x-(mc4w/2), mc4y+(mc4h/2));
    // bn::sprite_ptr dot44 = bn::sprite_items::dot.create_sprite(mc4x+(mc4w/2), mc4y+(mc4h/2));
    // bn::sprite_ptr dot51 = bn::sprite_items::dot.create_sprite(mc5x-(mc5w/2), mc5y-(mc5h/2));
    // bn::sprite_ptr dot52 = bn::sprite_items::dot.create_sprite(mc5x+(mc5w/2), mc5y-(mc5h/2));
    // bn::sprite_ptr dot53 = bn::sprite_items::dot.create_sprite(mc5x-(mc5w/2), mc5y+(mc5h/2));
    // bn::sprite_ptr dot54 = bn::sprite_items::dot.create_sprite(mc5x+(mc5w/2), mc5y+(mc5h/2));
    // bn::sprite_ptr dot61 = bn::sprite_items::dot.create_sprite(mc6x-(mc6w/2), mc6y-(mc6h/2));
    // bn::sprite_ptr dot62 = bn::sprite_items::dot.create_sprite(mc6x+(mc6w/2), mc6y-(mc6h/2));
    // bn::sprite_ptr dot63 = bn::sprite_items::dot.create_sprite(mc6x-(mc6w/2), mc6y+(mc6h/2));
    // bn::sprite_ptr dot64 = bn::sprite_items::dot.create_sprite(mc6x+(mc6w/2), mc6y+(mc6h/2));
    // ============================================================================================
        // dot11.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot12.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot13.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot14.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
        // dot21.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot22.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot23.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot24.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot31.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot32.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot33.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot34.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
        // dot41.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot42.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot43.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot44.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
        // dot51.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot52.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot53.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot54.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
        // dot61.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot62.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot63.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot64.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
        // dot71.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot72.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot73.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot74.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
        // dot81.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot82.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot83.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        // dot84.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));

    //gndd.set_tiles(bn::sprite_items::plyrsq.tiles_item().create_tiles(5));
    //gndd.set_scale(16,1);

    while(!bn::keypad::start_pressed()) {

        // Moving Back Title Screen
        moveback.update();

        // Corners (1 is top left, 2 is top right, 3 is bottom left, 4 is bottom right)
        lm = paplyrx-(plyrw/2); rm = paplyrx+(plyrw/2); tm = plyry-(plyrh/2); bm = plyry+(plyrh/2);

        // Move Debug Dots
        dot0.set_position(paplyrx,plyry);
        dot1.set_position(lm + 1, tm); dot2.set_position(rm - 0.1, tm); dot3.set_position(lm + 1, bm); dot4.set_position(rm - 0.1, bm);
        dot5.set_position(lm, tm + 1); dot6.set_position(rm, tm + 1); dot7.set_position(lm, bm - 0.1); dot8.set_position(rm, bm - 0.1);

        // Player Movement / Collision
            if(bn::keypad::left_held() //&& ocol.overlap(lm+lox,tm+loy,0,plyrh+loh, gndx-(32/2)-1, gndy-(32/2)-1, 34, 34) == false 
                                        ) { 
                paplyrx -= 2;
                //if(lvl1s1.x() > -16){ lvl1s1.set_x(60 + paplyrx - paplyrx % 2);} 
            } else 
            if(bn::keypad::right_held() //&& ocol.overlap(rm+rox,tm+roy,0,plyrh+roh, gndx-(32/2)-1, gndy-(32/2)-1, 34, 34) == false
                                        ) { 
                paplyrx += 2; 
                //if(lvl1s1.x() < 16){ lvl1s1.set_x(60 + paplyrx - paplyrx % 2);}
            }
            if(bn::keypad::a_held() && (ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == true)) { jumping = true; }
            if(stage == 1) {
            if(bn::keypad::a_held() && (ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc1x-32, rc1y-(16/2)-1, rc1w, rc1h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc2x-(rc2w/2), rc2y-(rc2h/2)-1, rc2w, rc2h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc3x-(rc3w/2), rc3y-(rc3h/2)-1, rc3w, rc3h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc4x-(rc4w/2), rc4y-(rc4h/2)-1, rc4w, rc4h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc5x-(rc5w/2), rc5y-(rc5h/2)-1, rc5w, rc5h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc6x-(rc6w/2), rc6y-(rc6h/2)-1, rc6w, rc6h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc7x-(rc7w/2), rc7y-(rc7h/2)-1, rc7w, rc7h+2) == true
                                    )) { jumping = true; }
            }
            if(stage == 2) {
            if(bn::keypad::a_held() && (ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc2x-(mc2w/2), mc2y-(mc2h/2)-1, mc2w, mc2h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc3x-(mc3w/2), mc3y-(mc3h/2)-1, mc3w, mc3h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc4x-(mc4w/2), mc4y-(mc4h/2)-1, mc4w, mc4h+2) == true
                                    || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc1x-(mc1w/2), mc1y-(mc1h/2)-1, mc1w, mc1h+2) == true
                                    )) { jumping = true; }
            }

            if(stage == 1 && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc8x-(rc8w/2), rc8y-(rc8h/2)-1, rc8w, rc8h+2) == true) { stage = 2; paplyrx = 100; }
            if(stage == 2 && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc6x-(mc6w/2), mc6y-(mc6h/2)-1, mc6w, mc6h+2) == true) { stage = 3; }

        // Jumping
        if(jumping) { 
            plyry -= fy;
            if(fy < 0.2) { fy -= 0.2; }
            actiontimer++;
            if(actiontimer > 12) { jumping = false; }
            if(bn::keypad::a_released()) { jumping = false; }
            //if(ocol.overlap(lm+uox,tm+uoy,plyrw+uow,0, gnd3x-(32/2)-1, gnd3y-(32/2)-1, 34, 34) == true) { plyry=plyry+4; jumping = false; }
            //if(ocol.overlap(lm+uox,tm+uoy,plyrw+uow,0, gnd2x-(16/2)-1, gnd2y-(64/2)-1, 18, 66) == true) { plyry=plyry+2; jumping = false; }
        }
        if(!jumping){ actiontimer = 0; fy = 2; }
 
        // Flatten
        if(bn::keypad::l_held() && size < 8) { flatten = true; }
        if(bn::keypad::l_released()) { flatten = false; soundtimer = 0; }
        if(flatten) { 
            if(size < 8) { flatten = false; }
            size++;
            // Rebound Flatten
            soundtimer++;
            if(soundtimer > 5) {
                bn::sound_items::flatten.play(0.25);
                soundtimer = 0;
            }
        }

        // Spindy
        if(bn::keypad::r_held() && size > -8) { spindly = true; }
        if(bn::keypad::r_released()) { spindly = false; soundtimer = 0; grv = 2;}
        if(spindly) { 
            if(size > -8) { spindly = false; }
            size--;
            // Rebound Spindly goes here vv
            if(ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == true
            || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc1x-32, rc1y-(16/2)-1, rc1w, rc1h+2) == false
            || ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc2x-(rc2w/2), rc2y-(rc2h/2)-1, rc2w, rc2h+2) == false
            ) { plyry -= 2;}
            //                           ^^
            soundtimer++;
            if(soundtimer > 5) {
                bn::sound_items::spindly.play(0.25);
                soundtimer = 0;
            }
        }

        // Player Size... oh my go... letter 1=direction, o=offset, 3=x,y,w,h; left, right, up, down
        if(size == 8)  { hscm = 1.6; vscm = -0.8; plyrw = 41.6; plyrh = 3.2;  
            lox = 0; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 2; uoy = 1; uow = -4; dux = 2; doy = 0; dow = -4;}
        if(size == 7)  { hscm = 1.4; vscm = -0.7; plyrw = 38.4; plyrh = 4.8;  
            lox = 0; loy = 2; loh = -4; rox = 0; roy = 2; roh = -4; uox = 1; uoy = 0; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == 6)  { hscm = 1.2; vscm = -0.6; plyrw = 35.2; plyrh = 6.4;  
            lox = 0; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 1; uoy = 1; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == 5)  { hscm = 1;   vscm = -0.5; plyrw = 32;   plyrh = 8;    
            lox = 0; loy = 1; loh = -2; rox = 0; roy = 1; roh = -2; uox = 1; uoy = 0; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == 4)  { hscm = 0.8; vscm = -0.4; plyrw = 28.8; plyrh = 9.6;  
            lox = 0; loy = 2; loh = -4; rox = 0; roy = 2; roh = -4; uox = 2; uoy = 0; uow = -4; dux = 2; doy = 0; dow = -4;}
        if(size == 3)  { hscm = 0.6; vscm = -0.3; plyrw = 25.6; plyrh = 11.2; 
            lox = 0; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 2; uoy = 1; uow = -4; dux = 2; doy = 0; dow = -4;}
        if(size == 2)  { hscm = 0.4; vscm = -0.2; plyrw = 22.4; plyrh = 12.8; 
            lox = 1; loy = 2; loh = -4; rox = 0; roy = 2; roh = -4; uox = 3; uoy = 0; uow = -4; dux = 3; doy = 0; dow = -4;}
        if(size == 1)  { hscm = 0.2; vscm = -0.1; plyrw = 19.2; plyrh = 14.4; 
            lox = 0; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 1; uoy = 1; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == 0)  { hscm = 0;   vscm =  0;   plyrw = 16;   plyrh = 16;   
            lox = 0; loy = 1; loh = -2; rox = 0; roy = 1; roh = -2; uox = 1; uoy = 0; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == -1) { vscm = 0.2; hscm = -0.1; plyrw = 14.4; plyrh = 19.2; 
            lox = 0; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 1; uoy = 1; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == -2) { vscm = 0.4; hscm = -0.2; plyrw = 12.8; plyrh = 22.4; 
            lox = 1; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 3; uoy = 1; uow = -5; dux = 3; doy = 0; dow = -5;}
        if(size == -3) { vscm = 0.6; hscm = -0.3; plyrw = 11.2; plyrh = 25.6; 
            lox = 1; loy = 3; loh = -5; rox = 0; roy = 3; roh = -5; uox = 3; uoy = 1; uow = -5; dux = 3; doy = 0; dow = -5;}
        if(size == -4) { vscm = 0.8; hscm = -0.4; plyrw = 9.6;  plyrh = 28.8; 
            lox = 0; loy = 2; loh = -5; rox = 0; roy = 2; roh = -5; uox = 2; uoy = 0; uow = -5; dux = 2; doy = 0; dow = -5;}
        if(size == -5) { vscm = 1;   hscm = -0.5; plyrw = 8;    plyrh = 32;   
            lox = 0; loy = 1; loh = -2; rox = 0; roy = 1; roh = -2; uox = 1; uoy = 0; uow = -2; dux = 1; doy = 0; dow = -2;}
        if(size == -6) { vscm = 1.2; hscm = -0.6; plyrw = 6.4;  plyrh = 35.2; 
            lox = 1; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 3; uoy = 1; uow = -4; dux = 3; doy = 0; dow = -4;}
        if(size == -7) { vscm = 1.4; hscm = -0.7; plyrw = 4.8;  plyrh = 38.4; 
            lox = 0; loy = 3; loh = -4; rox = 0; roy = 3; roh = -4; uox = 2; uoy = 1; uow = -4; dux = 2; doy = 0; dow = -4;}
        if(size == -8) { vscm = 1.6; hscm = -0.8; plyrw = 3.2;  plyrh = 41.6; 
            lox = 1; loy = 3; loh = -5; rox = 0; roy = 3; roh = -5; uox = 3; uoy = 1; uow = -4; dux = 3; doy = 0; dow = -4;}

        // Colour Change
        if(plyrsq.horizontal_scale() > 0.8 && plyrsq.horizontal_scale() <= 1.4) { colour = 0; }
        if(plyrsq.horizontal_scale() > 0.4 && plyrsq.horizontal_scale() <= 0.8) { colour = 1; }
        if(plyrsq.horizontal_scale() > 0.1 && plyrsq.horizontal_scale() <= 0.4) { colour = 2; }
        if(plyrsq.horizontal_scale() > 1.4 && plyrsq.horizontal_scale() <= 2.2) { colour = 3; }
        if(plyrsq.horizontal_scale() > 2.2 && plyrsq.horizontal_scale() <= 2.7) { colour = 4; }

        // Inital Position & Size
        if(bn::keypad::b_pressed()) {
            size = 0;
            plyrsq.set_scale(1,1);
            plyrsq.set_x(0);
            plyrsq.set_y(0);
            paplyrx = 0;
            plyry = 0;
            plyrw = 16;
            plyrh = 16;
            hscm = 0;
            vscm = 0;
            //hszm = 0;
            //vszm = 0;
        }

        // Toggle Edge Points
        if(bn::keypad::select_held()) { 
            dot0.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot1.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot2.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot3.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot4.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot5.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot6.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot7.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
            dot8.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1)); 
        }

        // Logging
        if(bn::keypad::select_released()) { 
            dot0.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot1.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot2.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot3.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot4.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0));
            dot5.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot6.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot7.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 
            dot8.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(0)); 

            BN_LOG("==================");
            BN_LOG("Size: ", bn::fixed(size));
            BN_LOG("Player X: ", bn::fixed(paplyrx)); BN_LOG("Player Y: ", bn::fixed(plyry));
            BN_LOG("Player Width: ", bn::fixed(plyrw)); BN_LOG("Player Height: ", bn::fixed(plyrh));
            // BN_LOG("Pos X: ", plyrsq.x()); BN_LOG("Pos Y: ", plyrsq.y());
            BN_LOG("Width Scale: ", plyrsq.horizontal_scale()); BN_LOG("Height Scale: ", plyrsq.vertical_scale());
            BN_LOG("Horizontal Scale Multiplier: ", bn::fixed(hscm)); BN_LOG("Vertical Scale Multiplier: ", bn::fixed(vscm));
            BN_LOG("000000000000000000");
            //BN_LOG("Back X: ", lvl1s1.x());
            // BN_LOG("Left Middle: ", bn::fixed(lm));
            // BN_LOG("Top Middle: ", bn::fixed(tm));
            // BN_LOG("Up Col X: ", bn::fixed(lm+1));
            // BN_LOG("Up Col Width: ", bn::fixed(plyrw-2));
            // BN_LOG("OBJ2X1: ", bn::fixed(obj2x[0]));
            // BN_LOG("OBJ2X2: ", bn::fixed(obj2x[1]));
            // BN_LOG("OBJ2Y1: ", bn::fixed(obj2y[0]));
            // BN_LOG("OBJ2Y2: ", bn::fixed(obj2y[1]));
            //for (int i = 0; i < 2; i++) { BN_LOG("OBJ2XI: ", bn::fixed(obj2x[i])); }
            //for (int i = 0; i < 2; i++) { BN_LOG("OBJ2YI: ", bn::fixed(obj2y[i])); }
        }

        if(stage == 0 && jumping == false && (ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == false)) { plyry += grv; }
        if(stage == 3 && jumping == false && (ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == false)) { plyry += grv; }

        if(stage == 1) {
        if(jumping == false &&
        (  ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc1x-32, rc1y-(16/2)-1, rc1w, rc1h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc2x-(rc2w/2), rc2y-(rc2h/2)-1, rc2w, rc2h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc3x-(rc3w/2), rc3y-(rc3h/2)-1, rc3w, rc3h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc4x-(rc4w/2), rc4y-(rc4h/2)-1, rc4w, rc4h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc5x-(rc5w/2), rc5y-(rc5h/2)-1, rc5w, rc5h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc6x-(rc6w/2), rc6y-(rc6h/2)-1, rc6w, rc6h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, rc7x-(rc7w/2), rc7y-(rc7h/2)-1, rc7w, rc7h+2) == false
        )) { plyry += grv; }
    }

        if(stage == 2) {
        if(jumping == false &&
        (  ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, gndx, gndy-(16/2)-1, gndw, 18) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc1x-(mc1w/2), mc1y-(mc1h/2)-1, mc1w, mc1h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc2x-(mc2w/2), mc2y-(mc2h/2)-1, mc2w, mc2h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc3x-(mc3w/2), mc3y-(mc3h/2)-1, mc3w, mc3h+2) == false
        && ocol.overlap(lm+dux,bm+doy,plyrw+dow,0, mc4x-(mc4w/2), mc4y-(mc4h/2)-1, mc4w, mc4h+2) == false
        )) { plyry += grv; }
        }

        plyrsq.set_z_order(3);
        if(stage == 0) { lvl1s0.set_z_order(1); lvl1s1.set_z_order(2); //lvl1s2.set_z_order(2); 
            lvl1s3.set_z_order(2); 
            lvl1s4.set_z_order(2);paa_title.set_visible(true);}
        if(stage == 1) { lvl1s0.set_z_order(2); lvl1s1.set_z_order(1); //lvl1s2.set_z_order(1); 
            lvl1s3.set_z_order(2); 
            lvl1s4.set_z_order(2);paa_title.set_visible(false);}
        if(stage == 2) { lvl1s0.set_z_order(2); lvl1s1.set_z_order(2); //lvl1s2.set_z_order(2); 
            lvl1s3.set_z_order(1); 
            lvl1s4.set_z_order(2); paa_title.set_visible(false);}
        if(stage == 3) { lvl1s0.set_z_order(2); lvl1s1.set_z_order(2); //lvl1s2.set_z_order(1); 
            lvl1s3.set_z_order(2); 
            lvl1s4.set_z_order(1);paa_title.set_visible(true); }
        // if(stage == 4) { lvl1s0.set_z_order(0); lvl1s1.set_z_order(2); //lvl1s2.set_z_order(1); lvl1s3.set_z_order(0); 
        //     lvl1s4.set_z_order(2); }

        if(stage == 0 && bn::keypad::select_pressed()) { stage = 1; }
        if(stage == 3 && bn::keypad::select_pressed()) { stage = 0; }

        plyrsq.set_position(paplyrx - paplyrx % 2,plyry);
        paa_title.set_position(0,-40);
        //plyrsq.set_scale(plyrw,plyrh);
        plyrsq.set_scale(1 + hscm, 1 + vscm);
        plyrsq.set_tiles(bn::sprite_items::anothersq.tiles_item().create_tiles(colour));
        //if(lvl1s1.x() < 16){ lvl1s1.set_position(60 + paplyrx - paplyrx % 2,-44 + plyry);}

        bn::core::update();
    }
}

void flipoon_advance(){
	// Overlap Functionas
    colli::sion ocol;
    flip::poon fp;
	// Player Sprites
	bn::sprite_ptr f_cucumba = bn::sprite_items::f_cumba.create_sprite(fp.plyrx, fp.plyry); // f_cucumba.set_visible(!f_cucumba.visible());
	bn::sprite_ptr f_poon = bn::sprite_items::f_poon.create_sprite(f_poonx, f_poony);	  	// f_poon.set_visible(!f_poon.visible());
	bn::sprite_ptr f_banana = bn::sprite_items::f_nana.create_sprite(fp.plyrx, fp.plyry);	// f_banana.set_visible(!f_banana.visible());
	// Poon Dots
	bn::sprite_ptr f_dot1 = bn::sprite_items::f_dot.create_sprite(0, 90);
	bn::sprite_ptr f_dot2 = bn::sprite_items::f_dot.create_sprite(0, 90);
	bn::sprite_ptr f_dot3 = bn::sprite_items::f_dot.create_sprite(0, 90);
	// Player Debug Dots
	// Old Calculation
	// bn::sprite_ptr f_dotbh1 = bn::sprite_items::dot.create_sprite(fp.plyrx-(fp.plyrw/2), fp.plyry-(fp.plyrh/2));
	// bn::sprite_ptr f_dotbh2 = bn::sprite_items::dot.create_sprite(fp.plyrx+(fp.plyrw/2)+1, fp.plyry-(fp.plyrh/2));
	// bn::sprite_ptr f_dotbh3 = bn::sprite_items::dot.create_sprite(fp.plyrx-(fp.plyrw/2), fp.plyry+(fp.plyrh/2));
	// bn::sprite_ptr f_dotbh4 = bn::sprite_items::dot.create_sprite(fp.plyrx+(fp.plyrw/2)+1, fp.plyry+(fp.plyrh/2));
	// Collision Calculation
	// plyrx-plyrw,	plyry+1,1,plyrh-2
	bn::sprite_ptr f_dotbh1 = bn::sprite_items::dot.create_sprite(fp.plyrx+fp.leftoffsetx - fp.plyrw+fp.leftoffsetw, fp.plyry - fp.plyrh);
	bn::sprite_ptr f_dotbh2 = bn::sprite_items::dot.create_sprite(fp.plyrx + fp.plyrw+1, fp.plyry - fp.plyrh);
	bn::sprite_ptr f_dotbh3 = bn::sprite_items::dot.create_sprite(fp.plyrx+fp.leftoffsetx - fp.plyrw+fp.leftoffsetw, fp.plyry + fp.plyrh);
	bn::sprite_ptr f_dotbh4 = bn::sprite_items::dot.create_sprite(fp.plyrx + fp.plyrw+1, fp.plyry + fp.plyrh);
	f_dotbh1.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_dotbh2.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_dotbh3.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_dotbh4.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	// Level Debug Dots
	bn::sprite_ptr f_lvlt1o01a = bn::sprite_items::dot.create_sprite(fp.lvlt1x[0]			     ,fp.lvlt1y[0]);
	bn::sprite_ptr f_lvlt1o01b = bn::sprite_items::dot.create_sprite(fp.lvlt1x[0] + fp.lvlt1w[0] ,fp.lvlt1y[0]);
	bn::sprite_ptr f_lvlt1o01c = bn::sprite_items::dot.create_sprite(fp.lvlt1x[0]			     ,fp.lvlt1y[0] + fp.lvlt1h[0]);
	bn::sprite_ptr f_lvlt1o01d = bn::sprite_items::dot.create_sprite(fp.lvlt1x[0] + fp.lvlt1w[0] ,fp.lvlt1y[0] + fp.lvlt1h[0]);
	f_lvlt1o01a.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_lvlt1o01b.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_lvlt1o01c.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_lvlt1o01d.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	bn::sprite_ptr f_lvlt1o02a = bn::sprite_items::dot.create_sprite(fp.lvlt1x[1]			     ,fp.lvlt1y[1]);
	bn::sprite_ptr f_lvlt1o02b = bn::sprite_items::dot.create_sprite(fp.lvlt1x[1] + fp.lvlt1w[1] ,fp.lvlt1y[1]);
	bn::sprite_ptr f_lvlt1o02c = bn::sprite_items::dot.create_sprite(fp.lvlt1x[1]			     ,fp.lvlt1y[1] + fp.lvlt1h[1]);
	bn::sprite_ptr f_lvlt1o02d = bn::sprite_items::dot.create_sprite(fp.lvlt1x[1] + fp.lvlt1w[1] ,fp.lvlt1y[1] + fp.lvlt1h[1]);
	f_lvlt1o02a.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_lvlt1o02b.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_lvlt1o02c.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));
	f_lvlt1o02d.set_tiles(bn::sprite_items::dot.tiles_item().create_tiles(1));//

	bn::regular_bg_ptr flipoon_testlevel1 = bn::regular_bg_items::flipoon_testlevel1.create_bg(fp.bgx,fp.bgy);

	while(true){
		for(int i = 0; i < 2; i++) {
			if(bn::keypad::left_held() && fp.lvlt1col_left()) {
				//Move Level
			 	fp.lvlt1x[i]+=2;
			 	fp.bgx++;
			}
			if(bn::keypad::right_held() && fp.lvlt1col_right()) {
				//Move Level
				fp.lvlt1x[i]-=2;
				fp.bgx--;
			}
		}

		flipoon_testlevel1.set_position(fp.bgx, fp.bgy);
		// Debug Positionx Update
		f_lvlt1o01a.set_position(fp.lvlt1x[0]			     ,fp.lvlt1y[0]);
		f_lvlt1o01b.set_position(fp.lvlt1x[0] + fp.lvlt1w[0] ,fp.lvlt1y[0]);
		f_lvlt1o01c.set_position(fp.lvlt1x[0]			     ,fp.lvlt1y[0] + fp.lvlt1h[0]);
		f_lvlt1o01d.set_position(fp.lvlt1x[0] + fp.lvlt1w[0] ,fp.lvlt1y[0] + fp.lvlt1h[0]);
		f_lvlt1o02a.set_position(fp.lvlt1x[1]			     ,fp.lvlt1y[1]);
		f_lvlt1o02b.set_position(fp.lvlt1x[1] + fp.lvlt1w[1] ,fp.lvlt1y[1]);
		f_lvlt1o02c.set_position(fp.lvlt1x[1]			     ,fp.lvlt1y[1] + fp.lvlt1h[1]);
		f_lvlt1o02d.set_position(fp.lvlt1x[1] + fp.lvlt1w[1] ,fp.lvlt1y[1] + fp.lvlt1h[1]);

		// Rotate Cumba (change this to L&R)
		bn::fixed f_cumr = f_cucumba.rotation_angle();
		if(bn::keypad::r_held()) {
			f_cucumba.set_rotation_angle(bn::max(f_cumr - 5, bn::fixed(0))); 
			if(f_cucumba.rotation_angle() == 0) { 
				f_cucumba.set_rotation_angle(360);
			}
		} else if(bn::keypad::l_held()) { 
        	f_cucumba.set_rotation_angle(bn::min(f_cumr + 5, bn::fixed(360))); 
        	if(f_cucumba.rotation_angle() == 360) { 
				f_cucumba.set_rotation_angle(0);
			}
        }
        // if(bn::keypad::up_pressed()) { f_cucumba.set_rotation_angle(300); }
        // if(bn::keypad::down_pressed()) { f_cucumba.set_rotation_angle(180); }
        // if(bn::keypad::l_pressed()) { f_cucumba.set_rotation_angle(270); }
        // if(bn::keypad::r_pressed()) { f_cucumba.set_rotation_angle(0);   }
        if(bn::keypad::b_pressed()) { f_cucumba.set_rotation_angle(330); }

        float f_anglex = bn::degrees_cos(f_cucumba.rotation_angle().to_float()).to_float();
        float f_angley = bn::degrees_sin(f_cucumba.rotation_angle().to_float()).to_float();
        //int f_angley = 0;//bn::abs(bn::sin(f_cucumba.rotation_angle().integer()).integer());
        f_startx = f_planet * f_anglex;
        f_starty = -f_planet * f_angley;

        if(bn::keypad::a_pressed())  { f_poonfiring = false; }
        if(bn::keypad::a_held())	 { 
        	f_poonx = f_startx-3; // - is temp
        	f_poony = f_starty-4; // - is temp
        	f_firex = bn::degrees_cos(f_cucumba.rotation_angle().round_integer()).round_integer();
        	f_firey = bn::degrees_sin(f_cucumba.rotation_angle().round_integer()).round_integer();
        	f_poon.set_rotation_angle(f_cumr);
        }
        if(bn::keypad::a_released()) { f_poonfiring = true; }

        // IT WORKS!! For Angle 330 it's good!! Now the attaching....
        if(f_poonfiring) { f_poonx += f_firex*2; f_poony -= f_firey*2; }
        //if(!f_poonfiring) {  }
        f_poon.set_position(f_poonx,f_poony);

        // Nana Flip
        bn::fixed nanar = f_banana.rotation_angle();
        if(bn::keypad::left_pressed())  { f_banana.set_horizontal_flip(true); }
        if(bn::keypad::right_pressed()) { f_banana.set_horizontal_flip(false); }
        if(bn::keypad::up_held()) {
        	f_banana.set_rotation_angle(bn::max(nanar - 30, bn::fixed(0))); 
			if(f_banana.rotation_angle() == 0) { 
				f_banana.set_rotation_angle(360);
			}
        }
        if(bn::keypad::up_released()) { f_banana.set_rotation_angle(0); }

        // Poon Dots / Wire
        f_dist = ocol.dist(fp.plyrx,fp.plyry,f_poonx,f_poony);
        f_dot1.set_position(fp.plyrx+f_poonx/1.3,fp.plyry+f_poony/1.3);
        f_dot2.set_position(fp.plyrx+f_poonx/2,fp.plyry+f_poony/2);
        f_dot3.set_position(fp.plyrx+f_poonx/4,fp.plyry+f_poony/4);
		f_dot1.set_tiles(bn::sprite_items::f_dot.tiles_item().create_tiles(ocol.distcheck(f_dist,2,f_poonfiring)));
		f_dot2.set_tiles(bn::sprite_items::f_dot.tiles_item().create_tiles(ocol.distcheck(f_dist,3,f_poonfiring)));
		f_dot3.set_tiles(bn::sprite_items::f_dot.tiles_item().create_tiles(ocol.distcheck(f_dist,4,f_poonfiring)));

        // Logging
        if(bn::keypad::select_pressed()) { 
        	BN_LOG("===============");
        	BN_LOG("Player Width: ",  fp.plyrw);
        	BN_LOG("Player X - Width: ",  fp.plyrx+fp.leftoffsetx-fp.plyrw+fp.leftoffsetw);
        	BN_LOG("Player X: ",  fp.plyrx);
        	BN_LOG("Player X + Width: ",  fp.plyrx+fp.plyrw+1);
        	BN_LOG("OBJ1 X: ",  fp.lvlt1x[0]);
        	BN_LOG("OBJ1 X + W: ",  fp.lvlt1x[0]+fp.lvlt1w[0]);
        	BN_LOG("OBJ2 X: ",  fp.lvlt1x[1]);
        	BN_LOG("OBJ2 X + W: ",  fp.lvlt1x[1]+fp.lvlt1w[1]);
        	// BN_LOG("Angle:    ",  f_cumr);
        	// BN_LOG("Dist:     ",  f_dist);
        	// BN_LOG("Aiming X: ",  f_startx);
        	// BN_LOG("Aiming Y: ",  f_starty);
        	/*
        	|<- OBJ1 X+W 	|
        	|		C 		|
        	|	   -X+		|
        	|	OBJ2 X ->	|left wall is adding by one on contact? hmmm
        	*/
    	}

		bn::core::update();
	}
}

int main() {
    bn::core::init();
    //bn::bg_palettes::set_transparent_color(bn::color(6, 10, 15));
    bn::bg_palettes::set_transparent_color(bn::color(8, 8, 11));
    // flip::poon fp;
    // fp.lvlt1debug(1);

    while(true) {
    	flipoon_advance();
        bn::core::update();
    }
};