##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make qui file
##

SRC_DIR			=	src
INCLUDE_DIR		=	include
LIBMY_DIR		=	lib/my/
LIBMY			=	lib/libmy.a

SRC_FILES		=	$(SRC_DIR)/file.c \
					$(SRC_DIR)/hash_func.c \
					$(SRC_DIR)/hash_table.c

LIB_FILES		=	$(LIBMY_DIR)my_putstr.c \
					$(LIBMY_DIR)my_putchar.c \
					$(LIBMY_DIR)my_strlen.c \
					$(LIBMY_DIR)my_revstr.c \
					$(LIBMY_DIR)my_compute_power_rec.c \
					$(LIBMY_DIR)my_compute_square_root.c \
					$(LIBMY_DIR)my_find_prime_sup.c \
					$(LIBMY_DIR)my_getnbr.c \
					$(LIBMY_DIR)my_isneg.c \
					$(LIBMY_DIR)my_is_prime.c \
					$(LIBMY_DIR)my_put_nbr.c \
					$(LIBMY_DIR)my_showmem.c \
					$(LIBMY_DIR)my_showstr.c \
					$(LIBMY_DIR)my_sort_int_array.c \
					$(LIBMY_DIR)my_strcapitalize.c \
					$(LIBMY_DIR)my_strcat.c \
					$(LIBMY_DIR)my_strcmp.c \
					$(LIBMY_DIR)my_strcpy.c \
					$(LIBMY_DIR)my_str_isalpha.c \
					$(LIBMY_DIR)my_str_islower.c \
					$(LIBMY_DIR)my_str_isnum.c \
					$(LIBMY_DIR)my_str_isprintable.c \
					$(LIBMY_DIR)my_str_isupper.c \
					$(LIBMY_DIR)my_strlowcase.c \
					$(LIBMY_DIR)my_strncat.c \
					$(LIBMY_DIR)my_strncmp.c \
					$(LIBMY_DIR)my_strncpy.c \
					$(LIBMY_DIR)my_strstr.c \
					$(LIBMY_DIR)my_strupcase.c \
					$(LIBMY_DIR)my_swap.c \
					$(LIBMY_DIR)copy_word.c \
					$(LIBMY_DIR)count_words.c \
					$(LIBMY_DIR)is_alnum.c \
					$(LIBMY_DIR)my_str_to_word_array.c \
					$(LIBMY_DIR)fill_word_array.c \
					$(LIBMY_DIR)my_printf.c \
					$(LIBMY_DIR)handle_char.c \
					$(LIBMY_DIR)handle_str.c \
					$(LIBMY_DIR)handle_int.c \
					$(LIBMY_DIR)percent.c \
					$(LIBMY_DIR)handle_hex.c \
					$(LIBMY_DIR)handle_hexmaj.c \
					$(LIBMY_DIR)handle_oct.c \
					$(LIBMY_DIR)handle_ptr.c \
					$(LIBMY_DIR)handle_flottants.c \
					$(LIBMY_DIR)handle_e.c \
					$(LIBMY_DIR)my_put_unsigned_nbr.c \
					$(LIBMY_DIR)handle_unsigned.c \
					$(LIBMY_DIR)my_strdup.c \
					$(LIBMY_DIR)str_to_digit.c \
					$(LIBMY_DIR)str_to_int.c \
					$(LIBMY_DIR)my_putfloat.c

OBJ		=	$(SRC_FILES:.c=.o)

OBJLIB	=	$(LIB_FILES:.c=.o)

EXEC	=	libhashtable.a

CFLAGS	=	-I$(INCLUDE_DIR) -Wall -Wextra -Llib -lmy

all:	libmy $(EXEC)

libmy:
	$(MAKE) -C $(LIBMY_DIR)

$(EXEC):	$(OBJ)
	ar rc -o $(EXEC) $(OBJ) $(OBJLIB)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBMY_DIR) clean

fclean:	clean
	rm -f $(EXEC)
	$(MAKE) -C $(LIBMY_DIR) fclean

re: fclean all
