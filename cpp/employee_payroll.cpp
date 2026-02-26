#include <iostream>
#include <vector>
#include <string>
using namespace std;

// *****************************************************************//
// ========================== Employee Class ==========================
// *****************************************************************//
class Employee {
public:
    int empID;
    string name;
    string type; // Part-time or Full-time
    string dept;
    string contact;
    string address;

    Employee(int id, string n, string t, string d, string c, string a) {
        empID = id;
        name = n;
        type = t;
        dept = d;
        contact = c;
        address = a;
    }

    void display() {
        cout << "ID: " << empID
             << ", Name: " << name
             << ", Type: " << type
             << ", Dept: " << dept
             << ", Contact: " << contact
             << ", Address: " << address << endl;
    }
};

// *****************************************************************//
// ========================== Salary Class ==========================
// *****************************************************************//
class Salary {
public:
    int empID;
    string empType;

    // Full-time
    double basic, hra, da, pf;

    // Part-time
    double hours, rate;

    Salary(int id, string type) {
        empID = id;
        empType = type;
        basic = hra = da = pf = 0;
        hours = rate = 0;
    }

    double calculateSalary() {
        if (empType == "Full-time") {
            return basic + hra + da - pf;
        } else {
            return hours * rate;
        }
    }

    void display() {
        cout << "Employee ID: " << empID << ", Type: " << empType << endl;
        if (empType == "Full-time") {
            cout << "Basic: " << basic << ", HRA: " << hra
                 << ", DA: " << da << ", PF: " << pf << endl;
        } else {
            cout << "Hours: " << hours << ", Rate: " << rate << endl;
        }
        cout << "Net Salary: " << calculateSalary() << endl;
    }
};

// *****************************************************************//
// ========================== Global Storage ==========================
// *****************************************************************//
vector<Employee> employees;
vector<Salary> salaries;

// *****************************************************************//
// ========================== Employee Functions ==========================
// *****************************************************************//
void addEmployee() {
    int id;
    string name, type, dept, contact, address;

    cout << "Enter Employee ID: ";
    cin >> id;

    for (auto &e : employees) {
        if (e.empID == id) {
            cout << "Employee with this ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    cout << "Enter Type (Part-time/Full-time): "; getline(cin, type);
    cout << "Enter Department: "; getline(cin, dept);
    cout << "Enter Contact: "; getline(cin, contact);
    cout << "Enter Address: "; getline(cin, address);

    employees.push_back(Employee(id, name, type, dept, contact, address));
    cout << "Employee added successfully!\n";
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->empID == id) {
            employees.erase(it);
            cout << "Employee deleted successfully!\n";
            return;
        }
    }
    
    cout << "Employee not found!\n";
}

void updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    for (auto &e : employees) {
        if (e.empID == id) {
            cout << "Enter new Name: "; cin.ignore(); getline(cin, e.name);
            cout << "Enter new Type (Part-time/Full-time): "; getline(cin, e.type);
            cout << "Enter new Department: "; getline(cin, e.dept);
            cout << "Enter new Contact: "; getline(cin, e.contact);
            cout << "Enter new Address: "; getline(cin, e.address);

            cout << "Employee updated successfully!\n";
            return;
        }
    }
    cout << "Employee not found!\n";
}

void searchEmployee() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    for (auto &e : employees) {
        if (e.empID == id) {
            e.display();
            return;
        }
    }
    cout << "Employee not found!\n";
}

void displayEmployee() {
    int id;
    cout << "Enter Employee ID to display: ";
    cin >> id;

    for (auto &e : employees) {
        if (e.empID == id) {
            e.display();
            return;
        }
    }
    cout << "Employee not found!\n";
}

void displayAllEmployees() {
    if (employees.empty()) {
        cout << "No employee records found!\n";
        return;
    }
    for (auto &e : employees) {
        e.display();
    }
}
// *****************************************************************//
// ========================== Salary Functions ==========================
// *****************************************************************//
void addSalary() {
    int id;
    cout << "Enter Employee ID for Salary: ";
    cin >> id;

    string type = "";
    for (auto &e : employees) {
        if (e.empID == id) {
            type = e.type;
            break;
        }
    }
    if (type == "") {
        cout << "Employee not found!\n";
        return;
    }

    for (auto &s : salaries) {
        if (s.empID == id) {
            cout << "Salary details for this employee already exist!\n";
            return;
        }
    }

    Salary s(id, type);
    if (type == "Full-time") {
        cout << "Enter Basic: "; cin >> s.basic;
        cout << "Enter HRA: "; cin >> s.hra;
        cout << "Enter DA: "; cin >> s.da;
        cout << "Enter PF: "; cin >> s.pf;
    } else {
        cout << "Enter Hours Worked: "; cin >> s.hours;
        cout << "Enter Rate per Hour: "; cin >> s.rate;
    }

    salaries.push_back(s);
    cout << "Salary record added!\n";
}

void deleteSalary() {
    int id;
    cout << "Enter Employee ID to delete Salary: ";
    cin >> id;

    for (auto it = salaries.begin(); it != salaries.end(); ++it) {
        if (it->empID == id) {
            salaries.erase(it);
            cout << "Salary deleted successfully!\n";
            return;
        }
    }
    cout << "Salary record not found!\n";
}

void updateSalary() {
    int id;
    cout << "Enter Employee ID to update Salary: ";
    cin >> id;

    for (auto &s : salaries) {
        if (s.empID == id) {
            if (s.empType == "Full-time") {
                cout << "Enter new Basic: "; cin >> s.basic;
                cout << "Enter new HRA: "; cin >> s.hra;
                cout << "Enter new DA: "; cin >> s.da;
                cout << "Enter new PF: "; cin >> s.pf;
            } else {
                cout << "Enter new Hours Worked: "; cin >> s.hours;
                cout << "Enter new Rate per Hour: "; cin >> s.rate;
            }
            cout << "Salary updated successfully!\n";
            return;
        }
    }
    cout << "Salary record not found!\n";
}

void displaySalary() {
    int id;
    cout << "Enter Employee ID to display Salary: ";
    cin >> id;

    for (auto &s : salaries) {
        if (s.empID == id) {
            s.display();
            return;
        }
    }
    cout << "Salary record not found!\n";
}

void displayAllSalaries() {
    if (salaries.empty()) {
        cout << "No salary records found!\n";
        return;
    }
    for (auto &s : salaries) {
        s.display();
    }
}

// *****************************************************************//
// ========================== Employee Menu ==========================
// *****************************************************************//
void employeeMenu() {
    int choice;
    do {
        cout << "\n--- Employee Menu ---\n";
        cout << "1. Add Employee Details\n";
        cout << "2. Delete Employee Details\n";
        cout << "3. Update Employee Details\n";
        cout << "4. Search Employee\n";
        cout << "5. Display Employee Details\n";
        cout << "6. Display All Employees\n";
        cout << "7. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: updateEmployee(); break;
            case 4: searchEmployee(); break;
            case 5: displayEmployee(); break;
            case 6: displayAllEmployees(); break;
            case 7: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}
// *****************************************************************//
// ========================== Salary Menu ==========================
// *****************************************************************//
void salaryMenu() {
    int choice;
    do {
        cout << "\n--- Salary Menu ---\n";
        cout << "1. Add Salary Details\n";
        cout << "2. Delete Salary Details\n";
        cout << "3. Update Salary Details\n";
        cout << "4. Display Salary Details\n";
        cout << "5. Display All Salary Records\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addSalary(); break;
            case 2: deleteSalary(); break;
            case 3: updateSalary(); break;
            case 4: displaySalary(); break;
            case 5: displayAllSalaries(); break;
            case 6: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

// *****************************************************************//
// ========================== Main ==========================
// *****************************************************************//
int main() {
    int choice;
    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Employee\n";
        cout << "2. Salary\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: salaryMenu(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
