#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

namespace Chess
{
	class Bishop : public Piece {

	public:
    bool legal_move_shape(const Position& start, const Position& end) const override;

		/////////////////////////////////////
		// DO NOT MODIFY THIS FUNCTION!!!! //
		/////////////////////////////////////
		char to_ascii() const override { return is_white() ? 'B' : 'b';	}
    
    /////////////////////////////////////
		// DO NOT MODIFY THIS FUNCTION!!!! //
		/////////////////////////////////////
		std::string to_unicode() const override { return is_white() ? "\u2657" : "\u265D"; }

	private:
		/////////////////////////////////////
		// DO NOT MODIFY THIS FUNCTION!!!! //
		/////////////////////////////////////
		Bishop(bool is_white) : Piece(is_white) {}

		friend Piece* create_piece(const char& piece_designator);
	};
}
#endif // BISHOP_H
