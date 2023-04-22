CC =gcc
CFLAGS =-I/usr/include -g 
LDFLAGS = 
EXEC =ft_ls

INCLUDES = -I ./Libft/Libft -I ./Libft/List -I /Libft -I ls_struct -I ls_list -I ./opt -I ./ls_aff -I ./ls_sort_alg

SRC = ./Libft/Libft/libft.c \
		./Libft/Libft/ft_strsjoin.c \
		./Libft/List/list.c \
		./Libft/ft_printf.c \
		./ls_list/ls_list.c \
		./opt/options.c \
		./ls_aff/ls_aff.c \
		./ls_sort_alg/sort_alg.c \
		./ls_sort_alg/ls_sort_swap.c \
		./ft_ls.c

HEADS = ./Libft/Libft/libft.h \
		./Libft/List/list.h \
		./ls_list/ls_list.h \
		./ls_aff/ls_aff.h \
		./ls_sort_alg/sort_alg.h \
		./ls_sort_alg/ls_sort_swap.h \
		./opt/options.h
		
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC) 

$(OBJ) : $(HEADS)

%.o :%.c  $(HEADS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	

.PHONY : clean mrproper

clean : 
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXEC)

