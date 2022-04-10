
NAME =  so_long

SRCS =	map_check.c utilities.c utilities2.c utilities3.c so_long.c utilities4.c

HEADER = map.h
LIBMLX = libmlx.dylib
OBJ =   $(SRCS:%.c=%.o)
OBJ_B =   $(SRCS_B:%.c=%.o)

CFLAGS = -Wall -Wexra -Werror -I$(HEADER)

.PHONY : all clean fclean re get

all : $(NAME)

$(NAME)	:	$(OBJ) $(HEADER) ${GET} ${LIBMLX}
	gcc $(CFLAGS) *bonus.o $(OBJ) -o $@ -L. -lmlx -framework OpenGL -framework AppKit
	
%.o		:	%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@
clean :
	rm -f $(OBJ) *bonus.o && cd minilibx_mms_20200219 && make -f Makefile clean
fclean : clean
	@$(RM) $(NAME) $(NAME_B) ${LIBMLX} && cd minilibx_mms_20200219/ && make -f Makefile clean
re : fclean all

${LIBMLX}:
	cd ./minilibx_mms_20200219 && make -f Makefile all && mv libmlx.dylib ./..
${GET}:
	gcc -c ./gnl/*bonus.c