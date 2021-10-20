git status
git add *
git status
echo "Klk con este commit?"
read commitname
git commit -m $commitname
git push -u origin main 

