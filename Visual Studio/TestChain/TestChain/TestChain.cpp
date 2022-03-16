// TestChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Blockchain.h"
#include "Vote.h"
#include "sha256.h"


Vote testVote = Vote();

bool stopVotingThread = false;
bool stopMiningThread = false;


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
	testVote.initializeValidVoterIDs();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	while (!stopVotingThread) {
		//for (int i = 1; i < 15; i++) {
		testVote.voterLogin();
		std::this_thread::sleep_for(std::chrono::seconds(5));
		if (stopVotingThread == true) {
			stopMiningThread = true;
			std::cout << "Test Main.cpp: stopMiningThread set to true" << std::endl;
			std::cout << "Test Main.cpp: Vote Thread Exited" << std::endl;			
			return;
		}
		
		
	}
	//}
	
	/*stopMiningThread = true;
	std::cout << "Test: stopMiningThread set to true" << std::endl;*/
	// Old Manual Voting for 5 users
	/*std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	testVote.voterLogin();*/
}
void mining()
{//	manually mines three blocks 
 //	@TODO Blockchain need to continue / end automaticly 
 // @TODO Data need to be populated with votes users votes
	std::cout << "Test Main.cpp: Mining Thread Initialized" << std::endl;
	
	Blockchain bChain = Blockchain();
	bChain.GenerateGenesis(Block(0, testVote.voterInitialStatus), testVote.voterInitialStatus);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	int blockIndex;
	for (int i = 1; i < 5; i++) {
		blockIndex = i;
		bChain.AddBlock(Block(i, testVote.unverifiedVotes), testVote.unverifiedVotes);
		if (testVote.unverifiedVotes != "")
		{
			testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
		}
		testVote.unverifiedVotes = "";
		//std::cout << "Test Main.cpp: VerifiedVotes\n" << testVote.verifiedVotes << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(15));
		/*if (stopMiningThread == true) {
			bChain.AddBlock(Block(i+1, testVote.unverifiedVotes), testVote.unverifiedVotes);
			if (testVote.unverifiedVotes != "")
			{
				testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
			}
			testVote.unverifiedVotes = "";
			std::cout << "Test: VerifiedVotes\n" << testVote.verifiedVotes;
			return;
		}*/
	}
	stopVotingThread = true;
	std::cout << "Test Main.cpp: stopVotingThread set to true" << std::endl;
	while (stopMiningThread== false) {
		std::this_thread::sleep_for(std::chrono::seconds(15));
		if (stopMiningThread == true) {
			blockIndex = blockIndex + 1;
			bChain.AddBlock(Block(blockIndex, testVote.unverifiedVotes), testVote.unverifiedVotes);
			if (testVote.unverifiedVotes != "")
			{
				testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
			}
			testVote.unverifiedVotes = "";
			std::cout << "Test Main.cpp: VerifiedVotes\n" << testVote.verifiedVotes<< std::endl;;
			std::cout << "Test Main.cpp: stopVotingThread set to true" << std::endl;
			std::cout << "Test Main.cpp: Mining Thread Exited" << std::endl;
			return;
		}
	}
	
	
	//exit;
	// Old Manual mining of 5 Blocks
	/*bChain.AddBlock(Block(1, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(std::chrono::seconds(45));
	bChain.AddBlock(Block(2, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(std::chrono::seconds(45));
	bChain.AddBlock(Block(3, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(std::chrono::seconds(45));
	bChain.AddBlock(Block(4, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(std::chrono::seconds(45));
	bChain.AddBlock(Block(5, testVote.unverifiedVotes), testVote.unverifiedVotes);
	testVote.unverifiedVotes = "";
	std::this_thread::sleep_for(std::chrono::seconds(45));*/
}

int main()
{
	SetConsoleTitleA("Testchain");
	
	//generateTestHash();

	std::thread voteingThread(voting);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread miningThread(mining);
	voteingThread.join();
	miningThread.join();
	
	
    return 0;
}
