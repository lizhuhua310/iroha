/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_SIMULATOR_MOCKS_HPP
#define IROHA_SIMULATOR_MOCKS_HPP

#include <gmock/gmock.h>
#include "simulator/block_creator.hpp"

namespace iroha {
  namespace simulator {
    class MockBlockCreator : public BlockCreator {
     public:
      MOCK_METHOD1(process_verified_proposal,
                   void(const VerifiedProposalCreatorEvent &));
      MOCK_METHOD0(on_block, rxcpp::observable<BlockCreatorEvent>());
    };
  }  // namespace simulator
}  // namespace iroha

#endif  // IROHA_SIMULATOR_MOCKS_HPP
