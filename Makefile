NAME = wolf3d

DIR_H = ./includes/

DIR_H_SDL = ./SDL/SDL2/Headers/

DIR_H_IMAGE = ./SDL/SDL2_image/Headers/

DIR_C = ./src/

DIR_O = ./objs/

FILE_C = draw_column.c\
	 main.c\
	 map_malloc.c\
	 key_press.c\
	 mini_map.c\
	 ray_cast.c\
	 sdl_all.c\
	 maps_creat.c\
	 put_image.c\
	 column_color.c\
	 sky.c\

FILE_O = $(FILE_C:.c=.o)

SRC_C := $(addprefix $(DIR_C), $(FILE_C))

SRC_O := $(addprefix $(DIR_O), $(FILE_O))

	FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	   @clang -o $(NAME) $(SRC_O) ./libft/libft.a ./SDL/SDL2/SDL2.a ./SDL/SDL2_image/SDL2_image.a -I $(DIR_H) -I $(DIR_H_SDL) -I $(DIR_H_IMAGE) 

$(SRC_O): $(SRC_C)
	@make -C libft/
	@clang -c $(SRC_C) -I $(DIR_H) -I $(DIR_H_SDL) -I $(DIR_H_IMAGE)
	@mkdir -p $(DIR_O)
	@mv $(FILE_O) $(DIR_O)

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean all re
