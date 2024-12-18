#! /bin/sh

pwd
cd ..
pwd
echo "subst: saving working dir state"
git status
git config user.email 'build-tool@samsung.com'
git config user.name 'Build Tool'
git stash -a
git stash apply
echo "subst: making substitutions"
echo $PATH
which subst

# grep -rnE --exclude-dir=external --exclude-dir=tools --exclude-dir=build --exclude-dir=docs --exclude-dir=lib --exclude-dir=resource --include=\*.c --include=\*.cc --include=\*.cpp --include=\*.C '".*%[-#0 +'\''I]?[*0-9]*(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm].*"' * | grep -vE ':\s*(\<[fs]printf)' | subst
