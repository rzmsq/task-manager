#include "./task.hpp"

Task::Task(const std::string &_title, const std::string &_description,
           const std::string &_dueTme, const bool &_isCompl)
{
    this->title = _title;
    this->description = _description;
    this->dueTime = _dueTme;
    this->isCompleted = _isCompl;
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