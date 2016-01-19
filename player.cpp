#include"player.h"
using namespace std; 

/* Initializig the AI player "phenom"*/
player player::mPhenom; 

player::~player()
{
	cout<<"Phenom(AI) is leaving the game ! \n";
}
player::player()
{
	cout<<"Phenom(AI) is entering the game . Good Luck! \n";
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
	if(b.checkGameState()==LOSS)
		{	
		return LOSS;
		}
	/* This function will play KNOT or AI's moves */
	if(b.getLevel()==9)
		{
			return DRAW;
		}
	else 
	{
		/* if found winning move in next step . Prune everything else
           It stops the process of finding the suitable move as soon 
           as the winning move is found.
		*/ 
		bool flag=false;
		/* Saves the current best coordinate/Box in the current state*/
		int *coord=new int[2];

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
						if(res>=finalResult)
						{
							coord[0]=i;
							coord[1]=j;
							finalResult=res;
							
							if(res==WIN)
							{
								flag=true;
								break;
							}
						}
					}
				}
				if(flag==true)
					break;
			}

		p.r=coord[0];
		p.c=coord[1];	

	return finalResult;
	}
}


result player::mini( pos& p , board& b )
{
	if(b.checkGameState()==WIN)
		return WIN;
	else
	{
		result finalResult=WIN;
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
					
					result res=max(p ,tempBoard);
					if(res<finalResult)
						{
							finalResult=res; 

						}
				}
			}
		}
		return finalResult;
	}
}

void player::test(board& b)
{
	pos p ;
	max(p,b);
	b.set(KNOT , p.r , p.c);
	
}







