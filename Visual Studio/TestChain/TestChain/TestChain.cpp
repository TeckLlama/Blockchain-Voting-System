// TestChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include "Blockchain.h"
#include "Vote.h"

Vote testVote = Vote();


void mining(Vote testVote) 
{//	manually mines three blocks 
 //	@TODO Blockchain need to continue / end automaticly 
 // @TODO Data need to be populated with votes users votes
	Blockchain bChain = Blockchain();

	//bChain.AddBlock(Block(1, "Block 1 Data"));
	bChain.AddBlock(Block(1, testVote.unverifiedVotes),testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	bChain.AddBlock(Block(2, testVote.unverifiedVotes), testVote.unverifiedVotes);

	bChain.AddBlock(Block(3, "Block 3 Data"),"Block 3 Data");
}
void voting() 
{//	Manually starts voting
	std::cout << "TEST VOTING" << std::endl;
	testVote.initializeVoteCandidates();
	testVote.voterLogin();
	//testVote.userInputVote(); NOW CALLED at end of testVotevoterLogin();
}

int menu() 
{//	inputChar used to navigate menu only accepts M/V/E as input 
	char inputChar;
	do {
		std::cout << "\nTest Mining, Test Voting or Exit[M/V/E] --> ";
		std::cin >> inputChar;
	} while (std::cin.fail() || inputChar != 'm' && inputChar != 'v' && inputChar != 'e' && inputChar != 'M' && inputChar != 'V' && inputChar != 'E');
	std::cin.ignore();
	if (inputChar == 'm' || inputChar == 'M')
	{
		mining(testVote);
		menu();
	}
	else if (inputChar == 'v' || inputChar == 'V')
	{
		voting();
		menu();
	}
	else if (inputChar == 'e' || inputChar == 'E')
	{// if user chooses exit out return 0 will close program 
		
		return 0;
	}
	else {
		return 0;
	}
}


int main()
{
    SetConsoleTitleA("Testchain");
	
	menu();
	  

    return 0;
}
