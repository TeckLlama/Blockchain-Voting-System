#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "sha256.h"

class Block{

public:
    uint32_t _nIndex;
    std::string _prevHash;
    uint32_t _nNonce;
    std::string sHash;
    std::string sPrevHash;

    Block(uint32_t nIndexIn, const std::string& sDataIn);

    void MineBlock(uint32_t nDifficulty);
    void saveBlock(uint32_t blockIndex);
    std::string generateBlockHash() const;

private:
    
   
    std::string _sData;
    time_t blockTime;

    

};
#endif //TESTCHAIN_BLOCK_H