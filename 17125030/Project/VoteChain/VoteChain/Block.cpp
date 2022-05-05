// Author: Elliot Rihan
// Created: 15/02/22
// Last Modified Date: 05/05/22
// Description: C++ file for the Block Class that controls and maintains the data stored within each Block. For use with Block.cpp.
// Block.cpp: This file file contains the functions for the Block Class.
#include "Block.h"

Block::Block(uint32_t blockIndex, const std::string& sDataIn) : blockIndex(blockIndex), blockDataSTR(sDataIn)
{
    blockIndex;                   // Incrementing Block ID 
    prevBlockHash;                  // SHA256 Hash of Previous Block
    blockSolveTime = time(nullptr);  // UNIX Timestamp of Solve Time
    blockNonce = 123456;           // Num Only Used Once: Value to find To solve Block
    sDataIn;                    // Block Data: 
                                //       Genesis: Vote, Candidate & VoterPublicKeys 
                                //       Following Blocks: Submitted Votes
    blockHash = generateBlockHash();// SHA256 Hash of Current Block
}

void Block::mineNewBlock(uint32_t nDifficulty)
{// Starts mining next block 
    char* cstr = new char[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    std::string str(cstr);
    do
    {
        blockNonce++;
        blockHash = generateBlockHash();
    } while (blockHash.substr(0, nDifficulty) != str);
    //std::cout << "Test Block.cpp: Block " << _nIndex <<" mined at " << blockTime <<  std::endl;
    saveNewBlock(blockIndex);
    delete[] cstr;
}

inline std::string Block::generateBlockHash() const
{// Converts block contents into string and generates sha256 hash
    std::stringstream ss;
    ss << "----- Start of Block -----"
        << "\n----- Block Index -----\n"         // Incrementing Block ID 
        << blockIndex
        << "\n----- Previous Block Hash -----\n" // SHA256 Hash of Previous Block
        << prevBlockHash
        << "\n----- Block Solve Time -----\n"    // UNIX Timestamp of Solve Time
        << blockSolveTime
        << "\n----- Block Nonce -----\n"         // Num Only Used Once: Value to find To solve Block
        << blockNonce
        << "\n----- Block Data -----\n"          // Block Data: 
        << blockDataSTR                                // Genesis Containing Vote, Candidate & VoterPublicKeys           
        << "\n----- End of Block -----";
    //std::cout << "TEST: Data Hashed: \n" + ss.str() + "\n";
    return sha256(ss.str());
}

void Block::saveNewBlock(uint32_t blockIndex)
{// saveBlock saves blocks after they are solved in folder /Blockchain/ 
 // Function unable to create folder but executes corect if folder exists
    //std::cout << "Test Block.cpp: Starting saveBlock function" << std::endl;
    std::stringstream ss;
    ss << "----- Start of Block -----"
        << "\n----- Block Index -----\n"         // Incrementing Block ID 
        << blockIndex
        << "\n----- Previous Block Hash -----\n" // SHA256 Hash of Previous Block
        << prevBlockHash
        << "\n----- Block Solve Time -----\n"    // UNIX Timestamp of Solve Time
        << blockSolveTime
        << "\n----- Block Nonce -----\n"         // Num Only Used Once: Value to find To solve Block
        << blockNonce
        << "\n----- Block Data -----\n"          // Block Data: 
        << blockDataSTR                                // Genesis Containing Vote, Candidate & VoterPublicKeys           
        << "\n----- End of Block -----"          // Following Blocks contining 
        << "\n----- Block Hash -----\n"          // Current Block Hash included for test
        << blockHash;
    std::string blockContent = ss.str();
    std::ofstream fileToSave("./Blockchain/Block" + std::to_string(blockIndex) + ".txt");
    fileToSave << blockContent;
    fileToSave.close();
    //std::cout << "Test Block.cpp: Block " << blockIndex << " has been saved" << std::endl;
}