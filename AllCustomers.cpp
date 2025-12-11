#include "AllCustomers.h"


void printTestMessage(){
    std::cout << "Fuck vscode intellisense";
}



//Default Constructor
AllCustomers::AllCustomers() 
    : m_firstName("N/A"), m_lastName("N/A"), m_accountNumber(0000), 
      m_streetAddress("N/A"), m_city("N/A"), m_state("N/A"), 
      m_zipCode("N/A"), m_phoneNumber("N/A") {}
//PARAM Constructor
AllCustomers::AllCustomers(const std::string& firstName, const std::string& lastName, const int& accountNumber, 
    const std::string& streetAddress, const std::string& city, const std::string& state, 
    const std::string& zipCode, const std::string& phoneNumber) 
    : m_firstName(firstName), m_lastName(lastName), m_accountNumber(accountNumber),
      m_streetAddress(streetAddress), m_city(city), m_state(state),
      m_zipCode(zipCode), m_phoneNumber(phoneNumber) {}

//Copy Constructor
AllCustomers::AllCustomers(const AllCustomers& other) {
    m_firstName = other.m_firstName;
    m_lastName = other.m_lastName;
    m_accountNumber = other.m_accountNumber;
    m_streetAddress = other.m_streetAddress;
    m_city = other.m_city;
    m_state = other.m_state;
    m_zipCode = other.m_zipCode;
    m_phoneNumber = other.m_phoneNumber;
}

//Overloaded Assignment Operator
AllCustomers& AllCustomers::operator=(const AllCustomers& rhs){
    if (this == &rhs){
        return *this;
    }
    m_firstName = rhs.m_firstName;
    m_lastName = rhs.m_lastName;
    m_accountNumber = rhs.m_accountNumber;
    m_streetAddress = rhs.m_streetAddress;
    m_city = rhs.m_city;
    m_state = rhs.m_state;
    m_zipCode = rhs.m_zipCode;
    m_phoneNumber = rhs.m_phoneNumber;
    return *this;
}

void AllCustomers::printCustomerData() const
{
    //Seting the width size of collums for display of data
    //const int wIndexCollum = 5;
    const int wFirstNameCollum = 20;
    const int wLastNameCollum = 20;
    const int wAccountNumberCollum = 10;
    const int wStreetAddressCollum = 40;
    const int wCityCollum = 15;
    const int wStateCollum = 15;
    const int wZipCodeCollum = 15;
    const int wPhoneNumberCollum = 20;

    //Helper Chars
    const char dashFillChar = '-';
    const std::string bar = "|";

    //Splitter Collum To Seperate Header From Data
    std::cout //<< std::string(wAccountNumberCollum, dashFillChar) << bar 
              << std::string(wFirstNameCollum, dashFillChar) << bar
              << std::string(wLastNameCollum, dashFillChar) << bar
              << std::string(wStreetAddressCollum, dashFillChar) << bar
              << std::string(wCityCollum, dashFillChar) << bar
              << std::string(wStateCollum, dashFillChar) << bar
              << std::string(wZipCodeCollum, dashFillChar) << bar
              << std::string(wPhoneNumberCollum, dashFillChar) << std::endl;

    //Printing Customer Data  index accountNumber,firstName,lastName,streetAddress,city,state,zipCode,phoneNumber
    std::cout //<< std::left << std::setw(wIndexCollum) << "" << bar
              << std::left << std::setw(wAccountNumberCollum) << m_accountNumber << bar
              << std::left << std::setw(wFirstNameCollum) << m_firstName << bar
              << std::left << std::setw(wLastNameCollum) << m_lastName << bar
              << std::left << std::setw(wStreetAddressCollum) << m_streetAddress << bar
              << std::left << std::setw(wCityCollum) << m_city << bar
              << std::left << std::setw(wStateCollum) << m_state << bar
              << std::left << std::setw(wZipCodeCollum) << m_zipCode << bar
              << std::left << std::setw(wPhoneNumberCollum) << m_phoneNumber << std::endl;
}   

void AllCustomers::printPurchaseHistory() const //AllPurchases(const int& accountNumber, const std::string& item, const Date& dateOfPurchase, const double& costOfPurchase)
{
    const int accountNumberWidth = 10;
    const int itemWidth = 30;
    const int dateWidth = 15;
    const int costWidth = 10;

    const char dashFillChar = '-';
    const std::string bar = "|";

    //Header
    std::cout << std::left << std::setw(accountNumberWidth) << "Account #" << bar
              << std::left << std::setw(itemWidth) << "Item" << bar
              << std::left << std::setw(dateWidth) << "Date" << bar
              << std::left << std::setw(costWidth) << "Cost" << std::endl;
    

    //Splitter
    std::cout << std::string(accountNumberWidth, dashFillChar) << bar
                << std::string(itemWidth, dashFillChar) << bar
                << std::string(dateWidth, dashFillChar) << bar
                << std::string(costWidth, dashFillChar) << std::endl;
    //Print Each Purchase In History
    for (int i = 0; i < customerPurchaseHistory.size(); ++i)
    {
        std::cout << std::left << std::setw(accountNumberWidth) << customerPurchaseHistory[i].getAccountNumber() << bar
                  << std::left << std::setw(itemWidth) << customerPurchaseHistory[i].getItem() << bar
                  << std::left << std::setw(dateWidth) << customerPurchaseHistory[i].getDateOfPurchase().returnDateAsString() << bar
                  << std::left << "$" << std::fixed << std::setprecision(2) << customerPurchaseHistory[i].getCostOfPurchase() << std::endl;
    }
}