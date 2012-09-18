#include <TurnLeftLib/TestSuite/TestSuite.h>
#include <assert.h>
namespace T_TestValue{

using namespace std;
void test()
{

    TestValue _str;
    TestValue _int;
    TestValue _flt;
    TestValue _chr;

    int i =8;
    float f = 12.4;

    TestValue __str("foo");
    TestValue __int(i);
    TestValue __flt(f);
    TestValue __chr('{');

    _str.as_string = "foo";
    _int.as_int = i;
    _flt.as_float = f;
    _chr.as_char = '{';

    assert(_str.as_string == __str.as_string);
    assert(_int.as_int == __int.as_int);
    assert(_flt.as_float == __flt.as_float);
    assert(_chr.as_char == __chr.as_char);

    cout << _str.as_string << endl;
    cout << _int.as_int << endl;
    cout << _flt.as_float << endl;
    cout << _chr.as_char << endl;
}

}//namespace T_TestValue
