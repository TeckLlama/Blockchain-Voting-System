// TestChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Blockchain.h"
#include "Vote.h"

Vote testVote = Vote();


//
using namespace std::chrono_literals;
void mining()
{//	manually mines three blocks 
 //	@TODO Blockchain need to continue / end automaticly 
 // @TODO Data need to be populated with votes users votes
	
	Blockchain bChain = Blockchain();
	std::this_thread::sleep_for(45000ms);
	
	
	//std::cout << "TEST: unverifiedVotes Value Before Block  " << testVote.unverifiedVotes << std::endl;
	bChain.AddBlock(Block(1, testVote.unverifiedVotes), testVote.unverifiedVotes);
	//std::cout << "TEST: unverifiedVotes Value After Block  " << testVote.unverifiedVotes << std::endl;
	testVote.unverifiedVotes = "";
	//std::cout << "TEST: unverifiedVotes Value After Reset  " << testVote.unverifiedVotes << std::endl;
	std::this_thread::sleep_for(45000ms);
	bChain.AddBlock(Block(2, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(45000ms);
	bChain.AddBlock(Block(3, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(45000ms);
	bChain.AddBlock(Block(4, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(45000ms);
	bChain.AddBlock(Block(5, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(45000ms);
}

void voting()
{//	Manually starts voting


	std::cout << "TEST: Vote Thread Initialized" << std::endl;
	testVote.initializeVoteCandidates();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();
	std::this_thread::sleep_for(5000ms);
	testVote.voterLogin();

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
		//mining(testVote);
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
	return 0;
}


int main()
{
	SetConsoleTitleA("Testchain");
	
	std::thread voteingThread(voting);
	std::thread miningThread(mining);
	miningThread.join();
	voteingThread.join();
	
    
	
	//menu();
	  

    return 0;
}
