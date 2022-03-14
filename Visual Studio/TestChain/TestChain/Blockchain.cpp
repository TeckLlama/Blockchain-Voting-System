#include "Blockchain.h"


Blockchain::Blockchain()
{
    //std::string VoterStatus = "VoterID#1,1\nVoterID#2,1\nVoterID#3,1\nVoterID#4,1\nVoterID#5,1\nVoterID#6,1\nVoterID#7,1\nVoterID#8,1\nVoterID#9,1\nVoterID#10,1";
    //GenerateGenesis(Block(0 , VoterStatus),VoterStatus);
}
void Blockchain::GenerateGenesis(Block genBlock,std::string votsta) 
{// Initializes Block 0 aka Genesis Block and sets mining difficulty
    std::cout << "Initializing Genesis Block: Block " << genBlock._nIndex << "..." << std::endl;
    genBlock.sPrevHash = "0000000000000000000000000000000000000000000000000000000000000000";
    genBlock._nNonce = 1337;
    voteChain.emplace_back(Block(0, votsta));
    miningDifficulty = 4;    
    genBlock.saveBlock(0);
    // miningDifficulty Mining speed notes 
    // **MORE testing required**
    // =<3:   2-5 seconds 
    //   4: 10-30 seconds
    //   5: 30-60 seconds
    // 5.5:   2-5 minutes
    //   6:   >15 minutes    
}

void Blockchain::AddBlock(Block newBlock, std::string votesPendingVerification)
{// Gets previous blocks hash, starts mining block then adds to end of the blockchain
    std::cout << "Mining block "<< newBlock._nIndex <<"..." << std::endl;
    newBlock.sPrevHash = _GetLastBlock().sHash;
    newBlock.MineBlock(miningDifficulty);
    voteChain.push_back(newBlock);
}

Block Blockchain::_GetLastBlock() const
{// returns previous block in the chain
    return voteChain.back();
}