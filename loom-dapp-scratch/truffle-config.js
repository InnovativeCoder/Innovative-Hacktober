require('dotenv').config();
const LoomTruffleProvider = require('loom-truffle-provider');
const HDWalletProvider = require('truffle-hdwallet-provider');

module.exports = {
  networks: {
    extdev: {
      provider: function() {
          const privateKey = process.env.PRIVATE_KEY;
          const chainId = 'extdev-plasma-us1';
          const writeUrl = 'http://extdev-plasma-us1.dappchains.com:80/rpc';
          const readUrl = 'http://extdev-plasma-us1.dappchains.com:80/query';;
          return new LoomTruffleProvider(chainId, writeUrl, readUrl, privateKey)
      },
      network_id: '9545242630824'
    }
  }
}
