                                        // First Application from (C++ course) using methods
#include <iostream>
using namespace std;

void startApp()
{
    cout << "Enter your choice: " << endl;
    cout << "1) Add new employee" << endl;
    cout << "2) Print all employees" << endl;
    cout << "3) Delete by age" << endl;
    cout << "4) Update salary by name" << endl;
    cout << "5) Exit the Application" << endl;
    cout << "*****************************" << endl;
}

void printError(int &choice)
{
    cout << "Invalid choice, pls try again !" << endl;
    startApp();
    cin >> choice;

}

void addNewEmp(int &index, string Emp_name[50], int Emp_age[50], int Emp_salary[50], char Emp_gender[50])
{
        cout << endl<< "******* Employee Card *******" << endl;
        cout << "Employee name : ";
        cin.ignore();
        getline(cin, Emp_name[index]);
        cout << "Employee age : ";
        cin >> Emp_age[index];
        cout << "Employee salary : ";
        cin >> Emp_salary[index];
        cout << "Employee gender (F/M) : ";
        cin >> Emp_gender[index];
        index++;
        cout << "*****************************" << endl;
}

void printAllEmps(int &index, string Emp_name[50], int Emp_age[50], int Emp_salary[50], char Emp_gender[50])
{

      if (index)
      {
        cout << endl<< "******* Employees details *******" << endl;
        for(int i = 0; i < index; i++)
        {
            if(Emp_age[i])
            {
                    cout << "*********************************" << endl;
                    cout << "***** Employee ( " << i + 1 << " ) details *****" << endl;
                    cout << "Name : " << Emp_name[i] << endl;
                    cout << "Age : " << Emp_age[i] << endl;
                    cout << "Salary : " << Emp_salary[i] << endl;
                    cout << "Gender : " << Emp_gender[i] << endl;
                }
            }

      }
      else
        cout << "No Employees in the system ! " << endl;

}

void deleteByAge(int &index, int Emp_age[50])
{
    if (index)
    {
        int start_age, end_age;
        cout << "Enter the starting date : ";
        cin >> start_age;
        cout << "Enter the ending date : ";
        cin >> end_age;
        for(int i = 0; i <= index; i++)
        {
            if(Emp_age[i] >= start_age && Emp_age[i] <= end_age)
            {
                Emp_age[i] = 0;
            }
        }
    }
    else
        cout << "No Employees in the system !";
}

void updateSalary(int &index, string Emp_name[50], int Emp_salary[50])
{
    if(index)
    {
        string name;
        int salary;
        cout << "Enter the name : ";
        cin >> name;
        cout << "Enter the salary : ";
        cin >> salary;

        for(int i = 0; i <= index; i++)
        {
            if (name == Emp_name[i])
            {
                Emp_salary[i] = salary;
            }
        }
    }
    else
        cout << "No Employees in the system !";
}

int main()
{
    int choice;
    int index = 0;
    int Emp_age[50], Emp_salary[50];
    string Emp_name[50];
    char Emp_gender[50];

    while(true)
    {

        startApp();
        cin >> choice;

        if (choice > 5 || choice < 1)
            printError(choice);


        if (choice == 1)
        {
            addNewEmp(index, Emp_name, Emp_age, Emp_salary, Emp_gender);
        }
        else if (choice == 2)
        {
            printAllEmps(index, Emp_name, Emp_age, Emp_salary, Emp_gender);
        }
        else if (choice == 3)
        {
            deleteByAge(index, Emp_age);
        }
        else if(choice == 4)
        {
            updateSalary(index, Emp_name, Emp_salary);
        }
        else if (choice == 5)
        {
            cout <<"See you soon !";
            break;
        }

        cout << endl << "###############################\n" << endl;
    }


    return 0;
}
