if [ ! -d "$1" ]; then
    echo "Must pass git directory as the first argument."
    exit 2;
fi

cd $1
echo -e "Enter new version (Current `git describe --abbrev=0 --tags`): \c "
while read ver; do
    if ([[ ! -z "$ver" ]]) && ([ "$ver" == "`echo $ver | grep "^[0-9]\{1,\}\.[0-9]\{1,\}\.[0-9]\{1,\}$"`" ])
    then
        break
    else
        echo "  Version entered ($ver) was not formatted properly."
        echo -e "Enter new version (Current `git describe --abbrev=0 --tags`): \c "
    fi
done

echo -e "Are you sure you want to release version $ver? (y|n): \c "
read confirm

if([ $confirm == "y" ]) then
    git checkout -b release-$ver develop
    git checkout master
    result=`git merge --no-ff release-$ver`
    if([ "$result" == "`echo $result | grep "^Already up-to-date\."`" ]) then
        git branch -D release-$ver
        echo "The branch is already up to date.  Aborting version bump.";
        exit 3;
    else
        git tag -a $ver -m "Used bump script."
        git branch -D release-$ver
        echo ""
        echo "If you need to undo this last commit, abort now and run:"
        echo "  git reset --hard HEAD~1"
        echo "  git tag -d $ver"
        echo ""
        echo -e "Push this change to the origin server and merge back into the develop branch? (y|n): \c "
        read confirm 
        if([ $confirm == "y" ]) then
            git push origin master
            git checkout develop
            git merge master
        fi

        echo "Finished merging."
        exit 1;
    fi
else
    echo "Aborted the version bump."
    exit 1;
fi