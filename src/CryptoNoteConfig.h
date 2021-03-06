// Copyright (c) 2011-2017 The Cryptonote Developers
// Copyright (c) 2018 The Circle Foundation
// Copyright (c) 2019 Aluisyo
//
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER													= 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE												= 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE														= 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX										= 0x641c7; /* anx address prefix */
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW											= 10; /* 20 minutes */
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT											= 60 * 60 * 2; /* two hours */
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1										= 360; /* changed for LWMA3 */
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE											= 10; /* 20 minutes */
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW											= 30;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1											= 11; /* changed for LWMA3 */

const uint64_t MONEY_SUPPLY																	= UINT64_C(200000000000000); /* max supply:200M ANX */

const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX													= 0;
const size_t   ZAWY_DIFFICULTY_FIX															= 1;
const uint8_t  ZAWY_DIFFICULTY_BLOCK_VERSION												= 0;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW												= 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE									= 100000; /* size of block in bytes, after which reward is calculated using block size */
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE										= 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT												= 6;

const uint64_t POINT																		= UINT64_C(1000); 
const uint64_t COIN																			= UINT64_C(1000000); /* smallest atomic unit */
const uint64_t MINIMUM_FEE																	= UINT64_C(10); /* 0.000010 ANX */
const uint64_t MINIMUM_FEE_V1																= UINT64_C(100); /* 0.000100 ANX */
const uint64_t MINIMUM_FEE_BANKING															= UINT64_C(1000); /* 0.001000 ANX */
const uint64_t DEFAULT_DUST_THRESHOLD														= UINT64_C(10); /* 0.000010 ANX */  

const uint64_t DIFFICULTY_TARGET															= 120; /* two minutes */
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY											= 24 * 60 * 60 / DIFFICULTY_TARGET; /* 720 blocks */
const size_t   DIFFICULTY_WINDOW															= EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 	
const size_t   DIFFICULTY_WINDOW_V1															= DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2															= DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V3															= 60; /* changed for LWMA3 */
const size_t   DIFFICULTY_BLOCKS_COUNT														= DIFFICULTY_WINDOW_V3 + 1; /* added for LWMA3 */
const size_t   DIFFICULTY_CUT																= 60; /* timestamps to cut after sorting */
const size_t   DIFFICULTY_CUT_V1															= DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2															= DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG																= 15; 
const size_t   DIFFICULTY_LAG_V1															= DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2															= DIFFICULTY_LAG;

static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT															= 1 * COIN; 
const uint32_t DEPOSIT_MIN_TERM																= 5040; /* one week */	
const uint32_t DEPOSIT_MAX_TERM																= 1 * 12 * 21900; /* legacy deposts - one year */
const uint32_t DEPOSIT_MAX_TERM_V1															= 64800 * 20; /* five years */
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR												= 0; /* constant rate */
const uint64_t DEPOSIT_MAX_TOTAL_RATE														= 4; /* legacy deposits */

static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR															= 100; /* legacy deposits */
const uint32_t END_MULTIPLIER_BLOCK															= 12750; /* legacy deposits */

const size_t   MAX_BLOCK_SIZE_INITIAL														= CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR										= 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR										= 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS									= 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS									= DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const size_t   CRYPTONOTE_MAX_TX_SIZE_LIMIT													= (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE; /* maximum transaction size */
const size_t   CRYPTONOTE_OPTIMIZE_SIZE														= 100; /* proportional to CRYPTONOTE_MAX_TX_SIZE_LIMIT */

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME												= (60 * 60 * 12); /* 12 hours in seconds */
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME								= (60 * 60 * 24); /* 23 hours in seconds */
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL					= 7; /* CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx */

const size_t   FUSION_TX_MAX_SIZE															= CRYPTONOTE_MAX_TX_SIZE_LIMIT * 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT													= 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO												= 4;

const uint64_t UPGRADE_HEIGHT																= 1;
const uint64_t UPGRADE_HEIGHT_V2															= 1;
const uint64_t UPGRADE_HEIGHT_V3															= 12750; /* Cryptonight-Fast */
const uint64_t UPGRADE_HEIGHT_V4															= 26490; /* MixIn 2 */
const uint64_t UPGRADE_HEIGHT_V5															= 26495; /* Deposits 2.0, Investments 1.0 */
const uint64_t UPGRADE_HEIGHT_V6															= 26500; /* LWMA3 */
const uint64_t UPGRADE_HEIGHT_V7															= 19999999; /* TBD */
const unsigned UPGRADE_VOTING_THRESHOLD														= 90; // percent
const size_t   UPGRADE_VOTING_WINDOW														= EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 
const size_t   UPGRADE_WINDOW																= EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]													= "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]											= "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]											= "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]												= "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]														= "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]										= "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]														= "miner_conf.json";

} // params

const uint64_t START_BLOCK_REWARD															= (UINT64_C(5000) * parameters::POINT); // start block reward 
const uint64_t FOUNDATION_TRUST																= (UINT64_C(0) * parameters::COIN); // No Premine
const uint64_t MAX_BLOCK_REWARD																= (UINT64_C(50) * parameters::COIN); // max block reward
const uint64_t REWARD_INCREASE_INTERVAL														= (UINT64_C(21900)); // aprox. 1 month (+ 0.25 ANX increment per month)

const char     CRYPTONOTE_NAME[]															= "aluisyo";
const char     GENESIS_COINBASE_TX_HEX[]													= "010a01ff0001c096b102029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121014d669c1540f08c6af42bcbf50623514a085bf898292cd8e90b6f88c9abeaef94";
const uint32_t GENESIS_NONCE                         	      							    = 10000;
const uint64_t GENESIS_TIMESTAMP															= 1551106337;
const uint8_t  TRANSACTION_VERSION_1														=  1;
const uint8_t  TRANSACTION_VERSION_2														=  2;
const uint8_t  BLOCK_MAJOR_VERSION_1														=  1; // (Consensus I)
const uint8_t  BLOCK_MAJOR_VERSION_2														=  2; // (Consensus II)
const uint8_t  BLOCK_MAJOR_VERSION_3														=  3; // (Consensus III)
const uint8_t  BLOCK_MAJOR_VERSION_4														=  4; // LWMA3
const uint8_t  BLOCK_MAJOR_VERSION_7														=  7; /* Cryptonight Conceal */
const uint8_t  BLOCK_MINOR_VERSION_0														=  0;
const uint8_t  BLOCK_MINOR_VERSION_1														=  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT										= 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT											= 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT										= 1000;

const int      P2P_DEFAULT_PORT																= 18001;
const int      RPC_DEFAULT_PORT																= 19000;


/* P2P Network Configuration Section - This defines our current P2P network version
and the minimum version for communication between nodes */
const uint8_t  P2P_CURRENT_VERSION															= 1;
const uint8_t  P2P_MINIMUM_VERSION															= 1;
const uint8_t  P2P_UPGRADE_WINDOW															= 2;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT												= 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT												= 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE											= 64 * 1024 * 1024; // 64MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT												= 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT									= 70; // percent
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL												= 60; // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE													= 50000000; // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE												= 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT												= 5000; // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT											= 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT													= 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT											= 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]													= "a9206a9e0l0e30986afde49lubiba02esf30afdb44304673h460a9sa34bf5s5p";

// Seed Nodes
const std::initializer_list<const char*> SEED_NODES = {
		"132.145.165.72:18001", // seed one
		"132.145.211.6:18001", // seed two
		"150.136.245.66:18001", // seed three
		"150.136.137.49:18001" // seed four
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// Blockchain Checkpoints:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
	{0, "5d3ae87eb5dc2833698423eb29b83c68f66e4f3bd9c6130860412f85a8bc4af5"},
	{1000, "ce05d06605894474501455c03ca170d3f6503f39055f6cc8c7a791e823721305"},
	{5000, "056144a6af9a457afd32094bd1be263f3610854b76bca742b6710cde9486b075"},
	{10000, "6f44f15858b4eb7afe814b3d0e1945118d71909ae11f20e06c17fcf0e33e2f4a"},
	{15000, "276162175b19991a9bc7650d3c8a9dcce0a5daad5cac5b7387f725a03a337290"},
	{20000, "a113901a9d3d6f13b710367e9e0919d0f4155612e56b2eb23d99ed7b1ff044b8"},
	{25000, "005ac409b5e4c1dbdbde0a74378a919cf725caa5b6f782e7875913c0bde99e21"},
	{30000, "faab8771a177dc4a15acd75f1228cd999c078b9cdf481f14f84c9a0def7b8752"},
	{35000, "600592d5dbb182a8a6bb0ac4a2fc52e3fb539c45690dd17ddcbd9673a211a7b6"},
	{40000, "780207cfbf37e68a88d8abe7c744ad86351e4412be17bc22708007d63b26b687"},
	{45000, "1a9540dbd562cadcf69ee8cadeeb7ffdff0fdb5ea3205dced9001188eb0b6e58"},
	{50000, "ee76d5295759fb8bf6feb8b916b649eb0703aeb5cd7baf52cf2132c1fc41c27e"}
	
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
