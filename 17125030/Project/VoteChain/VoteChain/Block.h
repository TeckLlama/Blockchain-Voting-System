// Author: Elliot Rihan
// Created: 12/02/22
// Last Modified Date: 05/05/22
// Description: C++ Header file for the Block Class that controls the data stored within each Block. For use with Block.cpp.
// Vote.h: This file declares the libraries, functions and variables used in the Block Class.
#ifndef VOTECHAIN_BLOCK
#define VOTECHAIN_BLOCK

#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "sha256.h"

class Block {
public:
    uint32_t blockIndex;
    std::string prevBlockHash;
    uint32_t blockNonce;
    std::string blockHash;    
    Block(uint32_t blockIndex, const std::string& blockData);
    void mineNewBlock(uint32_t currentDifficulty);
    void saveNewBlock(uint32_t blockIndex);
    std::string generateBlockHash() const;

private:
    std::string blockDataSTR;
    time_t blockSolveTime;

};
#endif //VOTECHAIN_BLOCK