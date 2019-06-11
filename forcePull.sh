#Ignores git "something... local changes ...something"

git stash save --keep-index
git stash drop
git pull origin master
