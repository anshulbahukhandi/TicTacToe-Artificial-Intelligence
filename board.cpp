#include"board.h"
using namespace std ; 

/* Initializing the only board object that exists*/
board board::mBoard;

board::board()
{
	for ( int i =0 ; i<3 ; i++)
			for ( int j=0 ; j < 3 ; j++)
				mMatrix[i][j]=NONE;
}

board::~board()
{

}

/* Function to display the board */
void board::display()
{
	for ( int i =0 ; i<3 ; i++)
	{
		cout<<" | ";
		for ( int j=0 ; j < 3 ; j++)
		{
			if(mMatrix[i][j]==-1)
				cout<<"  | ";
			else if(mMatrix[i][j]==1) cout<<"X  | ";
				else cout<<"O  | ";
		}
		cout<<endl;
		cout<<" --------------";
		cout<<endl;
	}

}

void board::set (const value& val, const int & row , const int & col )
{
	mMatrix[row][col]=val;
}

/* Function returns result from AI perspective . WIN means AI that is
   playing KNOT wins
*/

result board::checkGameState()
{
	if(
	   (mMatrix[0][0]==KNOT && mMatrix[1][0]==KNOT && mMatrix[2][0]==KNOT) ||
	   (mMatrix[0][1]==KNOT && mMatrix[1][1]==KNOT && mMatrix[2][1]==KNOT) ||
	   (mMatrix[0][2]==KNOT && mMatrix[1][2]==KNOT && mMatrix[2][2]==KNOT) ||
	   (mMatrix[0][0]==KNOT && mMatrix[0][1]==KNOT && mMatrix[0][2]==KNOT) ||
	   (mMatrix[1][0]==KNOT && mMatrix[1][1]==KNOT && mMatrix[1][2]==KNOT) ||
	   (mMatrix[2][0]==KNOT && mMatrix[2][1]==KNOT && mMatrix[2][2]==KNOT) ||
	   (mMatrix[0][0]==KNOT && mMatrix[1][1]==KNOT && mMatrix[2][2]==KNOT) ||
	   (mMatrix[0][2]==KNOT && mMatrix[1][1]==KNOT && mMatrix[2][0]==KNOT) 
	  )
		{return WIN;}
	if(
	   (mMatrix[0][0]==CROSS && mMatrix[1][0]==CROSS && mMatrix[2][0]==CROSS)||
	   (mMatrix[0][1]==CROSS && mMatrix[1][1]==CROSS && mMatrix[2][1]==CROSS)||
	   (mMatrix[0][2]==CROSS && mMatrix[1][2]==CROSS && mMatrix[2][2]==CROSS)||
	   (mMatrix[0][0]==CROSS && mMatrix[0][1]==CROSS && mMatrix[0][2]==CROSS)||
	   (mMatrix[1][0]==CROSS && mMatrix[1][1]==CROSS && mMatrix[1][2]==CROSS)||
	   (mMatrix[2][0]==CROSS && mMatrix[2][1]==CROSS && mMatrix[2][2]==CROSS)||
	   (mMatrix[0][0]==CROSS && mMatrix[1][1]==CROSS && mMatrix[2][2]==CROSS)||
	   (mMatrix[0][2]==CROSS && mMatrix[1][1]==CROSS && mMatrix[2][0]==CROSS)
	  ) 
		{return LOSS;}
	else return DRAW;	
}

board::board( const board& b )
{
	for ( int i =  0 ; i<3  ; i++)
		for ( int j=0 ; j<3 ; j++)
			this->mMatrix[i][j]=b.mMatrix[i][j];
}

void board::operator=( const board& b)
{

	for ( int i =  0 ; i<3  ; i++)
		for ( int j=0 ; j<3 ; j++)
			mMatrix[i][j]=b.mMatrix[i][j];
}

const int board::getLevel()
{
	int count=0; 
	for ( int i= 0 ;i<3 ; i++)
		for ( int j=0 ; j<3 ; j++)
			if(mMatrix[i][j]!=NONE)
				count++;

	return count; 
} 

int board::get(const int & x , const int & y)
{
	return mMatrix[x][y];
} 