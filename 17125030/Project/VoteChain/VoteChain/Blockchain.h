// Author: Elliot Rihan
// Created: 12/02/22
// Last Modified Date: 05/05/22
// Description: C++ Header file for the Blockchain Class that controles the Blockchain. For use with Blockchain.cpp.
// Blockchain.h: This file declares the libraries, functions and variables used in the Blockchain Class.
#ifndef VOTECHAIN_BLOCKCHAIN
#define VOTECHAIN_BLOCKCHAIN

#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();
    void addNewBlock(Block bNew, std::string votesPendingVerification);
    void generateGenesisBlock(Block bGen, std::string votsta);
private:
    uint32_t miningDifficulty = 4;
    std::vector<Block> voteChain;
    Block findPrevBlock() const;
};
#endif //VOTECHAIN_BLOCKCHAIN