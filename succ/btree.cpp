#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Btree{
public:
    fstream fs;
    Btree(){

    }
    void cif(char* filename, int blockSize){
        fs.open(filename, ios::out|ios::binary);
        fs.write(reinterpret_cast<char*>(blockSize), sizeof(blockSize));
        fs.close();
    }

};
int main(int argc, char* argv[]){
    char command = argv[1][0];
    char* filename = argv[2];
    Btree btree = Btree();
    if(command == 'c'){
        btree.cif(filename, atoi(argv[3]));
    }
}