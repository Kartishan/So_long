
NAME =  so_long

SRCS =	map_check.c utilities.c utilities2.c utilities3.c so_long.c utilities4.c utilities5.c utilities6.c valid_checker.c
GNL_SRCS = ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c

HEADER = map.h
LIBMLX = libmlx.dylib
OBJ =   $(SRCS:%.c=%.o)
GNL_OBJ =   $(GNL_SRCS:%.c=%.o)

CFLAGS = -Wall -Wexra -Werror -I$(HEADER)

.PHONY : all clean fclean re get

all : $(NAME)

$(NAME)	:	$(OBJ) $(HEADER) ${GNL_OBJ} ${LIBMLX}
	gcc $(CFLAGS) ${GNL_OBJ} $(OBJ) -o $@ -L. -lmlx -framework OpenGL -framework AppKit
	
%.o		:	%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@
clean :
	rm -f $(OBJ) ${GNL_OBJ} && cd minilibx_mms_20200219 && make -f Makefile clean
fclean : clean
	@$(RM) ${LIBMLX} $(NAME)
re : fclean all

${LIBMLX}:
	cd ./minilibx_mms_20200219 && make -f Makefile all && mv libmlx.dylib ./..