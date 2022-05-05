// Author: Elliot Rihan
// Created: 12/02/22
// Last Modified Date: 05/05/22
// Description: VoteChain: A C++ program that receives Votes and stores data within a Blockchain.
// VoteChain.cpp: This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <mutex>
#include "Blockchain.h"
#include "Vote.h"
#include "sha256.h"

std::mutex voteVC_mutex;
Vote testVote = Vote();
bool stopVotingThread = false;
bool stopMiningThread = false;

void generateTestHash()
{// Function to test accuracy of sha256.cpp
	std::cout << "\nTest Main.cpp: generateTestHash Started" << std::endl;
	std::stringstream ss;
	ss << "password";
	std::cout << "Test Hash: " << ss.str() << std::endl;
	std::cout << "SHA256 Hash: " << sha256(ss.str()) << std::endl;
	ss.str("");
	ss << "passWORD";
	std::cout << "Test Hash: " << ss.str() << std::endl;
	std::cout << "SHA256 Hash: " << sha256(ss.str()) << std::endl;
	ss.str("");
	ss << "9000password1000";
	std::cout << "Test Hash: " << ss.str() << std::endl;
	std::cout << "SHA256 Hash: " << sha256(ss.str()) << std::endl;
	ss.str("");
	ss << "--he//0w@r1d--";
	std::cout << "Test Hash: " << ss.str() << std::endl;
	std::cout << "SHA256 Hash: " << sha256(ss.str()) << std::endl;
	ss.str("");
	ss << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	std::cout << "Test Hash: " << ss.str() << std::endl;
	std::cout << "SHA256 Hash: " << sha256(ss.str()) << std::endl;
}

void voting()
{//	Voting Thread
	std::cout << "Test Main.cpp: Vote Thread Initialized" << std::endl;
	testVote.initializeVoteCandidates();
	std::unique_lock<std::mutex> ulVM(voteVC_mutex);
	testVote.initializeValidVoterIDs();
	ulVM.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(6));
	while (!stopVotingThread) {
		std::unique_lock<std::mutex> ulVM(voteVC_mutex);
		testVote.voterLogin();
		ulVM.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(2));
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
	std::unique_lock<std::mutex> ulVM(voteVC_mutex);
	bChain.generateGenesisBlock(Block(0, testVote.voterInitialStatus), testVote.voterInitialStatus);
	ulVM.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	int blockIndex;
	for (blockIndex = 1; blockIndex < 11; blockIndex++) {
		//std::cout << "\nTest Main.cpp: blockIndex " << blockIndex << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(120));
		std::unique_lock<std::mutex> ulVM(voteVC_mutex);
		std::cout << "\nTest Main.cpp: Mining Block: " << blockIndex << std::endl;
		bChain.addNewBlock(Block(blockIndex, testVote.unverifiedVotes), testVote.unverifiedVotes);
		if (testVote.unverifiedVotes != "")
		{
			testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
		}
		testVote.unverifiedVotes = "";
		std::cout << "Test Main.cpp: Block " << blockIndex << " successfully mined\n" << std::endl;
		ulVM.unlock();
		//std::cout << "Test Main.cpp: VerifiedVotes\n" << testVote.verifiedVotes << std::endl;
	}
	stopVotingThread = true;
	std::cout << "\nTest Main.cpp: stopVotingThread set to true" << std::endl;
	while (stopMiningThread == false) {
		std::this_thread::sleep_for(std::chrono::seconds(15));
		if (stopMiningThread == true) {
			std::unique_lock<std::mutex> ulVM(voteVC_mutex);
			bChain.addNewBlock(Block(blockIndex, testVote.unverifiedVotes), testVote.unverifiedVotes);
			if (testVote.unverifiedVotes != "")
			{
				testVote.verifiedVotes += testVote.unverifiedVotes + "\n";
				testVote.unverifiedVotes = "";
			}
			ulVM.unlock();
			if (stopVotingThread && stopMiningThread == true) {
				testVote.totalVerifiedVotes();
				bChain.addNewBlock(Block(blockIndex + 1, testVote.voteBreakdown), testVote.voteBreakdown);
			}
			std::cout << "Test Main.cpp: VerifiedVotes\n" << testVote.verifiedVotes << std::endl;;
			std::cout << "Test Main.cpp: Mining Thread Exited" << std::endl;
			return;
		}
	}
}

int main()
{
	char menuChar;
	SetConsoleTitleA("VoteChain");
	do {// changed from cin to _getch to force input of one char 
		menuChar = (char)0;
		std::cout << "[A] Start Voting [A]" << std::endl;
		std::cout << "[B] Test Hash    [B]" << std::endl;
		std::cout << "[C] Exit         [C]" << std::endl;
		//std::cout << "[D] Exit         [D]" << std::endl;
		std::cout << "Press A to Initilize Vote or [A/B/C] --> ";
		menuChar = _getch();
		std::cout << menuChar << std::endl;
		menuChar = toupper(menuChar);		
	} while (menuChar != 'A' && menuChar != 'B' && menuChar != 'C');
	//std::cout << "Test Main.cpp: Accepted User input Char " << menuChar << std::endl;
	if (menuChar == 'A') {
		std::thread voteingThread(voting);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::thread miningThread(mining);
		voteingThread.join();
		miningThread.join();
	}
	if (menuChar == 'B') {
		generateTestHash();
		std::this_thread::sleep_for(std::chrono::seconds(10));
		return 2;
	}
	if (menuChar == 'C') {
		return 2;
	}
	return 0;
}