/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_AMETSUCHI_H
#define IROHA_AMETSUCHI_H

#include <rxcpp/rx-observable.hpp>
#include <vector>
#include "ametsuchi/mutable_factory.hpp"
#include "ametsuchi/temporary_factory.hpp"
#include "common/result.hpp"

namespace shared_model {
  namespace interface {
    class Block;
  }
}  // namespace shared_model

namespace iroha {

  namespace ametsuchi {

    class BlockQuery;
    class WsvQuery;

    /**
     * Storage interface, which allows queries on current committed state, and
     * creation of state which can be mutated with blocks and transactions
     */
    class Storage : public TemporaryFactory, public MutableFactory {
     public:
      virtual std::shared_ptr<WsvQuery> getWsvQuery() const = 0;

      virtual std::shared_ptr<BlockQuery> getBlockQuery() const = 0;

      /**
       * Raw insertion of blocks without validation
       * @param block - block for insertion
       * @return true if inserted
       */
      virtual bool insertBlock(const shared_model::interface::Block &block) = 0;

      /**
       * Raw insertion of blocks without validation
       * @param blocks - collection of blocks for insertion
       * @return true if inserted
       */
      virtual bool insertBlocks(
          const std::vector<std::shared_ptr<shared_model::interface::Block>>
              &blocks) = 0;

      /**
       * method called when block is written to the storage
       * @return observable with the Block committed
       */
      virtual rxcpp::observable<std::shared_ptr<shared_model::interface::Block>>
      on_commit() = 0;

      /**
       * Remove all information without dropping the storage
       */
      virtual void reset() = 0;

      /**
       * Remove all information from ledger
       */
      virtual void dropStorage() = 0;

      virtual ~Storage() = default;
    };

  }  // namespace ametsuchi

}  // namespace iroha

#endif  // IROHA_AMETSUCHI_H
