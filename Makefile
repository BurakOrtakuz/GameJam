NAME		=	jam.exe

INC_FLAGS	=	-Ilib -Iinclude -Iinclude/Animation -Iinclude/Game -Iinclude/Objects

CXX			=	clang++
CXXFLAGS	=
#-Wall -Wextra -Werror
LDFLAGS		=	-lglfw -ldl -lGL -lz
GRAPHIC		=	lib/graphic.a

SRCDIR		=	./src

SRC			=	$(SRCDIR)/Animation/Animation.cpp \
				$(SRCDIR)/Animation/frame.cpp \
				$(SRCDIR)/Animation/FrameManager.cpp \
				$(SRCDIR)/Camera.cpp \
				$(SRCDIR)/Collision.cpp \
				$(SRCDIR)/CollisionManager.cpp \
				$(SRCDIR)/Game.cpp \
				$(SRCDIR)/GameMap.cpp \
				$(SRCDIR)/GameObject.cpp \
				$(SRCDIR)/InputCallbacks.cpp \
				$(SRCDIR)/TagManager.cpp \
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
	@make -C lib clean
	$(RM) $(OBJ)

f: fc
fclean: fc
fc: clean
	@make -C lib fclean
	$(RM) $(NAME)

re: fclean all

rr: rerun

rerun: re
	./$(NAME)

run : all
	./$(NAME)
.PHONY: all c clean fc fclean re run


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

graphall:
	@make -C lib

.PHONY: all clean fclean re c f
