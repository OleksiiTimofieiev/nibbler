#include "IncGraphics.hpp"

IncGraphics::IncGraphics() {

    initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	start_color();
	timeout(1);
	init_pair (1, COLOR_CYAN, COLOR_BLACK);
	init_pair (2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair (3, COLOR_WHITE, COLOR_WHITE);
	init_pair (4, COLOR_YELLOW, COLOR_YELLOW);
	init_pair (5, COLOR_RED, COLOR_BLACK);
	init_pair (6, COLOR_GREEN, COLOR_GREEN);
	init_pair (7, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair (8, COLOR_GREEN, COLOR_BLACK);

}
IncGraphics::IncGraphics(IncGraphics const &ref) { *this = ref; }
IncGraphics::~IncGraphics() {}

IncGraphics &IncGraphics::operator=(IncGraphics const &ref)
{
    (void)ref;
    return *this;
}

void IncGraphics::Draw(Fruit &fruit, Score &score, Init &init) const
{
	int height = init.getHeight();
	int width = init.getWidth();

	attron(COLOR_PAIR (5));
	mvprintw(height + 1, 0, "Score: ");
	mvprintw(height + 1, 7, std::to_string(score.getScore()).c_str());
	attroff(COLOR_PAIR (5));	
}

void IncGraphics::DrawMap(Border &border) const
{
	int height = border.getHeight();
	int width = border.getWidth();

    for (int j = 0; j < width; j++) {

		attron(COLOR_PAIR (3));
		mvprintw(0, j, "#");
		attroff(COLOR_PAIR (3));
	}

	for (int i = 0; i < height; i++) {

		attron(COLOR_PAIR (3));
		mvprintw(i, 0, "#");
		mvprintw(i, width, "#");
		attroff(COLOR_PAIR (3));
	}
    
    for (int j = 0; j < width + 1; j++) {

		attron(COLOR_PAIR (3));
		mvprintw(height, j, "#");
		attroff(COLOR_PAIR (3));
	}
    refresh();
    erase();
}