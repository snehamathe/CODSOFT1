#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }

        cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear newline from the input buffer
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                cout << "Enter task number to mark as completed: ";
                int index;
                cin >> index;
                toDoList.markTaskCompleted(index);
                break;
            }
            case 4: {
                cout << "Enter task number to remove: ";
                int index;
                cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}