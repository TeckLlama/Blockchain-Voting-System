#pragma
//#ifndef TESTCHAIN_VOTE_H
//#define TESTCHAIN_VOTE_H
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <conio.h>
#include <regex>
//#include <ctype.h>

class Vote{

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
	void checkVoterStatus(std::string voterID);

	std::string userVoterID;
	void checkVoteID(std::string voteID);

	void voterLogin();


private:

	
};

//#endif //TESTCHAIN_VOTE_H