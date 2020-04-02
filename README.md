# cpquestion
                           

NameA and NameB are two friends. Once NameC gave them a Challenge. NameC gave an integer n as input and then an nXn 
dimensional matrix (lets denote it by M) .  This challenge is basically a game and this game is played by NameA and NameB . Normally in a game two player play to defeat each other but this game is different, in this game NameA and nameB play optimally make a condition given by nameC true. If the condition given by nameC is made true by nameA and nameB then nameC loses.
Initially NameA is at position (0,0) in the matrix and NameB is at position (n-1,n-1).
nameA has to go to position (n-1,n-1) provided it moves only down and right whereas nameB has to reach position (0,0) by moving up and left only.
While moving nameA,nameB sums all the elements which they encounter. lets denote them by x,y respectively. NameA moves first and then nameB and than they alternatively move themselves until they reach their final positions. If B is at position (i,j) then the element aij of the matrix M is multiplied by -1. whereas the element remains unaltered if nameA is at the position (i,j) of the matrix M.

NameC has also given k as input and the task that nameC gives to nameA and nameB is that if x-y>=k then they win else nameC wins. You have to tell whether it is possible for nameA,nameB to win the challenge

 ---------Input format
 first line contains integer n and k.
 The next n lines contains n elements each( Matrix m)

 ---------Output format
 one line containing whether "Wins" if nameA,nameB wins else "lose" if nameA,nameB wins (output should be without quotes).


Contraints

2<=n<=50
1<=k<=100000000
-1000<=aij<=1000 (aij detones elements of M for all i,j possible)



