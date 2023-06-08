var Manufacturer = artifacts.require("./manufaturer.sol")

module.exports = function(_deployer) {
  
  _deployer.deploy(Manufacturer); 
};
