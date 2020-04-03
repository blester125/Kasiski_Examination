# CS 1653 Vigenere Cipher

##

### Kasiski Examination Program.

This program can preform Kasiski analysis and decode ciphertext if provided a 
key.

To compile this program run 
	`make`
This will create a program called "breaker" this can be run in 2 way. The 
first way preforms Kasiski analysis on file.txt and is run like so.

	./breaker kasiski < file.txt	

This strips all white space and punctuation marks from the incoming 
ciphertext.

The program then runs Kasiski analysis and tries to find the greatest common 
denominator of all the the distances between repeated words. If a usable 
greatest common denominator is found (i.e. not 1) then it is returned. 
Otherwise it calculates which gap distances are the most likely to be the key 
length. 

This analysis doesn't ignore sub string repeats, for example the string 
"homework at home" will have matches of:

* "home" at 0 and 12
* "ome" at 1 and 13

This is ok because the actual gaps between the numbers are the same. 
The gap distances are stored in a set to this same gap width happening 
again and again will not effect anything.

The program can also be used to decode ciphertext using the Vigenere cipher 
given the key. It is run like so:

	./breaker decode key < file.txt

Like before the spaces and punctuation will be stripped before decoded and 
restored later. This implements the shift like so:

* a = 0
* b = 1
* ...
* z = 25

This means that if there is an a in the key then the plaintext will match 
the ciphertext. 


### Approach used to break the cipher.

After I used my program to establish the fact that the key was most likely of 
length 7 I figured out the key based on the first word of the ciphertext. The 
first word was "dsyrrshvpleigbt!" The fact that this word is the first word, ends 
with an exclamation point and is 15 letters long it seems pretty obvious that the
word will decode to "congratulations!" Once I guess that this was the first word 
I found a key of length 7 that would cause "dsyrrshvpleigbt!" to decode to
"congratulations!" 

* 'd' -> 'c' is a shift of 1 so the first letter of the key is 'a'.
* 's' -> 'o' is a shift of 4 so the second letter is 'd'.
* 'y' -> 'n' is a shift of 11 so the third letter is 'k'.
* 'r' -> 'g' is a shift of 11 so the fourth letter is 'k'.
* 'r' -> 'r' is a shift of 26 so the fifth letter is 'z'.
* 's' -> 'a' is a shift of 18 so the sixth letter is 'r'.
* 'h' -> 't' is a shift of 14 so the last letter is 'n'.
* 'v' -> 'u' is a shift of 1 so the first letter is confirmed 'a'.
* 'p' -> 'l' is a shift of 4 so the second letter is confirmed 'd'.
* ...

This key works to decode congratulations from dsyrrshvpleigbt. So I wrote up the
decode program to see if this decoded the entire message. I implemented this so 
that the key is repeated once it ends however the letter of the key are not used 
for spaces or punctuation which seems the standard practice in Vigenere ciphers 
according to my research online. This key successfully decode the message but 
something didn't sit right with me. While a random key is a good thing to use in 
a real cryptographic application this is a homework assignment so I was expecting 
a word as a key. The only way to change the key is to change the shift values of
each letter. So I tried this. Rather than 'a' being a shift of 1 and 'z' a shift 
of 26 (this can be thought of as a shift of 0 due to the circular nature of the 
alphabet) I tried it with 'a' being a shift of 0 and 'z' being a shift of 25. 
Changing the shift like this means that all the letters in the key should be one 
letter higher in the alphabet so 'a' becomes 'b', 'b' becomes 'c', and so forth. 
With this change the key becomes 'bellaso' this is the last name of the original 
inventor of the Vigenere Cipher so it makes a lot of sense as a key. After I 
found 'bellaso' as the key I edited my program to use this new decoding shift 
distances. The message still decoded properly so this seems to be the correct 
key. 

Homework 2 for CS 1653 at The University of Pittsburgh with Dr. Garrison.
