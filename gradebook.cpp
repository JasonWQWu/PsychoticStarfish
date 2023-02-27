#include "gradebook.h"

Gradebook::Gradebook(){
    this->size = 0;
    this->numParams = 4;
}

int Gradebook::getNumParams(){
    return this->numParams;
}

void Gradebook::addAssignment(std::vector<std::string> newAssignment){
    this->assignments.push_back(newAssignment);
    this->size++;
}

std::string Gradebook::toString(){
    std::string output;
    std::string line;
    for(int i = 0; i < this->size; i++){
        line = "";
        for(int j = 0; j < this->numParams; j++){
            line += this->assignments[i][j] + " ";
        }
        if(i < this->size - 1){
            line += "\n";
        }
        output += line;
    }
    return output;
}