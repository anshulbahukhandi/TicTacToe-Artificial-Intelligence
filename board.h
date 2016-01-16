/* Tic Tac Toe Game Board 
   Name : Anshul Bahukhandi
   Date : 1/15/2016
 
   This is a singleton class so that there is only one 
   board that exists 
 */

   #ifndef BOARD_H_
   #define BOARD_H_

   #include<iostream>
   #include<fstream>

   /* Matrix can have only these two values*/
		enum value { KNOT=0 , CROSS=1 , NONE = -1};

	class board
	{
	private :
		/* This is the only board object that will exist at a time */
		static  board mBoard; 

		value mMatrix[3][3];
		/*Constructor disallowed*/
		board();  
		/*Copy constructor disallowed*/
		board( const board& ); 
		/*Assignment operator disallowed*/
		board& operator=( board&); 
		/* This function sets a vlue at a partiular position 
		   in the board.
		   It is made private because only player can set the 
		   board elements
		*/
		void set (const value& , const int & , const int &  );

		friend class player;
	public : 
		/*Function to return the only board that exists*/
		static board& getInstance()
		{
			return mBoard;
		}
		
		~board();
		/*Displays the board*/
		void display();

	}; 

   #endif