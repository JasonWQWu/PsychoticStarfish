/**
 * 
 * 
 * 
 * @authors Eric Chin, ...
 * @date 3/1/23
 * 
 * CLA => main.cpp gradebook.cpp test.txt(optional)
 * 
*/
#include "gradebook.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

bool readCSV(std::string fileName, Gradebook* gradebook){
   std::ifstream inputFile(fileName);
      
   // File not opened
   if(!inputFile.is_open()){
      std::cout << "Failed ot open file\n";
      return false;
   }
   // File opened
   else{
      // Annotate csv reading variables
      std::string line = "";
      std::stringstream ss;

      // Read header
      // Ex: Task, Type, Points Earned, Max Points
      std::getline(inputFile, line);
      ss << line << std::endl;
      
      // Read rest of the file into the gradebook object
      while(std::getline(inputFile, line)){
         std::stringstream ss(line); 
         std::string temp = "";
         std::vector<std::string> line_vals;
         
         // Push values into array
         for(int i = 0; i < gradebook->getNumParams(); i++){
            if (i == gradebook->getNumParams() - 1){
               std::getline(ss, temp);
            }
            else{
               std::getline(ss, temp, ',');
            }
            line_vals.push_back(temp);
         }

         // Add gradebook assignment
         if(line_vals.size() == gradebook->getNumParams()){
            // Assign values to Gradebook object
            gradebook->addAssignment(line_vals);
         }
         else{
            std::cout << "(Error) csv line:\n\" " << line << "\" " << "\ndoes not meet gradebook criteria\n";
         }
      }
      return true;
   }
}

int main(int argc, char* argv[]){

   // Annotate variables
   Gradebook* gradebook = new Gradebook();
   std::string fileName;
   bool CSVFound;

   // CLA file open
   // std::cout << argc << std::endl;
   // std::cout << argv[1] << std::endl;
   if(argc == 2){
      fileName = argv[1];
      CSVFound = readCSV(fileName, gradebook);
   }
   else{
      std::cout << "No CSV loaded upon start\n";
   }

   if(CSVFound){
      std::cout << gradebook->toString() << std::endl;
   }

   /*************** UI ****************/

   return 0;
}
