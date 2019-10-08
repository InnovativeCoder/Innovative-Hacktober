# Geth-Docs

## What is Geth?

Geth is an implementation of an Ethereum node in the Go programming language.

In simpler terms, Geth is a program which serves as a node for the Ethereum blockchain, and via which a user can mine Ether and create software which runs on the EVM – the Ethereum Virtual Machine. This software can be things like crypto tokens, decentralized apps, and more.

### Download Link 

https://geth.ethereum.org/downloads/

## What happen after download ??
After startup, Geth will connect to the existing live blockchain or create its own, depending on provided settings. Left at the default values, Geth will connect to the live Ethereum blockchain (the Mainnet) which we use daily. Simply by running Geth, you're already participating in making the Ethereum network better and stronger. Geth also serves as a console for inputting certain commands and executing specific functions. 

## How to install in Ubuntu .

### Installing from PPA
```
sudo apt-get install software-properties-common
sudo add-apt-repository -y ppa:ethereum/ethereum
sudo apt-get update
sudo apt-get install ethereum
```
If you want to stay on the bleeding edge, install the `ethereum-unstable` package instead.
After installing, run `geth account new` to create an account on your node.

You should now be able to run `geth` and connect to the network.
Make sure to check the different options and commands with `geth --help`

You can alternatively install only the geth CLI with apt-get install geth if you don't want to install the other `utilities (bootnode, evm, disasm, rlpdump, ethtest).`

### Building from Source
#### Building Geth (command line client)

Clone the repository to a directory of your choosing:

`git clone https://github.com/ethereum/go-ethereum`

Install latest distribution of Go if you don't have it already.
Building `geth` requires Go and C compilers to be installed:

```
sudo apt-get install -y build-essential
```

Finally, build the `geth` program using the following command.
```
cd go-ethereum
make geth
```
You can now run `build/bin/geth` to start your node.

or, to build the full suite of utilities:
```
make all
```
## Run Geth

### Full node on the main Ethereum network
By far the most common scenario is people wanting to simply interact with the Ethereum network: create accounts; transfer funds; deploy and interact with contracts. For this particular use-case the user doesn't care about years-old historical data, so we can fast-sync quickly to the current state of the network. To do so:

```
$ geth console
```
This command will:

Start geth in fast sync mode (default, can be changed with the --syncmode flag), causing it to download more data in exchange for avoiding processing the entire history of the Ethereum network, which is very CPU intensive.
Start up Geth's built-in interactive JavaScript console, (via the trailing console subcommand) through which you can invoke all official web3 methods as well as Geth's own management APIs. This tool is optional and if you leave it out you can always attach to an already running Geth instance with geth attach.

### A Full node on the Ethereum test network
Transitioning towards developers, if you'd like to play around with creating Ethereum contracts, you almost certainly would like to do that without any real money involved until you get the hang of the entire system. In other words, instead of attaching to the main network, you want to join the test network with your node, which is fully equivalent to the main network, but with play-Ether only.
```
$ geth --testnet console
```
Specifying the `--testnet` flag, however, will reconfigure your Geth instance a bit:

Instead of using the default data directory `(~/.ethereum on Linux for example)`, Geth will nest itself one level deeper into a testnet subfolder `(~/.ethereum/testnet on Linux)`. Note, on OSX and Linux this also means that attaching to a running testnet node requires the use of a custom endpoint since geth attach will try to attach to a production node endpoint by default. E.g. `geth attach <datadir>/testnet/geth.ipc.` Windows users are not affected by this.
Instead of connecting the main Ethereum network, the client will connect to the test network, which uses different P2P bootnodes, different network IDs and genesis states.
Note: Although there are some internal protective measures to prevent transactions from crossing over between the main network and test network, you should make sure to always use separate accounts for play-money and real-money. Unless you manually move accounts, Geth will by default correctly separate the two networks and will not make any accounts available between them.

### Standard API's and Geth specific API's
https://github.com/ethereum/go-ethereum/wiki/Management-APIs


https://github.com/ethereum/wiki/wiki/JSON-RPC


### Compiling Smart Contract
Before you are able to Deploy it though, you'll need two things: the compiled code, and the Application Binary Interface, which is a sort of reference template that defines how to interact with the contract.

The first you can get by using a compiler. You should have a solidity compiler built in on your geth console. To test it, use this command:

```eth.getCompilers()```
If you have it installed, it should output something like this:

```['Solidity' ]```
If instead the command returns an error, then you need to install it.


#### Install SolC on Ubuntu
Press control+c to exit the console (or type exit) and go back to the command line. Open the terminal and execute these commands:
```
sudo add-apt-repository ppa:ethereum/ethereum
sudo apt-get update
sudo apt-get install solc
which solc
```
Take note of the path given by the last line, you'll need it soon.

### Linking your compiler in Geth
Now go back to the console and type this command to install solC, replacing path/to/solc to the path that you got on the last command you did:
```
admin.setSolc("path/to/solc")
```
Now type again:

`eth.getCompilers()
`

### Article to run Smart Contract on Geth with Truffle Framework


https://medium.com/infrageth/developing-smart-contract-on-go-ethereum-using-truffle-framework-d61e95e74992

