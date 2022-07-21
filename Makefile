  CC		= 	gcc
  LIBA		=	include/liba/*  
  LIBG		=	lisgraph.a
  MOD           =       adventure

  BIN           =       adventure
  FLAG          =       -W -Wall -Werror -Wextra -Wundef -Wshadow -Wdouble-promotion -Wformat=2 -Wformat-truncation -Wunused-parameter -fno-common -ffunction-sections -fdata-sections\
-g3 -s -Os -s -std=c11

  INCLUDE       =       -I./include/ -I./include/lib -I./include/lib_pixel -I./include/animation -I./include/scene -I./include/graph
  SRC           =       $(shell find ./ -name "*.c")
  OBJ           =       $(SRC:.c=.o)
  LIBPATH       =       -L${HOME}/.froot/lib/
  LIB           =       -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -l\
avcall -lusb

  all:          complib
  bin:          $(OBJ)
	@$(CC) $(OBJ) -o $(BIN) $(LIB)
	@echo ${YELLOW} "[FINISHED] " ${DEFAULT} $(BIN)

  complib:      $(OBJ)
	@$(CC) $(OBJ) -o $(BIN) $(LIBA2) $(LIB) #$(LIBG)
	@echo ${YELLOW} "[FINISHED] " ${DEFAULT} $(BIN)

  lib:          $(OBJ)
	@ar cr $(LIBA) $(OBJ)
	@ranlib $(LIBA)
	@echo ${PURPLE} "[DONE]" ${DEFAULT}

  .c.o:
	@$(CC) $(INCLUDE) $(FLAG) -c $< -o $@
	@echo ${GREEN} "[OK]" ${DEFAULT} $< 
  clean:
	@rm -f $(OBJ)
	@echo ${PURPLE} "[CLEANED]" ${DEFAULT}
  fclean:       clean
	@rm -f $(BIN)
  re:           fclean complib

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o

# Colors

DEFAULT = "\033[00m"
GREEN = "\033[1;32m"
TEAL = "\033[1;36m"
RED = "\033[1;31m"
BLACK = "\033[1;30m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE = "\033[1;37m"
