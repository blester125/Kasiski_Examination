/************************************
 * CS 1653 Homework Two at the      *
 * University of Pittsburgh         *
 * Taught by Bill Garrison          *
 * Spring 2016                      *
 * By:                              *
 *   Brian Lester                   *
 ************************************/

#ifndef __BREAKER_H_
#define __BREAKER_H_

int isChar(char c);
char toLower(char c);
int readIn(char * text, int length);
int stripInput(char *in, char *out, int length);
struct node * kasiski(char * text, int length);
int findGCD(int nums[], int length);
int GCD(int a, int b);
int countCleanDivisions(int nums[], int length, int num);
void decode(char *key, int keyLength, char *cipherText, int length);
void reinsert(char *in, char *out, int length);

#endif