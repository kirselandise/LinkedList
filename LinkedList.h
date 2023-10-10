//Header file providing all the necessary resources for LinkedList.cpp

#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node;

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();

    Node* getHead();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void print_list() const;
    void insert(size_t index, const Item_Type item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
};

class Employee {
public:
    virtual double calculateWeeklySalary() const = 0;
    virtual double computeHealthCareContributions() const = 0;
    virtual int computeVacationDays() const = 0;
};

class Professional : public Employee {
private:
    double monthlySalary;
    int vacationDays;

public:
    Professional(double salary, int vacationDays);

    double calculateWeeklySalary() const override;
    double computeHealthCareContributions() const override;
    int computeVacationDays() const override;
};

class Nonprofessional : public Employee {
private:
    double hourlyRate;
    int workedHours;

public:
    Nonprofessional(double rate, int hours);

    double calculateWeeklySalary() const override;
    double computeHealthCareContributions() const override;
    int computeVacationDays() const override;
};
