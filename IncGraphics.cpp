#include "IncGraphics.hpp"

IncGraphics::IncGraphics() {

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
	init_pair (6, COLOR_GREEN, COLOR_GREEN);
	init_pair (7, COLOR_RED, COLOR_BLACK);
	timeout(1);
}
IncGraphics::IncGraphics(IncGraphics const &ref) { *this = ref; }
IncGraphics::~IncGraphics() {}

IncGraphics &IncGraphics::operator=(IncGraphics const &ref)
{
    (void)ref;
    return *this;
}

Direction IncGraphics::CheckEvent(Direction &dr) const
{
	int key = 0;

	key = getch();
	// if (key == 113)
	// {
	// 	refresh();
	// 	system("reset");
	// 	exit(1);
	// }
	if (key == 115) // key W
		dr = down;
	if (key == 119) // key S
		dr = up;
	if (key == 97) 	// key D
		dr = left;
	if (key == 100) // key A
		dr = right;
	return (dr);
}

void IncGraphics::Draw(Snake &snake, Fruit &fruit, Score &score, Init &init) const
{
	int height = init.getHeight();
	int width = init.getWidth();

	attron(COLOR_PAIR (7));
	mvprintw(height + 1, 0, "Score: ");
	mvprintw(height + 1, 7, std::to_string(score.getScore()).c_str());
	attroff(COLOR_PAIR (7));

	DelSnake(snake, init);
	DrawSnake(snake, init);
	// refresh();
	// erase();
}
void IncGraphics::DelSnake(Snake &snake, Init &init) const
{
	std::pair<int, int> head = snake.getHeadCoords();
	std::vector<std::pair<int, int>> tail = snake.getTailCoords();
	Direction dr = snake.getDir();
	int x = 0;
	int y = 0;	

	if (dr == up)
		y = -1;
	else if (dr == down)
		y = 1;
	else if (dr == left)
		x = -1;
	else if (dr == right)
		x = 1;

	mvprintw(head.second - y, head.first - x, "  ");
	for (size_t i = 0; i < snake.getTailLen(); i++)
	{
		mvprintw(tail[i].second - y, tail[i].first - x, "  ");
	}
}

void IncGraphics::DrawSnake(Snake &snake, Init &init) const
{
	std::pair<int, int> head = snake.getHeadCoords();
	std::vector<std::pair<int, int> > tail = snake.getTailCoords();

	attron(COLOR_PAIR (1));
	mvprintw(head.second, head.first, "XX");
	attroff(COLOR_PAIR (1));
	for (size_t i = 0; i < snake.getTailLen(); i++)
	{
		attron(COLOR_PAIR (2));
		mvprintw(tail[i].second, tail[i].first, "00");
		attroff(COLOR_PAIR (2));
	}
}

void IncGraphics::DrawMap(Border &border) const
{
	int height = border.getHeight();
	int width = border.getWidth();

	for (int j = 0; j < width; j++) {

		attron(COLOR_PAIR (3));
		mvaddstr(0, j, "#");
		attroff(COLOR_PAIR (3));
	}

	for (int i = 0; i < height; i++) {

		attron(COLOR_PAIR (3));
		mvaddstr(i, 0, "##");
		mvaddstr(i, width, "##");
		attroff(COLOR_PAIR (3));
	}
    
    for (int j = 0; j < width + 1; j++) {

		attron(COLOR_PAIR (3));
		mvaddstr(height, j, "#");
		attroff(COLOR_PAIR (3));
	}
	attron(COLOR_PAIR(3));
	mvaddstr(height, width + 1, "#");
	attroff(COLOR_PAIR(3));
}
