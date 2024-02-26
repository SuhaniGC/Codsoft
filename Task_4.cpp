/*
Build a simple console-based to-do list manager that allows users to add, view, anddelete tasks.

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.
*/

#include <iostream>
#include <vector>
using namespace std;

class TODOLIST
{
private:
    vector<string> Index;
    vector<bool> Completed;

public:
    void AddTask()
    {
        string Task;
        cout << "\t\t\t| Write Down the Task Description | \t\t\t" << "\n";
        cin.ignore();
        getline(cin, Task);
        Index.push_back(Task);
        Completed.push_back(false);
        cout << "\t---Task Added Successfully---\t" << "\n";
    }

    void ViewTask()
    {
        int n = Index.size();
        if (n == 0) 
        {
            cout << "\t---No tasks available---\t" << "\n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "\t\t\t" << i + 1 << ". ";
            cout << Index[i] << " ";
            if (Completed[i])
                cout << "[Completed] ";
            cout<<"\n";
        }
    }

    void RemoveTask()
    {
        int Task_Index;
        ViewTask();
        int n = Index.size();
        if (n == 0) 
        {
            cout << "\t---No tasks available to remove---\t" << "\n";
            return;
        }
        cout << "Enter the Task no which you want to Remove from your TO-DO-LIST: ";
        cin >> Task_Index;
        if (Task_Index < 1 || Task_Index > n) 
        {
            cout << "Invalid task number!" << endl;
            return;
        }
        Index.erase(Index.begin() + Task_Index - 1);
        Completed.erase(Completed.begin() + Task_Index - 1);
        cout << "\t---Task Removed Successfully---\t" << "\n";
    }

    void MarkTaskCompleted()
    {
        int Task_Index;
        ViewTask();
        int n = Index.size();
        if (n == 0) 
        {
            cout << "\t---No tasks available to mark as completed---\t" << "\n";
            return;
        }
        cout << "Enter the Task no which you want to Mark as Completed: ";
        cin >> Task_Index;
        if (Task_Index < 1 || Task_Index > n) 
        {
            cout << "Invalid task number!" << endl;
            return;
        }
        Completed[Task_Index - 1] = true;
        cout << "\t---Task Marked as Completed---\t" << "\n";
    }
};

int main()
{
    TODOLIST obj;
    cout << "\tWelcome to the TO-DO-LIST Manager\t" << "\n";
    cout << "\t Here You Can Add, view, mark as complete, and delete the task from your TO-DO-LIST\t" << "\n";
    int choice;
    while (true)
    {
        cout << "\nTodo List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter the Operation you want to Perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.AddTask();
            break;
        case 2:
            obj.ViewTask();
            break;
        case 3:
            obj.MarkTaskCompleted();
            break;
        case 4:
            obj.RemoveTask();
            break;
        case 5:
            cout << "----You have Successfully Exited the TO-DO-LIST----";
            return 0;
        default:
            cout << "You have given the Wrong Input";
            break;
        }
    }
}