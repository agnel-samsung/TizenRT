#! /bin/sh

set -x
echo "subst: saving working dir state"
git config user.email 'build-tool@samsung.com'
git config user.name 'Build Tool'
date > subst-timestamp
git stash
git stash apply
echo "subst: making substitutions"
export PATH=`pwd`/os/tools/subst/build:$PATH
echo $PATH
which subst

grep -rnP --exclude-dir=external --exclude-dir=tools --exclude-dir=build --exclude-dir=docs --exclude-dir=lib --exclude-dir=resource --include=\*.c --include=\*.cc --include=\*.cpp --include=\*.C '".*%[-#0 +'\''I]?[*0-9]*(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm].*"' * | grep -vE ':\s*(\<[fs]printf)' | subst > subst.json
