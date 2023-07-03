all: program.x

program.x: p12887.cc
	g++ -Wall -D_GLIBCXX_DEBUG p12887.cc -o program.x

run: program.x
	./program.x < input.txt > output.txt
	more output.txt
input: program.x
	./program.x > output.txt
	more output.txt


check:
	vimdiff output.txt check.txt

clean:
	rm -f program.x
