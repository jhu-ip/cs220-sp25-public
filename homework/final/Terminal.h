/////////////////////////////////
// DO NOT MODIFY THIS FILE!!!! //
/////////////////////////////////
#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <iostream>

static const char *CSI = "\x1b[";

// The Terminal class abstracts away things we need to draw in the terminal.
class Terminal {

public:
	// The possible colors. Note that foreground colors can also be 'bright',
	// adding another 8 colors
	enum Color {
		BLACK = 0,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE,
		DEFAULT_COLOR = 9
	};

	// Set the foreground color for the next piece of text, keeping the
	// background color as is.
	static void color_fg(bool bright, Color color) {
		std::cout << CSI << 30 + color << (bright ? ";1" : "") << "m";
	}

	// Set the background color for the next piece of text, keeping the
	// foreground color as-is.
	static void color_bg(Color color) {
		std::cout << CSI << 40 + color << "m";
	}

	// Set both background and foreground colors at the same time.
	static void color_all(bool bright, Color foreColor, Color backColor) {
		std::cout << CSI << 30 + foreColor << (bright ? ";1;" : ";") <<
			40 + backColor << "m";
	}

	// Reset the color to the default
	static void set_default() {
		std::cout << CSI << "0m";
	}

};

#endif // TERMINAL_H
