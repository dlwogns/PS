#include <iostream>
#include <fstream>
#include <fstream>
#include <string>

class FileHeader {
private:
    int blockSize;
    int rootBID;
    int depth;
    const int headerSize = 12;
    std::string fileName;

public:
    FileHeader(const std::string& fileName)
        : fileName(fileName)
    {
        std::ifstream in(fileName, std::ios::binary);
        readFileHeader(in);
        in.close();
    }

    FileHeader(const std::string& fileName, int blockSize, int rootBID = 0, int depth = 0)
        : blockSize(blockSize), rootBID(rootBID), depth(depth), fileName(fileName)
    {
        setFileHeader(blockSize, rootBID, depth);
        createFileHeader();
    }

    void setFileHeader(int blockSize, int rootBID = 12, int depth = 0) {
        setBlockSize(blockSize);
        setRootBID(rootBID);
        setDepth(depth);
    }

    void setBlockSize(int newBlockSize) {
        blockSize = newBlockSize;
    }

    void setRootBID(int newRootBID) {
        rootBID = newRootBID;
    }

    void setDepth(int newDepth) {
        depth = newDepth;
    }

    void writeFileHeader(std::ofstream& out) {
        out.seekp(0, std::ios::beg);
        out.write(reinterpret_cast<const char*>(&blockSize), sizeof(blockSize));
        out.write(reinterpret_cast<const char*>(&rootBID), sizeof(rootBID));
        out.write(reinterpret_cast<const char*>(&depth), sizeof(depth));
    }

    void readFileHeader(std::ifstream& in) {
        in.seekg(0, std::ios::beg);
        in.read(reinterpret_cast<char*>(&blockSize), sizeof(blockSize));
        in.read(reinterpret_cast<char*>(&rootBID), sizeof(rootBID));
        in.read(reinterpret_cast<char*>(&depth), sizeof(depth));
    }

    void createFileHeader() {
        std::ofstream out(fileName, std::ios::out);
        writeFileHeader(out);
        out.close();
    }

    int getBlockSize() const {
        return blockSize;
    }

    int getRootBID() const {
        return rootBID;
    }

    int getHeaderSize() const {
        return headerSize;
    }

    int getDepth() const {
        return depth;
    }
};

class BTree{
public:
    BTree(const char *fileName, int blockSize);
    bool insert(int key, int rid);
    void print();
    int* search(int key);
    int* search(int startRange, int endRange);
}
int main(int argc, char* argv[]){
    char command = argv[1][0];
    char* filename = argv[2];
    if(command == 'c'){

    }else if(command == 'i'){

    }else if(command == 's'){

    }else if(command == 'r'){

    }else if(command == 'p'){

    }
    
}