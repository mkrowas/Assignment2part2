#include <iostream>
using namespace std;

class Employee {
public:
    string firstName;
    string lastName;

    Employee() {
        firstName = "";
        lastName = "";
    }

    Employee(string first, string last) {
        firstName = first;
        lastName = last;
    }

    virtual void setPay() {
    }

    virtual float paycheck() {
        return 0.0;
    }
    
    virtual float vacationEarned() {
        return 0.0;
    }

    virtual float healthcareEarned() {
        return 0.0;
    }

    virtual float weekPay() {
        return 0.0;
    }
};

class Professional : public Employee {
public:
    int yearsworked;
    int payRate;

    Professional(string first, string last, int years) {
        firstName = first;
        lastName = last;
        yearsworked = years;
        payRate = 0;
        
    } 

    void setPay(float pay) {
        payRate = pay;
    }

    float payCheck() {
        return (payRate/52) - healthcarecontributions();
    }

    float vacationEarned() {
        if (yearsworked < 10) {
            return 1 * yearsworked;
        }
        else
            return 10;
    }

    float healthcarecontributions() {
        return (payRate / 52) * .05;
    }

};

class NonProfessional : public Employee {
public:
    int yearsworked;
    int hoursWorked;
    int payRate;

    NonProfessional(string first, string last, int years) {
        firstName = first;
        lastName = last;
        yearsworked = years;
        hoursWorked = 0;
        payRate = 0;

    }

    void typicalHours(float hours) {
        hoursWorked = hours;
    }

    void setPay(float pay) {
        payRate = pay;
    }

    float payCheck() {
        return (payRate * hoursWorked) - healthcarecontributions();
    }

    float vacationEarned() {
        if (yearsworked < 10) {
            return .005*hoursWorked * yearsworked;
        }
        else
            return .005*hoursWorked * 10;
    }

    float healthcarecontributions() {
        return (payRate / 52) * .10;
    }
};

int main()
{
    Professional test = Professional("John", "Smith", 15);
    test.setPay(52000);
    cout << test.payCheck() << "   " << test.vacationEarned() << endl;

    NonProfessional test2 = NonProfessional("John", "Smith", 5);
    test2.setPay(24);
    test2.typicalHours(40);
    cout << test2.payCheck() << "   " << test2.vacationEarned() << endl;


}