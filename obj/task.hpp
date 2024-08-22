#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

class Task
{
private:
    std::string title;
    std::string description;
    std::string dueTime;
    bool isCompleted;

public:
    Task(const std::string &title, const std::string &description,
         const std::string &time, const bool &isCompl = false);
    ~Task() {};

    const std::string &getTitle() const;
    const std::string &getDescription() const;
    const std::string &getTime() const;
    const bool &getCompl() const;
};