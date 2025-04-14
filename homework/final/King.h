#ifndef KING_H
#define KING_H

#include "Piece.h"

namespace Chess
{
	class King : public Piece {

	public:
    bool legal_move_shape(const Position& start, const Position& end) const override;

		/////////////////////////////////////
		// DO NOT MODIFY THIS FUNCTION!!!! //
		/////////////////////////////////////
		char to_ascii() const override { return is_white() ? 'K' : 'k';	}
    
    /////////////////////////////////////
		// DO NOT MODIFY THIS FUNCTION!!!! //
		/////////////////////////////////////
		std::string to_unicode() const override { return is_white() ? "\u2654" : "\u265A"; }
    
	private:
		/////////////////////////////////////
		// DO NOT MODIFY THIS FUNCTION!!!! //
		/////////////////////////////////////
		King(bool is_white) : Piece(is_white) {}

		friend Piece* create_piece(const char& piece_designator);
	};

}
#endif // KING_H
