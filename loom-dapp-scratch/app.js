const express = require('express');
const app = express();
const port = 7000 || process.env.PORT;
const bodyParser = require('body-parser');

const { readFileSync } = require('fs')
const LoomTruffleProvider = require('loom-truffle-provider')
const path = require('path')
const { join } = require('path')

const Web3 = require('web3')
const connection = require('./connection')

const chainId    = 'extdev-plasma-us1'
const writeUrl   = 'http://extdev-plasma-us1.dappchains.com:80/rpc'
const readUrl    = 'http://extdev-plasma-us1.dappchains.com:80/query'
const privateKey = readFileSync(path.join(__dirname, 'private_key'), 'utf-8')

const loomTruffleProvider = new LoomTruffleProvider(chainId, writeUrl, readUrl, privateKey)
const loomProvider = loomTruffleProvider.getProviderEngine()

loomTruffleProvider.createExtraAccounts(1)

// console.log("Accounts list", loomProvider.accountsAddrList)
// console.log("Accounts and Private Keys", loomProvider.accounts)

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use('/', express.static('public_static'));
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});

loadConnection()

async function loadConnection() {
	await connection.loadContract()	
}

app.get('/get_value', async (req, res) => {
  console.log("**** GET /getValue ****");
  try {
	var v = await connection.getValue()
	console.log(v)
  } catch (e) {
    console.log(e)
  }
  res.send(v)
});

app.get('/set_value', async (req, res) => {
  console.log("**** GET /setValue ****");
  try {
	var sv = await connection.setValue(5)
	console.log("Resultss",sv)
  } catch (e) {
	console.log(e)
  }
  res.send(sv)
});

app.get('/total_supply', async (req, res) => {
  console.log("**** GET /totalSupply ****");
  try {
  var v = await connection.totalSupply()
  console.log(v)
  } catch (e) {
    console.log(e)
  }
    res.send(v)
});

app.get('/CurrentuserAddress', async (req, res) => {
  console.log("**** GET /Current user address ****");
  try {
  var v = await connection._createCurrentUserAddress()
  console.log(v)
  } catch (e) {
    console.log(e)
  }
    res.send(v)
});


app.get('/name', async (req, res) => {
  console.log("**** GET /name ****");
  try {
  var v = await connection.name()
  console.log(v)
  // res.send(v)
  } catch (e) {
    console.log(e)
  }
  res.send(v)
});


app.get('/symbol', async (req, res) => {
  console.log("**** GET /symbol ****");
  try {
  var v = await connection.symbol()
  console.log(v)
  // res.send(v)
  } catch (e) {
    console.log(e)
  }
  res.send(v)

});


// app.get('/balanceOf', async (req, res) => {
//   console.log("**** GET /balanceOf ****");
//   try {
//   var v = await connection.balanceOf()
//   console.log(v)
//   // res.send(v)
//   } catch (e) {
//     console.log(e)
//   }
//   res.send(v)
// });


app.get('/balanceOf', async (req, res) => {
  console.log("**** GET /Balance OF****");
  try {
	var sv = await connection.balanceOf('0x5f0B0A62F91DC5829b1b54D280013f792D208A4a')
	console.log(sv)
  } catch (e) {
	console.log(e)
  }
  res.send(sv.toString())
});

app.get('/keys', (req, res) => {
  console.log("**** GET /Keys****");
  try {
	var sv =  connection.Keys()
	console.log(sv)
  } catch (e) {
	console.log(e)
  }
  res.send(sv)
});


app.post('/transfer', (req, res) => {
  console.log("**** Post/Transfer****");
  console.log(req.body);

  let Givaddress = req.body.address;
  let Givamount = req.body.amount;
  try {
    var sv =  connection.fetchTransfer(Givaddress,Givamount)
    console.log(sv)
    } catch (e) {
    console.log("Error",e)
    }
  res.send(sv)
});


// app.post('/transfer', (req, res) => {
//   console.log("**** Post/Transfer****");
//   console.log(req.body);

//   let Givaddress = req.body.address;
//   let Givamount = req.body.amount;
//   console.log("Provided address and amount",Givaddress,Givamount);
//   connection.fetchTransfer(Givaddress,Givamount,(answer)=> {
//     console.log('Transfer ====>', answer  )
//     res.send(answer);
//   });
// });

app.listen(port, () => {
  console.log("Loom Express Listening at http://localhost:" + port);
});
