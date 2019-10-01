# Loom-dapp-scratch
In this we will deploy simple smart-contract from scratch to deploy on LOOM Network.


## Download Loom Binary 
```
curl https://raw.githubusercontent.com/loomnetwork/loom-sdk-documentation/master/scripts/get_loom.sh | sh
# set LOOM_BIN to reference the downloaded loom binary,
# makes it easy to invoke it from anywhere
export LOOM_BIN=`pwd`/loom
```

## Generate Private_Key and Public_Key

```
$LOOM_BIN genkey -k extdev_private_key -a extdev_public_key
```

## Install and setup truffle

```
$ npm install -g truffle
```

```
$ truffle init
Downloading...
Unpacking...
Setting up...
Unbox successful. Sweet!

Commands:

  Compile:        truffle compile
  Migrate:        truffle migrate
  Test contracts: truffle test
  ```
  
  ## Now write a simple Smart Contract in `contracts/Counter.sol`  and also modify `migrations/2_deploy_contracts.js`.

You can see the code from repository also you can write your own code.

## Time to install dependencies.

```
$ npm install truffle-hdwallet-provider loom-truffle-provider dotenv --save-dev
```

## Create a .env file and copy the Private Key that we have generated in starting

## In the end just modify the `truffle_config.js` script and modify it accordingly.

### Now we are alll set up.

```
truffle compile
truffle migrate --network extdev
```

## You will see something like this.

```

Compiling your contracts...
===========================
> Everything is up to date, there is nothing to compile.


Starting migrations...
======================
> Network name:    'extdev'
> Network id:      9545242630824
> Block gas limit: 0x0


1_initial_migration.js
======================

   Deploying 'Migrations'
   ----------------------
   > transaction hash:    0xbfc8761ec98ee6940773cfb9c04c84dc1069fb20e66e8bf7c5dbc6a3c1198fd7
   > Blocks: 0            Seconds: 0
   > contract address:    0xEeb7A3C57DA6DdBa60F0a053Dbf4Cf1467313487
   > block number:        8084445
   > block timestamp:     1567489492
   > account:             0xEF6E82E8099Db14bB0a7cD426aE18ca0169Ee767
   > balance:             0
   > gas used:            0
   > gas price:           0 gwei
   > value sent:          0 ETH
   > total cost:          0 ETH


   > Saving migration to chain.
   > Saving artifacts
   -------------------------------------
   > Total cost:                   0 ETH


2_deploy_contracts.js
=====================

   Deploying 'Counter'
   -------------------
   > transaction hash:    0x0d67c1eee590940e6fe72bcfce494bc562c6d5152630fda27c45b09aaab1bfa8
   > Blocks: 0            Seconds: 0
   > contract address:    0xcB5B46FA01Ce20a69AE972AE6A983205d896be1b
   > block number:        8084452
   > block timestamp:     1567489505
   > account:             0xEF6E82E8099Db14bB0a7cD426aE18ca0169Ee767
   > balance:             0
   > gas used:            0
   > gas price:           0 gwei
   > value sent:          0 ETH
   > total cost:          0 ETH


   > Saving migration to chain.
   > Saving artifacts
   -------------------------------------
   > Total cost:                   0 ETH


Summary
=======
> Total deployments:   2
> Final cost:          0 ETH


```

