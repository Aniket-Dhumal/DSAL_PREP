let productAbi =[
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
      "outputs": [
         {
            "internalType": "bool",
            "name": "",
            "type": "bool"
         }
      ],
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
   }
];

let productContractAddress = "0x22a23C1f1Fa4428c669fCd48014E9B99E11C7Cf4 "; 

export {productAbi , productContractAddress}