#pragma once
#include <mutex>
#include "move.h"

namespace UCI {

class Info {
	Move _pv[MAX_PLY + 1];
	int _depth, _score, _nodes;
	mutable bool updated;
	mutable std::mutex m;
public:
	void clear();
	void update(int depth, int score, int nodes, Move *pv);
	void print() const;
};

}	// namespace UCI

