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
			./utilis/pathnew.c\
			./findpaths.c\
			./getpaths.c\
			./read.c\
			./utilis/isantnbr.c\
			./utilis/isroom.c\
			./utilis/islink.c\
			./utilis/iscommand.c\
			./utilis/iscomment.c\
			./utilis/roomadd.c\
			./utilis/roomnew.c\
			./utilis/roomrev.c\
			./utilis/linknew.c\
			./utilis/linkadd.c\
			./utilis/linkrev.c\
			./utilis/linkdel.c\
			./setlink.c\
			./dfs.c\
			./setroom.c\
			./solvefarm.c\
			./terminate.c\
			./utilis/wayadd.c\
			./utilis/waynew.c\
			./utilis/wayrev.c\
			./destroyfarm.c\
			./printstatus.c\
			./printrooms.c\
			./splitrooms.c\
			./adjustlinks.c\
			./checkoverlap.c\
			./cancelpaths.c\
			./sortpaths.c\
			./ants_move.c

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
