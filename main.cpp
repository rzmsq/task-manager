#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include <nlohmann/json.hpp>

class Task
{
private:
    std::string title;
    std::string description;
    std::string dueTime;
    bool isCompleted{false};

public:
    Task(const std::string &title, const std::string &description,
         const std::string &time);
    ~Task() {};

    const std::string &getTitle() const;
    const std::string &getDescription() const;
    const std::string &getTime() const;
    const bool &getCompl() const;
};

Task::Task(const std::string &_title, const std::string &_description,
           const std::string &_dueTme)
{
    this->title = _title;
    this->description = _description;
    this->dueTime = _dueTme;
}

const std::string &Task::getTitle() const
{
    return this->title;
};
const std::string &Task::getDescription() const
{
    return this->description;
};
const std::string &Task::getTime() const
{
    return this->dueTime;
};
const bool &Task::getCompl() const
{
    return this->isCompleted;
};

class TaskManager
{
private:
    std::vector<Task> tasks;

public:
    TaskManager();
    ~TaskManager();

    const void add_task(const Task &task);
    const void delete_task(const size_t &id);
    const void print_tasks() const;
};

TaskManager::TaskManager(/* args */)
{
}

TaskManager::~TaskManager()
{
}

const void TaskManager::add_task(const Task &task)
{
    tasks.push_back(task);
}

const void TaskManager::delete_task(const size_t &id)
{
    tasks.erase(tasks.begin() + id);
}

const void TaskManager::print_tasks() const
{
    for (auto &&task : this->tasks)
    {
        const std::string Compl = task.getCompl() ? "Completed" : "In progress";
        std::cout << task.getTitle() << "\t|" << task.getDescription()
                  << "\t|" << task.getTime() << "\t|" << Compl << std::endl;
    }
}

int main(int argc, char const *argv[])
{

    Task newTask = Task("test", "new test", "10.07.2023");
    TaskManager manager = TaskManager();

    manager.add_task(newTask);
    manager.add_task(newTask);

    manager.delete_task(1);

    manager.print_tasks();

    return 0;
}
