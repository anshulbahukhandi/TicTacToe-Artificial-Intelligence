/* This is the player or the AI that will play the game
   This is also made singleton as only one AI will play against 
   the human opponent
*/
 /* Moreover AI never starts the game . Human player is given 
    first chance . Otherwise human will never ever win.
    AI places KNOT  , Human places CROSS
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include<iostream>
#include<fstream>

struct pos
{
	int r; //row
	int c; //column
};

class player
{
	/* only AI player " phenom " that will play the game*/
	static player mPhenom; 

public:
static player& getPlayer()
{
	return mPhenom;
}
void play();
/* Only thing phenom will do is make his move*/
	result max(pos&, board&);
	~player();
private:
	/* Disallowing constructor , copy constructor  and assignment operator*/
	player();
	player(player&);
	player& operator=(const player&);
	/* Fucntions that takes computations to depeer level*/
	result  mini(pos& , board& );
};

#endif   


