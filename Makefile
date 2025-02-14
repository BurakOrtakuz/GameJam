NAME		=	jam.exe

RELEASE_FLAGS = -O3 -DNDEBUG -s
INCLUDEFLAGS = -Ilib -Iinclude -Iinclude/Animation -Iinclude/Game -Iinclude/Objects
LDFLAGS = -lglfw3 -lgdi32 -lopengl32 -lmingw32 -mwindows

INC_FLAGS	=	-Ilib -Iinclude

CXX			=	c++
CXXFLAGS	=	$(RELEASE_FLAGS) $(INCLUDEFLAGS) -static
#-Wall -Wextra -Werror
GRAPHIC		=	lib/graphic.a

SRCDIR		=	./src

SRC			=	$(SRCDIR)/Animation/Animation.cpp \
				$(SRCDIR)/Animation/frame.cpp \
				$(SRCDIR)/Animation/FrameManager.cpp \
				$(SRCDIR)/Camera.cpp \
				$(SRCDIR)/Game.cpp \
				$(SRCDIR)/GameMap.cpp \
				$(SRCDIR)/GameObject.cpp \
				$(SRCDIR)/InputCallbacks.cpp \
				$(SRCDIR)/main.cpp \
				$(SRCDIR)/Shader.cpp \
				$(SRCDIR)/SpriteRenderer.cpp \
				$(SRCDIR)/Texture2D.cpp \
				$(SRCDIR)/Objects/Player.cpp \
				$(SRCDIR)/Objects/Wall.cpp

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