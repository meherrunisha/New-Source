/*
  Al Qahtani , a UCI chess playing engine derived from Stockfish
  Al Qahtani  is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Al Qahtani  is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <fstream>
#include <string>

#include "misc.h"
#include "position.h"

class PolyglotBook : private std::ifstream {
public:
  PolyglotBook();
 ~PolyglotBook();
  Move probe(const Position& pos, const std::string& fName, bool pickBest);

private:
  template<typename T> PolyglotBook& operator>>(T& n);

  bool open(const char* fName);
  size_t find_first(Key key);

  PRNG rng;
  std::string fileName;
};

#endif // #ifndef BOOK_H_INCLUDED
