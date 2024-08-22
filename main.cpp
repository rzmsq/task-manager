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
    const std::string path{"./tasks.json"};

public:
    TaskManager() {};
    ~TaskManager() {};

    const void add_task(const Task &task);
    const void delete_task(const size_t &id);
    const void print_tasks() const;
    const void save_to_json() const;
};

const void TaskManager::add_task(const Task &task)
{
    tasks.push_back(task);
}

const void TaskManager::delete_task(const size_t &id)
{
    tasks.erase(tasks.begin() + (id - 1));
}

const void TaskManager::print_tasks() const
{
    size_t ind{0};
    for (auto &&task : this->tasks)
    {
        const std::string Compl = task.getCompl() ? "Completed" : "In progress";
        std::cout << ind << "|\t|" << task.getTitle() << "|\t|" << task.getDescription()
                  << "|\t|" << task.getTime() << "|\t|" << Compl << std::endl;
        ind++;
    }
}

const void TaskManager::save_to_json() const
{
    using json = nlohmann::json;
    try
    {
        std::ofstream f(path, std::ios_base::app);
        if (!f.is_open())
            throw "err";

        json jsonTasks{};
        size_t ind{0};
        for (auto &&task : tasks)
        {
            jsonTasks["id"][std::to_string(ind)]["title"] = task.getTitle();
            jsonTasks["id"][std::to_string(ind)]["description"] = task.getDescription();
            jsonTasks["id"][std::to_string(ind)]["dueTime"] = task.getTime();
            jsonTasks["id"][std::to_string(ind)]["isCompleted"] = task.getCompl();
            ind++;
        }

        f << jsonTasks;
        f.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int argc, char const *argv[])
{

    Task newTask = Task("test", "new test", "10.07.2023");
    TaskManager manager = TaskManager();

    manager.add_task(newTask);
    manager.add_task(newTask);

    manager.print_tasks();

    manager.save_to_json();

    return 0;
}
