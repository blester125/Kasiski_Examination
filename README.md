#CS 1653 Vigenere Cipher Homework two.

##

###Kasiski Examination Program.

This program can preform Kasiski analysis and decode ciphertext if provided a 
key.

To compile this program run 
	`make`
This will create a program called "breaker" this can be run in 2 way. The 
first way preforms Kasiski analysis on file.txt and is run like so.

	`./breaker kasiski < file.txt`	

This strips all white space and punctuation marks from the incoming 
ciphertext.

The program then runs Kasiski analysis and tries to find the greatest common 
denominator of all the the distances between repeated words. If a usable 
greatest common denominator is found (i.e. not 1) then it is returned. 
Otherwise it calculates which gap distances are the most likely to be the key 
length. 

This analysis doesn't ignore sub string repeats, for example the string "homework at home" will have matches of:

* "home" at 0 and 12
* "ome" at 1 and 13

This is ok because the actual gaps between the numbers are the same. 
The gap distances are stored in a set to this same gap width happending 
again and again will not effect anything.

The program can also be used to decode ciphertext using the Vigenere cipher 
given the key. It is run like so:

	`./breaker decode key < file.txt`

Like before the spaces and punctuation will be stipped before decoded and 
restored later. This implements the shift like so:

* a = 0
* b = 1
* ...
* z = 25

This means that if there is an a in the key then the plaintext will match 
the ciphertext. 


### Approach used to break the cipher. 
