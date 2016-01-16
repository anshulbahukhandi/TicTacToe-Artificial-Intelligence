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
			cout<<mMatrix[i][j]<<" | ";
		}
		cout<<endl;
		cout<<" ----------------";
		cout<<endl;
	}

}

void board::set (const value& val, const int & row , const int & col )
{
	mMatrix[row][col]=val;
}

