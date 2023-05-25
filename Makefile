all:
	@g++ fileio.cpp -o fileio
	@./fileio

run:
	@./fileio

clean:
	@rm fileio