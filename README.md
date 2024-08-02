# logineasy
cli tool to show ALL startup items/daemons (OSX)    
# Installation
## Homebrew (from src)
Run these commands in your terminal (Requires CMake and make to be installed, though homebrew should do that for you)
```shell
brew tap penguinify/homebrew-logineasy
brew install logineasy
logineasy -v
```
## Manual (from src)
1. Download source from github
2. Install xcode select tools if you haven't already (`xcode-select --install`)
3. `cd` into the directory
4. Run `make`
5. All outputted items will be in ./dist/*
6. Move logineasy into your bin directory.
