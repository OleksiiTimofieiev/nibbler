#include "IGraphicsNCURSES.hpp"

extern "C" IGraphics *NewDisplay(void)
{
	return (new IGraphicsNCURSES());
}

IGraphicsNCURSES::IGraphicsNCURSES() {

	setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	start_color();
	init_pair (1, COLOR_CYAN, COLOR_CYAN);
	init_pair (2, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair (3, COLOR_WHITE, COLOR_WHITE);
	init_pair (4, COLOR_YELLOW, COLOR_YELLOW);
	init_pair (5, COLOR_RED, COLOR_RED);
	init_pair (7, COLOR_RED, COLOR_BLACK);
	timeout(1);
}
IGraphicsNCURSES::IGraphicsNCURSES(IGraphicsNCURSES const &ref) { *this = ref; }
IGraphicsNCURSES::~IGraphicsNCURSES() { erase(); refresh(); endwin(); system("reset"); }

IGraphicsNCURSES &IGraphicsNCURSES::operator=(IGraphicsNCURSES const &ref)
{
    (void)ref;
    return *this;
}

Direction IGraphicsNCURSES::CheckEvent(Direction &dr)
{
	int key = 0;

	key = getch();
	if (key == 115)      // key W
		dr = down;
	else if (key == 119) // key S
		dr = up;
	else if (key == 97)  // key D
		dr = left;
	else if (key == 100) // key A
		dr = right;
	else if (key == 113) // key Q
		dr = stop_the_game;
	else if (key == 101) // key E
		dr = change_the_lib;
	return (dr);
}

void IGraphicsNCURSES::Draw(Snake &snake, Fruit &fruit, Score &score, Init &init)
{
	(void)score;
	(void)init;	
	if (snake.getDir() != stop)
		DelSnake(snake);
	DrawObstacle(snake);
	DrawSnake(snake);
	DrawFruit(fruit);
	DrawMap(init);
}
void IGraphicsNCURSES::DrawObstacle(Snake &snake)
{
	std::vector<std::pair<int, int> > obs = snake.getObstacleCoords();

	for (size_t i = 0; i < obs.size(); i++)
    {
		attron(COLOR_PAIR (4));
		mvprintw(obs[i].second + 1, obs[i].first + 1, "o");		
		attroff(COLOR_PAIR (4));
		
    }
}

void IGraphicsNCURSES::DelSnake(Snake &snake)
{
	std::pair<int, int> head = snake.getPrevHeadCoords();
	std::vector<std::pair<int, int>> tail = snake.getPrevTailCoords();

	for (int i = 0; i < snake.getTailLen(); i++)
	{
		mvprintw(tail[i].second + 1, tail[i].first + 1, " ");
	}
	mvprintw(head.second + 1, head.first + 1, " ");
}

void IGraphicsNCURSES::DrawSnake(Snake &snake)
{
	std::pair<int, int> head = snake.getHeadCoords();
	std::vector<std::pair<int, int> > tail = snake.getTailCoords();

	for (int i = 0; i < snake.getTailLen() - 1; i++)
	{
		attron(COLOR_PAIR(2));
		mvprintw(tail[i].second + 1, tail[i].first + 1, "o");
		attroff(COLOR_PAIR(2));
	}
	attron(COLOR_PAIR(1));
	mvprintw(head.second + 1, head.first + 1, "X");
	attroff(COLOR_PAIR(1));
}

void IGraphicsNCURSES::DrawFruit(Fruit &fruit)
{
	std::pair<int, int> crd = fruit.getCoords();
	attron(COLOR_PAIR(5));
	mvprintw(crd.second + 1, crd.first + 1, "0");
	attroff(COLOR_PAIR(5));
}

void IGraphicsNCURSES::DrawMap(Init &init)
{
	int height = init.getHeight();
	int width = init.getWidth();

	attron(COLOR_PAIR(3));
	for (int j = 0; j < width + 2; j++)
		mvaddstr(0, j, "#");

	for (int i = 0; i < height + 2; i++)
	{
		mvaddstr(i, 0, "#");
		mvaddstr(i, width + 2, "#");
	}
	for (int j = 0; j < width + 3; j++)
		mvaddstr(height + 2, j, "#");
	attroff(COLOR_PAIR(3));
}

void IGraphicsNCURSES::DrawMap(Border &border)
{
	int height = border.getHeight();
	int width = border.getWidth();
	
	attron(COLOR_PAIR (3));
	for (int j = 0; j < width + 2; j++)
		mvaddstr(0, j, "#");

	for (int i = 0; i < height + 2; i++) {
		mvaddstr(i, 0, "#");
		mvaddstr(i, width + 2, "#");
	}    
    for (int j = 0; j < width + 3; j++)
		mvaddstr(height + 2, j, "#");
	attroff(COLOR_PAIR (3));
}
