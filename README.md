# Tetrix
They said there were no linux viruses. So we made one for CodeDay.
#I want to compile from source.
You'll need to build another project. `Virepri/NotSudo`, specifically.
After you've built that make a folder. Create a subfolder `resources`.
Pop `NotSudo` into `resources`.
If you need a quick little script to do this:
```
git clone https://www.github.com/virepri/Tetrix
git clone https://www.github.com/virepri/NotSudo
cd Tetrix
make
cd ..
cd NotSudo
make
cd ..
mkdir TetrixBin
mkdir TetrixBin/resources
cp Tetrix/builds/Tetrix TetrixBin/Tetrix
cp NotSudo/builds/NotSudo TetrixBin/resources/NotSudo
```