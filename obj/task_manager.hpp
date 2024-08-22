#pragma once

#include "./task.hpp"

class TaskManager
{
private:
    using json = nlohmann::json;

    std::vector<Task> tasks;
    const std::string path{"./tasks.json"};

    const void read_from_json();

public:
    TaskManager() { read_from_json(); };
    ~TaskManager() {};

    const void add_task(const Task &task);
    const void delete_task(const size_t &id);
    const void print_tasks() const;
    const void save_to_json() const;
};