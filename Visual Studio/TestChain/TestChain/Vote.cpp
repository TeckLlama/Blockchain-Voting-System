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
	
	std::cout << "TEST: Accepted User input Char " << yesOrNo[0] << std::endl;
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
	voterInitialStatus = "VoterID#1,1,1647255894\nVoterID#2,1,1647255895\nVoterID#3,1,1647255896\nVoterID#4,1,1647255897\nVoterID#5,1,1647255898\nVoterID#6,1,1647255899\nVoterID#7,1,1647256077\nVoterID#8,1,1647256078\nVoterID#9,1,1647256079\nVoterID#10,1,1647256080";
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
		voterLogin();
	}	
	if (yesOrNo[0] == 'N' || yesOrNo[0] == 'n')
	{
		userInputVote();
	}	

}

void Vote::checkVoterStatus(std::string voterID)
{// Checks if VoterID has used there vote in unverifiedVotes, verifiedVotes and checks if is in Initial Status
 
	std::istringstream unverifiedVotesSS(unverifiedVotes);
	std::string lineUnverifiedVotesSS;
	while (std::getline(unverifiedVotesSS, lineUnverifiedVotesSS)) {
		//std::cout << line << std::endl;
		if (lineUnverifiedVotesSS.find(voterID) != std::string::npos)
		{
			//std::cout << line << std::endl;
			std::cout << "Valid Voter ID: " << voterID << std::endl;
			std::cout << "Error " << voterID << " has alread used Vote" << std::endl;
			voterLogin();
		}
	}
	std::istringstream verifiedVotesSS(verifiedVotes);
	std::string lineVerifiedVotesSS;
	while (std::getline(verifiedVotesSS, lineVerifiedVotesSS)) {
		//std::cout << line << std::endl;
		if (lineVerifiedVotesSS.find(voterID) != std::string::npos)
		{
			//std::cout << line << std::endl;
			std::cout << "Valid Voter ID: " << voterID << std::endl;
			std::cout << "Error " << voterID << " has alread used Vote" << std::endl;
			voterLogin();
		}
	}
	std::istringstream voterInitialStatusSS(voterInitialStatus);
	std::string lineVoterInitialStatusSS;
	while (std::getline(voterInitialStatusSS, lineVoterInitialStatusSS)) {
		//std::cout << line << std::endl;
		if (lineVoterInitialStatusSS.find(voterID) != std::string::npos)
		{
			//std::cout << line << std::endl;
			std::cout << "Valid Voter ID: " << voterID << std::endl;
			if (lineVoterInitialStatusSS.find(",1,") != std::string::npos) {
				std::cout << "Voter Status: 1 " << std::endl;
				userInputVote();
			}
			else {
				std::cout << voterID <<" has alread used Vote" << std::endl;
				voterLogin();
			}
		}		
	}
	std::cout << "Invalid Voter ID: " << voterID << std::endl;
	voterLogin();

}
void Vote::voterLogin()
{// Logs user in using VoterID 
 // @TODO Implement Public and Private Keys 
	userVoterID.erase();
	std::cout << "Please enter your Voter ID --> ";
	std::cin >> userVoterID;
	checkVoterStatus(userVoterID);
	//userInputVote();
}
