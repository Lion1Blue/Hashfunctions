# Hashfunctions
## Task

Desigining a Gui Application in c++ with qt and implement various Hashfunctions which will convert a given string of ascii code to the matching hash value.

## [Definition](https://en.wikipedia.org/wiki/Hash_function)

A hash function is any function that can be used to map data of arbitrary size to fixed-size values. The values returned by a hash function are called hash values, hash codes, digests, or simply hashes. It is a one-way function, that is, a function for which is practically infeasible to invert or reverse the computation. Ideally, the only way to find a message that produces a given hash is to attempt a brute-force search of possible inputs to see if they produce a match.

<br>

![Example_01](https://github.com/Lion1Blue/Hashfunctions/blob/main/Pictures/Example_01.png)

<br>

The ideal cryptographic hash function has the following main properties:

- it is deterministic, meaning that the same message always results in the same hash
- it is quick to compute the hash value for any given message
- it is infeasible to generate a message that yields a given hash value (i.e. to reverse the process is also known that generated the given hash value)
- it is infeasible to find two different messages with the same hash value
- a small change to a message should change the hash value so extensively that a new hash value appears uncorrelated with the old hash value ([avalanche effect](https://en.wikipedia.org/wiki/Avalanche_effect))
 
## Conzept of the UI

![GUI_Concept](https://github.com/Lion1Blue/Hashfunctions/blob/main/Pictures/GUI_Concept.png)

<br>

This is a possible Designt for the UI. At the top is a GroupBox with RadioButtons or a ComboBox in which the Hash-Algorithm can be chosen. At the center of the UI is a InputField where the usere can input values and at the bottom is a OutputField which will contain the hash value. At the bottom right corner is a Button to generate the hash value.

## 

## Sources
https://en.wikipedia.org/wiki/Hash_function  
https://de.wikipedia.org/wiki/Secure_Hash_Algorithm  
https://increaseyourskills.com/blog-artikel/hashfunktion  
https://www.dr-datenschutz.de/hashwerte-und-hashfunktionen-einfach-erklaert/  
https://en.wikipedia.org/wiki/Cryptographic_hash_function  
https://www.geeksforgeeks.org/what-are-hash-functions-and-how-to-choose-a-good-hash-function/  
https://www.tutorialspoint.com/cryptography/cryptography_hash_functions.htm
