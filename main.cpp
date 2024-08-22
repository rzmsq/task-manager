#include "./obj/task_manager.hpp"

int main(int argc, char const *argv[])
{
    Task newTask = Task("test", "descr", "14.02.2025");
    TaskManager manager = TaskManager();

    // manager.add_task(newTask);
    // manager.add_task(newTask);5

    manager.print_tasks();

    // manager();
    return 0;
}
