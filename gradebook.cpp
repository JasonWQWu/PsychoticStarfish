#include "gradebook.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

Gradebook::Gradebook(std::vector<std::string> work) {
    this->m_task = work[0];
    this->m_type = work[1];
    this->m_earned = std::stof(work[2]);
    this->m_max = std::stof(work[3]);
}

void Gradebook::SetTask(std::string task) {
    this->m_task = task;
}

std::string Gradebook::GetTask() {
    return m_task;
}

void Gradebook::SetType(std::string type) {
    this->m_type = type;
}

std::string Gradebook::GetType() {
    return m_type;
}

void Gradebook::SetEarned(float earned) {
    this->m_earned = earned;
}

float Gradebook::GetEarned() {
    return m_earned;
}

void Gradebook::SetMax(float max) {
    this->m_max = max;
}

float Gradebook::GetMax() {
    return m_max;
}

void Gradebook::PrintGrade() {
    if (m_earned == -1) {
        std::cout << this->m_task << ":\tIncomplete/" << this->m_max << "\n";

    } else {
        std::cout << this->m_task << ":\t" << this->m_earned << "/" << this->m_max << "\n";
    }
}

