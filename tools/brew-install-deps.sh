brew update

PKGS="
  cmake
  rust
  "

for pkg in $PKGS
do
  brew install $pkg
done
