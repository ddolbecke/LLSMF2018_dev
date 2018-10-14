
## Reminders
* Computer architecture
* Code/compile/program
* Your computer board


## Today's plan 
* C language examples
* Tools installation and exercises

## Softwares
* [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide?tab=t2) 
* [XC32 compiler](http://www.microchip.com/mplab/compilers)


Download and intall the last version under the "Download Archive" tab. 



## Example 0
\lstinputlisting[firstline=12,lastline=13,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

\lstinputlisting[firstline=17,lastline=19,language=c]{../../code/mrk-board/intro_examples/sources/main.c}


\lstinputlisting[firstline=280,lastline=284,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Comments : _//_
2. Main function : _void main(void)_
3. An instruction line ends with ';'
4. Functions and levels of abstraction
    - Hierarchy

    
## Example 1
\lstinputlisting[firstline=35,lastline=39,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Digital outputs
2. Arguments of a function between '( )'
3. Hexa notation
4. Levels of abstraction
    - Modularity
5. Function initIO()

## Example 2
\lstinputlisting[firstline=41,lastline=48,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Digital intputs
2. _if(...) ... else_ 
3. Binary notation
4. The _main_ function is executed once
    
## Example 3
\lstinputlisting[firstline=50,lastline=59,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. while(1) = infinite loop
2. _setLeds( getButton2() );_

## Example 4
\lstinputlisting[firstline=61,lastline=73,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Variable declaration (here type _char_)
2. Logic operators
 
\begin{center}
\includegraphics[width=1\textwidth]{images/logique.png}
\end{center}
* ? If( (x > 4) && (x  < 10) )  

## Example 5
\lstinputlisting[firstline=76,lastline=84,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Typical structure of our programs
2. CPU frequency : 10 MHz
3. Bitwise operators

\begin{center}
\includegraphics[width=.7\textwidth]{images/logique2.png}
\end{center}
* ??
    * leds = 0xaa & 0xf0
    * leds = 0xaa && 0xf0
    
## Example 6
\lstinputlisting[firstline=86,lastline=99,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Execution time

## Example 7 (1/2)
\lstinputlisting[firstline=101,lastline=108,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Example 7 (2/2)
\lstinputlisting[firstline=29,lastline=33,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Modularity

## Example 8
\lstinputlisting[firstline=110,lastline=121,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. New functions provided by _delay.h_
	* _initDelay()_
	* _DelayMs(int tms)_
	* _DelayUs(short tus)_
	
## Example 9
\lstinputlisting[firstline=123,lastline=132,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Analog inputs
2. 10-bits conversion
3. 4-bits display

## Example 10
\lstinputlisting[firstline=135,lastline=145,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. 16 x 2 characters screen
2. Table of variable (here table of char)
3. functions provided by _PmodCLP.h_
	* _void initLCD();_
	* _void writeLine(char * string, char line);_
	* _void clearScreen();_
	* _void shiftScreen(unsigned char right);_

## Example 11
\lstinputlisting[firstline=146,lastline=161,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. function _sprintf()_
	* doc [==>**here**<==](https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm) 

## Example 12
\lstinputlisting[firstline=163,lastline=174,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Frequency command

## Example 13
\lstinputlisting[firstline=176,lastline=192,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Duty cycle command


## Example 14
\lstinputlisting[firstline=192,lastline=203,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. "Analog" output
2. Dimmer

## Example 15
\lstinputlisting[firstline=205,lastline=212,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. ascii code

\begin{center}
\includegraphics[width=0.7\textwidth]{images/ascii.png}
\end{center}


## Example 16 (1/2)
\lstinputlisting[firstline=214,lastline=223,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Example 16 (2/2)
\lstinputlisting[firstline=224,lastline=231,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
1. Table
	* declaration and use

## Example 17 (1/3)
\lstinputlisting[firstline=233,lastline=243,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Example 17 (2/3)
\lstinputlisting[firstline=244,lastline=258,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Example 17 (3/3)
\lstinputlisting[firstline=260,lastline=275,language=c]{../../code/mrk-board/intro_examples/sources/main.c}

## Lessons
* A calculator
* Type casting


