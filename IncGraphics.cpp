#include "IncGraphics.hpp"

IncGraphics::IncGraphics() {

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
IncGraphics::IncGraphics(IncGraphics const &ref) { *this = ref; }
IncGraphics::~IncGraphics() { erase(); refresh(); endwin(); system("reset"); }

IncGraphics &IncGraphics::operator=(IncGraphics const &ref)
{
    (void)ref;
    return *this;
}

Direction IncGraphics::CheckEvent(Direction &dr)
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

void IncGraphics::Draw(Snake &snake, Fruit &fruit, Score &score, Init &init)
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
void IncGraphics::DrawObstacle(Snake &snake)
{
	std::vector<std::pair<int, int> > obs = snake.getObstacleCoords();

	for (size_t i = 0; i < obs.size(); i++)
    {
		attron(COLOR_PAIR (4));
		mvprintw(obs[i].second, obs[i].first, "o");		
		attroff(COLOR_PAIR (4));
		
    }
}

void IncGraphics::DelSnake(Snake &snake)
{
	std::pair<int, int> head = snake.getPrevHeadCoords();
	std::vector<std::pair<int, int>> tail = snake.getPrevTailCoords();

	for (int i = 0; i < snake.getTailLen(); i++)
	{
		mvprintw(tail[i].second, tail[i].first, " ");
	}
	mvprintw(head.second, head.first, " ");
}

void IncGraphics::DrawSnake(Snake &snake)
{
	std::pair<int, int> head = snake.getHeadCoords();
	std::vector<std::pair<int, int> > tail = snake.getTailCoords();

	for (int i = 0; i < snake.getTailLen() - 1; i++)
	{
		attron(COLOR_PAIR(2));
		mvprintw(tail[i].second, tail[i].first, "o");
		attroff(COLOR_PAIR(2));
	}
	attron(COLOR_PAIR(1));
	mvprintw(head.second, head.first, "X");
	attroff(COLOR_PAIR(1));
}

void IncGraphics::DrawFruit(Fruit &fruit)
{
	std::pair<int, int> crd = fruit.getCoords();
	attron(COLOR_PAIR(5));
	mvprintw(crd.second, crd.first, "0");
	attroff(COLOR_PAIR(5));
}

void IncGraphics::DrawMap(Init &init)
{
	int height = init.getHeight();
	int width = init.getWidth();
	
	attron(COLOR_PAIR (3));
	for (int j = 0; j < width; j++)
		mvaddstr(0, j, "#");

	for (int i = 0; i < height; i++) {
		mvaddstr(i, 0, "#");
		mvaddstr(i, width, "#");
	}
    
    for (int j = 0; j < width + 1; j++)
		mvaddstr(height, j, "#");
	attroff(COLOR_PAIR (3));
}

void IncGraphics::DrawMap(Border &border)
{
	int height = border.getHeight();
	int width = border.getWidth();
	
	attron(COLOR_PAIR (3));
	for (int j = 0; j < width; j++)
		mvaddstr(0, j, "#");

	for (int i = 0; i < height; i++) {
		mvaddstr(i, 0, "#");
		mvaddstr(i, width, "#");
	}
    
    for (int j = 0; j < width + 1; j++)
		mvaddstr(height, j, "#");
	attroff(COLOR_PAIR (3));
}
