// Author: Elliot Rihan
// Created: 15/02/22
// Last Modified Date: 05/05/22
// Description: C++ Header file for the Vote Class that handles user voting input. For use with Vote.cpp.
// Vote.h: This file declares the libraries, functions and variables used in the Vote Class.
#pragma
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <conio.h>
#include <regex>
#include <cctype>
#include <mutex>

class Vote {
public:
	//std::string voteText;
	char yesOrNo[2];
	void cinYesOrNo(std::string yNQuestion);
	std::string voteText;
	std::string voteCandidateA;
	std::string voteCandidateB;
	std::string voteCandidateC;
	std::string voteCandidateD;
	void initializeVoteCandidates();
	std::string voterInitialStatus;
	void initializeValidVoterIDs();
	std::string userPrivateKey;
	void userSignVote();
	char userInputVoteChar[2];
	std::string newVote;
	time_t voteTime;
	std::string voteTimeString;
	std::string unverifiedVotes;
	std::string verifiedVotes;
	void userInputVote();
	bool voterStatus;
	void checkVoterStatus(std::string voterID);
	std::string userVoterID;
	void checkVoteID(std::string voteID);
	void voterLogin();
	std::string voteBreakdown;
	int totalVotesA = 0;
	int totalVotesB = 0;
	int totalVotesC = 0;
	int totalVotesD = 0;
	int totalVotes = 0;
	void totalVerifiedVotes();
private:

};