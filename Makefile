main:
	@gcc -g -Wall -o main src/main.c src/Lab3IO.c -lm -fopenmp

serial-main:
	@gcc -g -Wall -o serial-main src/serial-main.c src/Lab3IO.c

datagen:
	@gcc -o datagen src/datagen.c src/Lab3IO.c

serialtester:
	@gcc -o serialtester src/serialtester.c src/Lab3IO.c -lm

clean:
	-@rm -rf main data_input data_output serialtester datagen
