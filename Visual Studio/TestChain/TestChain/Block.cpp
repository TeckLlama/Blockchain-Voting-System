#include "Block.h"

Block::Block(uint32_t nIndexIn, const std::string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    nIndexIn;                   // Incrementing Block ID 
    _prevHash;                  // SHA256 Hash of Previous Block
    blockTime = time(nullptr);  // UNIX Timestamp of Solve Time
    _nNonce = 123456;           // Num Only Used Once: Value to find To solve Block
    sDataIn;                    // Block Data: 
                                //       Genesis: Vote, Candidate & VoterPublicKeys 
                                //       Following Blocks: Submitted Votes
    sHash = generateBlockHash();// SHA256 Hash of Current Block
}

void Block::MineBlock(uint32_t nDifficulty)
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
        _nNonce++;
        sHash = generateBlockHash();
    } while (sHash.substr(0, nDifficulty) != str);
    //std::cout << "Test Block.cpp: Block " << _nIndex <<" mined at " << blockTime <<  std::endl;
    saveBlock(_nIndex);
    delete[] cstr;
}

inline std::string Block::generateBlockHash() const
{// Converts block contents into string and generates sha256 hash
    std::stringstream ss;
    ss  <<   "----- Start of Block -----"
        << "\n----- Block Index -----\n"         // Incrementing Block ID 
        << _nIndex
        << "\n----- Previous Block Hash -----\n" // SHA256 Hash of Previous Block
        << sPrevHash
        << "\n----- Block Solve Time -----\n"    // UNIX Timestamp of Solve Time
        << blockTime
        << "\n----- Block Nonce -----\n"         // Num Only Used Once: Value to find To solve Block
        << _nNonce
        << "\n----- Block Data -----\n"          // Block Data: 
        << _sData                                // Genesis Containing Vote, Candidate & VoterPublicKeys           
        << "\n----- End of Block -----";
    //std::cout << "TEST: Data Hashed: " + ss.str() + "\n";
    return sha256(ss.str());
}




void Block::saveBlock(uint32_t blockIndex)
{// saveBlock saves blocks after they are solved in folder /Blockchain/ 
 // Function unable to create folder but executes corect if folder exists
   //std::cout << "Test Block.cpp: Starting saveBlock function" << std::endl;
    std::stringstream ss;
    ss << "----- Start of Block -----"
       << "\n----- Block Index -----\n"         // Incrementing Block ID 
       << _nIndex 
       << "\n----- Previous Block Hash -----\n" // SHA256 Hash of Previous Block
       << sPrevHash 
       << "\n----- Block Solve Time -----\n"    // UNIX Timestamp of Solve Time
       << blockTime 
       << "\n----- Block Nonce -----\n"         // Num Only Used Once: Value to find To solve Block
       << _nNonce
       << "\n----- Block Data -----\n"          // Block Data: 
       << _sData                                // Genesis Containing Vote, Candidate & VoterPublicKeys           
       << "\n----- End of Block -----"          // Following Blocks contining 
       
       << "\n----- Block Hash -----\n"          // Current Block Hash included for test
       <<sHash;
    std::string blockContent = ss.str();
    std::ofstream fileToSave("./Blockchain/Block" + std::to_string(blockIndex) + ".txt");
    fileToSave << blockContent;
    fileToSave.close();    
    //std::cout << "Test Block.cpp: Block " << blockIndex << " has been saved" << std::endl;
}
