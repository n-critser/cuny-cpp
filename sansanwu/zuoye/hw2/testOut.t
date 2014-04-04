g++  -Wall -Werror -g -I../include   -c -o main.o main.cpp
/usr/bin/g++ -Wall -Werror -g -I../include  -o hw2 main.o
Changed files: main.o

************RUNNING TEST ON FILE tests/findTest.txt***********
number of args =2
fix or remove NOT_FOUND 
first	1
second	1
ENTERING ROTATE WITH RIGHT CHILD
third	1

first          (1)
second         (1)
third          (1)

second(1)h=1
first(1)h=0
third(1)h=0

fourth	1
fourth	2
fourth	3
fifth	1
sixth	1

fifth          (1)
first          (1)
fourth         (3)
second         (1)
sixth          (1)
third          (1)

second(1)h=2
first(1)h=1
fifth(1)h=0
fourth(3)h=0
third(1)h=1
sixth(1)h=0

ENTERING ROTATE WITH LEFT CHILD
seventh	1

fifth          (1)
first          (1)
fourth         (3)
second         (1)
seventh        (1)
sixth          (1)
third          (1)

second(1)h=2
first(1)h=1
fifth(1)h=0
fourth(3)h=0
sixth(1)h=1
seventh(1)h=0
third(1)h=0

eighth	1
ninth	1
first	1
second	1
third	1
fourth	3

eighth         (1)
fifth          (1)
first          (1)
fourth         (3)
ninth          (1)
second         (1)
seventh        (1)
sixth          (1)
third          (1)

second(1)h=3
first(1)h=2
fifth(1)h=1
eighth(1)h=0
fourth(3)h=1
ninth(1)h=0
sixth(1)h=1
seventh(1)h=0
third(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 9
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 9
               Ave. Nodes hit with Find  = 2.25

Deleting Min Node for 2 Subtree
first	NOT-FOUND
Deleting Min Node for 2 Subtree
second	NOT-FOUND
second	NOT-FOUND

eighth         (1)
fifth          (1)
fourth         (3)
ninth          (1)
seventh        (1)
sixth          (1)
third          (1)

seventh(1)h=3
fourth(3)h=2
fifth(1)h=1
eighth(1)h=0
ninth(1)h=0
sixth(1)h=1
third(1)h=0

second	0
first	0
last	0
fourth	3
"sixth"	0
ENTERING ROTATE WITH LEFT CHILD
"sixth"	1

"sixth"        (1)
eighth         (1)
fifth          (1)
fourth         (3)
ninth          (1)
seventh        (1)
sixth          (1)
third          (1)

seventh(1)h=3
fourth(3)h=2
eighth(1)h=1
"sixth"(1)h=0
fifth(1)h=0
ninth(1)h=0
sixth(1)h=1
third(1)h=0

sixth	2

               EAVLTREE INSTANCE REPORT
               size              = 8
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 8
               Ave. Nodes hit with Find  = 3.11111


"sixth"        (1)
eighth         (1)
fifth          (1)
fourth         (3)
ninth          (1)
seventh        (1)
sixth          (2)
third          (1)

seventh(1)h=3
fourth(3)h=2
eighth(1)h=1
"sixth"(1)h=0
fifth(1)h=0
ninth(1)h=0
sixth(2)h=1
third(1)h=0

EXIT COMMAND GIVEN------>GOODBYE
******TESTING COMPLETED ON FILE tests/findTest.txt*********
 

************RUNNING TEST ON FILE tests/insertTest.txt***********
number of args =2
fix or remove NOT_FOUND 
fancy	1
this	1
ENTERING ROTATE WITH RIGHT CHILD
tuesday	1
666fat	1

               EAVLTREE INSTANCE REPORT
                            size = 4
                          height = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
                Int. Path Length = 4
               Ave. Nodes hit with Find  = -nan

666fat	1

666fat         (1)
fancy          (1)
this           (1)
tuesday        (1)

this(1)h=2
fancy(1)h=1
666fat(1)h=0
tuesday(1)h=0

ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
distancerunning	1
this	1

666fat         (1)
distancerunning(1)
fancy          (1)
this           (1)
tuesday        (1)

this(1)h=2
distancerunning(1)h=1
666fat(1)h=0
fancy(1)h=0
tuesday(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 5
               height            = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 5
               Ave. Nodes hit with Find  = 2

ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
fancy-pants	1
fancy-pants	NOT-FOUND
fancy-pants	0
ford	1
ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
chevy	1
lincoln	1
Deleting Min Node for 2 Subtree
chevy	NOT-FOUND
distancerunning	1
chevy	0
ford	1
facist	1

               EAVLTREE INSTANCE REPORT
               size              = 8
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 8
               Ave. Nodes hit with Find  = 2.66667

facist	1

               EAVLTREE INSTANCE REPORT
               size              = 8
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 8
               Ave. Nodes hit with Find  = 2.71429

fancy-pants	0

               EAVLTREE INSTANCE REPORT
               size              = 8
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 8
               Ave. Nodes hit with Find  = 2.875


666fat         (1)
distancerunning(1)
facist         (1)
fancy          (1)
ford           (1)
lincoln        (1)
this           (1)
tuesday        (1)

fancy(1)h=3
distancerunning(1)h=1
666fat(1)h=0
facist(1)h=0
this(1)h=2
ford(1)h=1
lincoln(1)h=0
tuesday(1)h=0

distance=to\mars	1

666fat         (1)
distance=to\mars(1)
distancerunning(1)
facist         (1)
fancy          (1)
ford           (1)
lincoln        (1)
this           (1)
tuesday        (1)

fancy(1)h=3
distancerunning(1)h=2
666fat(1)h=1
distance=to\mars(1)h=0
facist(1)h=0
this(1)h=2
ford(1)h=1
lincoln(1)h=0
tuesday(1)h=0

facist	1

               EAVLTREE INSTANCE REPORT
               size              = 9
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 9
               Ave. Nodes hit with Find  = 2.88889

fancy-pants	1
fancy-pants	2
fancy-pants	3
fancy-pants	4
fancy-pants	5

               EAVLTREE INSTANCE REPORT
               size              = 10
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 10
               Ave. Nodes hit with Find  = 2.88889

fancy-pants	5

666fat         (1)
distance=to\mars(1)
distancerunning(1)
facist         (1)
fancy          (1)
fancy-pants    (5)
ford           (1)
lincoln        (1)
this           (1)
tuesday        (1)

fancy(1)h=3
distancerunning(1)h=2
666fat(1)h=1
distance=to\mars(1)h=0
facist(1)h=0
this(1)h=2
ford(1)h=1
fancy-pants(5)h=0
lincoln(1)h=0
tuesday(1)h=0

fancy-pants	4
fancy-pants	3
fancy-pants	2
fancy-pants	1
ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
hello	1
EXIT COMMAND GIVEN------>GOODBYE
******TESTING COMPLETED ON FILE tests/insertTest.txt*********
 

************RUNNING TEST ON FILE tests/malformedTest.txt***********
number of args =2
fix or remove NOT_FOUND 
fancy	1
this	1
ENTERING ROTATE WITH RIGHT CHILD
tuesday	1
666fat	1

               EAVLTREE INSTANCE REPORT
                            size = 4
                          height = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
                Int. Path Length = 4
               Ave. Nodes hit with Find  = -nan

Testing size[4] : [4]

666fat         (1)
fancy          (1)
this           (1)
tuesday        (1)

this(1)h=2
fancy(1)h=1
666fat(1)h=0
tuesday(1)h=0

ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
distancerunning	1
ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
pants	1

666fat         (1)
distancerunning(1)
fancy          (1)
pants          (1)
this           (1)
tuesday        (1)

fancy(1)h=2
distancerunning(1)h=1
666fat(1)h=0
this(1)h=1
pants(1)h=0
tuesday(1)h=0

Testing size[6] : [6]

               EAVLTREE INSTANCE REPORT
               size              = 6
               height            = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 6
               Ave. Nodes hit with Find  = -nan

hello-world	1
what	1

666fat         (1)
distancerunning(1)
fancy          (1)
hello-world    (1)
pants          (1)
this           (1)
tuesday        (1)
what           (1)

fancy(1)h=3
distancerunning(1)h=1
666fat(1)h=0
this(1)h=2
pants(1)h=1
hello-world(1)h=0
tuesday(1)h=1
what(1)h=0

pants	NOT-FOUND
pants	NOT-FOUND
pants	1
pants	2
this	2
ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
blackmail	1
Testing size[9] : [9]
what	2
what	3
what	3

               EAVLTREE INSTANCE REPORT
               size              = 9
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 9
               Ave. Nodes hit with Find  = 4

blackmail	1

666fat         (1)
blackmail      (1)
distancerunning(1)
fancy          (1)
hello-world    (1)
pants          (2)
this           (2)
tuesday        (1)
what           (3)

fancy(1)h=3
blackmail(1)h=1
666fat(1)h=0
distancerunning(1)h=0
this(2)h=2
hello-world(1)h=1
pants(2)h=0
tuesday(1)h=1
what(3)h=0


               EAVLTREE INSTANCE REPORT
               size              = 9
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 9
               Ave. Nodes hit with Find  = 3

EXIT COMMAND GIVEN------>GOODBYE
******TESTING COMPLETED ON FILE tests/malformedTest.txt*********
 

************RUNNING TEST ON FILE tests/removeTest.txt***********
number of args =2
fix or remove NOT_FOUND 
distance=to\mars	1
facist	1
facist	1

               EAVLTREE INSTANCE REPORT
                            size = 2
                          height = 1
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
                Int. Path Length = 2
               Ave. Nodes hit with Find  = 2

ENTERING ROTATE WITH RIGHT CHILD
fancy-pants	1
fancy-pants	2
fancy-pants	3
fancy-pants	4
Fancy-pants	1
ENTERING ROTATE WITH LEFT CHILD
Fancy-panTS	1
Fancy-pants	2

               EAVLTREE INSTANCE REPORT
                            size = 5
                          height = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
                Int. Path Length = 5
               Ave. Nodes hit with Find  = 2

fancy-pants	4

Fancy-panTS    (1)
Fancy-pants    (2)
distance=to\mars(1)
facist         (1)
fancy-pants    (4)

facist(1)h=2
Fancy-pants(2)h=1
Fancy-panTS(1)h=0
distance=to\mars(1)h=0
fancy-pants(4)h=0

Fancy-pants	1
fancy-pants	3
fancy-pants	2
fancy-pants	1
ENTERING ROTATE WITH LEFT CHILD
fancy-pants	NOT-FOUND
fancy-pants	NOT-FOUND
fancy-pants	NOT-FOUND

Fancy-panTS    (1)
Fancy-pants    (1)
distance=to\mars(1)
facist         (1)

Fancy-pants(1)h=2
Fancy-panTS(1)h=0
facist(1)h=1
distance=to\mars(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 4
               height            = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 4
               Ave. Nodes hit with Find  = 2

hello	1
hello	NOT-FOUND
facist	NOT-FOUND

Fancy-panTS    (1)
Fancy-pants    (1)
distance=to\mars(1)

Fancy-pants(1)h=1
Fancy-panTS(1)h=0
distance=to\mars(1)h=0

distance=to\mars	NOT-FOUND

               EAVLTREE INSTANCE REPORT
               size              = 2
               height            = 1
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 2
               Ave. Nodes hit with Find  = 2


Fancy-panTS    (1)
Fancy-pants    (1)

Fancy-pants(1)h=1
Fancy-panTS(1)h=0

EXIT COMMAND GIVEN------>GOODBYE
******TESTING COMPLETED ON FILE tests/removeTest.txt*********
 

************RUNNING TEST ON FILE tests/zLenghtTest.txt***********
number of args =2
fix or remove NOT_FOUND 
one	1
two	1
ENTERING ROTATE WITH LEFT CHILD
ENTERING ROTATE WITH RIGHT CHILD
three	1

one            (1)
three          (1)
two            (1)

three(1)h=1
one(1)h=0
two(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 3
               height            = 1
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 3
               Ave. Nodes hit with Find  = -nan

four	1
ENTERING ROTATE WITH LEFT CHILD
five	1

five           (1)
four           (1)
one            (1)
three          (1)
two            (1)

three(1)h=2
four(1)h=1
five(1)h=0
one(1)h=0
two(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 5
               height            = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 5
               Ave. Nodes hit with Find  = -nan

ENTERING ROTATE WITH RIGHT CHILD
ENTERING ROTATE WITH LEFT CHILD
six	1

five           (1)
four           (1)
one            (1)
six            (1)
three          (1)
two            (1)

one(1)h=2
four(1)h=1
five(1)h=0
three(1)h=1
six(1)h=0
two(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 6
               height            = 2
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 6
               Ave. Nodes hit with Find  = -nan

seven	1
ENTERING ROTATE WITH LEFT CHILD
eight	1
nine	1
ten	1

eight          (1)
five           (1)
four           (1)
nine           (1)
one            (1)
seven          (1)
six            (1)
ten            (1)
three          (1)
two            (1)

one(1)h=3
five(1)h=2
eight(1)h=0
four(1)h=1
nine(1)h=0
three(1)h=2
six(1)h=1
seven(1)h=0
ten(1)h=0
two(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 10
               height            = 3
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 10
               Ave. Nodes hit with Find  = -nan

eleven	1
twelve	1
thirteen	1

eight          (1)
eleven         (1)
five           (1)
four           (1)
nine           (1)
one            (1)
seven          (1)
six            (1)
ten            (1)
thirteen       (1)
three          (1)
twelve         (1)
two            (1)

one(1)h=4
five(1)h=2
eight(1)h=1
eleven(1)h=0
four(1)h=1
nine(1)h=0
three(1)h=3
six(1)h=2
seven(1)h=0
ten(1)h=1
thirteen(1)h=0
two(1)h=1
twelve(1)h=0


               EAVLTREE INSTANCE REPORT
               size              = 13
               height            = 4
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
FIXME: TEST THIS AGAIN 
               Int. Path Length  = 13
               Ave. Nodes hit with Find  = -nan

EXIT COMMAND GIVEN------>GOODBYE
******TESTING COMPLETED ON FILE tests/zLenghtTest.txt*********
 
rm -f main.o  hw2  *.debug
