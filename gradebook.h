
#include <iostream>
#include <vector>

class Gradebook{
private:
    int size;
    int numParams;
    std::vector<std::vector<std::string> > assignments;

public:
    Gradebook();
    
    int getNumParams();
    void addAssignment(std::vector<std::string> newAssignment);
    std::string toString();
};
