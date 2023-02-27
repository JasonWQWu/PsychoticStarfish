#include "gradebook_test.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

GradebookTest::GradebookTest(std::vector<std::string> work) {
    this->m_task = work[0];
    this->m_type = work[1];
    this->m_earned = std::stof(work[2]);
    this->m_max = std::stof(work[3]);
}

void GradebookTest::SetTask(std::string task) {
    this->m_task = task;
}

std::string GradebookTest::GetTask() {
    return m_task;
}

void GradebookTest::SetType(std::string type) {
    this->m_type = type;
}

std::string GradebookTest::GetType() {
    return m_type;
}

void GradebookTest::SetEarned(float earned) {
    this->m_earned = earned;
}

float GradebookTest::GetEarned() {
    return m_earned;
}

void GradebookTest::SetMax(float max) {
    this->m_max = max;
}

float GradebookTest::GetMax() {
    return m_max;
}

void GradebookTest::PrintGrade() {
    if (m_earned == -1) {
        std::cout << this->m_task << ":\tIncomplete/" << this->m_max << "\n";

    } else {
        std::cout << this->m_task << ":\t" << this->m_earned << "/" << this->m_max << "\n";
    }
}

