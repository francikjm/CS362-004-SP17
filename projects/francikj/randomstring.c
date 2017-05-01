Jacqueline Francik
April 28, 2017
CS362_400_SP2017
Random Testing Quiz 2


For inputChar(), I made a switch statement that has a case for each of the 9 characters being looked for. 
I used rand() to randomly choose a case which determined which character would be returned.

This moves through the first set of "if" statements until state = 9.

For inputString(), I used the same idea that I used for inputChar(). 
I knew the string that was needed to cause the error message was "reset" so I made a switch statement that had a case for each letter in the word "reset". 
I used rand() to randomly choose a case and combined that with a for loop to populate the characeter array. This randomly went through combinations of the letters 'r', 'e', 's' and 't' until the string = "reset".
