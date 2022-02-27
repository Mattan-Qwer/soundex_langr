prog: SoundexTest.o Soundex.o 
	g++ -I../include  ./SoundexTest.cpp Soundex.cpp -lgtest
	./a.out

clean: 
	rm *.out
	rm S*.o