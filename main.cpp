#include "gradebook_test.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

void ReadCSV(std::string &header, std::vector<GradebookTest> &work);

void Progress(std::vector<GradebookTest> &work, int &input);

std::pair<float, float> CalcGrade(std::vector<GradebookTest> &work);

void Update(std::vector<GradebookTest> &work, int &input);

int FindWork(std::vector<GradebookTest> &work, std::string type);

void ViewAll(std::string header, std::vector<std::string> &work);


int main(int argc, char* argv[]) {

    std::string header;
    std::vector<GradebookTest> work;
    int input = 0;

    ReadCSV(header, work);

    // UI
    while (input != -1) {
        std::cout << "\n\nChoose option:\n"
            << "\t1. Display progress.\n\t2. Update grades.\n\t3. View all grades.\n\b\b\t4. Quit.\n";
        std::cin >> input;

        switch (input) {
            case 1:             // Display progress
                Progress(work, input);
                break;

            case 2:             // Update grades
                Update(work, input);
                break;

            case 3:             // View all grades (writes updated csv file)

                break;

            case 4:             // Quit
                input = -1;
                std::cout << "Quitting.\n";
                break;

            default:
                std::cout << "Error: Valid option not chosen.";
                input = 0;
        }
    }

}

// Repeatedly reads input for valid csv file name.
// When csv file found, creates an object for each row and tokenizes every item.
void ReadCSV(std::string &header, std::vector<GradebookTest> &work) {

    std::ifstream input_file;
    std::string file_name;
    std::string line;

    std::cout << "Input file name:";
    while (std::cin >> file_name) {
        input_file.open(file_name);

        if (input_file) {
            std::cout << "File found.";
            break;
        } else {
            std::cout << "File not found; try again:";
        }
    }

    // saves first line of csv file as header
    std::getline(input_file, header);

    // Works on each individual row of csv file
    while (std::getline(input_file, line)) {
        std::vector<std::string> tmp_vec;
        std::istringstream iss(line);
        std::string tmp_string;

        // Tokenizes each row and pushes each item into temporary string vector
        while(std::getline(iss, tmp_string, ',')) {
            tmp_vec.push_back(tmp_string);

        }

        // Push tokenized items (Tasks, Type, Earned, Max) into an object
        GradebookTest tmp(tmp_vec);

        // Push object into work vector
        work.push_back(tmp);
    }

    return;
}

void Progress(std::vector<GradebookTest> &work, int &input) {

    // Retrieves total points earned and max points
    std::pair<float, float> earned_max = CalcGrade(work);
    std::string let_grade("");

    // Calculates number grade to be used to determine letter grade
    float num_grade = std::floor(((earned_max.first / earned_max.second) * 100));

    // Determines corresponding letter grade
    if (num_grade >= 94) {
        let_grade = "A";
    } else if (num_grade >= 90) {
        let_grade = "A-";
    } else if (num_grade >= 87) {
        let_grade = "B+";
    } else if (num_grade >= 83) {
        let_grade = "B";
    } else if (num_grade >= 80) {
        let_grade = "B-";
    } else if (num_grade >= 77) {
        let_grade = "C+";
    } else if (num_grade >= 73) {
        let_grade = "C";
    } else if (num_grade >= 70) {
        let_grade = "C-";
    } else if (num_grade >= 67) {
        let_grade = "D+";
    } else if (num_grade >= 63) {
        let_grade = "D";
    } else if (num_grade >= 60) {
        let_grade = "D-";
    } else {
        let_grade = "F";
    }

    std::cout << "Grade:\t\t" << num_grade << "|" << let_grade << "\nCumulative:\t"
        << earned_max.first << "/1000" << "\n\n";

    std::cout << "Choose option:\n"
        << "\t1. Return to menu.\n\t2. Quit.\n";

    std::cin >> input;

    switch (input) {
        case 1:
            input = 0;
            break;

        case 2:
            input = -1;
            std::cout << "Quitting.\n";
            break;

        default:
            std::cout << "Error: Valid option not chosen.\n";
    }
}

std::pair<float, float> CalcGrade(std::vector<GradebookTest> &work) {
    float cumulative;
    float max;

    std::pair<float, float> output;

//    switch (option) {
//        case 1:                 // individual
//
//            break;
//
//        case 2:                 // category
//
//            break;
//
//        case 3:                 // overall
//
//            break;
//
//        default:
//            std::cout << "Error: Valid option not chosen.";
//
//    }

    // Iterates through entire work vector, summing all available grades.
    // Any tasks that have not been completed will be skipped (indicated by -1).
    for (int i = 0; i < work.size(); i++) {

        if (work[i].GetEarned() == -1) {        // Skip incomplete assignments
        } else {                                // Else sum available grades
            cumulative += work[i].GetEarned();
            max += work[i].GetMax();
        }
    }

    return output = std::make_pair(cumulative, max);
}

void Update(std::vector<GradebookTest> &work, int &input) {
    std::string assign_name;        // assignment name is means task
    float earned;

    // While input remains 2, continue to prompt grade update
    while (input == 2) {
        std::cout << "Input name of assignment to update:\n";
        std::cin >> assign_name;
        std::cout << "\nInput new grade:\n";

        // If assignment name was in lowercase, convert to uppercase
        if ((assign_name[0] >= 'a') && assign_name[0] <= 'z') {
            assign_name[0] -= 32;

        }

        // Finds assignment in work vector and changes its m_earned
        work[FindWork(work, assign_name)].SetEarned(earned);

        std::cout << "Assignment " << assign_name << " grade changed to " << earned << ".\n\n";

        std::cout << "Choose option:\n"
                  << "\t1. Return to menu.\n\t2. Update again.\n\t3. Quit.";

        std::cin >> input;

        switch (input) {
            case 1:             // Return to menu
                input = 0;
                break;

            case 2:             // Update another grade
                break;

            case 3:             // Quit
                input = -1;
                std::cout << "Quitting.\n";
                break;

            default:
                std::cout << "Error: Valid option not chosen.\n";
        }
    }
}

// Finds assignment in work vector and returns index
int FindWork(std::vector<GradebookTest> &work, std::string type) {
    for (int idx = 0; idx < work.size(); idx++) {
        if (work[idx].GetType() == type) {
            return idx;
        }
    }
}

void ViewAll(std::string header, std::vector<std::string> &work, ) {
    std::string output_name;

    std::cout << "\nInput desired name of csv file:\n";

    std::getline(std::cin, output_name);

    std::ofstream ofs(output_name);
    


}

