
# main: bin/Slab.o bin/Grid.o bin/Main.o
# 	gcc  -Wall -Wextra -std=c99 -o bin/main src/Main.c bin/Slab.o bin/Grid.o bin/Main.o




# bin/Slab.o: src/Slab.h src/Slab.c src/Grid.h
# 	gcc  -Wall -Wextra -std=c99 -o bin/Slab.o  src/Slab.c 
	
# bin/Grid.o: src/Grid.h src/Grid.c
# 	gcc  -Wall -Wextra -std=c99 -o bin/Grid.o  src/Grid.c
	
# bin/Main.o: src/Main.c
# 	gcc  -Wall -Wextra -std=c99 -o bin/Main.o  src/Main.c

main: src/*.c src/*.h
	gcc -std=c99 -Wall -Wextra src/*.c -o bin/main
