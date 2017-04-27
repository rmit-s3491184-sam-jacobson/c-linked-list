# c-linked-list

<h1>Phone book linked list</h1>

<b>Usage:</b>

compile: gcc -ansi -Wall -pedantic -o addressbook *.
run: ./addressbook

<h3><b>Commands:</b></h3>

<b>load file_name</b>

Loads address book from .txt file

<b>unload</b>

unloads the current file

<b>display</b>

Displays the phone book list

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
