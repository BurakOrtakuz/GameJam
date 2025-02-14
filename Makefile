NAME		=	jam.exe

INCLUDEFLAGS = -Ilib -Iinclude
INCLUDEFLAGS +=	-Iinclude/Animation
INCLUDEFLAGS += -Iinclude/Enemies
INCLUDEFLAGS += -Iinclude/Game
INCLUDEFLAGS += -Iinclude/Objects


CXX			=	clang++
CXXFLAGS	=
#-Wall -Wextra -Werror
LDFLAGS		=	-lglfw -ldl -lGL -lz
GRAPHIC		=	lib/graphic.a

SRCDIR		=	./src
ANIMDIR		=	$(SRCDIR)/Animation
ENEMDIR		=	$(SRCDIR)/Enemies
OBJDIR		=	$(SRCDIR)/Objects

#Animation
SRC			=	$(ANIMDIR)/Animation.cpp \
				$(ANIMDIR)/frame.cpp \
				$(ANIMDIR)/FrameManager.cpp \

#Enemies
SRC			+=	$(ENEMDIR)/Enemy.cpp \
				$(ENEMDIR)/Wowo.cpp \

#Objects
SRC			+=	$(OBJDIR)/Player.cpp \
				$(OBJDIR)/Wall.cpp

SRC			+=	$(SRCDIR)/Camera.cpp \
				$(SRCDIR)/Collision.cpp \
				$(SRCDIR)/CollisionManager.cpp \
				$(SRCDIR)/Game.cpp \
				$(SRCDIR)/GameMap.cpp \
				$(SRCDIR)/GameObject.cpp \
				$(SRCDIR)/InputCallbacks.cpp \
				$(SRCDIR)/main.cpp \
				$(SRCDIR)/Shader.cpp \
				$(SRCDIR)/SpriteRenderer.cpp \
				$(SRCDIR)/TagManager.cpp \
				$(SRCDIR)/Texture2D.cpp \

OBJ			=	$(SRC:.cpp=.o)

all: graphall $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  $(OBJ) $(GRAPHIC) $(INCLUDEFLAGS) $(LDFLAGS) -o $(NAME)

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
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@

graphall:
	@make -C lib

.PHONY: all clean fclean re c f
