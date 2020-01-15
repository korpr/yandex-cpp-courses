#include <string>
#include <map>
using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
private:
    map<string, TasksInfo> task_for_persons;
    TaskStatus Next_Status ( TaskStatus& current )
    {
        switch ( current ) {
        case TaskStatus::NEW:
            return TaskStatus::IN_PROGRESS;
            break;
        case TaskStatus::IN_PROGRESS:
            return TaskStatus::TESTING;
            break;
        case TaskStatus::TESTING:
            return TaskStatus::DONE;
            break;
        case TaskStatus::DONE:
            return  TaskStatus::DONE;
            break;
        }
    }
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo ( const string& person ) const
    {
        if ( task_for_persons.count ( person ) ) {
            return task_for_persons.at ( person );
        }
        throw domain_error ( "" );
    }
    
    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask ( const string& person )
    {
        ++task_for_persons[person][TaskStatus::NEW];
    }
    
    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks (
        const string& person, int task_count )
    {
        TasksInfo updated;
        TasksInfo not_updated;
        TasksInfo tasks  = task_for_persons.at ( person );
        TasksInfo& tasks_for_update  = task_for_persons.at ( person );
        
        for ( const auto& task : tasks ) {
            if ( task.first == TaskStatus::DONE  || task_count < 1 ) {
                break;
            }
            TaskStatus next = Next_Status ( task.first );
            
            int delta = task.second  - task_count ;
            if ( delta <= 0 ) {
                tasks_for_update[next] += tasks_for_update[ task.first];
                tasks_for_update.erase ( task.first );
                
                updated[next] = task.second;
            } else {
                tasks_for_update[task.first] = delta;
                tasks_for_update[next] += task_count;
                
                updated[next] = task_count;
                not_updated[task.first] = delta;
                break;
            }
            task_count = abs ( delta );
        }
        
        return make_tuple ( updated, not_updated );
    }
};
