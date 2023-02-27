#include "gradebook_test.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

void ReadCSV(std::string &header, std::vector<GradebookTest> &work);

void Progress(std::vector<GradebookTest> &work, int &input);

void Individual(std::vector<GradebookTest> &work);
void Category(std::vector<GradebookTest> &work);
void Course(std::vector<GradebookTest> &work, int &input);
void Cumulative(std::vector<GradebookTest> &work);

std::pair<float, float> CalcGrade(std::vector<GradebookTest> &work);

void Update(std::vector<GradebookTest> &work, int &input);

int FindWork(std::vector<GradebookTest> &work, std::string type);

// Creates updated CSV file.
// To actually see the CSV file in the directory, must quit program.
void ViewAll(std::string header, std::vector<GradebookTest> &work, int &input);


int main(int argc, char* argv[]) {

    std::string header;
    std::vector<GradebookTest> work;
    int input = 0;

    ReadCSV(header, work);

    // UI
    while (input != -1) {
        std::cout << "\n\n-------------------------------------------";
        std::cout << "\nChoose option:\n"
                  << "\t1. Display progress\n\t2. Update grades\n\t3. Retrieve updated CSV file\n\t4. Quit\n";
        std::cin >> input;

        switch (input) {
            case 1:             // Display progress
                Progress(work, input);
                break;

            case 2:             // Update grades
                Update(work, input);
                break;

            case 3:             // Writes updated CSV file
                ViewAll(header, work, input);
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

// Prompts user to choose between individual task grade, category grades, or overall grade.
void Progress(std::vector<GradebookTest> &work, int &input) {

    std::cout << "\nChoose [Display progress] option:\n"
              << "\t1. Individual\n\t2. Category\n\t3. Course\n";
    std::cin >> input;

    switch (input) {
        case 1:             // Individual
            Individual(work);
            break;
        case 2:             // Category
            Category(work);
            break;
        case 3:             // Course
            Course(work, input);
            break;
        default:
            std::cout << "Error: Valid option not chosen.\n";
    }

    std::cout << "\nChoose option:\n"
              << "\t1. Return to menu\n\t2. Quit\n";

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

// Iterates through work vector and sums all points earned.
// Returns total earned and corresponding max in std::pair<float, float> format.
std::pair<float, float> CalcGrade(std::vector<GradebookTest> &work) {
    float cumulative = 0;
    float max = 0;

    std::pair<float, float> output;

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

// Modifies earned points of user-selected assignment
void Update(std::vector<GradebookTest> &work, int &input) {
    std::string assign_name;        // assignment name is synonymous to task
    float earned;

    // While input remains 2, continue to prompt grade update
    while (input == 2) {
        std::cout << "\nInput name of assignment to update:";
        std::cin >> assign_name;
        std::cout << "\nInput new grade:";
        std::cin >> earned;

        // If assignment name was in lowercase, convert to uppercase
        if ((assign_name[0] >= 'a') && assign_name[0] <= 'z') {
            assign_name[0] -= 32;

        }

        // Checks if name exists in CSV file
        while (FindWork(work, assign_name) == -1) {
            std::cout << "\nName not found in CSV; Re-enter name:";
            std::cin >> assign_name;

            // If assignment name was in lowercase, convert to uppercase
            if ((assign_name[0] >= 'a') && assign_name[0] <= 'z') {
                assign_name[0] -= 32;

            }
        }

        // Finds assignment in work vector and changes its m_earned
        work[FindWork(work, assign_name)].SetEarned(earned);

        std::cout << "\nAssignment " << assign_name << " grade changed to " << earned << ".\n\n";

        std::cout << "Choose option:\n"
                  << "\t1. Return to menu\n\t2. Update another assignment\n\t3. Quit\n";

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
int FindWork(std::vector<GradebookTest> &work, std::string task) {
    for (int idx = 0; idx < work.size(); idx++) {
        if (work[idx].GetTask() == task) {
            return idx;
        }
    }
    return -1;
}

// Creates updated CSV file, which becomes accessible in the directory after quitting program
void ViewAll(std::string header, std::vector<GradebookTest> &work, int &input) {
    std::string output_name;
    std::cout << "\nInput desired name of output CSV file:\n";
    std::cin >> output_name;
    output_name += ".csv";
    std::ofstream ofs(output_name);

    ofs << header << "\n";              // pushes header row first

    for (int i = 0; i < work.size(); i++) {
        ofs << work[i].GetTask() << "," << work[i].GetType() << "," << std::setprecision(1)
            << std::to_string(work[i].GetEarned()) << "," << std::to_string(work[i].GetMax())
            << "\n";

    }

    std::cout << "\nChoose option:\n"
              << "\t1. Return to menu\n\t2. Quit\n";

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

// Calculates sum of available grades (ignores -1) and divides over max.
// Outputs current number grade, corresponding letter grades, and cumulative points earned.
void Cumulative(std::vector<GradebookTest> &work) {
    // Retrieves total points earned and max points
    std::pair<float, float> earned_max = CalcGrade(work);
    std::string let_grade("");

    // Calculates number grade to be used to determine letter grade
    float num_grade = std::floor(((earned_max.first / earned_max.second)) * 100);

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

    std::cout << "\nGrade:\t\t" << num_grade << "|" << let_grade << "\nCumulative:\t"
              << earned_max.first << "/1000" << "\n\n";

}

// Prompts user for assignment name, and prints grade for that assignment
void Individual(std::vector<GradebookTest> &work) {
    std::cout << "\nInput name of assignment to display:";
    std::string assign_name;
    std::cin >> assign_name;

    // If assignment name was in lowercase, convert to uppercase
    if ((assign_name[0] >= 'a') && assign_name[0] <= 'z') {
        assign_name[0] -= 32;

    }

    // Checks if name exists in CSV file
    while (FindWork(work, assign_name) == -1) {
        std::cout << "\nName not found in CSV; Re-enter name:";
        std::cin >> assign_name;

        // If assignment name was in lowercase, convert to uppercase
        if ((assign_name[0] >= 'a') && assign_name[0] <= 'z') {
            assign_name[0] -= 32;

        }
    }

    work[FindWork(work, assign_name)].PrintGrade();

}

// Prompts user for category, and prints all grades associated with that category
void Category(std::vector<GradebookTest> &work) {
    std::cout << "\nInput name of category to display:";
    std::string cat_name;
    std::cin >> cat_name;

    // If assignment name was in lowercase, convert to uppercase
    if ((cat_name[0] >= 'a') && cat_name[0] <= 'z') {
        cat_name[0] -= 32;

    }

    std::cout << "\nFor " << cat_name << ":\n";
    for (int i = 0; i < work.size(); i++) {
        if (work[i].GetType() == cat_name) {
            std::cout << "\t";
            work[i].PrintGrade();
        }
    }
}

// Prompts
void Course(std::vector<GradebookTest> &work, int &input) {
    std::cout << "\nChoose [Course] option:\n"
              << "\t1. All grades\n\t2. Category totals\n\t3. Course overall\n";
    std::cin >> input;

    if (input == 1) {                   // Outputs all grades
        std::cout << "\nLab:\n";
            for (int i = 0; i < work.size(); i++) {
                if (work[i].GetType() == "Lab") {
                    std::cout << "\t";
                    work[i].PrintGrade();
                } else {}
            }
            std::cout << "Assignment:\n";
        for (int i = 0; i < work.size(); i++) {
            if (work[i].GetType() == "Assignment") {
                std::cout << "\t";
                work[i].PrintGrade();
            } else {}
        }
        std::cout << "Project:\n";
        for (int i = 0; i < work.size(); i++) {
            if (work[i].GetType() == "Project") {
                std::cout << "\t";
                work[i].PrintGrade();
            } else {}
        }
        std::cout << "Exam:\n";
        for (int i = 0; i < work.size(); i++) {
            if (work[i].GetType() == "Exam") {
                std::cout << "\t";
                work[i].PrintGrade();
            } else {}
        }
        Cumulative(work);

    } else if (input == 2) {                // Outputs total earned for each category
        float total = 0.0;

        for (int i = 0; i < work.size(); i++) {
            if ((work[i].GetEarned() != - 1) && (work[i].GetType() == "Lab")) {
                total += work[i].GetEarned();
            } else {}
        }
        std::cout << "Lab:\t\t" << total << "\n";
        total = 0;
        for (int i = 0; i < work.size(); i++) {
            if ((work[i].GetEarned() != - 1) && (work[i].GetType() == "Assignment")) {
                total += work[i].GetEarned();
            } else {}
        }
        std::cout << "Assignment:\t" << total << "\n";
        total = 0;
        for (int i = 0; i < work.size(); i++) {
            if ((work[i].GetEarned() != - 1) && (work[i].GetType() == "Project")) {
                total += work[i].GetEarned();
            } else {}
        }
        std::cout << "Project:\t" << total << "\n";
        total = 0;
        for (int i = 0; i < work.size(); i++) {
            if ((work[i].GetEarned() != - 1) && (work[i].GetType() == "Exam")) {
                total += work[i].GetEarned();
            } else {}
        }
        std::cout << "Exam:\t\t" << total << "\n";
        total = 0;

        Cumulative(work);

    } else if (input == 3) {                // Outputs current grade and cumulative
        Cumulative(work);

    } else {
        std::cout << "Error: Valid option not chosen.\n";

    }
}
