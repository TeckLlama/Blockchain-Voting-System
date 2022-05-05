// Author: Elliot Rihan
// Created: 15/02/22
// Last Modified Date: 05/05/22
// Description: C++ file for the Blockchain Class that maintains the addition of new Blocks being added to the Chain. For use with Blockchain.h.
// Blockchain.cpp: This file file contains the functions for the Blockchain Class.
#include "Blockchain.h"

Blockchain::Blockchain()
{    
}

void Blockchain::generateGenesisBlock(Block genBlock, std::string genBlockData)
{// Initializes Block 0 aka Genesis Block and sets mining difficulty
    //std::cout << "Test Blockchain.cpp: Initializing Genesis Block: Block " << genBlock._nIndex << "..." << std::endl;
    genBlock.prevBlockHash = "0000000000000000000000000000000000000000000000000000000000000000";
    genBlock.blockNonce = 1337;
    voteChain.emplace_back(Block(0, genBlockData));
    miningDifficulty = 4;
    genBlock.saveNewBlock(0);
    // miningDifficulty Mining speed notes 
    // **MORE testing required**
    // =<3:   2-5 seconds 
    //   4: 10-30 seconds
    //   5: 30-60 seconds
    // 5.5:   2-5 minutes
    //   6:   >15 minutes    
}

void Blockchain::addNewBlock(Block newBlock, std::string votesPendingVerification)
{// Gets previous blocks hash, starts mining block then adds to end of the blockchain
    //std::cout << "Test Blockchain.cpp: Mining block "<< newBlock._nIndex <<"..." << std::endl;
    newBlock.prevBlockHash = findPrevBlock().blockHash;
    newBlock.mineNewBlock(miningDifficulty);
    voteChain.push_back(newBlock);
}

Block Blockchain::findPrevBlock() const
{// returns previous block in the chain
    return voteChain.back();
}