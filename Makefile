EXECUTABLE=lem-in
EXECUTABLE2=visu-hex
CC=gcc

D_LIBFT=./libft
I_LIBFT=-I $(D_LIBFT)/
L_LIBFT=-L $(D_LIBFT) -lft

D_INC=./includes
I_INC=-I $(D_INC) -I ./

N_SDLARCH=SDL2-2.0.10.tar.gz
D_SDL = ./SDL2-2.0.10
D_SDLINC = $(D_SDL)/include
D_SDLLIB = $(D_SDL)/lib
L_SDL = `$(D_SDL)/sdl2-config --cflags --libs`

INC=$(I_LIBFT) $(I_INC) -I ${D_SDLINC}

CFLAGS=-Wall -Wextra -Werror -g $(INC)

SRCS =		./lem_in.c\
			./read.c\
			./setlink.c\
			./setroom.c\
			./terminate.c\
			./destroyfarm.c\
			./utils/ways.c\
			./utils/ways_methods.c\
			./utils/ways_debug.c\
			./utils/rooms.c\
			./utils/matrix.c\
			./utils/matrix_methods.c\
			./utils/queue.c\
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
			./utilis2/linkdel.c\
			./utilis2/wayadd.c\
			./utilis2/waynew.c\
			./bfs/bfs_dist.c\
			./bfs/search_ways.c\
			./bfs/splitrooms.c\
			./bfs/adjustlinks.c\
			./bfs/bfs.c\
			./bfs/bfs_queue.c\
			./bfs/bfs_utils.c\
			./bfs/bfs_utils2.c\
			./algo/algo_ants.c\

SRCS2=		./visualizer/visu-main.c\
			./visualizer/sdl.c\
			./visualizer/render.c\
			./visualizer/render_rooms.c\
			./visualizer/do_tick.c\
			./visualizer/render_utils.c\
			./visualizer/sdl_draw_circle.c\
			./visualizer/visu-reader.c\
			./visualizer/visu_readcommand.c\
			./visualizer/visu-reader-predictions.c\
			./visualizer/visu_islink_utils.c\
			./visualizer/visu_isroom_utils.c\
			./utilis2/roomadd.c\
			./utilis2/roomnew.c\
			./terminate.c\

HEADERS =	./lem_in.h

OBJS = $(patsubst %.c,%.o, $(SRCS))
OBJS2 = $(patsubst %.c,%.o, $(SRCS2))

all: $(EXECUTABLE) $(EXECUTABLE2)

$(EXECUTABLE):  $(OBJS) $(L_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) -lm $(L_LIBFT)
	@echo "===>$(EXECUTABLE) has been builded"

$(EXECUTABLE2):$(L_LIBFT) $(D_SDL) $(D_SDLLIB) $(OBJS2)
	echo ${OBJS2}
	$(CC) $(CFLAGS) -o $(EXECUTABLE2) $(OBJS2) -lm ${L_LIBFT} -L $(D_SDLLIB) $(L_SDL)
	@echo "===>$(EXECUTABLE2) has been builded"

$(L_LIBFT):
	@echo "===>Building libft for lem_in if needed..."
	@make -C $(D_LIBFT)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE)"

$(D_SDL):
	@tar -xf $(N_SDLARCH)
	@printf "Push_Swap:  %-25s$(C_CYAN)[extracted]$(C_NONE)\n" $@

$(D_SDLLIB):
	@mkdir $(D_SDLLIB)
	@printf "\n$(C_CYAN)[configuring SDL]$(C_NONE)\n"
	@cd $(D_SDL); ./configure --prefix=`pwd`/lib
	@printf "$(C_CYAN)[compiling SDL]$(C_NONE)\n"./
	@make -C $(D_SDL)
	@make -C $(D_SDL) install >/dev/null
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

%.o: %.c
	echo $@
	echo $<
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make -C $(D_LIBFT) clean
	rm -rf $(OBJS)
	rm -rf $(OBJS2)

fclean: clean
	make -C $(D_LIBFT) fclean
	rm -rf $(EXECUTABLE)
	#rm -rf $(D_SDL)

re: fclean all
