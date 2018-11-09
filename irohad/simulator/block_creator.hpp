/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_BLOCK_CREATOR_HPP
#define IROHA_BLOCK_CREATOR_HPP

#include <rxcpp/rx.hpp>
#include "simulator/verified_proposal_creator_common.hpp"

namespace shared_model {
  namespace interface {
    class Block;
  }  // namespace interface
}  // namespace shared_model

namespace iroha {
  namespace simulator {

    /**
     * Interface for creating blocks from proposal
     */
    class BlockCreator {
     public:
      /**
       * Processing proposal for making stateful validation
       * @param proposal - object for validation
       */
      virtual void process_verified_proposal(
          const VerifiedProposalCreatorEvent &event) = 0;

      /**
       * Emit blocks made from proposals
       * @return
       */
      virtual rxcpp::observable<std::shared_ptr<shared_model::interface::Block>>
      on_block() = 0;

      virtual ~BlockCreator() = default;
    };
  }  // namespace simulator
}  // namespace iroha
#endif  // IROHA_BLOCK_CREATOR_HPP
