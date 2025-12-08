#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#ifndef AllPurchases_h
#define AllPurchases_h


struct Date {
    int year;
    int month;
    int day;

    //Default Constructor
    Date() : year(2025), month(1), day(1) {}
    //Param Date
    Date(const int& yearVal, const int& monthVal, const int& dayVal)
    : year(yearVal), month(monthVal), day(dayVal) {}

    //getters 
    int getYear() {return year;}
    int getMonth() {return month;}
    int getDay() {return day;}
    

    //setters
    void setYear(int val) {year = val;}
    void setMonth(int val) {month = val;}
    void setDay(int val) {day = val;}
};




class AllPurchases{
    public:
    //Constructors
    AllPurchases(): m_accountNumber(0000), m_item("N/A"), m_dateOfPurchase(), m_costOfPurchase(0.0) {} //Default Constructor
    AllPurchases(const int& accountNumber, const std::string& item, const Date& dateOfPurchase, const double& costOfPurchase) :
        m_accountNumber(accountNumber), m_item(item), m_dateOfPurchase(dateOfPurchase), m_costOfPurchase(costOfPurchase) {} //Param Constructor

    AllPurchases(const AllPurchases& other) { //Copy Constructor
        m_accountNumber = other.m_accountNumber;
        m_item = other.m_item;
        m_dateOfPurchase = other.m_dateOfPurchase;
        m_costOfPurchase = other.m_costOfPurchase;
    }

    AllPurchases& operator=(const AllPurchases& rhs){ //Overloaded Assignment Operator
        if (this == &rhs){
            return *this;
        }
        m_accountNumber = rhs.m_accountNumber;
        m_item = rhs.m_item;
        m_dateOfPurchase = rhs.m_dateOfPurchase;
        m_costOfPurchase = rhs.m_costOfPurchase;
        return *this;
    }

    //Getter's
    int getAccountNumber() const {return m_accountNumber;}
    std::string getItem() const {return m_item;}
    Date getDateOfPurchase() const {return m_dateOfPurchase;}
    double getCostOfPurchase() const {return m_costOfPurchase;}

    //Setters
    void setAccountNumber(const int accountNumberVal) {m_accountNumber = accountNumberVal;}
    void setItem(const std::string itemVal) {m_item = itemVal;}
    void setDateOfPurchase(const Date dateOfPurchaseVal) {m_dateOfPurchase = dateOfPurchaseVal;}
    void setCostOfPurchase(const double costOfPurchaseVal) {m_costOfPurchase = costOfPurchaseVal;}

    void printPurchaseData() const {
        std::cout << "Account Number: " << m_accountNumber << "\n"
                  << "Item: " << m_item << "\n"
                  << "Date of Purchase: " << m_dateOfPurchase.month << "/" 
                  << m_dateOfPurchase.day << "/" << m_dateOfPurchase.year << "\n"
                  << "Cost of Purchase: $" << std::fixed << std::setprecision(2) << m_costOfPurchase << "\n";
    }
    
    
    private:
        int m_accountNumber; //Link this purchase to a customer 
        std::string m_item;
        Date m_dateOfPurchase;
        double m_costOfPurchase;

};
#endif