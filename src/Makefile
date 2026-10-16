CXX = clang++
CFLAGS = -Wall -Wvla -Werror -gdwarf-4

########################################################################

.PHONY: asan msan nosan

asan: CXXFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CXXFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

.PHONY: all
all: chess

chess: setupGame/setupGame.h normalGame/normalGame.h replayGame/replayGame.h statsGame/statsGame.h endGame/endGame.h gameData/gameData.h boardFunctions/boardFunctions.h
	$(CXX) $(CXXFLAGS) -o chess main.cpp setupGame/setupGame.cpp normalGame/normalGame.cpp replayGame/replayGame.cpp statsGame/statsGame.cpp endGame/endGame.cpp gameData/gameData.cpp boardFunctions/boardFunctions.cpp

.PHONY: clean
clean:
	rm -f chess

