# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:56:08 by cpollito          #+#    #+#              #
#    Updated: 2022/10/17 13:45:32 by cpollito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#directories
INC_DIR := includes
SRC_DIR := src
GNL_DIR := get_next_line
LIBFT_DIR := libft
UTILS_DIR := utils
PARS_DIR := parser
OBJ_DIR := objects


#headers
HEADERS := $(INC_DIR)/so_long.h \
$(SRC_DIR)/$(GNL_DIR)/get_next_line.h \
$(SRC_DIR)/$(LIBFT_DIR)/libft.h

#files
GNL := get_next_line.c get_next_line_utils.c
GNL := $(addprefix $(GNL_DIR)/, $(GNL))
LIBFT := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
ft_strcmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strnstr.c\
ft_atoi.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putnbr_fd.c ft_itoa.c ft_putendl_fd.c ft_substr.c ft_strjoin.c\
ft_strmapi.c ft_striteri.c ft_split.c ft_strtrim.c ft_lstsize.c\
ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstlast.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c
LIBFT := $(addprefix $(LIBFT_DIR)/, $(LIBFT))
UTILS := error.c utils.c 
UTILS := $(addprefix $(UTILS_DIR)/, $(UTILS))
PARS := parse_file.c parser_general.c validation_lines.c
PARS := $(addprefix $(PARS_DIR)/, $(PARS))
SRC := so_long.c draw.c move.c init_image.c
SRC := $(SRC) $(UTILS) $(PARS) $(GNL)
OBJ := $(SRC:.c=.o)
SRC := $(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))


#compilation
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit

MLX = minilibx/libmlx.a

#commands
RM := rm -rf

.PHONY:	all clean fclean re bonus

all : $(NAME)

bonus : all

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L src/libft -l ft -Lminilibx $(MLX_FLAGS)  -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(MAKE) bonus -C src/$(LIBFT_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I $(SRC_DIR)/$(LIBFT_DIR) -I $(SRC_DIR)/$(GNL_DIR)  -c $< -o $@ 

$(MLX):
		@$(MAKE) -C minilibx/ CFLAGS=-DSTRINGPUTX11\ -Ofast\ -g\ -Wno-deprecated
		@cp $(MLX) .

clean :
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(SRC_DIR)/$(LIBFT_DIR)
	@rm -rf libmlx.a
	@make -C minilibx clean

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(SRC_DIR)/$(LIBFT_DIR)
	@rm -f libmlx.dylib 

re : fclean all 
