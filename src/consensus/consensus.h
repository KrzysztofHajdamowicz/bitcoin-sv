// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2018-2019 Bitcoin Association
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#ifndef BITCOIN_CONSENSUS_CONSENSUS_H
#define BITCOIN_CONSENSUS_CONSENSUS_H

#include <cstdint>

/** 1KB */
static const uint64_t ONE_KILOBYTE = 1000;
/** 1MB */
static const uint64_t ONE_MEGABYTE = ONE_KILOBYTE * 1000;
/** 1GB */
static const uint64_t ONE_GIGABYTE = ONE_MEGABYTE * 1000;
/** The maximum allowed size for a transaction, in bytes */
static const uint64_t MAX_TX_SIZE = ONE_MEGABYTE;
/** The maximum allowed size for a block, before the UAHF */
static const uint64_t LEGACY_MAX_BLOCK_SIZE = ONE_MEGABYTE;

/**
 * The maximum allowed number of signature check operations per MB in a block
 * (network rule).
 */
static const int64_t MAX_BLOCK_SIGOPS_PER_MB = 20000;
/** allowed number of signature check operations per transaction. */
static const uint64_t MAX_TX_SIGOPS_COUNT = 20000;

// Maximum number of non-push operations per script before GENESIS
static const uint64_t MAX_OPS_PER_SCRIPT_BEFORE_GENESIS = 500;

// Maximum number of non-push operations per script after GENESIS
static const uint64_t MAX_OPS_PER_SCRIPT_AFTER_GENESIS = UINT32_MAX;


/** Allowed number of signature check operations per transaction before Genesis */
static const uint64_t MAX_TX_SIGOPS_COUNT_BEFORE_GENESIS = 20000;
/** Allowed number of signature check operations per transaction after Genesis (max value of uint32) */
static const uint64_t MAX_TX_SIGOPS_COUNT_AFTER_GENESIS = UINT32_MAX;

// Maximum number of public keys per multisig before GENESIS
static const uint64_t MAX_PUBKEYS_PER_MULTISIG_BEFORE_GENESIS = 20;

// Maximum number of public keys per multisig after GENESIS
// Actual maximum number of public keys that can be stored in script of
// maximum length is actually smaller (since each compressed pub key takes up 33 bytes).
static const uint64_t MAX_PUBKEYS_PER_MULTISIG_AFTER_GENESIS = INT32_MAX;

/**
 * Coinbase transaction outputs can only be spent after this number of new
 * blocks (network rule).
 */
static const int COINBASE_MATURITY = 100;
/** Activation time for P2SH (April 1st 2012) */
static const int64_t P2SH_ACTIVATION_TIME = 1333234914;

/** Flags for nSequence and nLockTime locks */
enum {
    /* Interpret sequence numbers as relative lock-time constraints. */
    LOCKTIME_VERIFY_SEQUENCE = (1 << 0),

    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};

/**
 * Compute the maximum number of sigops operation that can contained in a block
 * given the block size as parameter. It is computed by multiplying
 * MAX_BLOCK_SIGOPS_PER_MB by the size of the block in MB rounded up to the
 * closest integer.
 */
inline uint64_t GetMaxBlockSigOpsCount(uint64_t blockSize) {
    auto nMbRoundedUp = 1 + ((blockSize - 1) / ONE_MEGABYTE);
    return nMbRoundedUp * MAX_BLOCK_SIGOPS_PER_MB;
}

#endif // BITCOIN_CONSENSUS_CONSENSUS_H
