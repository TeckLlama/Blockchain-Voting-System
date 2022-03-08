#include "Block.h"



Block::Block(uint32_t nIndexIn, const std::string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{

    _nNonce = 0;
    _tTime = time(nullptr);
    sHash = generateBlockHash();
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
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce; 
    return sha256(ss.str());
}

void Block::saveBlock(uint32_t blockIndex)
{// saveBlock saves blocks after they are solved in folder /Blockchain/ 
 // Function unable to create folder but executes corect if folder exists
    std::cout << "TEST: Starting saveBlock function";
    std::stringstream ss;
    ss << "----- Start of Block -----"
       << "\n----- Block Index -----\n" 
       << _nIndex 
       << "\n----- Previous Block Hash -----\n"
       << sPrevHash 
       << "\n----- Block Solve Time -----\n"
       << _tTime 
       << "\n----- Block Data -----\n"
       << _sData 
       << "\n----- Block Nonce -----\n"
       << _nNonce
       << "\n----- End of Block -----"
    // Current Block Hash included for testing purpuses 
       << "\n----- Block Hash -----\n"
       <<sHash;
    std::string blockContent = ss.str();
    std::ofstream fileToSave("./Blockchain/Block" + std::to_string(blockIndex) + ".txt");
    fileToSave << blockContent;
    fileToSave.close();    
    std::cout << "\n" << "Block " << blockIndex << " has been saved\n";
}
