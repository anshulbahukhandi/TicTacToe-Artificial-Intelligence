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
		enum result { LOSS=-1 , WIN =1 , DRAW=0};

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
		void operator=( const board&);

		friend class player;
	public :
		/* This function sets a vlue at a partiular position 
		   in the board.
		*/
		void set (const value& , const int & , const int &  );

		/* Function to return the value of any element of matrix*/
		int get(const int& , const int &);
		
		/* Function to return at what level the board is being played*/
		const int getLevel();
		
		~board();
		
		/*Displays the board*/
		void display();
		
		/* Tells if the game has ended or not */
		result checkGameState(); 
		
		/*Function to return the only board that exists*/
		static board& getBoard()
		{
			return mBoard;
		}
	}; 

   #endif