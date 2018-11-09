/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_VERIFIED_PROPOSAL_CREATOR_HPP
#define IROHA_VERIFIED_PROPOSAL_CREATOR_HPP

#include <rxcpp/rx.hpp>
#include "network/ordering_gate_common.hpp"
#include "simulator/verified_proposal_creator_common.hpp"

namespace iroha {
  namespace simulator {

    /**
     * Interface for providing proposal validation
     */
    class VerifiedProposalCreator {
     public:
      /**
       * Processing proposal for making stateful validation
       * @param event - object for validation
       */
      virtual void process_proposal(const network::OrderingEvent &event) = 0;

      /**
       * Emit proposals which were verified by stateful validator
       */
      virtual rxcpp::observable<VerifiedProposalCreatorEvent>
      on_verified_proposal() = 0;

      virtual ~VerifiedProposalCreator() = default;
    };
  }  // namespace simulator
}  // namespace iroha
#endif  // IROHA_VERIFIED_PROPOSAL_CREATOR_HPP
