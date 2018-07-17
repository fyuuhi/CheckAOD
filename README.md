
# Install
```sh
git clone ssh://git@gitlab.cern.ch:7999/yfukuhar/CheckAOD.git
cd checkAOD
ls
>>> MyNewPackage/  run/  compile.sh  install.sh  setup.sh
source install.sh
ls
>>> MyNewPackage/  RootCoreBin/  run/  rcSetup.csh@  compile.sh  install.sh  rcSetup.sh@  setup.sh
```

# Compile
When you restart shell,
```sh
source setup.sh
```
When you edit the codes (MyNewPackage/*)
```sh
source compile.sh
```

# Run
```sh
cd run
./runCheckAOD.sh
```
