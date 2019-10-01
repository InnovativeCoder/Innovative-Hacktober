const Loom = require('loom-js')
const Client = Loom.Client
const LocalAddress = Loom.LocalAddress
const CryptoUtils = Loom.CryptoUtils
const LoomProvider = Loom.LoomProvider

const Web3 = require('web3')
const SimpleStore = require('../build/contracts/Counter.json')


async function createClient() {
    console.log('\t \t \t Create client started !!\n')

    this.privateKey = (CryptoUtils.generatePrivateKey())
    this.publicKey = CryptoUtils.publicKeyFromPrivateKey(this.privateKey)

    // Conversion of private key and public key to hex CryptoUtils.bytesToHexAddr(this.publicKey)
    // console.log(" \n \n ", CryptoUtils.bytesToHexAddr(this.publicKey))
  
    writeUrl = 'ws://extdev-plasma-us1.dappchains.com:80/websocket'
    readUrl = 'ws://extdev-plasma-us1.dappchains.com:80/queryws'
    networkId = 'extdev-plasma-us1'

    this.client = new Client(networkId, writeUrl, readUrl)
    // console.log('this.client: ', this.client)
    this.client.on('error', msg => {
      console.error('Error on connect to client', msg)
      console.warn('Please verify if loom command is running')
    })
  }

async function createCurrentUserAddress() {
    this.currentUserAddress = LocalAddress.fromPublicKey(this.publicKey).toString()    
    console.log('currentUserAddress: ', this.currentUserAddress)
    return this.currentUserAddress
  }

async function createWebInstance() {
    this.web3 = new Web3(new LoomProvider(this.client, this.privateKey))    
    // console.log('this.web3: ', this.web3)
}

async function createContractInstance() {
    const networkId = '9545242630824'
    // console.log('Contract Data: ', SimpleStore)
    this.currentNetwork = SimpleStore.networks[networkId]
    console.log('this.currentNetwork', this.currentNetwork)

    if (!this.currentNetwork) {
      throw Error('Contract not deployed on DAppChain')
    }

    const ABI = SimpleStore.abi
    this.simpleStoreInstance = new this.web3.eth.Contract(ABI, this.currentNetwork.address, {
      from: this.currentUserAddress
    })

    // console.log('this.simpleStoreInstance: ', this.simpleStoreInstance)

}


async function getCounter() {
    var result =  await this.simpleStoreInstance.methods.getCounter().call({
      from: this.currentUserAddress
    })
    console.log("Counter Status : ",result);
  }

async function increment() {
    var result = await this.simpleStoreInstance.methods.increment().send({
      from: this.currentUserAddress
    })
    console.log("Incremented :", result);

  }
  


  createClient()
  createCurrentUserAddress()
  createWebInstance()
  createContractInstance()
  getCounter()
  increment()