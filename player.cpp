#include"player.h"
using namespace std; 

/* Initializig the AI player "phenom"*/
player player::mPhenom; 

player::~player()
{

}

player::player()
{

}

void player::play()
{
	pos p ; 
	board& b=board::getBoard();
	max(p,b);
	b.set(KNOT , p.r,p.c);
}
result  player::max(pos& p , board& b)
{
	/* This function will play KNOT or AI's moves 
	*/


	if(b.getLevel()==9)
		return DRAW;
	else 
	{
		result finalResult = LOSS;
		for ( int i=0 ; i<3 ; i++)
			{
				for ( int j=0 ; j<3 ; j++)
				{
					
					if(b.mMatrix[i][j]==NONE)
					{

						board tempBoard=b;
						tempBoard.mMatrix[i][j]=KNOT;
						result res=mini(p ,tempBoard);
						if(res > finalResult)
							{
								finalResult=res;
								p.r=i; p.c=j;
								//you can even break if its a win to implement alpha beta pruning
							}	
					}
				}
			}		
	}

}


result player::mini( pos& p , board& b )
{
	if(b.checkGameState()==WIN)
		return WIN;

	else
	{
			/*	This Function will simulate Human moves and try to reduce the score
				Human will go for the move by which he can win*/
		for ( int i=0  ;i<3 ; i++)
		{
			for ( int j=0 ; j<3 ; j++)
			{
				board tempBoard=b; 
				if(tempBoard.mMatrix[i][j]==NONE)
				{
					tempBoard.mMatrix[i][j]=CROSS;
					if(tempBoard.checkGameState()==LOSS)
						return LOSS;
					else
					{
						result res=max(p ,tempBoard);
						return res;
					}
				}
			}
		}
	}

}









