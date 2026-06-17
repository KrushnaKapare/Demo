
# set of rules which are used to compile the program
# Every rule will have two lines
	# dependency line - which contains list of all dependenecies
	# receipe line - which contains command to create target of the rule

# outcome of the rule(file) is called as target of the rule

# eg
# main.o: main.c
# 	gcc -c main.c

# compulsory one tab will be given on receipe line
# rule to create final outcome should be the first rule

	
main.out: main.o mmath.o
	gcc main.o mmath.o -o main.out

main.o: main.c
	gcc -c main.c

mmath.o: mmath.c
	gcc -c mmath.c


run:
	./main.out

clean:
	rm main.out main.o mmath.o

# tagets with no outcome are called as phony targets

.phony: run clean








