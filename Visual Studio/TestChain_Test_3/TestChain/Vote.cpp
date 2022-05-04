#include "Vote.h"

//std::mutex vote_mutex;

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
	//voterInitialStatus = "VoterID1,1,1647255894\nVoterID2,1,1647255895\nVoterID3,1,1647255896\n"
    ///*Test VoteIDs*/	   "VoterID4,1,1647255897\nVoterID5,1,1647255898\nVoterID6,1,1647255899\n"
	///*Regex Set {8,8}*/  "VoterID7,1,1647256077\nVoterID8,1,1647256078\nVoterID9,1,1647256079\n"
	//					   "VoterID0,1,1647256080\n";
	
	voterInitialStatus =	"1Llama000000000000000000000000test,1,1651018681\n1NB1AG1qwY6H6djdQcFG6v3pdhxbird1AW,1,1651018682\n1LfRjCK53Du11cAPjqdFTPsXVmCvV4qm6P,1,1651018683\n"
							"1FTzoj5WKRqejXYPYXZVQNnZ1ZLS9ZPEPU,1,1651018684\n1AE4WL5ZQ1xPngeWJoZG8VZqLbeCQGkDAA,1,1651018685\n1G75sJ6CPJ2D9cNR2SQDFGPa4AKg2yVzfD,1,1651018686\n"
							"16T8uEAVhHCjoH77CbEKRWp5mugbCBV1uD,1,1651018687\n1CosJHVMbFhc1viAVGEQNUXVJ66y4eqm4x,1,1651018688\n1BFdc5mfVjejizgHfsK22BNjzJ9mbLxng5,1,1651018689\n"
							"13DCzN98n7K8pEPZiMmsMgivRFkdt32Ssj,1,1651018690\n1NSLcnCHM4Zt7ASh3XCuFhGty6i8Dd6WiK,1,1651018691\n1NyBrf7UkG91Tx7mXc4GDZaLdz6yGP9svE,1,1651018692\n"
							"1EVCvFjhdMXmhXHsfGysHptWv9NSdE97RK,1,1651018693\n1DXwC6HAsnf1Eyvwab5gPT4XCRDvDb65Mc,1,1651018694\n15b7yEoA9gh9d44chb732AxFwYmQqPr989,1,1651018695\n"
							"1PQzMUn87sKDFSB5siwUoq6EY3w6fpZXD9,1,1651018696\n1HHkw3EFy9Uwpov1Q175A1gwBD4grrUjoN,1,1651018697\n1Hzt13iVuWaXGTBZTzgCDMhxyqaEDPqxQj,1,1651018698\n"
							"125Hh46Q3eTotVYDAZ1ZYXcKcRK669eKvE,1,1651018699\n1P3V7c6VrdN2yW9yRK4EGKNBnGsMBPULc6,1,1651018700\n1ARf8FT9fyBKUqLEz9tGwhFJxqdKssCp5x,1,1651018701\n"
							"1MkWcQFQBVxFwSM9FD8iScuqFHYRLL5Z4X,1,1651018702\n1MRJJy7CFsh28Ft5qyu3A3o6CNLd2g2euG,1,1651018703\n188NmLDAqKYxJ8aSAe4eaAempvh4y9E6U3,1,1651018704\n"
							"1GNRmpbKbQxXVAcJJtmSEYn72NWgQ8mhn6,1,1651018705\n1G9gKbavM1DNhvXGdabDCKk1mQaLfRbGRb,1,1651018706\n18GfDqTw9pKNSzx9aFGRWhVKnTYSdXr4ap,1,1651018707\n"
							"1HCXBAvGTGgtMmfYaWjRVQ38WDRvEdkQ1c,1,1651018708\n1AnksC8xtZ3M23aioR5gQjTpW7wxWRbVhK,1,1651018709\n1Jp6HJknz7Tm7aqfw8TkzCzUau4FZEn3cp,1,1651018710\n"
							"1HBXSCmQLuvUQzjxsTaBYMgymNDSEBZiGC,1,1651018711\n1KAPAF4DrWzohgs7Jamww9f6HV5GM3s3h7,1,1651018712\n1CoudRjrXQcQoHceMvqrzRKwbPo2bRBKCd,1,1651018713\n"
							"18pBW29YE1TAh6xKx1KsLf8ypG98F2nyMJ,1,1651018714\n15RqFjSdTw1DqcfrfYsDVHxgppWw9HmHAd,1,1651018715\n12d9SzrJgYp8T2ePxsds1fpGs6mtkNtvrE,1,1651018716\n"
							"1EqEqhjwb7SevuB5iZDYLuZS2Ft3enQeFA,1,1651018717\n14B7Sgr9n4CUQt3VMPtbwQjC5c97VPnG7A,1,1651018718\n1K6m3BYQ36QTSDNJHDveHodoeuCaLfW4qG,1,1651018719\n"
							"1HuSScekWNT3Q4Hmiprtno1QJL4yfcxYkm,1,1651018720\n1Dym8DH7B9wjyiqTBRdjbAVHx35Z1pU3KL,1,1651018721\n19bUDTHqxhUb5vguaVzpDJ4qmDUci2frS7,1,1651018722\n"
							"1AcEBPwCEMfcMuJxyd1Kd9KQiLtNNeo7j6,1,1651018723\n123xaUVoV4kVk54Dm3k33BauGCtW6SkQjD,1,1651018724\n1PMFf1uMWSduSrDZPVCVUqujAJzbzvAA7E,1,1651018725\n"
							"1E9Aspw23U3nr2DypF1Me7vEKwRA9cwidx,1,1651018726\n1BUw3oqhouye3w3h3aLP5heEXf3JRJsS6A,1,1651018727\n1D2dd1Q8uR6KVc4pncnXTr79YgKw477PE5,1,1651018728\n"
							"1ErgNvC62iRLr434QZ4fogQoenjfFyDKhp,1,1651018729\n15dyARLoTTE97UTvV1dkC4U4FZPfkVXhAq,1,1651018730\n19rvbBTmdrdDMhseyPWWbAT93vs427JL1Q,1,1651018731\n"
							"14tkt97zGCqZueYFC32zMLoVmV2KX6Ko5b,1,1651018732\n1HoQUkEYgTDHhwGBhLTF3GhYnCkv7EwYkm,1,1651018733\n1Frixn9u9E9GdUkH8kjGLj7uqkAZPL6wAv,1,1651018734\n"
							"16gKLt4MxAfYcMstdaPdi4y6JYJECTvBoe,1,1651018735\n1KZL3wffAXt2gUTPHBhGJSRRMYvPShxhhP,1,1651018736\n1AtR8noMucac76MvQv2Ye6Y92A6qjwoaQQ,1,1651018737\n"
							"1CVMiqySpiUL94GQHczFuBdRu5eEoF6Uag,1,1651018738\n188Nj528fP7HdXKVkrDzTtE4FRW14zBtdT,1,1651018739\n1CDzgboG89bf3iWd4sunygqftxqcctAvA2,1,1651018740\n"
							"1ByYZvhHdwpeGvNvMcDwqgC2dotYnqNFsn,1,1651018741\n1PvHQSfUeVTc6HakHV7PKPUqQEXjEzcaEh,1,1651018742\n1FQgopKn1BqqZHYBUd325g2McAwwKEmx3G,1,1651018743\n"
							"1HZvbuojf1Pce7kTVN4xLdW17qwbfzE1i1,1,1651018744\n1CJrmPRHZtCaB4boLokC2GXgoBgz7Yrevt,1,1651018745\n14jCJhVLr94TMA5VRfaAANVGyjSNugVE2S,1,1651018746\n"
							"19cwirC76GcBNAK3xAu6LGR92QVXpJFL2S,1,1651018747\n1NrR9oQCs5nc7Rj9o544jFgA4PKDo8Jk8B,1,1651018748\n1FcgtRSyXNMeyJk4PjLHJQbk3BkQrf2UBC,1,1651018749\n"
							"1GAvGDjrsXfBLHVHcHbx6v8afPhJ2EaUXP,1,1651018750\n18h3Y5ft3APV7VTzdM5HrYEKXhoxbKCE3S,1,1651018751\n1FXgFjThVkngLizGS3udN3wzDvipTiVmmo,1,1651018752\n"
							"1NP2rKs6VRVzqfetx6kqxaS9hzMHncvEno,1,1651018753\n14ZBu1eWUWLjdXSgj4RKr34w4LTvwMfRpb,1,1651018754\n1Bnwf72VGqr8tB7f3QPSqonhPVh3a15Hhh,1,1651018755\n"
							"1L8x4Gvk6qdzjgAMRezfYD69JjQtyjDNqY,1,1651018756\n1Q8cPk8oQEeqL1wAtaf5DZXNJ9TzC9UWWB,1,1651018757\n1AMTjTPDNQoVep4BLJEFLj2oU9qKq139Sv,1,1651018758\n"
							"18tEkRDdaYHkvR5QBVn52p5RaktxsUgbSP,1,1651018759\n1DU9W8BZUStotjNWdnqGwCiSoUecjCQXoi,1,1651018760\n17ZaxmQCUAdLtBCR6JBj11jmxCdmmt6EU3,1,1651018761\n"
							"1H1s8vKmVzpJ1jfe4yifbs31B1VTyRoN1c,1,1651018762\n1LS4hF5CgW45J7HnJRDoLyTv8BXKLprxNt,1,1651018763\n16DM4hmBhhXoXMpDwfUmC6oL3dhA1ssh7U,1,1651018764\n"
							"1H7JWrXWEGZ13zB7JpattEHEh4tya8oz3W,1,1651018765\n1PD4hKaqPTFZktq5ZaTq7iKnc9MN1CVdTm,1,1651018766\n1NbaZJZgWBLDR7uJwmxaz3ERig25MQtX1s,1,1651018767\n"
							"17yr7LKsuTJVxyMP89GF4JgjR9BqHhyjXJ,1,1651018768\n1DiLaNhCLrdTCPfGGwxoFM3YMEanBxC4zE,1,1651018769\n1NRrfqwMHimshgiPKhrRdaVtGovSRNBA3d,1,1651018770\n"
							"17j3ryiEdQhoKfaTaN4tzynhGhWyJv5cui,1,1651018771\n1HMPD5adMtiBQQK4bd2rxfjVozXePYXtc9,1,1651018772\n1NJswbQLePBgnPbnKUVdsN1oKxGDUNfbwi,1,1651018773\n"
							"19U754snsZ8H17bWSjf1Pk2MGX65KW6jcn,1,1651018774\n1KnatZTyueKGREJbV9NcLFuLxdGUgzjG9k,1,1651018775\n1CWKo3XmxiJSHoK3dmJw86n6ZRAk6m5Mf3,1,1651018776\n"
							"1Azy33m8Sc95p7RJz53beP5sGJaYgKHiVM,1,1651018777\n1L3qmpSHTAZM8ojkevBthXeJA2pduFoxM2,1,1651018778\n1DUE9zpwSkwnfC4yntTtdTuyzTdkcBxsyR,1,1651018779\n"
							"1JJDSAczxgzrB3dK3TW4Qaf9pUMKsGoaRj,1,1651018780\n1Q93EJQ1pK6xvToip2JhM3pLMA3AQCuKVm,1,1651018781\n1Hnu8dZ9EuyDxrgGTzpbTYbCxYzS3JhqUJ,1,1651018782\n"
							"1JC4gdDCvn66JL5aV2LJYVU4soZbWXbQtZ,1,1651018783\n12RqTsBTtDAn78RehQkXWhXGdWwkpUaSDJ,1,1651018784\n1DKTpcvrTkhu21eri3GG49XQ8gUQSyRegf,1,1651018785\n"
							"13HtF7a6ZVKmK6ybw3nzkjRL1UP7bQ3y4y,1,1651018786\n1HtgjyJTGL83d5cQwWseEJFPReaFDhYRee,1,1651018787\n19zYVTEHDydpMT4X7qk4fLSWW1UXaC1hGr,1,1651018788\n"
							"1NFBPyRdqM7EyFVRFFg4cAPmDyahGEvh2D,1,1651018789\n1FBLBk7ar8NeykHsUKqQBndb4BswLjfFUW,1,1651018790\n1MoE8Cb43CyfZQQAVxg3ERGVqhFtjBWket,1,1651018791\n"
							"14fxrtGKw1HycYRtoEcq4svsbZjcq5v53a,1,1651018792\n12RZ4FWVabFS9iUkti7tJwGiWQsSxEfwQz,1,1651018793\n1Apd9mysccz3sF3w48NUHfLXBKHQ3ppxZP,1,1651018794\n"
							"18PMiy3xZUdGdp3E3bTRyouS1viwWuhNWa,1,1651018795\n1KHJ5DCMVjoaaECt332MXmsZ9n4RYo7iCm,1,1651018796\n1FnpWauEn8ZSeUqqJ9awiiMc2Ef94fth6J,1,1651018797\n"
							"15cPptd2q4Yi2LzZjtafTeLYzydDAfWDgN,1,1651018798\n1EUgkgk98mxWwFmR8TMgdEa8aZMbihQgFW,1,1651018799\n1BUmvtUrqimp8g8fxGRytG6bmFUXjyRLjP,1,1651018800\n"
							"13T1yAeudHrdxdijTShu8bTbAnRJVX9rhe,1,1651018801\n125cNArAGQLMMzbBRDd6GmwpPwibG8i1XX,1,1651018802\n1F6AB5xnuKS4N6XAFRfUH2RJv7xR3XdG8V,1,1651018803\n"
							"18ZNMFwtk5HE2barPmQe6MsWpJ4e3s7KoY,1,1651018804\n19V5pacKhQSpbWCZrgXwJEWxkQHgEokcji,1,1651018805\n1BFdsJUnkpcSLcebxdC6xoeemztTC1wHAa,1,1651018806\n"
							"1AgcnJ52ArCStZpq4hvb2fHnujoBTkXxfV,1,1651018807\n1D73NnBBLSCtpAr851BVfNXQasAJhMszJJ,1,1651018808\n17rLt8t6dJyGRykPVytJ438S7w3bGB29Qs,1,1651018809\n"
							"1HiD4mrVmZaKT1AJvsZTG2YCZ1scm773kV,1,1651018810\n1CRZXeCVnmKCt2go97FnVsyP7HzV17cZ8M,1,1651018811\n171Hp2G4kJAmKA65yfyQmTDtiKzBhVnrKB,1,1651018812\n"
							"13yBndsuceK28LnCZKUJGYWEdsUGr8PFgk,1,1651018813\n1Pzo8ENE9RHXeYFamdUZkz3PLtF22eF4dw,1,1651018814\n13madoTd4KDfhdYE4ozc4dw7xT5KN6gBvC,1,1651018815\n"
							"16WnR4irF57fc5QmTLhB69nWZMCciexiHA,1,1651018816\n1KKBB52VKTAQm7SUfiGuYsfQDvhoRcpZtR,1,1651018817\n1CBJLrE4qBnxSPhMm5Y8utxejM3cgXN2KR,1,1651018818\n"
							"155TzvenvpCFtJHssUfYXW3HGuvGnUpymK,1,1651018819\n1E9kGoGToQCAiPdkRZKe8wMRrEBNVdxGNa,1,1651018820\n16JoH99NG1nyymeBxjoWQGA6dY2Y72aNfy,1,1651018821\n"
							"1EZdyexB3s3QxDwqn1wyXSbT2jmCDTVAUX,1,1651018822\n18nHogW3Vib3PPxg5n2SBfGmZhZiaxm5gA,1,1651018823\n15XYyJNRyhf441uaQKz1N4QXMC4VPaxe4r,1,1651018824\n"
							"14ZbQ6QeG8u5ETEck68hqheSJ2NWybUezK,1,1651018825\n176RaHGDXB8NXEECvJSVf4BcdBX2GH1XQC,1,1651018826\n172Yf2uorHNFG4EvWyUQcMphLSBoXhYusW,1,1651018827\n"
							"1ESGG9gbVojAwbgPWNwJaSSiMn3wnccKHx,1,1651018828\n15MnjTp4dpVQZ582B6vkPirLjS9MjuUhBp,1,1651018829\n1CAS3axju39nrU4kUkwjUfNEtqLDNez8ET,1,1651018830\n"
							"1N918cWttDauvc5oSJqfB68XSCvSeN1cub,1,1651018831";
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
		//std::unique_lock<std::mutex> ulVM(vote_mutex);
		if (unverifiedVotes == "")
		{
			unverifiedVotes += userVoterID + "," + userInputVoteChar[0] + "," + voteTimeString;
		}
		else {
			unverifiedVotes += "\n" + userVoterID + "," + userInputVoteChar[0] + "," + voteTimeString;
		}
		//ulVM.unlock();
		std::cout << "Your input has been saved and will be added to the next block verified at this node\n" << std::endl;
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
	std::stringstream ss;
	ss << "Total Votes: " << totalVotes << "\n"
	   << "Total Votes for [A]: " << totalVotesA << "\t" << voteCandidateA << "\n"
	   << "Total Votes for [B]: " << totalVotesB << "\t" << voteCandidateB << "\n"
	   << "Total Votes for [C]: " << totalVotesC << "\t" << voteCandidateC << "\n"
	   << "Total Votes for [D]: " << totalVotesD << "\t" << voteCandidateD;
	voteBreakdown = ss.str();
	std::cout << voteBreakdown;
	
}
