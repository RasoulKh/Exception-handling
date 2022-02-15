#include<iostream>
#include<exception>
#include<string>
using namespace std;

/* List of Standard Exceptions:
        std::exception <exception> interface (debatable if you should catch this)
        std::bad_alloc <new> failure to allocate storage
        std::bad_array_new_length <new> invalid array length
        std::bad_cast <typeinfo> execution of an invalid dynamic-cast
        std::bad_exception <exception> signifies an incorrect exception was thrown
        std::bad_function_call <functional> thrown by "null" std::function
        std::bad_typeid <typeinfo> using typeinfo on a null pointer
        std::bad_weak_ptr <memory> constructing a shared_ptr from a bad weak_ptr
        std::logic_error <stdexcept> errors detectable before the program executes
        std::domain_error <stdexcept> parameter outside the valid range
        std::future_error <future> violated a std::promise/std::future condition
        std::invalid_argument <stdexcept> invalid argument
        std::length_error <stdexcept> length exceeds its maximum allowable size
        std::out_of_range <stdexcept> argument value not in its expected range
        std::runtime_error <stdexcept> errors detectable when the program executes
        std::overflow_error <stdexcept> arithmetic overflow error.
        std::underflow_error <stdexcept> arithmetic underflow error.
        std::range_error <stdexcept> range errors in internal computations
        std::regex_error <regex> errors from the regular expression library.
        std::system_error <system_error> from operating system or other C API
        std::ios_base::failure <ios> Input or output error
 */

// Custom Exception //
class CustomException: public exception {
public:
    virtual const char* what() const throw() {
        return "Something bad happened (Custom Exception)!";
    }
};

class Printer{
private:
    int _availablePaper;
    string _name;
public:
    Printer(string name, int numberOfPaper){       // Constructor
        _name = name;
        _availablePaper = numberOfPaper;
    }
    void Print(string text){
        int requiredPaper = text.length() / 10; 
        if (requiredPaper > _availablePaper) {
            throw "Number of paper is not Enough!"; 
          /*  throw  101 */;

        }
        cout << "Printing ...." << text << endl;
        _availablePaper -= requiredPaper;
    }
    void PrinterName() {
        char* prtName = new char[999999999999];   // bad_alloc exception
        delete[] prtName;
    }
    void goesWrong() {      // Custom Exception
        throw CustomException();
    }
};


//*********************************//
//***********   Main   ************//
//*********************************//
int main()
{
    Printer myPrinter("HD_Printer", 10);

    try {
        myPrinter.Print("My name is Rasoul. I am a Software Developer... ");
        myPrinter.Print("My name is Rasoul. I am a Software Developer... ");
        myPrinter.Print("My name is Rasoul. I am a Software Developer... ");
    }
    catch (char const* textException) {
        cout << "Exception: " << textException << endl;
    }
    catch(int exCode) {
        cout << "Exception: " << exCode << endl;
    } 
    catch (...) {    // Default Handler can be used for any type of exceptions
        cout << "Exception Happened: " << endl;
    }

    try {
        myPrinter.PrinterName();
    }
    catch (bad_alloc &e) {
        cout << "Caught Exception: " << e.what() << endl;
    }
    cout << "Still Running ..." << endl;

    try {
        myPrinter.goesWrong(); 
    }
    catch (CustomException &e) {
        cout << e.what() << endl;

    }

    





    system("pause>null");
}