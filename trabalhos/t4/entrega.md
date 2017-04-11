-Alan Bessauer Lencina
-Programação Paralela

1:The problem with that program is that only the master thread was supposed to check the tid, but there's no control made, so they just all
execute at the same time, having a problem where all the threads are assigned at once, you need to make something to control so it's properly
worked out
