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

		// changing w1 makes no difference
		int lvlt1x[4] = {-118,104,-119,  0};
		//int lvlt1x[4] = {-49,49,-119,  0};
		int lvlt1y[4] = { -79,-79,  68,-79};
		int lvlt1w[4] = {  15, 15, 238, 33};
		int lvlt1h[4] = { 158,158,  33, 11};

		void lvlt1debug(int showtiles); // ignore this for now

		bool lvlt1col_left() {
			if(!ocol.overlap(plyrx-plyrw+leftoffsetx,	plyry+1,leftoffsetw,plyrh-2,lvlt1x[0],lvlt1y[0],lvlt1w[0],lvlt1h[0])
			&& !ocol.overlap(plyrx-plyrw+leftoffsetx,	plyry+1,leftoffsetw,plyrh-2,lvlt1x[1],lvlt1y[1],lvlt1w[1],lvlt1h[1])) {
				return true;
			} else { return false; }
		}
		bool lvlt1col_right() {
			if(!ocol.overlap(plyrx+plyrw,	plyry+1,1,plyrh-2,lvlt1x[0],lvlt1y[0],lvlt1w[0],lvlt1h[0])
			&& !ocol.overlap(plyrx+plyrw,	plyry+1,1,plyrh-2,lvlt1x[1],lvlt1y[1],lvlt1w[1],lvlt1h[1])) {
				return true;
			} else { return false; }
		}
	};
};
#endif