**This project has been created as part of the 42 curriculum by `rabounou`**

# Description

# Instructions
open index.html

# Resources
#### [What is TCP/IP](#what-is-tcpip)
#### [subnet mask](#subnet-mask)
#### [default gateway](#default-gateway)
#### [routers and switches](#routers-and-switches)
#### [OSI model](#osi-model)

# TCP/IP Model

### What is TCP/IP
**Transmission Control Protocol/Internet Protocol(TCP/IP)** is a set of rules and procedures that enable reliable and effecient information sharing between devices across networks. TCP/IP facilitates connections acress the internet, as well as intranets and extranets.

## How does TCP/IP work:
TCP/IP works by breaking data into small small packets, assigning the data packets source and destination <abbr title="An (Internet Protocol)IP address is a unique identifier assigned to a device on the internet or a local network">IP addresses</abbr>, and routing them through various networks to their final detination. Once at the destination, TCP reassemles data packets into their original format, ensuring correct delivery to the receiver.

![Role of TCP/IP](https://us.norton.com/content/dam/blogs/images/norton/am/tcp-ip-01.png)

#### and a more detailed look at how this set of protocols works:

1. **Three-way handshake:** A three-step process establishes a relible connection between devices.
2. **Data deconstruction:** Large data isdevided into smaller packets for efficient transmission.
3. **IP addressing:** Each packet is assigned source and destination IP addresses for routing.
4. **Packet routing:** Packets travel through networks, often taking different paths.
5. **TCP reassembly:** At the destination, TCP reassembles packets into the original data format.
6. **Error checking:** TCP verifies data integrity and requests retransmission of corrupred packets.

##### How are TCP and IP differecnt:
TCP is responsible for reliable data delivery, ensuring data packets arrive in the correct order and without errors. IP is responsible for addressing and routing data packets acrtess networks, determining the best path for data to travel.

## The 4 layers of the TCP/IP model
The TCP/IP model consists of four layers: `Application`, `Transport`, `Internet`, and `Network Access`.

* **The Application** layer handles user interactions and data formatting.

* **The Transport** layer ensures data delivery, prioritizing either *reliability [<abbr title="Transmission Control Protocol">(TCP)</abbr>](#tcp)* or *efficiency [<abbr title="User Datagram Protocol">(UDP)</abbr>](#udp)*.

* **The Internet** leayer addresses and routes data packets and determines the best transmission route.

* **The Network Access** layer handles physical data transmission, connecting devices to the network.

![The 4 layers of the TCP/IP model](https://us.norton.com/content/dam/blogs/images/norton/am/tcp-ip-02.png)




### The main difference between TCP and UDP:
#### TCP:
Transmission Control Protocol(TCP): prioritizes reliability, ensuring that information ends up where it's supposed to with no mistakes.
#### UDP:
User Datagram Protocol(UDP): is built for speed, sending information without checking whether it's actualy being received.

| Feature | TCP | UDP |
|---|---|---|
|Connection|✅|❌|
|Resending|✅|❌|
|Fast|❌|✅|
|Ordering|✅|❌|

## Subnet mask

_Content coming soon._

## Default gateway

_Content coming soon._

## Routers and switches

_Content coming soon._

## OSI model
