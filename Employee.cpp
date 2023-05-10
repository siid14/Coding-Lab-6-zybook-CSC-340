//
//  Employee.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by ... on ...
//

#include "Employee.h"

namespace NS_PersonEmployee
{

    // * constructor implementation

    // Destructor for Employee class.
    Employee::~Employee()
    {
        delete[] sal_change_rates; // Deallocate the array of doubles.
    }

    Employee::Employee() : Person(), work_email("work@"), salary(0.0), cnt_sal_changes(10)
    {
        // Constructor for Employee class.
        // Call base class constructor (Person) with no arguments.
        // Initialize work email to "work@".
        // Initialize salary to 0.0.
        // Set the count of salary changes to 10.

        sal_change_rates = new double[cnt_sal_changes]; // Allocate an array of doubles of size cnt_sal_changes.
        for (int i = 0; i < cnt_sal_changes; ++i)
        {
            sal_change_rates[i] = 0.0; // Set each element of the array to 0.0.
        }
    }

    // Copy constructor that initializes an Employee object with the same data as another employee object
    Employee::Employee(const Employee &clone) : Person(clone), work_email(clone.work_email), salary(clone.salary), cnt_sal_changes(clone.cnt_sal_changes)
    {
        // Allocating memory to sal_change_rates pointer based on cnt_sal_changes variable of the clone object
        sal_change_rates = new double[cnt_sal_changes];

        // Copying the values of the array pointed by clone object's sal_change_rates pointer to the newly allocated array
        for (int i = 0; i < cnt_sal_changes; ++i)
        {
            sal_change_rates[i] = clone.sal_change_rates[i];
        }
    }

    Employee Employee::operator=(const Employee &rhs)
    {
        if (this != &rhs) // Check if the object being assigned to is not the same as the rhs object
        {
            Person::operator=(rhs);                         // Call the base class assignment operator
            work_email = rhs.work_email;                    // Copy the work email
            salary = rhs.salary;                            // Copy the salary
            cnt_sal_changes = rhs.cnt_sal_changes;          // Copy the count of salary changes
            delete[] sal_change_rates;                      // Free the memory allocated for the salary change rates
            sal_change_rates = new double[cnt_sal_changes]; // Allocate new memory for the salary change rates
            for (int i = 0; i < cnt_sal_changes; ++i)
            {
                sal_change_rates[i] = rhs.sal_change_rates[i]; // Copy the salary change rates
            }
        }
        return *this; // Return the updated object by reference
    }

    // * functions implementation

    double Employee::getChangeRate(int i) const
    {
        if (i >= 0 && i < cnt_sal_changes)
        {
            return sal_change_rates[i];
        }
        else
        {
            return -1.00;
        }
    }

    string Employee::getEmail() const
    {
        return work_email;
    }

    void Employee::setEmail(string new_email)
    {
        work_email = new_email;
    }

    string Employee::getTypeOfObj() const
    {
        return "Employee";
    }

    void mixedArray(Person **&arrayPersonEmp, int numPersons, int numEmployees)
    {
        // Calculate total number of elements in the mixed array
        int totalNum = numPersons + numEmployees;

        // Create a new array of pointers to Person objects with the total number of elements
        arrayPersonEmp = new Person *[totalNum];

        // Initialize the first numPersons elements with new Person objects and set their email addresses to personal@gmail.com
        for (int i = 0; i < numPersons; i++)
        {
            arrayPersonEmp[i] = new Person();
            arrayPersonEmp[i]->setEmail("personal@gmail.com");
        }

        // Initialize the remaining numEmployees elements with new Employee objects and set their email addresses to work@gmail.com
        for (int j = 0; j < numEmployees; j++)
        {
            arrayPersonEmp[numPersons + j] = new Employee();
            arrayPersonEmp[numPersons + j]->setEmail("work@gmail.com");
        }
    }

    void deleteMixedArray(Person **&arrayPersonEmp, int size)
    {
        // loop through each element in the array
        for (int i = 0; i < size; i++)
        {
            // delete the object pointed to by the Person pointer
            delete arrayPersonEmp[i];
        }

        // delete the array of Person pointers
        delete[] arrayPersonEmp;
        arrayPersonEmp = nullptr;
    }

} // end-of namespace NS_PersonEmployee
