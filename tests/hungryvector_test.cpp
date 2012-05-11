#include "../utils/src/test.h"
#include "../Utils"

int main()
{
    TurnLeft::Utils::HungryVector <int> hippo(100,0);
    unittest::Test <int> inttest;

    inttest.name("Default: ").expect(100).test( hippo.size() );

    int initsize = hippo.size();
    for (int i = 0; i < initsize; i++)
    {
        hippo.add(i);
    }

    inttest.name("Doubled: ").expect(200).test( hippo.size() );
    hippo.add(666);
    hippo.trim();
    inttest.name("Trimmed: ").expect(101).test(hippo.size() );

    return 0;
}
