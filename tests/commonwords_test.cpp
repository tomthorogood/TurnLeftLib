
#include "../utils/src/test.h"
#include "../utils/CommonWords"
#include "../utils/Explosion"
#include <vector>
#include <string>

int main()
{
	unittest::Test<int> inttest;
	TurnLeft::Utils::CommonWords library("commonwords.txt");
	std::string testString ="this is a fabulous endeavor";
    TurnLeft::Utils::Explosion explosion(testString);
    
    std::string strvector[10];
    std::cout << "Vector instantiated." << std::endl;
    explosion.explode(' ', strvector);
	inttest.name("Find 'this'").expect(1).test(
        library.find(strvector[0])
	);

	inttest.name("Find 'a' ").expect(1).test(
	    library.find(strvector[2])
	);

	inttest.name("Find 'fabulous'").expect(0).test(
	    library.find(strvector[3])
	);
	return 0;
}

