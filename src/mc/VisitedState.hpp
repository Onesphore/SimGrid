/* Copyright (c) 2007-2018. The SimGrid Team.
 * All rights reserved.                                                     */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#ifndef SIMGRID_MC_VISITED_STATE_HPP
#define SIMGRID_MC_VISITED_STATE_HPP

#include <cstddef>

#include <memory>

#include "src/mc/mc_snapshot.hpp"
#include "src/mc/mc_state.hpp"

namespace simgrid {
namespace mc {

class XBT_PRIVATE VisitedState {
public:
  std::shared_ptr<simgrid::mc::Snapshot> system_state = nullptr;
  std::size_t heap_bytes_used = 0;
  int actors_count            = 0;
  int num          = 0; // unique id of that state in the storage of all stored IDs
  int original_num = 0; // num field of the VisitedState to which I was declared equal to (used for dot_output)

  explicit VisitedState(unsigned long state_number);
  ~VisitedState() = default;
};

class XBT_PRIVATE VisitedStates {
  std::vector<std::unique_ptr<simgrid::mc::VisitedState>> states_;
public:
  void clear() { states_.clear(); }
  std::unique_ptr<simgrid::mc::VisitedState> addVisitedState(unsigned long state_number, simgrid::mc::State* graph_state, bool compare_snpashots);
private:
  void prune();
};

}
}

#endif
