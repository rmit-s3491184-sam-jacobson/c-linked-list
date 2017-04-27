# c-linked-list

<h1>Phone book linked list</h1>

<b>Usage:</b>

compile: gcc -ansi -Wall -pedantic -o addressbook *.
run: ./addressbook

<h3><b>Commands:</b></h3>

load file_name

Loads address book from .txt file

<b>unload</b>

unloads the current file

<b>display</b>

Displays the phone book list

example output:
Enter your command: display
------------------------------------------------------
| Pos | Serial | ID | Name               | Telephone |
------------------------------------------------------
| cur |1       |100 |Alice               |0411112222 |
|     |2       |101 |Bob                 |0411112222 |
|     |3       |102 |Ali                 |0411112223 |
|     |4       |103 |Reza                |0411112224 |
|     |5       |104 |Ryan                |0411112225 |
|     |6       |105 |Aaron               |0411112226 |
|     |7       |106 |Jessica             |0411112227 |
|     |8       |107 |Xudong              |0411112228 |
|     |9       |108 |James               |0411112229 |
|     |10      |109 |Shaahin             |0411112230 |
|     |11      |110 |Matthew             |0411112231 |
|     |12      |111 |Paul                |0411112232 |
|     |13      |112 |Elton               |0411112233 |
|     |14      |113 |Joe                 |0411112234 |
|     |15      |114 |Daniel              |0411112235 |
|     |16      |115 |Anthony             |0411112236 |
|     |17      |116 |Kelvin              |0411112237 |
|     |18      |117 |Harry               |0411112238 |
|     |19      |118 |Zhaowei             |0411112239 |
|     |20      |119 |Lei                 |0411112240 |
|     |21      |120 |Forest              |0411112241 |
------------------------------------------------------
| Total phone book entries: 21                       |
------------------------------------------------------



<b>forward number_of_steps_forward</b>

moves the phone book forward X number of times

example: forward 5

<b>forward number_of_steps_backward</b>

moves the phone book forward X number of times

example: backward 5

<b>insert id name telephone</b>

insert a new item into the linked list.

id must be unique
telephone must be 8 charaters long

<b>find name</b>

finds the entry with matching name

example: find john

<b>delete</b>

deletes the entry at the current position

<b>save file_name.txt</b>

saves modified addressbook
