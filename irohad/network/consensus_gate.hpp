/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_CONSENSUS_GATE_HPP
#define IROHA_CONSENSUS_GATE_HPP

#include <boost/optional.hpp>
#include <rxcpp/rx.hpp>
#include "consensus/gate_object.hpp"
#include "consensus/round.hpp"
#include "simulator/block_creator_common.hpp"

namespace shared_model {
  namespace interface {
    class Block;
    class Proposal;
  }  // namespace interface
}  // namespace shared_model

namespace iroha {
  namespace network {
    /**
     * Public api of consensus module
     */
    class ConsensusGate {
     public:
      using Round = consensus::Round;
      /**
       * Providing data for consensus for voting
       */
      virtual void vote(const simulator::BlockCreatorEvent &event) = 0;

      using GateObject = consensus::GateObject;

      /**
       * @return emit gate responses
       */
      virtual rxcpp::observable<GateObject> onOutcome() = 0;

      virtual ~ConsensusGate() = default;
    };
  }  // namespace network
}  // namespace iroha
#endif  // IROHA_CONSENSUS_GATE_HPP
