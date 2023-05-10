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

    Employee::~Employee()
    {
        delete[] sal_change_rates;
    }

    Employee::Employee() : Person(), work_email("work@"), salary(0.0), cnt_sal_changes(10)
    {
        sal_change_rates = new double[cnt_sal_changes];
        for (int i = 0; i < cnt_sal_changes; ++i)
        {
            sal_change_rates[i] = 0.0;
        }
    }

    Employee::Employee(const Employee &clone) : Person(clone), work_email(clone.work_email), salary(clone.salary), cnt_sal_changes(clone.cnt_sal_changes)
    {
        sal_change_rates = new double[cnt_sal_changes];
        for (int i = 0; i < cnt_sal_changes; ++i)
        {
            sal_change_rates[i] = clone.sal_change_rates[i];
        }
    }

    Employee Employee::operator=(const Employee &rhs)
    {
        if (this != &rhs)
        {
            Person::operator=(rhs);
            work_email = rhs.work_email;
            salary = rhs.salary;
            cnt_sal_changes = rhs.cnt_sal_changes;
            delete[] sal_change_rates;
            sal_change_rates = new double[cnt_sal_changes];
            for (int i = 0; i < cnt_sal_changes; ++i)
            {
                sal_change_rates[i] = rhs.sal_change_rates[i];
            }
        }
        return *this;
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
        int totalNum = numPersons + numEmployees;
        arrayPersonEmp = new Person *[totalNum];

        for (int i = 0; i < numPersons; i++)
        {
            arrayPersonEmp[i] = new Person();
            arrayPersonEmp[i]->setEmail("personal@gmail.com");
        }

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
