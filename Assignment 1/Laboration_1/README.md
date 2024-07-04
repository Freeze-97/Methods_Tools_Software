# Laboration 1
#### Uppgift 1:
##### Koder som användes:
```
1. git clone git@bitbucket.org:toya1800/toya1800.git
2. git add README (Skrev i den lokalt)
3. git commit -m "TEXT"
4. git push --set-upstream origin master
```
#### Uppgift 2:
Först gjorde jag som det stod i laborationen
```
1. git remote rm origin
2. git remote add origin git@bitbucket.org:miun_dt042g/toya1800_laboration_1.git
3. git push --set-upstream origin master  (failed)
4. git pull origin master (failed)
```
Jag fick felmeddelandet: `refusing to merge unrelated histories`
För att lösa det googlade jag problemet och fick fram svaret från den här länken: https://www.mkyong.com/git/git-pull-refusing-to-merge-unrelated-histories/

Där hittade jag att man skulle använda liknande commando men med tillägg: `git pull origin master --allow-unrelated-histories`

Sedan för att synka: `git push --set-upstream origin master`



