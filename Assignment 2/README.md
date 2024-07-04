Jag använde mig av kdiff3 som mergetool för att lösa uppgift 1. Programmet hade en ekel GUI
som jag använde för att lösa "conflicts" (1 av conflicts löstes automatiskt av programmet).

För uppgift 2 behövde jag bara följa anvisningarna, allt gick som det skulle.

För uppgift 3 så la jag till en decunstructor som delete båda pekarna för att fixa problemet med
minnesläckorna, jag använde även alla funktioner som fanns i screen.h, en del för rektangeln och en annan för text.


Commandon som användes:
```
Uppgift 1:
1. git clone git@bitbucket.org:miun_dt042g/screen.git
2. touch .gitignore 
3. git add .gitignore
4. git rm -rf --cached .idea
5. git commit -m "Ignore build files"
6. git mergetool
7. git add --all  
8. git merge origin/text

Uppgift 2:
1. git submodule add git@bitbucket.org:miun_dt042g/terminal.git terminal

Uppgift 3:
1. git add --all    
2. git commit -m "Inga minnesläckor nu"
```





