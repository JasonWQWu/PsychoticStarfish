#pragma once

#include <iostream>
#include <vector>
#include <string>

class Gradebook {

        private:
            std::string m_task;
            std::string m_type;
            float m_earned;
            float m_max;

        public:
            Gradebook(std::vector<std::string> work);
        
            void SetTask(std::string task);
            std::string GetTask();
            void SetType(std::string type);
            std::string GetType();
            void SetEarned(float earned);
            float GetEarned();
            void SetMax(float max);
            float GetMax();
            void PrintGrade();
};
