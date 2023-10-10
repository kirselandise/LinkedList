#include "LinkedList.h"

template <typename Item_Type>
//Creates struct Node used for finding location and data within the list
struct Single_Linked_List<Item_Type>::Node {
    Item_Type data;
    Node* next;

    Node() : data(Item_Type()), next(nullptr) {}

    Node(const Item_Type& item) : data(item), next(nullptr) {}
};

template <typename Item_Type>
//Single_Linked_List Constructor
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {
    head = new Node();
    head->data = Item_Type(); //Defines data, current node's type
    head->next = nullptr; //Defines head->next, pointer to the next value
    tail = nullptr;
}

//Getter for head
template <typename Item_Type>
typename Single_Linked_List<Item_Type>::Node* Single_Linked_List<Item_Type>::getHead() {
    return &head;
}

//Adds a value at the beginning of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (head->next == nullptr) {
        // Checks if the list is empty
        head->next = new_node;
        tail = new_node;  // Update tail when list was empty
    }
    else {
        // Updates head and next
        new_node->next = head->next;
        head->next = new_node;
    }
    num_items++; // Increases size of the list
}

//Adds a value at the end of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (!tail)
        tail = head;
    tail->next = new_node;
    tail = new_node;
    num_items++;
}

//Deletes first value
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (head->next == nullptr)
        return;

    Node* temp = head->next;
    head->next = head->next->next;
    delete temp;
    num_items--;

    if (head->next == nullptr)
        tail = nullptr;
}

//Deletes last value
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (!tail || tail == head)
        return;

    Node* current = head->next;
    while (current->next != tail)
        current = current->next;

    delete tail;
    tail = current;
    tail->next = nullptr;
    num_items--;
}

//Gets first value
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (head->next == nullptr)
        throw std::out_of_range("List is empty");

    return head->next->data;
}

//Gets last value
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (!tail || tail == head)
        throw std::out_of_range("List is empty");

    return tail->data;
}

//Boolean to test if list is empty (contains no values)
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head->next == nullptr;
}

//Prints list for testing and user interface
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print_list() const {
    Node* current = head->next;
    cout << "The List: ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n\n";
}

//Inserts value at a specific index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type item) {
    if (index > num_items) {
        push_back(item);
        return;
    }


    Node* new_node = new Node(item);
    Node* current = head;

    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    num_items++;
}

//Removes value at a specific index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items)
        return false;

    Node* current = head;

    for (size_t i = 0; i < index; ++i)
        current = current->next;

    Node* temp = current->next;
    current->next = current->next->next;

    if (temp == tail)
        tail = current;

    delete temp;
    num_items--;

    return true;
}

//Finds a value in the list and returns its index
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* current = head->next;
    size_t index = 0;

    while (current) {
        if (current->data == item)
            return index;

        current = current->next;
        index++;
    }

    return num_items;
}

// Definitions for Professional member functions
Professional::Professional(double salary, int vacationDays) : monthlySalary(salary), vacationDays(vacationDays) {}

double Professional::calculateWeeklySalary() const {
    return monthlySalary / 4.0; // Assuming a month has 4 weeks
}

double Professional::computeHealthCareContributions() const {
    return 100.0; // Some arbitrary value for demonstration
}

int Professional::computeVacationDays() const {
    return vacationDays;
}

// Definitions for Nonprofessional member functions
Nonprofessional::Nonprofessional(double rate, int hours) : hourlyRate(rate), workedHours(hours) {}

double Nonprofessional::calculateWeeklySalary() const {
    return hourlyRate * workedHours;
}

double Nonprofessional::computeHealthCareContributions() const {
    return hourlyRate * 10; // Some arbitrary value for demonstration
}

int Nonprofessional::computeVacationDays() const {
    return workedHours / 10; // Assuming one vacation hour for every 10 hours worked
}

int main() {
    //Testing the Classes
    Single_Linked_List<int> intList;

    cout << "Initializing Empty List \n";
    intList.print_list();

    //Test empty
    cout << "Is the list empty? " << (intList.empty() ? "Yes" : "No") << "\n\n";

    //Adds 1, 2, 3 to the front of the list, displaying them backwards. Test push_front
    cout << "Adding 1, 2, and 3 into the front of the list using push_front \n";
    intList.push_front(1);
    intList.push_front(2);
    intList.push_front(3);
    intList.print_list();

    //Adds 4, 5, 6 to the end of the list, displaying them forwards. Test push_back
    cout << "Adding 4, 5, and 6 into the back of the list using push_back \n";
    intList.push_back(4);
    intList.push_back(5);
    intList.push_back(6);
    intList.print_list();

    //Test pop_front
    cout << "Removing the first node using pop_front \n";
    intList.pop_front();
    intList.print_list();

    //Test pop_back
    cout << "Removing the last node using pop_back \n";
    intList.pop_back();
    intList.print_list();

    //Test front
    cout << "Front element: " << intList.front() << "\n";
    //Test back
    cout << "Back element: " << intList.back() << "\n";
    //Test empty
    cout << "Is the list empty? " << (intList.empty() ? "Yes" : "No") << "\n\n";

    //Test insert
    cout << "Inserting 100 at index 2\n";
    intList.insert(2, 100);
    intList.print_list();
    cout << "Inserting 200 at index 0\n";
    intList.insert(0, 200);
    intList.print_list();
    //Test insert out of bounds
    cout << "Inserting 300 at index 17 (out of bounds)\n";
    intList.insert(17, 300);
    intList.print_list();

    //Test remove
    cout << "Removing element at index 1: " << (intList.remove(1) ? "Success" : "Failed") << "\n\n";
    intList.print_list();
    //Test remove out of bounds
    cout << "Removing element at index 10: " << (intList.remove(10) ? "Success" : "Failed") << "\n\n";
    intList.print_list();

    //Test find
    cout << "Finding element 4: Index = " << intList.find(4) << "\n";
    //Test find out of bounds
    cout << "Finding element 10: Index = " << intList.find(10) << "\n\n";

    // Testing Professional employee
    Professional professional(5000.0, 20); // Monthly salary of $5000, 20 vacation days
    cout << "Professional Employee with a Monthly Salary of $5000 and 20 Vacation Days.\n";
    cout << "Professional Weekly Salary: $" << professional.calculateWeeklySalary() << "\n";
    cout << "Professional Health Care Contributions: $" << professional.computeHealthCareContributions() << "\n";
    cout << "Professional Vacation Days: " << professional.computeVacationDays() << "\n\n";

    // Testing Nonprofessional employee
    Nonprofessional nonprofessional(15.0, 30); // Hourly rate of $15, worked 30 hours
    cout << "Nonprofessional Employee with an Hourly Rate of $15 who worked 30 hours.\n";
    cout << "Nonprofessional Weekly Salary: $" << nonprofessional.calculateWeeklySalary() << "\n";
    cout << "Nonprofessional Health Care Contributions: $" << nonprofessional.computeHealthCareContributions() << "\n";
    cout << "Nonprofessional Vacation Hours: " << nonprofessional.computeVacationDays() << "\n";

    return 0;
}
