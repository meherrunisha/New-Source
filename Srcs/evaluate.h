/*
  Al Qahtani - A UCI chess engine. Copyright (C) 2013-2015 Mohamed Nayeem
  Al Qahtani is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  Al Qahtani is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Al Qahtani. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVALUATE_H_INCLUDED
#define EVALUATE_H_INCLUDED

#include <string>

#include "types.h"

class Position;

namespace Eval {

const Value Tempo = Value(20); // Must be visible to search

void init();
Value evaluate(const Position& pos);
std::string trace(const Position& pos);

}

#endif // #ifndef EVALUATE_H_INCLUDED
