/* Copyright (c) 2013-2016. The SimGrid Team. All rights reserved.          */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#ifndef SIMGRID_ROUTING_GENERIC_HPP_
#define SIMGRID_ROUTING_GENERIC_HPP_

#include "src/kernel/routing/NetZoneImpl.hpp"

namespace simgrid {
namespace kernel {
namespace routing {

class XBT_PRIVATE RoutedZone : public NetZoneImpl {
public:
  explicit RoutedZone(NetZone* father, const char* name);

  void getGraph(xbt_graph_t graph, xbt_dict_t nodes, xbt_dict_t edges) override;
  virtual sg_platf_route_cbarg_t newExtendedRoute(RoutingMode hierarchy, sg_platf_route_cbarg_t routearg,
                                                  int change_order);

protected:
  void getRouteCheckParams(NetCard* src, NetCard* dst);
  void addRouteCheckParams(sg_platf_route_cbarg_t route);
};
}
}
} // namespace

SG_BEGIN_DECL()
XBT_PRIVATE xbt_node_t new_xbt_graph_node(xbt_graph_t graph, const char* name, xbt_dict_t nodes);
XBT_PRIVATE xbt_edge_t new_xbt_graph_edge(xbt_graph_t graph, xbt_node_t s, xbt_node_t d, xbt_dict_t edges);
SG_END_DECL()

#endif /* SIMGRID_ROUTING_GENERIC_HPP_ */