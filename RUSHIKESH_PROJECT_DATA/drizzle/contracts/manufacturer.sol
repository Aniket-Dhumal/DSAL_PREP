// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract manufacturer {
     
    struct Manufacturer {
        string name;
        string location;
        address addr;
    }

    mapping(address => bool) public isManufacturer;
    Manufacturer public manufacturer;

    address public owner;

    constructor() {
        owner = msg.sender;
        manufacturer = Manufacturer("", "", msg.sender);
        isManufacturer[msg.sender] = true;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can perform this operation");
        _;
    }

    function editManufacturer(string memory _name, string memory _location) public onlyOwner {
        manufacturer.name = _name;
        manufacturer.location = _location;
    }

    function getManufacturer() public view returns (string memory, string memory, address) {
        require(isManufacturer[manufacturer.addr], "Manufacturer does not exist");
        return (manufacturer.name, manufacturer.location, manufacturer.addr);
    }
}
