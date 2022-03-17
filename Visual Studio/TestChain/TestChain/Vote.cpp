#include "Vote.h"


void Vote::cinYesOrNo(std::string yNQuestion)
{// cinYesOrNo is used to get input of Y or N from user 
	do {// changed from cin to _getch to force input of one char 
		yesOrNo[0] = (char)0;
		std::cout << yNQuestion << "[Y/N] --> ";
		yesOrNo[0] = _getch();
		std::cout << yesOrNo[0] << std::endl;
		yesOrNo[0] = toupper(yesOrNo[0]);
		//std::cin >> yesOrNo[0];
	} while (/*std::cin.fail() ||*/yesOrNo[0] != 'Y' && yesOrNo[0] != 'N');
	std::cout << "Test Vote.cpp: Accepted User input Char " << yesOrNo[0] << std::endl;
	//std::cin.ignore();
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
 // @TODO implement function for Admin to set ValidVoterIDs
	//voterInitialStatus = "VoterID1,1,1647255894\nVoterID2,1,1647255895\nVoterID3,1,1647255896\n",
    ///*Test VoteIDs*/	   "VoterID4,1,1647255897\nVoterID5,1,1647255898\nVoterID6,1,1647255899\n",
	///*Regex Set {8,8}*/  "VoterID7,1,1647256077\nVoterID8,1,1647256078\nVoterID9,1,1647256079\n",
	//					   "VoterID0,1,1647256080\n";
	voterInitialStatus = "1Llama000000000000000000000000test,1,1647480169\n16LpwiWshLWJHVnb8NWoK6misC5P2JiB5q,1,1647480171\n1AJGsPnGt16LpwiWshLWJHVnb8NWoK6mis,1,1647480172\n1bbfPre7yC5P2JiB5qAfkHmQbmQgWyC5P2,1,1647480173\n1AJGsPnGtbbfPre7yuCkYJL9jf7bB4Rk4k,1,1647480176\n1uCkYJL9jfXdgQVMtkxyqbB4Rk8i47F652,1,1647480177\n17bB4Rk4kkdfgd55ryehMtkxe7yu9i8JGs,1,1647480178\n1JpebqY87211yCe7fCmguW78QyS2sfCxAx,1,1647480179\n194cQkc1AEWNJaG5Wk5hWSR9cda9MNYWap,1,1647480180\n12RgP5biNxaYCDZTocFiMP7NbVQGCvNLCl,1,1647480181\n13vWaz8skbMaZ8odJiGJj7P9hR3Y4tgiWE,1,1647480182\n1GvyJihRFc33SMDuNUPEUg1fAkRnMdGC3C,1,1647480183\n1JX2y6wxDxk92RqTRoxQt13J5B4Xxu9G1Q,1,1647480184\n18JkdYW89N6eN9D7oSiP967zAwRVh7sQzm,1,1647480185\n16sVdhEzuJKPWsZvs59cUNNur5tTcVWFy1,1,1647480186\n1PVuG4XfBBCfKvhuHhE2iDVsWxSgH96NTw,1,1647480187\n19UKiuqHx14ockwBkF36yXCtShFRzmjGNu,1,1647480188\n19J6QeyMknr29oucUVFuENHQqctAUCTyGy,1,1647480189\n1HtY5kQvwjj3id9RYLv5ZUZXTykrsrRHa3,1,1647480190\n14Xf7icn7edVrMYkFUafdC4FqZtxmihe42,1,1647480191\n1J6oz5igbxgHJMHvsFVUxDcgsYYvV4JkXL,1,1647480192\n17rQP2FYPkoGFM2nozDb71F6oXmMaRxQ6r,1,1647480193\n1GLzFgspdRXQNPsiky7mnvz15NFb61v68i,1,1647480194\n1CBNxmTsNFFrPmrLLx6Y6ZsuyStFjEe18i,1,1647480195\n12ydSxvJeoX5crTxG6nfVwMYPgAddHFSRx,1,1647480196\n1K9qs1SEWHnBxuPgX361MNuniEMc8xvsT6,1,1647480197\n1KQ6rbMqXNDuSLG6iKQsD9Gvx1zin7JtTX,1,1647480198\n194kXsWtgf1nTdw6QHjfuokBgw62rshb88,1,1647480199\n19pw8BfUDAA8YU9esqVUp5zZkavEQ2UbSK,1,1647480200\n19GtAipeRfde3UdcffktQjQuq4w35gfw1L,1,1647480201\n3HVKTFikjRB1WmWmwoP3u4bYuCtZYeCwzt,1,1647480202\n38duLT9aqwX9dHmgRdRuxqbw6aX8mZd6ip,1,1647480203\n32Aexusex26MP4fX3WH79zfcq3qa5RGrzB,1,1647480204\n39JQtXDh7zJJxukAgsaCc39u7fUosAEXQD,1,1647480205\n32PaFPRWtjSHGBhHWXmkn3QGz7PyvGjQxm,1,1647480206\n3BGw1wGvTCjefG19EDLrY5kVL11kAZCkv3,1,1647480207\n337ugPqo1GQhzwvuai4JPcfdBo7bwrb6h3,1,1647480208\n33wPjmGR3Kb8cmhqM9SoszWToLLaHvJ7Mr,1,1647480209\n37sJgaj1SvWAhNjPuPdi7TR87ku4koaGsS,1,1647480210\n3CQTkJvjddVaVH8sNdK9CC4E5UdjFXqfMa,1,1647480211\n36L5sSXgkt1LmW33L1YdFCXoeMPYPdPR14,1,1647480212\n3DNP2iY4t7Bk5mL6ZLAXFgbQhz3BBV2aj5,1,1647480213\n33b3BLdgVepftEvFsh3uVQotr7KjW661UM,1,1647480214\n33hdf1RoreaJb9Ba44nuzNYz3TADv9ALoF,1,1647480215\n33vg4xg5h6m1FPgimj1qiM8uV9TdEHBrPW,1,1647480216\n3Ef19woDDEUt7NzwHzZrderB2VLmXrxjUo,1,1647480217\n3Ep9xwB6KPyf2693VNA8vzSeem2EruqabL,1,1647480218\n3P1Pw9shNJaFdZecUwTBNpxkHDtezewZfv,1,1647480219\n377SGUY2ePPX83eqwGV4qFAfkHmQbmQgWy,1,1647480220\n38i47F6Gr57ZLyTQTUh3r3yBLiu7QQgzxq,1,1647480221\n322v9i82ietiYXdgQVMtkxyq98WSGEDgwK,1,1647480222";
}
void Vote::userSignVote()
{
	//std::cout << "Please enter Private Key to sign Vote --> ";
	//std::cin >> userPrivateKey;

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
		userInputVoteChar[0] = toupper(userInputVoteChar[0]);
		//std::cin >> userInputChar;
	} while (/*std::cin.fail() ||*/ userInputVoteChar[0] != 'A' && userInputVoteChar[0] != 'B' && userInputVoteChar[0] != 'C' && userInputVoteChar[0] != 'D');
	//std::cin.ignore();
	std::cout << "Test Vote.cpp: Accepted User input Char " << userInputVoteChar[0] << std::endl;
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
		//voterLogin();
		return;
	}	
	if (yesOrNo[0] == 'N' || yesOrNo[0] == 'n')
	{
		userInputVote();
	}	

}

void Vote::checkVoterStatus(std::string voterID)
{// Checks if VoterID has used there vote in unverifiedVotes, verifiedVotes and checks if is in Initial Status
	voterStatus = false;
	std::istringstream unverifiedVotesSS(unverifiedVotes);
	std::string lineUnverifiedVotesSS;
	while (std::getline(unverifiedVotesSS, lineUnverifiedVotesSS)) {
		//std::cout << line << std::endl;
		if (lineUnverifiedVotesSS.find(voterID) != std::string::npos)
		{
			//std::cout << line << std::endl;
			std::cout << "Test Vote.cpp: Voter ID found in unverifiedVotesSS: " << voterID << std::endl;
			std::cout << "Error: " << voterID << " has already used Vote" << std::endl;
			return;
		}
	}
	std::istringstream verifiedVotesSS(verifiedVotes);
	std::string lineVerifiedVotesSS;
	while (std::getline(verifiedVotesSS, lineVerifiedVotesSS)) {
		//std::cout << line << std::endl;
		if (lineVerifiedVotesSS.find(voterID) != std::string::npos)
		{
			std::cout << "Test Vote.cpp: Voter ID found in verifiedVotesSS: " << voterID << std::endl;
			std::cout << "Error: " << voterID << " has already used Vote" << std::endl;
			return;
		}
	}
	std::istringstream voterInitialStatusSS(voterInitialStatus);
	std::string lineVoterInitialStatusSS;
	while (std::getline(voterInitialStatusSS, lineVoterInitialStatusSS)) {
		//std::cout << line << std::endl;
		if (lineVoterInitialStatusSS.find(voterID) != std::string::npos)
		{
			std::cout << "Test Vote.cpp: Voter ID found in voterInitialStatusSS: " << voterID << std::endl;
			//std::cout << "Test Vote.cpp: Found in line: " << lineVoterInitialStatusSS << std::endl;
			if (lineVoterInitialStatusSS.find(",1,") != std::string::npos) {

				std::cout << "Voter Status: 1" << std::endl;
				voterStatus = true;
				userInputVote();
			}
			else{
				std::cout << "Error: "<< voterID << " has already used Vote" << std::endl;
				return;
			}
		}		
	}
	if (!voterStatus) {
		std::cout << "Error: " << voterID << " is not assigned a Vote" << std::endl;
		//voterStatus = false;
		return;
	}
	

	
	
	

}
void Vote::checkVoteID(std::string voteID)
{// uses regex to validate input voteID
	//	 regex ^[accepts alphanumeric char]{min size 34, max size 34}$
	std::regex regexVoteID("^[a-zA-Z0-9]{34,34}$");// in testing {8,8}
	if (std::regex_search(voteID, regexVoteID)) {			
		std::cout <<"Test Vote.cpp: Vote ID Charaters & Length accepted" << std::endl;	
		checkVoterStatus(voteID);
	}
	else {
		std::cout << "Error: Vote ID not accepted" << std::endl;
		return;
	}
}


void Vote::voterLogin()
{// Logs user in using VoterID 
 // @TODO Implement Public and Private Keys 
	//userVoterID.erase();
	userVoterID = "";
	std::cout << "Please enter your Voter ID --> ";
	//std::cin >> userVoterID;
	std::getline(std::cin, userVoterID);
	std::cin.clear();
	//std::cin.ignore(1);	
	checkVoteID(userVoterID);
	//checkVoterStatus(userVoterID);
	//userInputVote();

}

void Vote::totalVerifiedVotes()
{
	std::cout << "Counting Verified Votes..." << std::endl;
	std::istringstream verifiedVotesSS(verifiedVotes);
	std::string lineVerifiedVotesSS;
	while (std::getline(verifiedVotesSS, lineVerifiedVotesSS)) {
		//std::cout << line << std::endl;
		if (lineVerifiedVotesSS.find(",A,") != std::string::npos) {
			totalVotesA++;
			//std::cout << "Test Vote.cpp: Vote added to: A" << std::endl;
		}
		else if (lineVerifiedVotesSS.find(",B,") != std::string::npos) {
			totalVotesB++;
			//std::cout << "Test Vote.cpp: Vote added to: B" << std::endl;
		}
		else if (lineVerifiedVotesSS.find(",C,") != std::string::npos) {
			totalVotesC++;
			//std::cout << "Test Vote.cpp: Vote added to: C" << std::endl;
		}
		else if (lineVerifiedVotesSS.find(",D,") != std::string::npos) {
			totalVotesD++;
			//std::cout << "Test Vote.cpp: Vote added to: D" << std::endl;
		}
	}
	totalVotes = totalVotesA + totalVotesB + totalVotesC + totalVotesD;
	std::cout << "Count Complete Total Votes: " << totalVotes << std::endl;
	std::cout << "Total Votes for [A]: " << totalVotesA << "\t" << voteCandidateA << std::endl;
	std::cout << "Total Votes for [B]: " << totalVotesB << "\t" << voteCandidateB << std::endl;
	std::cout << "Total Votes for [C]: " << totalVotesC << "\t" << voteCandidateC << std::endl;
	std::cout << "Total Votes for [D]: " << totalVotesD << "\t" << voteCandidateD << std::endl;

}
