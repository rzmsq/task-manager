#include <regex>

#include "./obj/task_manager.hpp"

void inputTask(TaskManager &manager);
void inputID(TaskManager &manager);
const bool isAllDigit(const std::string &input);

int main(int argc, char const *argv[])
{
    std::cout << "\t\t Tasks manager v0.1" << std::endl;

    bool progRun{true};
    TaskManager manager = TaskManager();

    while (progRun)
    {
        std::cout << "Please choose the option" << std::endl
                  << "1 - Add new task" << std::endl
                  << "2 - Print tasks" << std::endl
                  << "3 - Delete task" << std::endl
                  << "4 - Quit" << std::endl;
        std::string input{};
        getline(std::cin, input);

        if (input.size() != 1)
            continue;

        const char option = input[0];

        switch (option)
        {
        case '1':
            inputTask(manager);
            break;
        case '2':
            manager.print_tasks();
            break;
        case '3':
            inputID(manager);
            break;
        case '4':
            progRun = false;
            break;
        default:
            std::cout << "Error! Incorrect input!" << std::endl;
            break;
        }
    }

    return 0;
}

const bool isAllDigit(const std::string &input)
{
    std::regex digitReg("[0-9]");
    return std::regex_match(input, digitReg);
}

void inputID(TaskManager &manager)
{
    {
        std::cout << "Enter task id: ";
        std::string id{};
        getline(std::cin, id);

        if (!isAllDigit(id))
            std::cout << "Error! Incorrect id" << std::endl;
        else
        {
            long ind = std::stol(id);
            manager.delete_task(ind);
        }
    }
}
void inputTask(TaskManager &manager)
{
    {

        std::cout << "Enter task title: ";
        std::string title{};
        getline(std::cin, title);

        std::cout << "Enter task description: ";
        std::string description{};
        getline(std::cin, description);

        std::cout << "Enter task due time: ";
        std::string dueTime{};
        getline(std::cin, dueTime);

        Task newTask = Task(title, description, dueTime);
        manager.add_task(newTask);
    }
}
