///////////////////////////////////////////////////////////
// DO NOT REMOVE OR MODIFY ANY DECLARATIONS IN THIS FILE //
// YOU MAY ADD AS NEEDED TO SATISFY THE HANDOUT          //
///////////////////////////////////////////////////////////
#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include <string>

namespace Chess
{
  // define pair of characters as a new type to represent a position on the board
  typedef std::pair<char, char> Position;

	class Piece {

	public:
		// The destructor for Piece is declared virtual so derived classes can override it
		virtual ~Piece(){}

		// Returns information about the color of the piece.
		bool is_white() const { return white; }

		// Indicates whether the given start and end coordinates describe a move that
		// would be considered valid for this piece if there is no piece at the end
		// position (i.e. this is not a capture move).
        // It does not check whether the path from start to end is clear since not all
        // piece types require a clear path.
		virtual bool legal_move_shape(const Position& start, const Position& end) const = 0;

		// Indicates whether the given start and end coordinates describe a move that
		// would be considered valid for this piece if there is a piece at the end
		// position (i.e. this is a capture move)
		virtual bool legal_capture_shape(const Position& start, const Position& end) const {
			return legal_move_shape(start, end);
		}

		// Returns a character representing the piece type. Characters are:
        //      Piece     White   Black
		//		King:     K       k
		//		Queen:    Q       q
		//		Rook:     R       r
		//		Bishop:   B       b
		//		Knight:   N       n
		//		Pawn:     P       p
		//		Mystery:  M       m
		virtual char to_ascii() const = 0;

        // Return unicode character representing the piece type. Characters are:
        //      Piece     White   Black
		//		King:     U+2654  U+265A
		//		Queen:    U+2655  U+265B
		//		Rook:     U+2656  U+265C
        //		Bishop:   U+2657  U+265D
		//		Knight:   U+2658  U+265E
		//		Pawn:     U+2658  U+265F
		//		Mystery:  U+2687  U+2689
        virtual std::string to_unicode() const = 0;

	protected:
		// When a piece is created, its color must be provided as an argument
		Piece(bool is_white) : white(is_white){ }

	private:
		// A boolean value indicating whether the piece is white or black
		bool white;
	};
}
#endif // PIECE_H
