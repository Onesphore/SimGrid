/* Copyright (c) 2010-2018. The SimGrid Team.
 * All rights reserved.                                                     */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include "src/instr/instr_private.hpp"
#include <string>

XBT_LOG_NEW_DEFAULT_SUBCATEGORY (instr_resource, instr, "tracing (un)-categorized resource utilization");

void TRACE_surf_resource_set_utilization(const char* type, const char* name, const char* resource, const char* category,
                                         double value, double now, double delta)
{
  // only trace resource utilization if resource is known by tracing mechanism
  container_t container = simgrid::instr::Container::by_name_or_null(resource);
  if (not container || not value)
    return;

  // trace uncategorized resource utilization
  if (TRACE_uncategorized()){
    XBT_DEBUG("UNCAT %s [%f - %f] %s %s %f", type, now, now + delta, resource, name, value);
    container->get_variable(name)->instr_event(now, delta, resource, value);
  }

  // trace categorized resource utilization
  if (TRACE_categorized() && category) {
    std::string category_type = name[0] + std::string(category);
    XBT_DEBUG("CAT %s [%f - %f] %s %s %f", type, now, now + delta, resource, category_type.c_str(), value);
    container->get_variable(name)->instr_event(now, delta, resource, value);
  }
}
