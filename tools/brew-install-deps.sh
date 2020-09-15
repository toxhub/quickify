brew update

PKGS="
  cmake
  "

for pkg in $PKGS
do
  brew install $pkg
done
