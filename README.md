# LTNC2022_UET_Nhom25_JumpKing

JumpKing_v2.0 project is the game created by the C++ language and SDL library.
It is a game about a king who is going to pass all obstacles and meet his queen at the top of the complex map.

The game has menu with only 2 option ("New game" to start a game and "Exit" to exit the game)
When the game is started, the king has to jump to different obstacles to get to the top, there is a time counting system which can save the highest score player can reach.
Also there are many potions which can cause the king some effects:
  + speed potion: increase the king's speed in 60sec (the king can move faster)
  + reverse potion: swap the left and the right buttons
  + cleanse potion: cleanse the effects of reverse potion
  + jump potion: increase the king's jump force in 60sec (the king can jump higher)
When reach to the top and meet the queen, player can press Y to play the game again for better score or press N to quit the game.

Ways to run the game by command line:
- (Makefile)
  + mingw32-make compile: compile the code
  + mingw32-make run: compile and run the code
  + mingw32-make run-only: run the code
- (command line)
  + g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o JumpKing src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf: compile and make the JumpKing.exe file
  + JumpKing.exe: run the JumpKing.exe and start the game.

Work Assignments:
  + ALL: ideas of the project and ideas of bonus funcions to make the game more interesting
  + Nguyen Duy Chien: init the game and map rendering
  + Nguyen Duy Linh: character and potion(buff and debuff)
  + Vu Truong Giang: loading text, menu and design map image, video.

Thanks for reading!
