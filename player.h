
/* Name : Anshul Bahukhandi
   Date : 1/17/2016
   
   This is the player or the AI that will play the game
   This is also made singleton as only one AI will play against 
   the human opponent

   Moreover AI never starts the game . Human player is given 
   first chance . 
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
public:

static player& getPlayer()
{
	return mPhenom;
}
void play();
/* Only thing phenom will do is make his move*/
result max(pos&, board&);

~player();

/*  Function for testing and debugging purpose
	You can create your own test case and input 
	using this function to see how AI will respond*/
void test(board&);

private:

/* only AI player " phenom " that will play the game*/
static player mPhenom; 
/* Disallowing constructor , copy constructor  and assignment operator*/
player();
player(player&);
player& operator=(const player&);

/*  Fucntions that takes computations to depeer level
	It is made private because only AI will use it to 
	see into deeper levels and evaluate the move.
*/
result  mini(pos& , board& );

};

#endif   


