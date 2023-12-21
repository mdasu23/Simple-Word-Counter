My Own Version of Word Counter tool , Coding challenge link-> https://codingchallenges.fyi/challenges/challenge-wc
Usage:  
  1. Compile by giving the command make ccwc
  2. ./ccwc -c "input".txt : Outputs the number of bytes in the input file.
  3. ./ccwc -l "input".txt : Outputs the number of lines in the input file.
  4. ./ccwc -w "input".txt : Outputs the number of words in the input file.
  5. ./ccwc -m "input".txt : Outputs the number of characters in the input file.
  6. ./ccwc "input".txt: Outputs all the above stats of the input file.
  7. cat "input".txt | ./ccwc [-l -c -w -m] : Reads the input and outputs the above stats from the input.
  8. Clean the space by issuing the command make clean.

License: https://github.com/mdasu23/ccwc/blob/ccwc/LICENSE
