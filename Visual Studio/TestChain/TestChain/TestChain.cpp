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
void generateTestHash()
{// function to test accuracy of sha256
	std::stringstream ss;
	ss << "password";
	std::cout << "TEST " + ss.str() + "\n";
	std::cout << sha256(ss.str());
}

void mining()
{//	manually mines three blocks 
 //	@TODO Blockchain need to continue / end automaticly 
 // @TODO Data need to be populated with votes users votes
	std::cout << "TEST: Mining Thread Initialized" << std::endl;
	Blockchain bChain = Blockchain();

	bChain.GenerateGenesis(Block(0, testVote.voterInitialStatus), testVote.voterInitialStatus);
	std::this_thread::sleep_for(std::chrono::seconds(45));
	for (int i = 1; i < 10; i++) 	{
		bChain.AddBlock(Block(i, testVote.unverifiedVotes), testVote.unverifiedVotes);
		if (testVote.unverifiedVotes != "")
		{
			testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
		}				
		testVote.unverifiedVotes = "";
		std::cout <<"VerifiedVotes\n" << testVote.verifiedVotes;
		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
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
	std::this_thread::sleep_for(std::chrono::seconds(45));*/}

void voting()
{//	Manually starts voting
	std::cout << "TEST: Vote Thread Initialized" << std::endl;
	testVote.initializeVoteCandidates();
	testVote.initializeValidVoterIDs();
	for (int i = 1; i < 50; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(5));
		testVote.voterLogin();
	}
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
