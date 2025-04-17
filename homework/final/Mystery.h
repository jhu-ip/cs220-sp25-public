///////////////////////////////////
// IT IS OK TO MODIFY THIS FILE, //
// YOU WON'T HAND IT IN!!!!!     //
///////////////////////////////////
#ifndef MYSTERY_H
#define MYSTERY_H

#include "Piece.h"

namespace Chess
{
	class Mystery : public Piece {

	public:
		bool legal_move_shape(const Position&, const Position&) const override { return false; }

		char to_ascii() const override { return is_white() ? 'M' : 'm';	}
    
    std::string to_unicode() const override { return is_white() ? "\u2687" : "\u2689"; }

	private:
		Mystery(bool is_white) : Piece(is_white) {}

		friend Piece* create_piece(const char& piece_designator);
	};
}
#endif // MYSTERY_H
