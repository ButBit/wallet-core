// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "../uint256.h"

namespace TW::Ethereum {

class Transaction {
public:
    uint256_t nonce;
    uint256_t gasPrice;
    uint256_t gasLimit;
    // Public key hash (Address.bytes)
    Data to;
    uint256_t amount;
    Data payload;

    // Signature values
    uint256_t v = uint256_t();
    uint256_t r = uint256_t();
    uint256_t s = uint256_t();

    // factory methods
    // Create a native coin transfer transaction
    static Transaction buildTransfer(uint256_t nonce, uint256_t gasPrice, uint256_t gasLimit, const Data& to, uint256_t amount) {
        return Transaction(nonce, gasPrice, gasLimit, to, amount, {});
    }
    // Create a generic smart contract transaction
    static Transaction buildSmartContract(uint256_t nonce, uint256_t gasPrice, uint256_t gasLimit, const Data& to, const TW::Data& payload) {
        return Transaction(nonce, gasPrice, gasLimit, to, 0, payload);
    }

private:
    Transaction(uint256_t nonce, uint256_t gasPrice, uint256_t gasLimit, const Data& to, uint256_t amount, const Data& payload)
        : nonce(std::move(nonce))
        , gasPrice(std::move(gasPrice))
        , gasLimit(std::move(gasLimit))
        , to(std::move(to))
        , amount(std::move(amount))
        , payload(std::move(payload)) {}
};

} // namespace TW::Ethereum
