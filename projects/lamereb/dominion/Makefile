CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS)
	echo "unittest1.c --> " > unittestresults.out
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS)
	echo "unittest2.c --> " >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS)
	echo "unittest3.c --> " >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS)
	echo "unittest4.c --> " >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest1.c --> " >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest2.c --> " >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest3.c --> " >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest4.c --> " >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
