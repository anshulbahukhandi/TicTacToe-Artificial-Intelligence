
/*
  Name : Anshul Bahukhandi
  Date : 1/17/2016
 
 */ 


#include"board.cpp"
#include"player.cpp"
#include<iostream>
#include<string>
using namespace std; 

int main()
{
	board& b= board::getBoard(); 
	player& p = player::getPlayer();
 	
	char name[30]; 
	cout<<"Enter your name: ";
	cin.getline(name,30); 

	b.display();
	cout<<endl;
	while(true)
	{	
		if(b.getLevel()==9 )
		{
			cout<<"Game is a Draw!!.\n";
			break;
		}
		if((b.getLevel()+1)%2!=0)
		{
			int x,y;
			/*Human turn*/
			while(true)
			{
				cout<<"Your turn. Enter the row-column number : ";
				cin>>x>>y;

				if(b.get(x-1 , y-1)== -1 )
					break;
				else
					cout<<"Place Aready Filled. Renter\n ";		
			}
			b.set(CROSS,x-1,y-1);
			b.display();
			cout<<endl;
			if(b.checkGameState()==LOSS)
			{
				cout<<endl<<name<<" has won the game .  !\n";
				break;
			}
		}
		else 
		{
			p.play();
			b.display();
			cout<<endl;
			if(b.checkGameState()==WIN)
			{
				cout<<endl<<" AI \" phenom\" has won the game!\n";
				break;
			}	
		}
	}
	return 0;
}