//
//  Person.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by ...
//

#include "Person.h"

namespace NS_PersonEmployee
{

    // * constructor implementation

    // default constructor
    Person::Person() : name(""), personalEmail(""), cntPlaces(10)
    {
        placesVisited = new string[cntPlaces];
        for (int i = 0; i < cntPlaces; i++)
        {
            placesVisited[i] = "unknown";
        }
    }

    // // parameterized constructor
    // Person::Person(const char *newName, const char *newPersonalEmail) : cntPlaces(10)
    // {
    //     setName(newName);
    //     setEmail(newPersonalEmail);
    //     placesVisited = new string[cntPlaces];
    //     for (int i = 0; i < cntPlaces; i++)
    //     {
    //         placesVisited[i] = "unknown";
    //     }
    // }

    // copy constructor
    Person::Person(const Person &other) : cntPlaces(10)
    {
        setEmail(other.personalEmail);
        placesVisited = new string[cntPlaces];
        for (int i = 0; i < cntPlaces; i++)
        {
            placesVisited[i] = other.placesVisited[i];
        }
    }

    // destructor
    Person::~Person()
    {
        delete[] placesVisited;
    }

    // assignment operator
    Person Person::operator=(const Person &other)
    {
        if (this != &other)
        {
            setEmail(other.personalEmail);
            for (int i = 0; i < cntPlaces; i++)
            {
                placesVisited[i] = other.placesVisited[i];
            }
        }
        return *this;
    }

    // * functions implementation

    string Person::getPlace(int i) const
    {
        if (i >= 0 && i < cntPlaces)
        {
            return placesVisited[i];
        }
        else
        {
            return "out of bundary";
        }
    }

    string Person::getEmail() const
    {
        return personalEmail;
    }

    void Person::setEmail(string new_email)
    {
        personalEmail = new_email;
    }

    string Person::getTypeOfObj() const
    {
        return "Person";
    }

} // end-of namespace NS_PersonEmployee
