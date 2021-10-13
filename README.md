# Hashfunctions
## Task

Desigining a Gui Application in c++ with qt and implement various Hashfunctions which will convert a given string of ascii code to the matching hash value.

## [Definition](https://en.wikipedia.org/wiki/Hash_function)

A hash function is any function that can be used to map data of arbitrary size to fixed-size values. The values returned by a hash function are called hash values, hash codes, digests, or simply hashes. It is a one-way function, that is, a function for which is practically infeasible to invert or reverse the computation. Ideally, the only way to find a message that produces a given hash is to attempt a brute-force search of possible inputs to see if they produce a match.

<br>

![Example_01](https://github.com/Lion1Blue/Hashfunctions/blob/main/Pictures/Example.png)

<br>

The ideal hash function has the following main properties:

- it is deterministic, meaning that the same message always results in the same hash
- it is quick to compute the hash value for any given message
- it is infeasible to generate a message that yields a given hash value (i.e. to reverse the process is also known that generated the given hash value)
- it is infeasible to find two different messages with the same hash value (collisions)
- a small change to a message should change the hash value so extensively that a new hash value appears uncorrelated with the old hash value ([avalanche effect](https://en.wikipedia.org/wiki/Avalanche_effect))  

Implementation is based on parity-preserving bit operations (XOR and ADD), multiply, or divide  

## Concept of the UI

![GUI_Concept](https://github.com/Lion1Blue/Hashfunctions/blob/main/Pictures/GUI_Concept.png)

<br>

This is a possible Designt for the UI. At the top is a GroupBox with RadioButtons or a ComboBox in which the Hash-Algorithm can be chosen. At the center of the UI is a InputField where the usere can input values and at the bottom is a OutputField which will contain the hash value. At the bottom right corner is a Button to generate the hash value.

## Hashfunctions that will be implemented



### Identity hash function
If the data to be hashed is small enough, one can use the data itself (reinterpreted as an integer) as the hashed value. The cost of computing this identity hash function is effectively zero. This hash function is perfect, as it maps each input to a distinct hash value.  

**************************************************************************************************************************************************************************

### String Folding

This function takes a string as input. It processes the string eight bytes at a time, and interprets each of the four-byte chunks as a single long integer value. The integer values for the four-byte chunks are added together. In the end, the resulting sum is converted to the range 0 to M−1 using the modulus operator.  
<br>
For example, if the string “aaaabbbb” is passed to sfold, then the first four bytes (“aaaa”) will be interpreted as the integer value 1 633 771 873, and the next four bytes (“bbbb”) will be interpreted as the integer value 1 650 614 882. Their sum is 3 284 386 755 (when treated as an unsigned integer). If the table size is 101 then the modulus function will cause this key to hash to slot 75 in the table.

**************************************************************************************************************************************************************************

### Polynomial rolling hash function

A good way to definde the hash of a string **s** of length **n** is   

![PolynomialRollingFormula](https://github.com/Lion1Blue/Hashfunctions/blob/main/Pictures/PolynomialRolling.PNG)

where **p** and **m** are some chosen, positive numbers. It is called a **polinomial rolling hash function**.

Obviously **m** should be a large number since the probability of two random strings colliding is about  ≈ 1/m.  
A good choice for m is some large prime number. For example **m** = 10^9 + 9. This is a large number, but still small enough so that we can perform multiplication of two values using 64-bit integers.

For example **p** = 53 and **m** = 10^9 + 9  
input string is "Hello!", depending on how to interpret the string, either unicode oder ASCII - in this example ASCII is chosen - the hash code will differ.  
Chars in ASCII:  
'H' = 8, 'e' = 101, 'l' = 108, 'o' = 111, '!' = 33

**hashcode** = (8 * 53^0 + 101 * 53^1 + 108 * 53^2 + 108 * 53^3 + 111 * 53^4 + 33 * 53^5) mod (10^9 + 9)
= 692 681 983

**************************************************************************************************************************************************************************

## Sources
https://en.wikipedia.org/wiki/Hash_function  
https://de.wikipedia.org/wiki/Secure_Hash_Algorithm  
https://increaseyourskills.com/blog-artikel/hashfunktion  
https://www.dr-datenschutz.de/hashwerte-und-hashfunktionen-einfach-erklaert/  
https://en.wikipedia.org/wiki/Cryptographic_hash_function  
https://www.geeksforgeeks.org/what-are-hash-functions-and-how-to-choose-a-good-hash-function/  
https://www.tutorialspoint.com/cryptography/cryptography_hash_functions.htm
https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/HashFuncExamp.html 
https://cp-algorithms.com/string/string-hashing.html  
