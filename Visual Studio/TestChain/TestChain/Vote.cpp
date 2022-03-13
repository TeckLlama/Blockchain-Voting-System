#include "Vote.h"
#include <conio.h>

void Vote::cinYesOrNo(std::string yNQuestion)
{// cinYesOrNo is used to get input of Y or N from user 
	do {// changed from cin to _getch to force input of one char 
		yesOrNo[0] = (char)0;
		std::cout << yNQuestion << "[Y/N] --> ";
		yesOrNo[0] = _getch();
		std::cout << yesOrNo[0] << std::endl;
		//std::cin >> yesOrNo[0];
	} while (/*std::cin.fail() ||*/ yesOrNo[0] != 'y' && yesOrNo[0] != 'n' && yesOrNo[0] != 'Y' && yesOrNo[0] != 'N');
	std::cin.ignore();
	
}
	

void Vote::initializeVoteCandidates()
{// Hard coded Vote and and Vote Candidates to be initilized in Genesis block
 // @TODO implement function for Admin to set voteText and votevoteCandidates before Genesis is created 
	voteText = "Please choose from the candidates listed bellow and input [A/B/C/D]";
	voteCandidateA = "Labour";
	voteCandidateB = "Conservative";
	voteCandidateC = "Liberal Democrat";
	voteCandidateD = "Plaid Cymru";
}
void Vote::initializeValidVoterIDs()
{// Hard coded Valid Voter IDs to be initilized in Genesis block
 // @TODO implement function for Admin to set ValidVoterIDs/ Public Keys 
	voterStatus = "VoterID#1,1\nVoterID#2,1\nVoterID#3,1\nVoterID#4,1\nVoterID#5,1\nVoterID#6,1\nVoterID#7,1\nVoterID#8,1\nVoterID#9,1\nVoterID#10,1";
}
void Vote::userInputVote()
{// User Input of thier vote using A/B/C/D 
	do {// changed from cin to _getch to force input of one char 
		userInputVoteChar[0] = (char)0;
		std::cout << voteText << std::endl;
		std::cout << "Candidate A: " << voteCandidateA << std::endl;
		std::cout << "Candidate B: " << voteCandidateB << std::endl;
		std::cout << "Candidate C: " << voteCandidateC << std::endl;
		std::cout << "Candidate D: " << voteCandidateD << std::endl;
		std::cout << "Please enter which Candidate you want to vote for [A/B/C/D] --> ";
		userInputVoteChar[0] = _getch();
		std::cout << userInputVoteChar[0] << std::endl;
		//std::cin >> userInputChar;
	} while (/*std::cin.fail() ||*/ userInputVoteChar[0] != 'a' && userInputVoteChar[0] != 'b' && userInputVoteChar[0] != 'c' && userInputVoteChar[0] != 'd' && userInputVoteChar[0] != 'A' && userInputVoteChar[0] != 'B' && userInputVoteChar[0] != 'C' && userInputVoteChar[0] != 'D');
	std::cin.ignore();
	std::cout << "TEST: Accepted User input Char " << userInputVoteChar[0] << std::endl;
	cinYesOrNo("Your choice can NOT be changed after this are you sure? ");
	if (yesOrNo[0] == 'Y' || yesOrNo[0] == 'y')
	{
		voteTime = time(nullptr);
		std::stringstream voteTimeSS;
		voteTimeSS << voteTime;
		voteTimeString = voteTimeSS.str();;
		if (unverifiedVotes == "")
		{
			unverifiedVotes += userVoterID + "," + userInputVoteChar[0] + "," + voteTimeString;
		}
		else {
			unverifiedVotes += "\n" + userVoterID + "," + userInputVoteChar[0] + "," + voteTimeString;
		}		
		std::cout << "Your input has been saved and will be added to the next block verified at this node" << std::endl;
		//std::cout << "TEST: unverifiedVotes Current Value " << unverifiedVotes << std::endl;
	}	
	if (yesOrNo[0] == 'N' || yesOrNo[0] == 'n')
	{
		userInputVote();
	}	
}

void Vote::checkVoterStatus(std::string voterID)
{// Skeleton function to verify voter status  
 //	**ONLY checks input is not empty**
 // @TODO Verify VoterID is valid
 // @TODO Verify VoterID Vote has not been used with allVoterStatus
	if (voterID == "") {
		std::cout << "ERROR: Input Voter ID Empty";
		voterLogin();
	}
}
void Vote::voterLogin()
{// Logs user in using VoterID 
 // @TODO Implement Public and Private Keys 
	std::cout << "Please enter your Voter ID --> ";
	std::cin >> userVoterID;
	checkVoterStatus(userVoterID);
	userInputVote();
}
