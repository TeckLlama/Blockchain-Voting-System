#include "Block.h"

Block::Block(uint32_t nIndexIn, const std::string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    nIndexIn;                   // Incrementing Block ID 
    _prevHash;                  // SHA256 Hash of Previous Block
    _tTime = time(nullptr);     // UNIX Timestamp of Solve Time
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
    std::cout << "Block " << _nIndex <<" mined at " << _tTime <<  std::endl;
    saveBlock(_nIndex);
    delete[] cstr;
}

inline std::string Block::generateBlockHash() const
{// Converts block contents into string and generates sha256 hash
    std::stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _nNonce << _sData ;
    return sha256(ss.str());
}

void Block::saveBlock(uint32_t blockIndex)
{// saveBlock saves blocks after they are solved in folder /Blockchain/ 
 // Function unable to create folder but executes corect if folder exists
    std::cout << "TEST: Starting saveBlock function";
    std::stringstream ss;
    ss << "----- Start of Block -----"
       << "\n----- Block Index -----\n"         // Incrementing Block ID 
       << _nIndex 
       << "\n----- Previous Block Hash -----\n" // SHA256 Hash of Previous Block
       << sPrevHash 
       << "\n----- Block Solve Time -----\n"    // UNIX Timestamp of Solve Time
       << _tTime 
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
    std::cout << "\n" << "Block " << blockIndex << " has been saved\n";
}
