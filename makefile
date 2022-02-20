prog: SoundexTest.o SoundexTest.o 
	g++ -I../include  ./SoundexTest.cpp Soundex.cpp -lgtest
	./a.out

