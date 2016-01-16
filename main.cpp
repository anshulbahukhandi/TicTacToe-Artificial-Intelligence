#include"board.cpp"
#include<iostream>

using namespace std; 

int main()
{
	board& b= board::getInstance(); 
	b.display();
	return 0;
}