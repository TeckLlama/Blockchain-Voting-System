// TestChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <mutex>
#include "Blockchain.h"
#include "Vote.h"
#include "sha256.h"

std::mutex vote_mutex;
Vote testVote = Vote();

bool stopVotingThread = false;
bool stopMiningThread = false;
char menuChar;


void generateTestHash()
{// function to test accuracy of sha256
	std::stringstream ss;
	ss << "password";
	std::cout << "Test Main.cpp: " + ss.str() + "\n";
	std::cout << sha256(ss.str());
}



void voting()
{//	Manually starts voting
	std::cout << "Test Main.cpp: Vote Thread Initialized" << std::endl;	
	testVote.initializeVoteCandidates();
	std::unique_lock<std::mutex> ulVM(vote_mutex);
	testVote.initializeValidVoterIDs();
	ulVM.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	while (!stopVotingThread) {		
		std::unique_lock<std::mutex> ulVM(vote_mutex);
		testVote.voterLogin();
		ulVM.unlock();		
		std::this_thread::sleep_for(std::chrono::seconds(5));

		if (stopVotingThread == true) {
			stopMiningThread = true;
			std::cout << "Test Main.cpp: stopMiningThread set to true" << std::endl;
			std::cout << "Test Main.cpp: Vote Thread Exited" << std::endl;			
			return;
		}		
	}	
	
}
void mining()
{//	Mines the number of blocks allocated in the for loop at end of loop Voting Thread 
 // Set to close after any inprogress votes are made then one additional block is mined 

	std::cout << "Test Main.cpp: Mining Thread Initialized" << std::endl;
	
	Blockchain bChain = Blockchain();
	std::unique_lock<std::mutex> ulVM(vote_mutex);
	bChain.GenerateGenesis(Block(0, testVote.voterInitialStatus), testVote.voterInitialStatus);
	ulVM.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	int blockIndex;
	for (blockIndex = 1; blockIndex <= 3; blockIndex++) {		
		std::unique_lock<std::mutex> ulVM(vote_mutex);
		std::cout <<"Test Main.cpp: Loop Index "<< blockIndex;
		bChain.AddBlock(Block(blockIndex, testVote.unverifiedVotes), testVote.unverifiedVotes);
		if (testVote.unverifiedVotes != "")
		{
			testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
		}
		testVote.unverifiedVotes = "";
		ulVM.unlock();
		//std::cout << "Test Main.cpp: VerifiedVotes\n" << testVote.verifiedVotes << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(15));		
	}
	stopVotingThread = true;
	std::cout << "\nTest Main.cpp: stopVotingThread set to true" << std::endl;
	while (stopMiningThread== false) {
		std::this_thread::sleep_for(std::chrono::seconds(15));
		if (stopMiningThread == true) {
			bChain.AddBlock(Block(blockIndex+1, testVote.unverifiedVotes), testVote.unverifiedVotes);
			if (testVote.unverifiedVotes != "")
			{
				testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
				testVote.unverifiedVotes = "";
			}			
			if (stopVotingThread && stopMiningThread == true) {
				testVote.totalVerifiedVotes();
				bChain.AddBlock(Block(blockIndex + 2, testVote.voteBreakdown), testVote.voteBreakdown);
				
			}
			std::cout << "Test Main.cpp: VerifiedVotes\n" << testVote.verifiedVotes<< std::endl;;
			std::cout << "Test Main.cpp: Mining Thread Exited" << std::endl;
			return;
		}
	}	
	
}

int main()
{
	SetConsoleTitleA("VoteChain");
	
	//generateTestHash();

	do {// changed from cin to _getch to force input of one char 
		menuChar = (char)0;		
		std::cout << "[A] Start Voting [A]"  << std::endl;
		std::cout << "[B] Empty        [B]" << std::endl;
		std::cout << "[C] Exit         [C]" <<  std::endl;
      //std::cout << "[D] Exit         [D]" << std::endl;
		
		std::cout << "Press A to Initilize Vote or [A/B/C] --> ";
		menuChar = _getch();
		std::cout << menuChar << std::endl;
		menuChar = toupper(menuChar);
		//std::cin >> userInputChar;
	} while (/*std::cin.fail() ||*/ menuChar != 'A' && menuChar != 'B' && menuChar != 'C' /* && menuChar != 'D'*/);
	std::cout << "Test Vote.cpp: Accepted User input Char " << menuChar << std::endl;
	if (menuChar == 'A') {
		std::thread voteingThread(voting);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::thread miningThread(mining);
		voteingThread.join();
		miningThread.join();
		//if (stopVotingThread && stopMiningThread == true) {
		//	testVote.totalVerifiedVotes();
		//}
	}
	if (menuChar == 'B') {
		return 2;
	}
	if (menuChar == 'C') {
		return 2;
	}
    return 0;
}
