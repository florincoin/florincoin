// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     0, uint256("0x09c7781c9df90708e278c35d38ea5c9041d7ecfcdd1c56ba67274b7cff3e1cea"))
        (  8002, uint256("0x73bc3b16d99bbf797f396c9532f80c3b73bb21304280de2efbc5edcb75739234"))
        ( 18001, uint256("0x5a7a4821aa4fc7ee3dea2f8319e9fa4d991a8c6762e79cb624c64e4cf1031582"))
        ( 38002, uint256("0x4962437c6d0a450f44c1e40cd38ff220f8122af1517e1329f1abd07fb7791e40"))
        (160002, uint256("0x478d381c92298614c3a05fb934a4fffc4d3e5b573efbba9b3e8b2ce8d26a0f8f"))
        (208001, uint256("0x2bb3f8b2d5081aefa0af9f5d8de42bd73a5d89eebf78aa7421cd63dc40a56d4c"))
        (270001, uint256("0x74988a3179ae6bbc5986e63f71bafc855202502b07e4d9331015eee82df80860"))
        (290036, uint256("0x145994381e5e4f0e5674adc1ace9a03b670838792f6bd6b650c80466453c2da3"))
        (344665, uint256("0x40fe36d8dec357aa529b6b1d99b2989a37ed8c7b065a0e3345cd15a751b9c1ad"))
        (400236, uint256("0xf9a4b8e21d410539e45ff3f11c28dee8966de7edffc45fd02dd1a5f4e7d4ef38"))
        (415000, uint256("0x16ef8ab98a7300039a5755d5bdc00e31dada9d2f1c440ff7928f43c4ea41c0a8"))
        (420937, uint256("0x48a75e4687021ec0dda2031439de50b61933e197a4e1a1185d131cc2b59b8444"))
        (425606, uint256("0x62c8d811b1a49f6fdaffded704dc48b1c98d6f8dd736d8afb96c9b097774a85e"))
        (508694, uint256("0x65cde197e9118e5164c4dcdcdc6fcfaf8c0de605d569cefd56aa220e7739da6a"))
        (696454, uint256("0x8cfb75684405e22f8f69522ec11f1e5206758e37f25db13880548f69fe6f1976"))
        (955000, uint256("0xb5517a50aee6af59eb0ab4ee3262bcbaf3f6672b9301cdd3302e4bab491e7526"))
       (1505017, uint256("0xd38b306850bb26a5c98400df747d4391bb4e359e95e20dc79b50063ed3c5bfa7"))
       (1678879, uint256("0x1e874e2852e8dfb3553f0e6c02dcf70e9f5697effa31385d25a3c88fe26676fc"))
       (1678909, uint256("0x4c5a1040e337a542e6717904c8346bd72151fc34c390dff7b5cf23dcedc5058a"))
       (1679162, uint256("0xb32c64fb80a4196ff3e1be883db10629e1d7cd27c00ef0b5d1fe54af481fc10f"))
       (1796633, uint256("0xc2da8b936a7f2c0de02aa0c6c45f3d971ebad78655255a945b0e60b62f27d445"))
       (2094558, uint256("0x946616c88286f32bfac15868456d87a86f8611e1f9b56594b81e46831ce43f81"))
        ;
static const Checkpoints::CCheckpointData data = {
        &mapCheckpoints,
        1488680849, // * UNIX timestamp of last checkpoint block
        2660400,   // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        2160.0     // * estimated number of transactions per day after checkpoint
    };

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, uint256("0x9b7bc86236c34b5e3a39367c036b7fe8807a966c22a7a1f0da2a198a27e03731"))
        ;
static const Checkpoints::CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1371387277,
        547,
        2160
    };

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of
        ( 0, uint256("0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"))
        ;
static const Checkpoints::CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        0,
        0,
        0
    };

class CMainParams : public CChainParams {
public:
    CMainParams() {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xfd;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xa5;
        pchMessageStart[3] = 0xf1;
        vAlertPubKey = ParseHex("0416ca41786113574984664acedc7d338cc10a29edec0adae32f3fa0317fee95c9790150f38544204fac805ac58bca435df5021233d8e347f6127832a9e0207e1b");
        nDefaultPort = 7312;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        nSubsidyHalvingInterval = 800000;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nMaxTipAge = 24 * 60 * 60;

        nTargetSpacing = 40; // Florincoin: 40 seconds (~1/4x Litecoin: 2.5 minutes)

        nTargetTimespan_Version1 = 60 * 60; // Florincoin: 60 minutes (Litecoin: 3.5 days)
        nInterval_Version1 = nTargetTimespan_Version1 / nTargetSpacing; // Florincoin: 90 blocks

        nHeight_Version2 = 208440;
        nInterval_Version2 = 15;
        nTargetTimespan_Version2 = nInterval_Version2 * nTargetSpacing; // 10 minutes

        nHeight_Version3 = 426000;
        nInterval_Version3 = 1;
        nTargetTimespan_Version3 = nInterval_Version3 * nTargetSpacing; // 40 seconds

        nMaxAdjustDown_Version1 = 300; // 100+300 ~= 400% adjustment down
        nMaxAdjustUp_Version1 = 75; // 100-75 = 25% of original ~= 400% adjustment up

        nMaxAdjustDown_Version2 = nMaxAdjustDown_Version1;
        nMaxAdjustUp_Version2 = nMaxAdjustUp_Version1;

        nMaxAdjustDown_Version3 = 3; // 100+3 ~= 3% down
        nMaxAdjustUp_Version3 = 2; // 100-2 = 98% of original ~= 2% up

        nTargetTimespanAdjDown_Version1 = nTargetTimespan_Version1 * (100 + nMaxAdjustDown_Version1) / 100;
        nTargetTimespanAdjDown_Version2 = nTargetTimespan_Version2 * (100 + nMaxAdjustDown_Version2) / 100;
        nTargetTimespanAdjDown_Version3 = nTargetTimespan_Version3 * (100 + nMaxAdjustDown_Version3) / 100;

        nAveragingInterval_Version1 = nInterval_Version1;
        nAveragingInterval_Version2 = nInterval_Version2;
        nAveragingInterval_Version3 = 6;

        nAveragingTargetTimespan_Version1 = nAveragingInterval_Version1 * nTargetSpacing;
        nAveragingTargetTimespan_Version2 = nAveragingInterval_Version2 * nTargetSpacing;
        nAveragingTargetTimespan_Version3 = nAveragingInterval_Version3 * nTargetSpacing;

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         * 
         * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
         *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
         *   vMerkleTree: 4a5e1e
         */
        const char* pszTimestamp = "Slashdot - 17 June 2013 - Saudi Arabia Set To Ban WhatsApp, Skype";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 100 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("040184710fa689ad5023690c80f3a49c8f13f8d45b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a9") << OP_CHECKSIG;
        txNew.strTxComment = "text:Florincoin genesis block";
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1371488396;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 1000112548;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x09c7781c9df90708e278c35d38ea5c9041d7ecfcdd1c56ba67274b7cff3e1cea"));
        assert(genesis.hashMerkleRoot == uint256("0x730f0c8ddc5a592d5512566890e2a73e45feaa6748b24b849d1c29a7ab2b2300"));

        vSeeds.push_back(CDNSSeedData("seed1.florincoin.org", "seed1.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed2.florincoin.org", "seed2.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed3.florincoin.org", "seed3.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed4.florincoin.org", "seed4.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed5.florincoin.org", "seed5.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed6.florincoin.org", "seed6.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed7.florincoin.org", "seed7.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed8.florincoin.org", "seed8.florincoin.org"));
        vSeeds.push_back(CDNSSeedData("seed1.florincoin.com", "seed1.florincoin.com"));
        vSeeds.push_back(CDNSSeedData("seed2.florincoin.com", "seed2.florincoin.com"));
        vSeeds.push_back(CDNSSeedData("seed3.florincoin.com", "seed3.florincoin.com"));
        vSeeds.push_back(CDNSSeedData("seed4.florincoin.com", "seed4.florincoin.com"));
        vSeeds.push_back(CDNSSeedData("nyc2.entertheblockchain.com", "nyc2.entertheblockchain.com"));
        vSeeds.push_back(CDNSSeedData("sf1.entertheblockchain.com", "sf1.entertheblockchain.com"));
        vSeeds.push_back(CDNSSeedData("am2.entertheblockchain.com", "am2.entertheblockchain.com"));
        vSeeds.push_back(CDNSSeedData("sgp.entertheblockchain.com", "sgp.entertheblockchain.com"));
        vSeeds.push_back(CDNSSeedData("ind.entertheblockchain.com", "ind.entertheblockchain.com"));
        vSeeds.push_back(CDNSSeedData("de.entertheblockchain.com", "de.entertheblockchain.com"));

        base58Prefixes[PUBKEY_ADDRESS] = {35};
        base58Prefixes[SCRIPT_ADDRESS] = {8};
        base58Prefixes[SECRET_KEY] =     {176};
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Florincoin: Mainnet v2 enforced, transition from 0.8.7 to 0.10.4
        nEnforceV2AfterHeight = 1679161;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xfd;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0x5a;
        pchMessageStart[3] = 0xf2;
        vAlertPubKey = ParseHex("0456f0d9f60a0a7d9b92f2366c75106c6ce8430b76d49186e41866e3bcbbae0161a04cd423bfb055ae749c6847369d73b26ca16b9e82d0f99fc4611e0fb2251cb4");
        nDefaultPort = 17312;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        nTargetSpacing = 2.5 * 60; // 2.5 minutes
        nMaxTipAge = 0x7fffffff;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1371387277;
        genesis.nNonce = 1000580675;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x9b7bc86236c34b5e3a39367c036b7fe8807a966c22a7a1f0da2a198a27e03731"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testseed.florincoin.org", "testseed.florincoin.org"));

        base58Prefixes[PUBKEY_ADDRESS] = {115};
        base58Prefixes[SCRIPT_ADDRESS] = {198};
        base58Prefixes[SECRET_KEY]     = {239}; // ToDo: bitspill. florincoin?
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        // Litecoin: Testnet v2 enforced as of block 400k
        // Florincoin: Don't enforce V2
        nEnforceV2AfterHeight = 400000;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() { // ToDo: bitspill. regtest network? basically litecoin except pch and genesisHash
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x66;
        pchMessageStart[1] = 0x66;
        pchMessageStart[2] = 0x66;
        pchMessageStart[3] = 0x66;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        nTargetSpacing = 2.5 * 60; // 2.5 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nMaxTipAge = 24 * 60 * 60;
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 0;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19444;
        assert(hashGenesisBlock == uint256("0x327ce75b073d20561340facc578c53408c10472f363fcafaf8d1221a083cd319"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Florincoin: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams {
public:
    CUnitTestParams() {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18445;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;

        // Florincoin: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval)  { nSubsidyHalvingInterval=anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority)  { nEnforceBlockUpgradeMajority=anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority)  { nRejectBlockOutdatedMajority=anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority)  { nToCheckBlockUpgradeMajority=anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks)  { fDefaultConsistencyChecks=afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) {  fAllowMinDifficultyBlocks=afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams *pCurrentParams = 0;

CModifiableParams *ModifiableParams()
{
   assert(pCurrentParams);
   assert(pCurrentParams==&unitTestParams);
   return (CModifiableParams*)&unitTestParams;
}

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams &Params(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        case CBaseChainParams::REGTEST:
            return regTestParams;
        case CBaseChainParams::UNITTEST:
            return unitTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network) {
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
