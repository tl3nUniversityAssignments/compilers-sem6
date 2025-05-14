for easier work, i've created dockerfile with clang++-3.9 compiler installed.
build and run it using this commands:
```bash
docker build -t clang39-env .
docker run -it v [path to this repo]:/workspace clang39-env 
```