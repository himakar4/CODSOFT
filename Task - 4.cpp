//TO DO LIST

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Task 
{
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks, const string& description) 
{
	tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}


void viewTasks(const vector<Task>& tasks) 
{
    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) 
	{
        cout << i + 1 << ". ";
        if (tasks[i].completed) 
		{
            cout << "[X] ";
        } 
		else 
		{
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to mark a task as completed  
void markAsCompleted(vector<Task>& tasks, size_t index) 
{
    if (index >= 1 && index <= tasks.size()) 
	{
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    } 
	else 
	{
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, size_t index) 
{
    if (index >= 1 && index <= tasks.size()) 
	{
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    } 
	else 
	{
        cout << "Invalid task index." << endl;
    }
}

int main() 
{
    vector<Task> tasks;

    while (true) 
	{
        cout << "\n==== ToDo List Manager ====" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) 
		{
            case 1: 
			{
                cout << "Enter task description: ";
                string description;
                cin.ignore(); 
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: 
			{
                cout << "Enter task index to mark as completed: ";
                size_t index;
                cin >> index;
                markAsCompleted(tasks, index);
                break;
            }
            case 4: 
			{
                cout << "Enter task index to remove: ";
                size_t index;
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                cout << "Exiting ToDo List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please choose again.\n";
        }
    }

    return 0;
}

