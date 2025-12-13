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
    const int wFirstNameCollum = 20;
    const int wLastNameCollum = 20;
    const int wAccountNumberCollum = 10;
    const int wStreetAddressCollum = 40;
    const int wCityCollum = 15;
    const int wStateCollum = 15;
    const int wZipCodeCollum = 15;
    const int wPhoneNumberCollum = 20;

    //Tester Column Width Constants
    const int COL_ACCOUNT_NUMBER = 10;
    const int COL_FIRST_NAME = 15;
    const int COL_LAST_NAME = 15;
    const int COL_STREET_ADDRESS = 23;
    const int COL_CITY = 13;
    const int COL_STATE = 7;
    const int COL_ZIP_CODE = 10;
    const int COL_PHONE_NUMBER = 14;

    //Helper Chars
    const char dashFillChar = '-';
    const std::string bar = "|";

    //Splitter Collum To Seperate Header From Data
    std::cout << std::string(COL_ACCOUNT_NUMBER, dashFillChar) << bar 
              << std::string(COL_FIRST_NAME, dashFillChar) << bar
              << std::string(COL_LAST_NAME, dashFillChar) << bar
              << std::string(COL_STREET_ADDRESS, dashFillChar) << bar
              << std::string(COL_CITY, dashFillChar) << bar
              << std::string(COL_STATE, dashFillChar) << bar
              << std::string(COL_ZIP_CODE, dashFillChar) << bar
              << std::string(COL_PHONE_NUMBER, dashFillChar) << std::endl;

    //Printing Customer Data  accountNumber,firstName,lastName,streetAddress,city,state,zipCode,phoneNumber
    std::cout << std::left << std::setw(COL_ACCOUNT_NUMBER) << m_accountNumber << bar
              << std::left << std::setw(COL_FIRST_NAME) << m_firstName << bar
              << std::left << std::setw(COL_LAST_NAME) << m_lastName << bar
              << std::left << std::setw(COL_STREET_ADDRESS) << m_streetAddress << bar
              << std::left << std::setw(COL_CITY) << m_city << bar
              << std::left << std::setw(COL_STATE) << m_state << bar
              << std::left << std::setw(COL_ZIP_CODE) << m_zipCode << bar
              << std::left << std::setw(COL_PHONE_NUMBER) << m_phoneNumber << std::endl;
}

void AllCustomers::printCustomerDataWithIndex(int index) const
{
    //Seting the width size of collums for display of data
    const int wFirstNameCollum = 20;
    const int wLastNameCollum = 20;
    const int wAccountNumberCollum = 10;
    const int wStreetAddressCollum = 40;
    const int wCityCollum = 15;
    const int wStateCollum = 15;
    const int wZipCodeCollum = 15;
    const int wPhoneNumberCollum = 20;
    const int wIndexCollum = 7;

    //Tester Column Width Constants
    const int COL_ACCOUNT_NUMBER = 10;
    const int COL_FIRST_NAME = 15;
    const int COL_LAST_NAME = 15;
    const int COL_STREET_ADDRESS = 23;
    const int COL_CITY = 13;
    const int COL_STATE = 7;
    const int COL_ZIP_CODE = 10;
    const int COL_PHONE_NUMBER = 14;
    const int COL_INDEX = 7;

    //Helper Chars
    const char dashFillChar = '-';
    const std::string bar = "|";

    //Splitter Collum To Seperate Header From Data
    std::cout << std::string(COL_ACCOUNT_NUMBER, dashFillChar) << bar 
              << std::string(COL_FIRST_NAME, dashFillChar) << bar
              << std::string(COL_LAST_NAME, dashFillChar) << bar
              << std::string(COL_STREET_ADDRESS, dashFillChar) << bar
              << std::string(COL_CITY, dashFillChar) << bar
              << std::string(COL_STATE, dashFillChar) << bar
              << std::string(COL_ZIP_CODE, dashFillChar) << bar
              << std::string(COL_PHONE_NUMBER, dashFillChar) << bar
              << std::string(COL_INDEX, dashFillChar) << std::endl;

    //Printing Customer Data  accountNumber,firstName,lastName,streetAddress,city,state,zipCode,phoneNumber
    std::cout << std::left << std::setw(COL_ACCOUNT_NUMBER) << m_accountNumber << bar
              << std::left << std::setw(COL_FIRST_NAME) << m_firstName << bar
              << std::left << std::setw(COL_LAST_NAME) << m_lastName << bar
              << std::left << std::setw(COL_STREET_ADDRESS) << m_streetAddress << bar
              << std::left << std::setw(COL_CITY) << m_city << bar
              << std::left << std::setw(COL_STATE) << m_state << bar
              << std::left << std::setw(COL_ZIP_CODE) << m_zipCode << bar
              << std::left << std::setw(COL_PHONE_NUMBER) << m_phoneNumber << bar
              << std::left << std::setw(COL_INDEX) << index << std::endl;
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