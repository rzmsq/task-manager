#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

class Task
{
private:
    std::string title;
    std::string description;
    std::time_t dueTime;
    bool isCompleted{false};

public:
    Task(const std::string &title, const std::string &description,
         const std::time_t &dueTime);
    ~Task();
};

Task::Task(const std::string &title, const std::string &description,
           const std::time_t &dueTime)
{
    this->title = title;
    this->description = description;
    this->dueTime = dueTime;
}

Task::~Task()
{
}

int main(int argc, char const *argv[])
{
    auto timeNow = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(timeNow);

    Task newTask = Task("test", "new test", time);
    return 0;
}
