EXECUTABLE=lem-in

D_LIBFT=./libft
I_LIBFT=-I $(D_LIBFT)/
L_LIBFT=-L $(D_LIBFT) -lft

D_INC=./includes
I_INC=-I $(D_INC) -I ./

CC=gcc

INC=$(I_LIBFT) $(I_INC)

CFLAGS=-Wall -Wextra -Werror -g $(INC)

SRCS =		./lem_in.c\
			./pathnew.c\
			./findpaths.c\
			./getpaths.c\
			./read.c\
			./utilis2/isantnbr.c\
			./utilis2/isroom.c\
			./utilis2/islink.c\
			./utilis2/iscommand.c\
			./utilis2/iscomment.c\
			./utilis2/roomadd.c\
			./utilis2/roomnew.c\
			./utilis2/roomrev.c\
			./utilis2/linknew.c\
			./utilis2/linkadd.c\
			./utilis2/linkrev.c\
			./setlink.c\
			./dfs.c\
			./setroom.c\
			./solvefarm.c\
			./terminate.c\
			./utilis2/wayadd.c\
			./utilis2/waynew.c\
			./utilis2/wayrev.c\
			./destroyfarm.c\
			./printstatus.c\
			./bfs/bfs.c\
			./utils/ways.c\
			./utils/ways_methods.c\
			./utils/ways_debug.c\
			./utils/rooms.c\
			./utils/matrix.c\
			./utils/matrix_methods.c\
			./utils/queue.c\
			./splitrooms.c

HEADERS =	./lem_in.h

OBJS = $(patsubst %.c,%.o, $(SRCS))

all: $(EXECUTABLE)

$(EXECUTABLE): $(L_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) -lm $(L_LIBFT)
	@echo "===>$(EXECUTABLE) has been builded"

$(L_LIBFT):
	@echo "===>Building libft for lem_in if needed..."
	@make -C $(D_LIBFT)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE)"

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make -C $(D_LIBFT) clean
	rm -rf $(OBJS)
	rm -rf $(OBJS2)

fclean: clean
	make -C $(D_LIBFT) fclean
	rm -rf $(EXECUTABLE)
	rm -rf $(D_SDL)

re: fclean all
