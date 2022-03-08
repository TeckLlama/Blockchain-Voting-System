#pragma once
#include <iostream>
//#include <ctype.h>

class Vote{
public:
	//std::string voteText;
	char yesOrNo;
	void cinYesOrNo(std::string yNQuestion);


	std::string voteText;
	std::string voteCandidateA;
	std::string voteCandidateB;
	std::string voteCandidateC;
	std::string voteCandidateD;
	void initializeVoteCandidates();

	std::string voterStatus;
	void initializeValidVoterIDs();

	char userInputChar;
	std::string unverifiedVotes;
	void userInputVote();

	void checkVoterStatus(std::string voterID);

	std::string userVoterID;
	void voterLogin();


private:

	time_t _tTime;
};

