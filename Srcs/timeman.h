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

#ifndef TIMEMAN_H_INCLUDED
#define TIMEMAN_H_INCLUDED

#include "misc.h"
#include "search.h"
#include "thread.h"

/// The TimeManagement class computes the optimal time to think depending on
/// the maximum available time, the game move number and other parameters.

class TimeManagement {
public:
  TimeManagement(): newGame(false) {}
  void init(Search::LimitsType& limits, Color us, int ply);
  int optimum() const { return optimumTime; }
  int maximum() const { return maximumTime; }
  int elapsed() const { return int(Search::Limits.npmsec ? Threads.nodes_searched() : now() - startTime); }

  int64_t availableNodes; // When in 'nodes as time' mode
  bool newGame;

private:
  TimePoint startTime;
  int optimumTime;
  int maximumTime;
  int beyondReset;
};

extern TimeManagement Time;

#endif // #ifndef TIMEMAN_H_INCLUDED
