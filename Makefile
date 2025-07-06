all: release

release:
	g++ -Wall -std=gnu++17 -o arcade *.cpp 

debug:
	g++ -g -Wall -std=gnu++17 -o arcade *.cpp 





GTEST = -I googletest/googletest/include -pthread
GLIB = googletest/build/lib/libgtest.a googletest/build/lib/libgtest_main.a


test-hangman:
	g++ -g -Wall -std=c++17 $(GTEST) tests/test.cpp game.cpp hangman.cpp highscore.cpp player.cpp $(GLIB) -o test

clean-test-hangman:
	rm -f test
