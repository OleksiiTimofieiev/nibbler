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

	if (snake.getDir() != stop)
		DelSnake(snake);
	DrawSnake(snake);
	DrawFruit(fruit);
}
void IncGraphics::DelSnake(Snake &snake) const
{
	std::pair<int, int> head = snake.getPrevHeadCoords();
	std::vector<std::pair<int, int>> tail = snake.getPrevTailCoords();

	for (size_t i = 0; i < snake.getTailLen(); i++)
	{
		mvprintw(tail[i].second, tail[i].first, " ");
	}
	mvprintw(head.second, head.first, " ");
}

void IncGraphics::DrawSnake(Snake &snake) const
{
	std::pair<int, int> head = snake.getHeadCoords();
	std::vector<std::pair<int, int> > tail = snake.getTailCoords();

	for (size_t i = 0; i < snake.getTailLen(); i++)
	{
		attron(COLOR_PAIR(2));
		mvprintw(tail[i].second, tail[i].first, "0");
		// std::cout << "x: " << tail[i].second << " y: " << tail[i].second << std::endl;
		attroff(COLOR_PAIR(2));
	}
	attron(COLOR_PAIR(1));
	mvprintw(head.second, head.first, "X");
	attroff(COLOR_PAIR(1));
}

void IncGraphics::DrawFruit(Fruit &fruit) const
{
	std::pair<int, int> crd = fruit.getCoords();
	mvprintw(crd.second, crd.first, "%C", L'🍎');
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
