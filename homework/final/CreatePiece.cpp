/////////////////////////////////
// DO NOT MODIFY THIS FILE!!!! //
/////////////////////////////////
#include <cstddef>
#include "CreatePiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Mystery.h"

namespace Chess
{

	Piece* create_piece(const char& piece_designator) {
		switch (piece_designator) {

			case 'K': return new King(true);
			case 'k': return new King(false);
			case 'Q': return new Queen(true);
			case 'q': return new Queen(false);
			case 'B': return new Bishop(true);
			case 'b': return new Bishop(false);
			case 'N': return new Knight(true);
			case 'n': return new Knight(false);
			case 'R': return new Rook(true);
			case 'r': return new Rook(false);
			case 'P': return new Pawn(true);
			case 'p': return new Pawn(false);
			case 'M': return new Mystery(true);
			case 'm': return new Mystery(false);
			default: return nullptr;

		}
	}
}
