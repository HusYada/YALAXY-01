#ifndef FLIPOON_H
#define FLIPOON_H

#include "bn_math.h"

// #include "bn_sprite_ptr.h"
// #include "bn_sprite_tiles_ptr.h"
// #include "bn_sprite_items_dot.h"

#include "collision.h"

namespace flip {
	class poon {

	colli::sion ocol;

	public:
		//int plyrx = 0; int plyry = 0; int plyrw = 8; int plyrh = 10; //int nanar = 1;
		int plyrx = -4; int plyry = -4; int plyrw = 8; int plyrh = 10; //int nanar = 1;
		//int bgx = 8; int bgy = -44;
		int bgx = 0; int bgy = 0;

		int leftoffsetx = -1;
		int leftoffsetw = -1;

						//0   1   2    3    4   5
		int lvlt1x[6] = {-118, 80,-118,-118, -42, -42};
		int lvlt1y[6] = { -71,-71, -71,  -9, -9 , 172};
		int lvlt1w[6] = {  15, 15, 310,  88, 15 , 160};
		int lvlt1h[6] = {  72,238,  15,  15, 240, 15};

		int fruitx[5] = { -118, 80,-118,-118, -42 };
		int fruity[5] = { -71,-71, -71,  -9, -9 };

		/*
		2->
		0-------1
		|		|
		3---4 	|
			|	|
			|	|
			|	|
			5---o
		*/

		void lvlt1debug(int showtiles); // ignore this for now

		bool lvlt1col_left() {
			if(!ocol.overlap(plyrx-plyrw+leftoffsetx,	plyry+1,leftoffsetw,plyrh-2,lvlt1x[0],lvlt1y[0],lvlt1w[0],lvlt1h[0])
			&& !ocol.overlap(plyrx-plyrw+leftoffsetx,	plyry+1,leftoffsetw,plyrh-2,lvlt1x[4],lvlt1y[4],lvlt1w[4],lvlt1h[4])) {
				return true;
			} else { return false; }
		}
		bool lvlt1col_right() {
			if(!ocol.overlap(plyrx+plyrw,	plyry+1,1,plyrh-2,lvlt1x[1],lvlt1y[1],lvlt1w[1],lvlt1h[1])) {
				return true;
			} else { return false; }
		}
		bool lvlt1col_up() {
			if(!ocol.overlap(plyrx+plyrw,	plyry+1,1,plyrh-2,lvlt1x[2],lvlt1y[2],lvlt1w[2],lvlt1h[2])) {
				return true;
			} else { return false; }
		}
		bool lvlt1col_down() {
			if(!ocol.overlap(plyrx+plyrw,	plyry+1,1,plyrh-2,lvlt1x[3],lvlt1y[3],lvlt1w[3],lvlt1h[3])
			&& !ocol.overlap(plyrx+plyrw,	plyry+1,1,plyrh-2,lvlt1x[5],lvlt1y[5],lvlt1w[5],lvlt1h[5])) {
				return true;
			} else { return false; }
		}
	};
};
#endif