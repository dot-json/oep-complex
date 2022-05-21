#ifndef BEAD_READER_H
#define BEAD_READER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct Format{
    std::string name;
    char type;
    int count;
};

class Reader{
public:
    int n, m;
    std::vector<Format> content;
    Reader(std::string fileName){ this->fileName = fileName; }
    ~Reader(){ content.clear(); }

    void read(){
        bool firstline = true;
        std::string line;
        file.open(fileName);
        if (file.is_open()){
            while(std::getline(file, line)){
                std::stringstream data(line);
                if (firstline){
                    data >> n >> m;
                    firstline = false;
                    continue;
                }
                std::string name;
                char type;
                int count;
                data >> name >> type >> count;
                content.push_back({name, type, count});
            }
            file.close();
        } else {
            std::cout << "cannot open file!" << std::endl;
        }
    }

private:
    std::string fileName;
    std::ifstream file;
};

#endif //BEAD_READER_H
