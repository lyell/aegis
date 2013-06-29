#include <aftu_hexprinter.h>
#include <aunit.h>
#include <iostream>
#include <limits>

namespace aegis {
namespace aftu {

struct Struct
{
    int i;
    float f;
    double d;
    short s;
    char c;
};

class TestHexPrinter : public aunit::TestFixture
{
public:
    TestHexPrinter() {}
    
    virtual ~TestHexPrinter() {}

protected:
    virtual void runTest();
    
private:
    void testPrint();
};

void TestHexPrinter::runTest()
{
    testPrint();
}

void TestHexPrinter::testPrint()
{
    std::string t1 = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    std::cout << std::endl;
    std::cout << aftu::HexPrinter(t1.c_str(), t1.size()) << std::endl;

    std::cout << std::endl;
    std::cout << aftu::HexPrinter(t1.c_str(), t1.size(), 8) << std::endl;
    
    std::cout << std::endl;
    std::cout << aftu::InlineHexPrinter(t1.c_str(), t1.size()) << std::endl;
    
    Struct t2;
    t2.i = 10;
    t2.f = 1.2345f;
    t2.d = 1.2345;
    t2.s = 5;
    t2.c = 'a';
    
    std::cout << std::endl;
    std::cout << aftu::HexPrinter(reinterpret_cast<const char*>(&t2), sizeof(t2)) << std::endl;
    
    std::cout << std::endl;
    std::cout << aftu::HexPrinter(reinterpret_cast<const char*>(&t2), sizeof(t2), 8) << std::endl;
    
    std::cout << std::endl;
    std::cout << aftu::InlineHexPrinter(reinterpret_cast<const char*>(&t2), sizeof(t2)) << std::endl;
}

} // namespace
} // namespace
