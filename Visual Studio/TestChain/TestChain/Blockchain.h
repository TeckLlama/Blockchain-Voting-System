#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
//#include "Vote.h"
#include "Block.h"



class Blockchain{
public:
    Blockchain();
    void AddBlock(Block bNew, std::string votesPendingVerification);
    void GenerateGenesis(Block bGen,  std::string votsta);
private:
    uint32_t miningDifficulty = 4;
    std::vector<Block> voteChain;
    Block _GetLastBlock() const;
};

#endif //TESTCHAIN_BLOCKCHAIN_H