#include <TurnLeftLib/Utils>
#include <TurnLeftLib/utils/test.h>

enum TestEnum {
    FOO, BAR, ZIP, ZAP, ZOP
};

class TestEnumParser : public TurnLeft::Utils::EnumParser <TestEnum>
{
public:
    TestEnumParser() {
        enumMap["FOO"] = FOO;
        enumMap["BAR"] = BAR;
        enumMap["ZIP"] = ZIP;
        enumMap["ZAP"] = ZAP;
        enumMap["ZOP"] = ZOP;
    }
};

int main()
{
    TestEnumParser parser;
    unittest::Test <int> inttest;

    inttest.name("Test 0").expect(0).test ( parser.parse("FOO") );
    inttest.name("Test 1").expect(1).test ( parser.parse("BAR") );
    inttest.name("Test 2").expect(2).test ( parser.parse("ZIP") );

    return 0;
}
