const Loom = require('loom-js')
const Client = Loom.Client
const LocalAddress = Loom.LocalAddress
const CryptoUtils = Loom.CryptoUtils
const LoomProvider = Loom.LoomProvider

const Web3 = require('web3')
const SimpleStore = require('../build/contracts/Counter.json')

module.exports = {
  loadContract: async function() {
    this._createClient()
    this._createCurrentUserAddress()
    this._createWebInstance()
    await this._createContractInstance()
  },
  _createClient: function() {
    console.log('create client started !!')

    this.privateKey = CryptoUtils.generatePrivateKey()
    this.publicKey = CryptoUtils.publicKeyFromPrivateKey(this.privateKey)
    // console.log("############ \n \n ", this.privateKey)
    // let writeUrl = 'http://extdev-plasma-us1.dappchains.com:80/rpc'
    // let readUrl = 'http://extdev-plasma-us1.dappchains.com:80/query'
    // let networkId = 'extdev_plasma_us1'

    // if (process.env.NETWORK == 'extdev') {
      writeUrl = 'ws://extdev-plasma-us1.dappchains.com:80/websocket'
      readUrl = 'ws://extdev-plasma-us1.dappchains.com:80/queryws'
      networkId = 'extdev-plasma-us1'
    // }

    this.client = new Client(networkId, writeUrl, readUrl)
    console.log('this.client: ', this.client)
    this.client.on('error', msg => {
      console.error('Error on connect to client', msg)
      console.warn('Please verify if loom command is running')
    })
  },


  _createCurrentUserAddress: function() {
    this.currentUserAddress = LocalAddress.fromPublicKey(this.publicKey).toString()    
    console.log('this.currentUserAddress: ', this.currentUserAddress)
    return this.currentUserAddress
  },
  _createWebInstance: function() {
    this.web3 = new Web3(new LoomProvider(this.client, this.privateKey))    
    console.log('this.web3: ', this.web3)
  },
  _createContractInstance: async function() {
    const networkId = '9545242630824'
    console.log('SimpleStore: ', SimpleStore)
    this.currentNetwork = SimpleStore.networks[networkId]
    console.log('this.currentNetwork', this.currentNetwork)

    if (!this.currentNetwork) {
      throw Error('Contract not deployed on DAppChain')
    }

    const ABI = SimpleStore.abi
    this.simpleStoreInstance = new this.web3.eth.Contract(ABI, this.currentNetwork.address, {
      from: this.currentUserAddress
    })

    console.log('this.simpleStoreInstance: ', this.simpleStoreInstance)

    // this.simpleStoreInstance.events.NewValueSet({ filter: { _value: 10 }}, (err, event) => {
    //   if (err) console.error('Error on event', err)
    //   else {
    //     if (this.onEvent) {
    //       this.onEvent(event.returnValues)
    //     }
    //   }
    // })

    // this.simpleStoreInstance.events.NewValueSetAgain({ filter: { _value: 47 }}, (err, event) => {
    //   if (err) console.error('Error on event', err)
    //   else {
    //     setTimeout(() => alert("Loooomy help me :)"))
    //     if (this.onEvent) {
    //       this.onEvent(event.returnValues)
    //     }
    //   }
    // })
  },
  totalSupply: async function() {
    return await this.simpleStoreInstance.methods.getCounter().call({
      from: this.currentUserAddress
    })
  },

  name: async function() {
    return await this.simpleStoreInstance.methods.increment().send({
      from: this.currentUserAddress
    })
  },


  symbol: async function() {
    return await this.simpleStoreInstance.methods.symbol().call({
      from: this.currentUserAddress
    })
  },


  balanceOf: async function(address) {
    return await this.simpleStoreInstance.methods.balanceOf(address).call({
      from: this.currentUserAddress
    })
  },

  // fetchTransfer: async function(to, amount) {
  //   console.log("Params",to,amount)
  //   const transferRes = await this.simpleStoreInstance.methods.transfer(to,amount).send({
  //     from:'0xbEfA22D42EC5C04379b05da124E63410D9e91AAE'
  //   })

  //   console.log(transferRes)

  //   // return await this.simpleStoreInstance.methods.transfer(to,amount).send({
  //   //   from:'0xbEfA22D42EC5C04379b05da124E63410D9e91AAE'
  //   // }).then(function(res){
  //   //   console.log('fetchTransfer response: ', res)
  //   // }).catch(function(e){
  //   //   console.log('fetchTransfer Error: ', e)
  //   // })
  // },

  fetchTransfer: async function(to, amount) {
    return await this.simpleStoreInstance.methods.transfer(to,amount).send({
      from:'0x5f0B0A62F91DC5829b1b54D280013f792D208A4a'
    }).then(function(res){
      console.log('fetchTransfer response: ', res)
    }).catch(function(e){
      console.log('fetchTransfer Error: ', e)
    })
  },

  Keys: function() {
    this.privateKey = CryptoUtils.generatePrivateKey()
    this.publicKey = CryptoUtils.publicKeyFromPrivateKey(this.privateKey)
    console.log("Keys api has been initiated")
    console.log(this.publicKey)
    console.log("CurrentUser",this.currentUserAddress)
    return (this.privateKey, this.publicKey)
  },


  // fetchTransfer: async function(address,amount,callback) {
  //   var self = this;
    
  //   simpleStoreInstance.deployed().then(function(instance) {
  //     OZPinstance = instance;
  //     return OZPinstance.transfer(address,amount, {currentUserAddress});
  //   }).then(function(value) {
  //     console.log("Transfer done =>", value);
  //       callback(value);
  //   }).catch(function(e) {
  //       console.log(e);
  //       console.log("We are trapped in error block")
  //       callback("Error 404");
  //   });
  // },

 



  setValue: async function(value) {
    console.log('contract: ', value)
    // console.log('this.simpleStoreInstance: ', this.simpleStoreInstance.methods)
    return await this.simpleStoreInstance.methods.set(value).send({
      from: this.currentUserAddress
    })
    // console.log('%%%%%%%%%%%%%', a)
  },


  getValue: async function() {
    return await this.simpleStoreInstance.methods.get().call({
      from: this.currentUserAddress
    })
  }
}

// export default class Contract {
//   async loadContract() {
//     this.onEvent = null
//     this._createClient()
//     this._createCurrentUserAddress()
//     this._createWebInstance()
//     await this._createContractInstance()
//   }

//   _createClient() {
    // this.privateKey = CryptoUtils.generatePrivateKey()
    // this.publicKey = CryptoUtils.publicKeyFromPrivateKey(this.privateKey)
    // let writeUrl = 'ws://127.0.0.1:46658/websocket'
    // let readUrl = 'ws://127.0.0.1:46658/queryws'
    // let networkId = 'default'

    // if (process.env.NETWORK == 'extdev') {
    //   writeUrl = 'ws://extdev-plasma-us1.dappchains.com:80/websocket'
    //   readUrl = 'ws://extdev-plasma-us1.dappchains.com:80/queryws'
    //   networkId = 'extdev-plasma-us1'
    // }

    // this.client = new Client(networkId, writeUrl, readUrl)

    // this.client.on('error', msg => {
    //   console.error('Error on connect to client', msg)
    //   console.warn('Please verify if loom command is running')
    // })
//   }

//   _createCurrentUserAddress() {
//     this.currentUserAddress = LocalAddress.fromPublicKey(this.publicKey).toString()
//   }

//   _createWebInstance() {
//     this.web3 = new Web3(new LoomProvider(this.client, this.privateKey))
//   }

//   async _createContractInstance() {
//     const networkId = await this._getCurrentNetwork()
//     this.currentNetwork = SimpleStore.networks[networkId]

//     if (!this.currentNetwork) {
//       throw Error('Contract not deployed on DAppChain')
//     }

//     const ABI = SimpleStore.abi
//     this.simpleStoreInstance = new this.web3.eth.Contract(ABI, this.currentNetwork.address, {
//       from: this.currentUserAddress
//     })

//     this.simpleStoreInstance.events.NewValueSet({ filter: { _value: 10 }}, (err, event) => {
//       if (err) console.error('Error on event', err)
//       else {
//         if (this.onEvent) {
//           this.onEvent(event.returnValues)
//         }
//       }
//     })

//     this.simpleStoreInstance.events.NewValueSetAgain({ filter: { _value: 47 }}, (err, event) => {
//       if (err) console.error('Error on event', err)
//       else {
//         setTimeout(() => alert("Loooomy help me :)"))
//         if (this.onEvent) {
//           this.onEvent(event.returnValues)
//         }
//       }
//     })
//   }

//   addEventListener(fn) {
//     this.onEvent = fn
//   }

//   async _getCurrentNetwork() {
//     return Promise.resolve('default')
//   }

//   async setValue(value) {
//     // Just a small test with Loomy
    // if (value == 47) {
    //   return await this.simpleStoreInstance.methods.setAgain(value).send({
    //     from: this.currentUserAddress
    //   })
    // }

    // return await this.simpleStoreInstance.methods.set(value).send({
    //   from: this.currentUserAddress
    // })
//   }

//   async getValue() {
//     return await this.simpleStoreInstance.methods.get().call({
//       from: this.currentUserAddress
//     })
//   }
// }
