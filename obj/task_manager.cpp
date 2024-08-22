#include "./task_manager.hpp"

const void TaskManager::add_task(const Task &task)
{
    tasks.push_back(task);
}

const void TaskManager::delete_task(const size_t &id)
{
    try
    {
        tasks.erase(tasks.begin() + (id - 1));
    }
    catch (const std::exception &e)
    {
        std::cout << "Error! Task with index " << id << " is not exists!" << '\n';
    }
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
    try
    {
        json jsonTasks;

        std::ifstream inFile(path);
        if (inFile.good())
        {
            jsonTasks = json::parse(inFile);
            inFile.close();
        }

        std::ofstream f(path);
        if (!f.is_open())
            throw "err";

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

const void TaskManager::read_from_json()
{
    try
    {
        json jsonTasks;

        std::ifstream inFile(path);
        if (!inFile.good())
        {
            std::cout << "The tasks file.json won't find it, the tasks are empty!" << std::endl;
            return;
        }

        jsonTasks = json::parse(inFile);
        inFile.close();
        for (size_t i = 0; i < jsonTasks["id"].size(); i++)
        {
            Task newTask = Task(jsonTasks["id"][std::to_string(i)]["title"],
                                jsonTasks["id"][std::to_string(i)]["description"],
                                jsonTasks["id"][std::to_string(i)]["dueTime"],
                                jsonTasks["id"][std::to_string(i)]["isCompleted"]);
            this->add_task(newTask);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}