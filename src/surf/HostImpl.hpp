/* Copyright (c) 2004-2018. The SimGrid Team. All rights reserved.          */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include "cpu_interface.hpp"
#include "network_interface.hpp"
#include "src/surf/PropertyHolder.hpp"

#include "StorageImpl.hpp"

#ifndef SURF_HOST_INTERFACE_HPP_
#define SURF_HOST_INTERFACE_HPP_

/*********
 * Model *
 *********/

namespace simgrid {
namespace surf {

/** @ingroup SURF_host_interface
 * @brief SURF Host model interface class
 * @details A model is an object which handle the interactions between its Resources and its Actions
 */
class XBT_PRIVATE HostModel : public kernel::resource::Model {
public:
  HostModel() : Model(Model::UpdateAlgo::FULL) {}

  virtual void ignore_empty_vm_in_pm_LMM();
  virtual kernel::resource::Action* execute_parallel(int host_nb, sg_host_t* host_list, double* flops_amount,
                                                     double* bytes_amount, double rate);
};

/************
 * Resource *
 ************/
/** @ingroup SURF_host_interface
 * @brief SURF Host interface class
 * @details An host represents a machine with a aggregation of a Cpu, a RoutingEdge and a Storage
 */
class XBT_PRIVATE HostImpl : public simgrid::surf::PropertyHolder {

public:
  explicit HostImpl(s4u::Host* host);
  virtual ~HostImpl() = default;

  /** @brief Get the vector of storages (by names) attached to the Host */
  virtual std::vector<const char*> get_attached_storages();

  std::map<std::string, simgrid::surf::StorageImpl*> storage_;
  simgrid::s4u::Host* piface_ = nullptr;
};
}
}

XBT_PUBLIC_DATA simgrid::surf::HostModel* surf_host_model;

#endif /* SURF_Host_INTERFACE_HPP_ */
