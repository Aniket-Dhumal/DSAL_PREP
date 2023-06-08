const express = require('express');
const cors = require('cors');
const app = express();
app.use(cors());
const Web3 = require('web3');
const contractABI = [
   {
      "inputs": [
         {
            "internalType": "string",
            "name": "productName",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "productDetails",
            "type": "string"
         }
      ],
      "name": "addProduct",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "address",
            "name": "sellerAddress",
            "type": "address"
         },
         {
            "internalType": "string",
            "name": "name",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "location",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "contactNumber",
            "type": "string"
         }
      ],
      "name": "addSeller",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "incrementFakecounter",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "anonymous": false,
      "inputs": [
         {
            "indexed": false,
            "internalType": "uint256",
            "name": "productId",
            "type": "uint256"
         }
      ],
      "name": "ProductAdded",
      "type": "event"
   },
   {
      "inputs": [
         {
            "internalType": "address",
            "name": "sellerAddress",
            "type": "address"
         }
      ],
      "name": "removeSeller",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "string",
            "name": "newName",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "newLocation",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "newContactNumber",
            "type": "string"
         }
      ],
      "name": "updateManufacturerDetails",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "productId",
            "type": "uint256"
         }
      ],
      "name": "verifyProduct",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "productId",
            "type": "uint256"
         }
      ],
      "name": "verifyProductBySeller",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "_productId",
            "type": "uint256"
         }
      ],
      "name": "gerVerificationStatus",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "getAllSellers",
      "outputs": [
         {
            "internalType": "address[]",
            "name": "",
            "type": "address[]"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "getFakeProductCount",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "getProductIds",
      "outputs": [
         {
            "internalType": "uint256[]",
            "name": "",
            "type": "uint256[]"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "getSellerCount",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "address",
            "name": "sellerAddress",
            "type": "address"
         }
      ],
      "name": "getSellerDetails",
      "outputs": [
         {
            "internalType": "string",
            "name": "name",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "location",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "contactNumber",
            "type": "string"
         },
         {
            "internalType": "uint256",
            "name": "sellerId",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "getTotalProductCount",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "getVerifiedProductCount",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "_productId",
            "type": "uint256"
         }
      ],
      "name": "isExists",
      "outputs": [
         {
            "internalType": "bool",
            "name": "",
            "type": "bool"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "address",
            "name": "sellerAddress",
            "type": "address"
         }
      ],
      "name": "isSeller",
      "outputs": [
         {
            "internalType": "bool",
            "name": "",
            "type": "bool"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "owner",
      "outputs": [
         {
            "internalType": "address",
            "name": "",
            "type": "address"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "name": "productIds",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "name": "products",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "productId",
            "type": "uint256"
         },
         {
            "internalType": "string",
            "name": "productName",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "productDetails",
            "type": "string"
         },
         {
            "internalType": "address",
            "name": "manufacturer",
            "type": "address"
         },
         {
            "internalType": "address",
            "name": "seller",
            "type": "address"
         },
         {
            "internalType": "address",
            "name": "consumer",
            "type": "address"
         },
         {
            "internalType": "uint256",
            "name": "verificationStatus",
            "type": "uint256"
         },
         {
            "internalType": "uint256",
            "name": "manufacturingTimestamp",
            "type": "uint256"
         },
         {
            "internalType": "uint256",
            "name": "sellerVerificationTimestamp",
            "type": "uint256"
         },
         {
            "internalType": "uint256",
            "name": "consumerVerificationTimestamp",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "name": "sellerAddresses",
      "outputs": [
         {
            "internalType": "address",
            "name": "",
            "type": "address"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [],
      "name": "sellerCount",
      "outputs": [
         {
            "internalType": "uint256",
            "name": "",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   },
   {
      "inputs": [
         {
            "internalType": "address",
            "name": "",
            "type": "address"
         }
      ],
      "name": "sellers",
      "outputs": [
         {
            "internalType": "string",
            "name": "name",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "location",
            "type": "string"
         },
         {
            "internalType": "string",
            "name": "contactNumber",
            "type": "string"
         },
         {
            "internalType": "uint256",
            "name": "sellerId",
            "type": "uint256"
         }
      ],
      "stateMutability": "view",
      "type": "function"
   }
]; // replace with actual path to contract ABI
const contractAddress = '0xaeC4F40246d74f971d025Fa1D0C2F976EA40eb5b'; // replace with actual contract address
const providerUrl = 'http://127.0.0.1:7545'; // replace with your Infura project ID

// Initialize web3 and contract instance
console.log("inside the method")
const web3 = new Web3(new Web3.providers.HttpProvider(providerUrl));
const contract = new web3.eth.Contract(contractABI, contractAddress);

// Route for verifying a product
app.get('/verify/:productId', async (req, res) => {
  const productId = req.params.productId;

  // Check if product exists in the blockchain
  const productExists = await contract.methods.isExists(productId).call();
  if ( productExists) {
    console.log("fake product detected");
    await contract.methods.incrementFakecounter().send({ from: '0x29FBfcc7D811098C1Ad255A8B335A1DDF3AD9102' }); // replace with actual address
    return res.status(200).json({ message: 'Product does not exist' });
  }

  // Check the verification status of the product
  const verificationStatus = await contract.methods.gerVerificationStatus(productId).call();
  if (verificationStatus === '0') {
   
    return res.status(200).json({ message: 'Product is not verified by the seller yet' });
  } else if (verificationStatus === '2') {
     
    return res.status(200).json({ message: 'Product is already verified' });
  } else {
    // Call the verifyProduct method from the contract and return status as product verified
    await contract.methods.verifyProduct(productId).send({ from: '0x29FBfcc7D811098C1Ad255A8B335A1DDF3AD9102' }); // replace with actual address
    return res.status(200).json({ message: 'Product verified' });
  }
});


app.get('/product/:id', async (req, res) => {
   const productId = req.params.id;
 
   // Check if product exists in the blockchain
   const productExists = await contract.methods.isExists(productId).call();
 
   if (productExists) {
     // Product does not exist, return error response
     return res.status(200).json({ error: 'Product not found' });
   }
   
   // Product exists, get details
   const productDetails = await contract.methods.products(productId).call();
 
   // Return product details
   return res.json(productDetails);
 });
 
app.listen(3004, () => {
  console.log('Server started on port 3000');
});
