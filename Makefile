NAME		=	jam.exe

INC_FLAGS	=	-Ilib -Iinclude

CXX			=	clang++
CXXFLAGS	=	
#-Wall -Wextra -Werror
LDFLAGS		=	-lglfw -ldl -lGL -lz
GRAPHIC		=	lib/graphic.a

SRCDIR		=	./src

SRC			=	$(SRCDIR)/Camera.cpp \
				$(SRCDIR)/Game.cpp \
				$(SRCDIR)/GameMap.cpp \
				$(SRCDIR)/GameObject.cpp \
				$(SRCDIR)/InputCallbacks.cpp \
				$(SRCDIR)/main.cpp \
				$(SRCDIR)/Shader.cpp \
				$(SRCDIR)/SpriteRenderer.cpp \
				$(SRCDIR)/Texture2D.cpp \
				$(SRCDIR)/Player.cpp

OBJ			=	$(SRC:.cpp=.o)

all: graphall $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  $(OBJ) $(GRAPHIC) $(INC_FLAGS) $(LDFLAGS) -o $(NAME)

rrun: re
	@./$(NAME) || true

run: all
	@./$(NAME) || true

c: clean
clean:
	$(RM) $(OBJ)

f: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

graphall:
	@make -C lib

.PHONY: all clean fclean re c f