#ifndef COLLISION_H
#define COLLISION_H

#include "bn_math.h"

namespace colli
{
class sion
{

	public:

		//This function checks if the player object and other object are overlapping or not
		// x1 + w1 = top side of the player
		// x2 && x1 = contact between the left side of both shapes
		// x2 + w2 = left side of the player
		// y1 + h1 = left side of the other shape
		// y2 && y1 = contact between the top side of both shapes
		// y2 + h2 = top side of other shape
  
		bool overlap(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {

			// The if statement checks to see if two objects are overlapping; 
			// If so, it returns true, else it returns false   
			if (x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2) {
				return true;
			}
			else { return false; }
		}

		int dist(int x1, int y1, int x2, int y2) {
			// d=√((x2 – x1)² + (y2 – y1)²)
			//int distance = bn::sqrt(bn::abs(((x2-x1)^2) + ((y2-y1)^2)));
			int d = bn::abs(((x2-x1)^2) + ((y2-y1)^2));
			int distance = bn::sqrt(d);
			return distance;
		}

		int distcheck(int distfull, int distportion, bool firing) {
			int spritetile;
			if(distfull > distportion && firing) { spritetile = 1; }
			else { spritetile = 0; }
			return spritetile;
		}
	};
};
#endif